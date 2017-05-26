from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp
from datetime import datetime
import os.path
import pytz

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
base_dir = os.path.dirname(os.path.abspath(__file__))
db_path = os.path.join(base_dir, "finance.db")
db = SQL("sqlite:///{}".format(db_path))

# generate timezone dictionary
continents = get_timezone_dict()


@app.route("/")
@login_required
def index():
    user_cash = db.execute("SELECT cash "
                           "FROM users "
                           "WHERE id = :id;",
                           id=session["user_id"])[0]["cash"]
    try:
        portfolios = db.execute("SELECT * "
                                "FROM portfolios "
                                "WHERE id = :id;",
                                id=session["user_id"])
        cash_from_quotes = 0

        for transaction in portfolios:
            share_quote = lookup(transaction["symbol"])
            try:
                transaction["price"] = float(share_quote["price"])
            except ValueError:
                return apology("no online price for current symbol")

            transaction["name"] = share_quote["name"]

            result = transaction["price"] * transaction["shares"]
            cash_from_quotes += result
            transaction["total"] = str(usd(result))
            transaction["price"] = usd(transaction["price"])
            transaction["shares"] = str(transaction["shares"])

    except IndexError:
        portfolios = None
        cash_from_quotes = user_cash

    total_cash = user_cash + cash_from_quotes

    return render_template("index.html", total_cash=usd(total_cash), user_cash=usd(user_cash), portfolios=portfolios)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # get username
        try:
            # ensure uniqueness by using lower
            existing_user = db.execute("SELECT LOWER( username ) AS 'username' "
                                       "FROM users "
                                       "WHERE LOWER( username ) = :username;",
                                       username=request.form.get("username").lower())[0]['username']
        except:
            existing_user = None

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure username is not taken
        elif existing_user is not None and existing_user == request.form.get("username").lower():
            return apology("username already taken")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # ensure password verify was submitted
        elif not request.form.get("passwordverify"):
            return apology("must confirm password")

        # ensure matching password with verified password
        elif request.form.get("password") != request.form.get("passwordverify"):
            return apology("entered passwords do not match")
        # ensure timezone selection
        elif request.form.get("timezone") is None:
            return apology("select a timezone")

        # add user to database
        db.execute("INSERT INTO users ( 'username', 'hash', 'timezone' ) "
                   "VALUES ( :username, :hash, :timezone );",
                   username=request.form.get("username"),
                   hash=pwd_context.encrypt(request.form.get("password")),
                   timezone=request.form.get("timezone"))

        # get user_id
        user_id = db.execute("SELECT id "
                             "FROM users "
                             "WHERE username = :username;",
                             username=request.form.get("username"))

        # remember which user has logged in
        session["user_id"] = user_id[0]['id']

        # redirect user to home page
        flash("Registered!")
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        global continents
        return render_template("register.html", continents=continents)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for unique username using lower
        rows = db.execute("SELECT * "
                          "FROM users "
                          "WHERE LOWER( username ) = :username;",
                          username=request.form.get("username").lower())

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))


@app.route("/settings", methods=["GET", "POST"])
@login_required
def settings():
    """Change password/timezone, add additional funds"""
    if request.method == "POST":
        if not request.form.get("password"):
            return apology("need password to update")
        elif request.form.get("passwordnew") != request.form.get("passwordnewverify"):
            return apology("passwords don't match")

        if request.form.get("funds"):
            db.execute("UPDATE users "
                       "SET cash = cash + :cash "
                       "WHERE id = :id",
                       cash=request.form.get("funds"),
                       id=session["user_id"])
        if request.form.get("timezone"):
            db.execute("UPDATE users "
                       "SET timezone = :timezone "
                       "WHERE id = :id",
                       timezone=request.form.get("timezone"),
                       id=session["user_id"])
        if request.form.get("passwordnew") and request.form.get("passwordnewverify") and request.form.get(
                "passwordnew") == request.form.get("passwordnewverify"):
            db.execute("UPDATE users "
                       "SET hash = :hash "
                       "WHERE id = :id",
                       hash=pwd_context.encrypt(request.form.get("passwordnew")),
                       id=session["user_id"])
        flash("Updated!")
        return redirect(url_for("index"))

    else:
        return render_template("settings.html", continents=continents)


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        share_quote = lookup(request.form.get("symbol"))

        if share_quote is None:
            return apology("invalid symbol")

        share_quote = "A share of {} ({}) costs {}.".format(share_quote['name'], share_quote['symbol'],
                                                            usd(share_quote['price']))

        return render_template("quoted.html", quote=share_quote)
    else:
        return render_template("quote.html")


@app.route("/history", methods=["GET"])
@login_required
def history():
    transaction_history = db.execute("SELECT symbol, transactions.shares, date, price, timezone "
                                     "FROM portfolios "
                                     "INNER JOIN transactions ON transactions.id = portfolios.id "
                                     "INNER JOIN users ON users.id = portfolios.id")

    fmt = "%Y-%m-%d %H:%M:%S"
    for row in transaction_history:
        tz = pytz.timezone(row["timezone"])
        local_time = pytz.utc.localize(datetime.strptime(row["date"], fmt)).astimezone(tz)
        row["date"] = local_time.strftime(fmt)

    return render_template("history.html", history=transaction_history)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock."""

    if request.method == "POST":
        share_quote = lookup(request.form.get("symbol"))

        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            shares = None

        if not request.form.get("symbol"):
            return apology("missing symbol")
        elif shares is None:
            return apology("missing shares")
        elif shares < 0:
            return apology("negative shares", "not allowed")
        elif share_quote is None:
            return apology("invalid symbol")

        try:
            share_price = float(share_quote["price"])
        except ValueError:
            return apology("no online price for this symbol")

        total_price = shares * share_price
        user_cash = db.execute("SELECT cash "
                               "FROM users "
                               "WHERE id = :id;",
                               id=session["user_id"])[0]["cash"]

        if total_price <= user_cash:
            try:
                existing = db.execute("SELECT symbol "
                                      "FROM portfolios "
                                      "WHERE id = :id AND symbol = :symbol;",
                                      id=session["user_id"],
                                      symbol=share_quote["symbol"])[0]["symbol"]
            except IndexError:
                existing = False

            if not existing:
                db.execute("INSERT INTO portfolios ('id', 'symbol', 'shares' ) "
                           "VALUES ( :id, :symbol, :shares );",
                           id=session["user_id"], symbol=share_quote["symbol"], shares=shares)
            else:
                db.execute("UPDATE portfolios "
                           "SET shares = shares + :shares "
                           "WHERE id = :id AND symbol = :symbol;",
                           shares=shares, id=session["user_id"], symbol=share_quote["symbol"])

            db.execute("UPDATE users "
                       "SET cash = :cash "
                       "WHERE id = :id;",
                       cash=(user_cash - total_price), id=session["user_id"])

            db.execute("INSERT INTO transactions ( 'id', 'shares', 'price' ) "
                       "VALUES ( :id, :shares, :price );",
                       id=session["user_id"], shares=shares, price=share_price)

            flash("Bought!")
            return redirect(url_for("index"))
        else:
            return apology("can't afford")

    else:
        try:
            symbol = request.args["symbol"]
        except:
            symbol = ''
        return render_template("buy.html", symbol=symbol)


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""

    if request.method == "POST":
        try:
            sell_shares = int(request.form.get("shares"))
        except ValueError:
            return apology("invalid shares")

        share_quote = lookup(request.form.get("symbol"))
        try:
            user_shares = db.execute("SELECT shares "
                                     "FROM portfolios "
                                     "WHERE id = :id AND symbol = :symbol;",
                                     id=session["user_id"], symbol=share_quote["symbol"])[0]["shares"]
        except IndexError:
            return apology("no {} shares to sell".format(share_quote["symbol"]))

        if user_shares is None or sell_shares > user_shares:
            return apology("too many shares")
        elif sell_shares == 0:
            return apology("enter more than zero")

        share_price = share_quote["price"]

        db.execute("UPDATE users "
                   "SET cash = cash + :cash "
                   "WHERE id = :id",
                   cash=(share_price * sell_shares), id=session["user_id"])

        if user_shares - sell_shares > 0:
            db.execute("UPDATE portfolios "
                       "SET shares = shares - :shares "
                       "WHERE id = :id AND symbol = :symbol;",
                       shares=sell_shares, id=session["user_id"], symbol=share_quote["symbol"])
        else:
            db.execute("DELETE FROM portfolios "
                       "WHERE id = :id AND symbol = :symbol;",
                       id=session["user_id"], symbol=share_quote["symbol"])

        db.execute("INSERT INTO transactions ( 'id', 'shares', 'price' ) "
                   "VALUES ( :id, :shares, :price );",
                   id=session["user_id"], shares=-sell_shares, price=share_price)

        flash("Sold!")
        return redirect(url_for("index"))
    else:
        try:
            symbol = request.args["symbol"]
        except:
            symbol = ''
        return render_template("sell.html", symbol=symbol)


if __name__ == "__main__":
    app.run()
