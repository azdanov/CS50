#!/usr/bin/env python3


def main():
    height = get_height()

    print_half_pyramid(height)


def get_height():
    while True:
        try:
            height = int(input("Height: "))
        except ValueError:
            continue

        if 0 < height < 24:
            break

    return height


def print_half_pyramid(height):
    for i in range(2, height + 2):
        print("{:>{width}}".format("#" * i, width=height + 1))


if __name__ == "__main__":
    main()
