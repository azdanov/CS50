#!/usr/bin/env python3


def main():
    height = get_height()

    print__double_half_pyramid(height)


def get_height():
    while True:
        try:
            height = int(input("Height: "))
        except ValueError:
            continue

        if 0 < height < 24:
            break

    return height


def print__double_half_pyramid(height):
    for i in range(1, height + 1):
        print("{0:>{width}}{1:2}{0:<{width}}".format("#" * i, "", width=height))


if __name__ == "__main__":
    main()
