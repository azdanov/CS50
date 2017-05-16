#!/usr/bin/env python3


def main():
    change_owed = get_change()

    min_coins = get_min_coins(change_owed)

    print(min_coins)


def get_change():
    print("O hai! ", end="")
    while True:
        try:
            change = float(input("How much change is owed?\n"))
        except ValueError:
            continue
        if change > 0:
            break

    return change


def get_min_coins(change):
    min_coins = 0
    change *= 100

    quarter = 25
    dime = 10
    nickel = 5
    penny = 1

    while change > 0:
        if change - quarter >= 0:
            change -= quarter
            min_coins += 1
        elif change - dime >= 0:
            change -= dime
            min_coins += 1
        elif change - nickel >= 0:
            change -= nickel
            min_coins += 1
        else:
            change -= penny
            min_coins += 1

    return min_coins


if __name__ == "__main__":
    main()
