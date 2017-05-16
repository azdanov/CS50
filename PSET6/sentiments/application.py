from flask import Flask, redirect, render_template, request, url_for

import helpers

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    number_of_tweets = 100

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name, number_of_tweets)

    # get stats from tweets
    positive, negative, neutral = helpers.get_tweets_stats(tweets)

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)


if __name__ == "__main__":
    app.run()
