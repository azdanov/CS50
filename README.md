# CS50 -  2017 - Problem Sets [![unlicense](https://img.shields.io/badge/un-license-green.svg?style=flat)](http://unlicense.org)

[![](http://i.imgur.com/DN8KfOe.jpg "This is CS50")](https://cs50.harvard.edu)


## Table of Content

*  **[Intro](#intro)**
*  **[Dependencies](#dependencies)**
*  **[Problem Set 1](#problem-set-1)**
    *   **[Hello](#hello)**
    *   **[Water](#water)**
    *   **[Mario, less comfortable](#mario-less-comfortable)**
    *   **[Mario, more comfortable](#mario-more-comfortable)**
    *   **[Greedy, less comfortable](#greedy-less-comfortable)**
    *   **[Credit, more comfortable](#credit-more-comfortable)**


*  **[Problem Set 2](#problem-set-2)**
    *   **[Initials, less comfortable](#initials-less-comfortable)**
    *   **[Initials, more comfortable](#initials-more-comfortable)**
    *   **[Caesar, less comfortable](#caesar-less-comfortable)**
    *   **[Vigenere, less comfortable](#vigenere-less-comfortable)**
    *   **[Crack, more comfortable](#crack-more-comfortable)**


*  **[Problem Set 3](#problem-set-3)**
    *   **[Find, less comfortable](#find-less-comfortable)**
    *   **[Find, more comfortable](#find-more-comfortable)**
    *   **[Game of Fifteen](#game-of-fifteen)**

*  **[Problem Set 4](#problem-set-4)**

*  **[Problem Set 5](#problem-set-5)**

*  **[Problem Set 6](#problem-set-6)**

*  **[Problem Set 7](#problem-set-7)**

*  **[Problem Set 8](#problem-set-8)**

*  **[Final Project](#final-project)**

## Intro
This is a _work in progress_ repository containing solutions for CS50 problem sets.

I mainly use this as personal training grounds to try out different things and learn while doing it.

Feel free to contribute in any way you see fit, all feedback is welcome.

## Dependencies

[Latest CS50 Library](https://github.com/cs50/cs50) for C.

[How to install](https://manual.cs50.net/library/) _(Might contain outdated library files)_

## Problem Set 1

### Hello

A program that prints out a simple greeting to the user:

```
$ ./hello
Hello, world!
```

Official specifications for [hello](http://docs.cs50.net/problems/hello/hello.html) on CS50.

My implementation of [hello](PSET1/hello.c).


### Water

A program that reports a user’s water usage, converting minutes spent in the shower to bottles of drinking water:

```
$ ./water
Minutes: 1
Bottles: 12
```
```
$ ./water
Minutes: 10
Bottles: 120
```

Official specifications for [water](http://docs.cs50.net/problems/water/water.html) on CS50.

My implementation of [water](PSET1/water.c).

### Mario, less comfortable

A program that prints out a half-pyramid of a specified height:

```
$ ./mario
Height: 5
    ##
   ###
  ####
 #####
######
```

```
$ ./mario
Height: 3
  ##
 ###
####
```

Official specifications for [mario_less](http://docs.cs50.net/problems/mario/less/mario.html) on CS50.

My implementation of [mario_less](PSET1/mario.c).

### Mario, more comfortable

A program that prints out a double half-pyramid of a specified height:

```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

Official specifications for [mario_more](http://docs.cs50.net/problems/mario/more/mario.html) on CS50.


My implementation of [mario_more](PSET1/mario_more.c).

### Greedy, less comfortable

A program that calculates the minimum number of coins required to give a user change:

```
$ ./greedy
O hai! How much change is owed?
0.41
4
```

Official specifications for [greedy_less](http://docs.cs50.net/problems/greedy/greedy.html) on CS50.

My implementation of [greedy](PSET1/greedy.c).

### Credit, more comfortable

A program that determines whether a provided credit card number is valid according to [Luhn’s algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm):

```
$ ./credit
Number: 378282246310005
AMEX
```

Official specifications for [greedy_more](http://docs.cs50.net/problems/credit/credit.html) on CS50.

My implementation of [credit](PSET1/credit.c).


## Problem Set 2

### Initials, less comfortable

A program that, given a person’s name, prints a person’s initials:

```
$ ./initials
Regulus Arcturus Black
RAB
```

Official specifications for [initials_less](http://docs.cs50.net/problems/initials/less/initials.html) on CS50.

My implementation of [initials_less](PSET2/initials.c).

### Initials, more comfortable

A program that, given a person’s name, prints a person’s initials, while ignoring additional whitespace:

```
$ ./initials
  Regulus    Arcturus   Black
RAB
```

Official specifications for [initials_more](http://docs.cs50.net/problems/initials/more/initials.html) on CS50.

My implementation of [initials_more](PSET2/initials_more.c).

### Caesar, less comfortable

A program that encrypts messages using Caesar’s cipher:

```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

Official specifications for [caesar](http://docs.cs50.net/problems/caesar/caesar.html) on CS50.

My implementation of [caesar](PSET2/caesar.c).

### Vigenere, less comfortable

A program that encrypts messages using Vigenère’s cipher:

```
$ ./vigenere ABC
plaintext:  HELLO
ciphertext: HFNLP
```

Official specifications for [vigenere](http://docs.cs50.net/problems/vigenere/vigenere.html) on CS50.

My implementation of [vigenere](PSET2/vigenere.c).

### Crack, more comfortable

A program that cracks passwords:

```
$ ./crack 50fkUxYHbnXGw
rofl
```

Official specifications for [crack](http://docs.cs50.net/problems/crack/crack.html) on CS50.

My implementation of [crack](PSET2/crack.c).

A helpful website to  [visualize the algorithm](http://www.pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%0A%23define%20LEN%205%20//%20max%20password%20length%0A%0Avoid%20increment_guess%28char%20str%5B%5D,%20int%20pos%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%0A%20%20%20%20char%20*string%20%3D%20%22rofl%22%3B%0A%20%20%20%20char%20guess%5BLEN%5D%20%3D%20%7B'%5C0'%7D%3B%0A%20%20%20%20do%20%7B%0A%20%20%20%20%20%20%20%20if%20%28strcmp%28guess,%20string%29%20%3D%3D%200%29%20%7B%20//%20compare%20both%20hashes%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25s%22,%20guess%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20increment_guess%28guess,%200%29%3B%0A%20%20%20%20%7D%20while%20%28guess%5BLEN%20-%201%5D%20%3D%3D%20'%5C0'%29%3B%0A%0A%7D%0A%0Avoid%20increment_guess%28char%20str%5B%5D,%20int%20pos%29%20%7B%0A%20%20%20%20if%20%28str%5Bpos%5D%20%3D%3D%20'%5C0'%29%20%7B%20%20%20%20%20%20%20//%20start%20with%20upper%20'A'%0A%20%20%20%20%20%20%20%20str%5Bpos%5D%20%3D%20'A'%3B%0A%20%20%20%20%7D%20else%20if%20%28str%5Bpos%5D%20%3D%3D%20'Z'%29%20%7B%20//%20skip%20to%20lower%20'a'%0A%20%20%20%20%20%20%20%20str%5Bpos%5D%20%3D%20'a'%3B%0A%20%20%20%20%7D%20else%20if%20%28str%5Bpos%5D%20%3D%3D%20'z'%29%20%7B%20//%20next%20position%20when%20end%20is%20reached%0A%20%20%20%20%20%20%20%20str%5Bpos%5D%20%3D%20'a'%3B%0A%20%20%20%20%20%20%20%20increment_guess%28str,%20pos%20%2B%201%29%3B%0A%20%20%20%20%7D%20else%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//%20else%20increment%20char%0A%20%20%20%20%20%20%20%20str%5Bpos%5D%2B%2B%3B%0A%20%20%20%20%7D%0A%7D&cumulative=false&curInstr=722&heapPrimitives=false&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false).

## Problem Set 3

### Find, less comfortable

A program that finds a number among numbers:

```
$ ./generate 1000 | ./find 42
Didn't find needle in haystack.
```

Official specifications for [find, less comfortable](http://docs.cs50.net/problems/find/less/find.html) on CS50.

### Find, more comfortable

A program that finds a number among numbers:

```
$ ./generate 1000 | ./find 42
Didn't find needle in haystack.
```

Official specifications for [find, more comfortableack](http://docs.cs50.net/problems/find/more/find.html) on CS50.

### Game of Fifteen

Game of Fifteen:

```
$ ./fifteen 3
WELCOME TO GAME OF FIFTEEN

8  7  6

5  4  3

2  1  _

Tile to move:
```

Official specifications for [game of fifteen](http://docs.cs50.net/problems/fifteen/fifteen.html) on CS50.

## Problem Set 4
`Coming soon`

## Problem Set 5
`Coming soon`

## Problem Set 6
`Coming soon`

## Problem Set 7
`Coming soon`

## Problem Set 8
`Coming soon`

## Final Project
`Coming soon`

## License

This project is Unlicensed - see the [LICENSE.md](LICENSE.md) file for details