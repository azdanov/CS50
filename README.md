# CS50 -  2017 - Problem Sets
[![](http://i.imgur.com/DN8KfOe.jpg "This is CS50")](https://cs50.harvard.edu)


## Table of Content

*  **[Intro](#intro)**
*  **[Dependencies](#dependencies)**
*  **[Problem Set 0](#problem-set-0)**
    *   **[Scratch](#scratch)**
    
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
    *   **[Whodunit](#whodunit)**
    *   **[Resize, less comfortable](#resize-less-comfortable)**
    *   **[Resize, more comfortable](#resize-more-comfortable)**
    *   **[Recover](#recover)**

*  **[Problem Set 5](#problem-set-5)**
    *   **[Speller](#speller)**

*  **[Problem Set 6](#problem-set-6)**
    *   **[Mario](#mario-python)**
    *   **[Greedy](#greedy-less-comfortable-python)**
    *   **[Credit](#credit-more-comfortable-python)**
    *   **[Caesar](#caesar-less-comfortable-python)**
    *   **[Vigenere](#vigenere-less-comfortable-python)**
    *   **[Crack](#crack-more-comfortable-python)**
    *   **[Sentiments](#sentiments)**

*  **[Problem Set 7](#problem-set-7)**
    *   **[Finance](#finance)**

*  **[Problem Set 8](#problem-set-8)**
    *   **[Mashup](#mashup)**

*  **[Final Project](#final-project)**

## Intro
This is a work in progress repository containing solutions for CS50 problem sets.

I mainly use this as personal training grounds to try out different things and learn while doing it.

Feel free to contribute in any way you see fit, all feedback is welcome.

## Dependencies

[Latest CS50 Library](https://github.com/cs50/cs50) for C.

[How to install](https://manual.cs50.net/library/) _(Might be outdated)_

## Problem Set 0

### Scratch

As per [specifications](http://docs.cs50.net/2017/x/psets/0/pset0.html#tl-dr) make a program in [scratch](https://scratch.mit.edu):

![](https://cdn2.scratch.mit.edu/get_image/project/104489209_282x210.png)

My implementation of a simple [game](https://scratch.mit.edu/projects/104489209/).

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

Official specifications for [mario](http://docs.cs50.net/problems/mario/less/mario.html) on CS50.

My implementation of [mario](PSET1/mario.c).

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

Official specifications for [mario](http://docs.cs50.net/problems/mario/more/mario.html) on CS50.


My implementation of [mario](PSET1/mario_more.c).

### Greedy, less comfortable

A program that calculates the minimum number of coins required to give a user change:

```
$ ./greedy
O hai! How much change is owed?
0.41
4
```

Official specifications for [greedy](http://docs.cs50.net/problems/greedy/greedy.html) on CS50.

My implementation of [greedy](PSET1/greedy.c).

### Credit, more comfortable

A program that determines whether a provided credit card number is valid according to [Luhn’s algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm):

```
$ ./credit
Number: 378282246310005
AMEX
```

Official specifications for [credit](http://docs.cs50.net/problems/credit/credit.html) on CS50.

My implementation of [credit](PSET1/credit.c).


## Problem Set 2

### Initials, less comfortable

A program that, given a person’s name, prints a person’s initials:

```
$ ./initials
Regulus Arcturus Black
RAB
```

Official specifications for [initials](http://docs.cs50.net/problems/initials/less/initials.html) on CS50.

My implementation of [initials](PSET2/initials.c).

### Initials, more comfortable

A program that, given a person’s name, prints a person’s initials, while ignoring additional whitespace:

```
$ ./initials
  Regulus    Arcturus   Black
RAB
```

Official specifications for [initials](http://docs.cs50.net/problems/initials/more/initials.html) on CS50.

My implementation of [initials](PSET2/initials_more.c).

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

## Problem Set 3

### Find, less comfortable

A program that finds a number among numbers:

```
$ ./generate 1000 | ./find 42
Didn't find needle in haystack.
```

Official specifications for [find](http://docs.cs50.net/problems/find/less/find.html) on CS50.

My implementation of [find](PSET3/find_less/).

### Find, more comfortable

A program that finds a number among numbers:

```
$ ./generate 1000 | ./find 42
Didn't find needle in haystack.
```

Official specifications for [find](http://docs.cs50.net/problems/find/more/find.html) on CS50.

My implementation of [find](PSET3/find_more).

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

My implementation of [fifteen](PSET3/fifteen).

## Problem Set 4

### Whodunit

A program that reveals a reveals a hidden message in a BMP:

```
$ ./whodunit clue.bmp verdict.bmp
```

Official specifications for [whodunit](http://docs.cs50.net/problems/whodunit/whodunit.html) on CS50.

My implementation of [whodunit](PSET4/bmp/whodunit.c).


### Resize, less comfortable

Implement a program that resizes BMPs:

```
$ ./resize 4 small.bmp large.bmp
```

Official specifications for [Resize](http://docs.cs50.net/problems/resize/less/resize.html) on CS50.

My implementation of [Resize](PSET4/bmp/resize_less.c).


### Resize, more comfortable

Implement a program that resizes BMPs:

```
$ ./resize 4 small.bmp large.bmp
```
```
$ ./resize .25 large.bmp small.bmp
```

Official specifications for [Resize](http://docs.cs50.net/problems/resize/more/resize.html) on CS50.

My implementation of [~~Resize~~](PSET4/bmp/resize_more.c).


### Recover

Implement a program that recovers JPEGs from a forensic image:

```
$ ./recover card.raw
```

Official specifications for [Recover](http://docs.cs50.net/problems/recover/recover.html) on CS50.

My implementation of [Recover](PSET4/jpg/recover.c).


## Problem Set 5

### Speller

Implement a program that spell-checks a file:

```
$ ./speller texts/austinpowers.txt

MISSPELLED WORDS
[...]
Bigglesworth
[...]
Virtucon
[...]
friggin'
[...]
trippy
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```
Official specifications for [Speller](http://docs.cs50.net/problems/recover/recover.html) on CS50.

My old implementation of [Speller](PSET5/old).
My trie implementation of [Speller](PSET5/trie).

## Problem Set 6

Port some previous programs from C to Python.

Official specifications for [Problem Set 6](http://docs.cs50.net/2017/x/psets/6/pset6.html#problems)

### Mario python

My implementation of [Mario](PSET6/mario_less.py), less comfortable on python.

My implementation of [Mario](PSET6/mario_more.py), more comfortable on python.

### Greedy, less comfortable python

My implementation of [Greedy](PSET6/greedy.py) on python.

### Credit, more comfortable python

My implementation of [Credit](PSET6/credit.py) on python.

### Caesar, less comfortable python

My implementation of [Caesar](PSET6/caesar.py) on python.

### Vigenere, less comfortable python

My implementation of [Vigenere](PSET6/vigenere.py) on python.

### Crack, more comfortable python

My implementation of [Crack](PSET6/crack.py) on python.

### Sentiments

Official specifications for [Sentiments](http://docs.cs50.net/problems/sentiments/sentiments.html)

1) Implement a program that categorizes a word as positive or negative.

```
$ ./smile love
:)
$ ./smile hate
:(
$ ./smile Stanford
:|
```

My implementation of [smile](PSET6/sentiments/smile) and [analyzer](PSET6/sentiments/analyzer.py)

<br>

2) Implement a program that categorizes a user’s tweets as positive or negative.

```
$ ./tweets @cs50
 0 hello, @world
 1 I love you, @world
-1 I hate you, @world
...
```

My implementation of [tweets](PSET6/sentiments/tweets) and [analyzer](PSET6/sentiments/analyzer.py)

<br>

3) Implement a website that generates a pie chart categorizing a user’s tweets.

![Tweet pie](http://i.imgur.com/twGxbdI.png)

My implementation of [application](PSET6/sentiments/application.py) and [helpers](PSET6/sentiments/helpers.py)


## Problem Set 7

### Finance
Implement a website via which users can "buy" and "sell" stocks.

Official specifications for [finance](http://docs.cs50.net/problems/finance/finance.html) on CS50.

![Finance](http://i.imgur.com/LC4yMws.png)

My implementation of [finance](PSET7/finance/) and [online website](http://implaier.pythonanywhere.com/).

## Problem Set 8

## Mashup
Implement a website that lets users search for articles atop a map.

Official specifications for [mashup](http://docs.cs50.net/problems/mashup/mashup.html) on CS50.

![Mashup](http://i.imgur.com/r7g6y7k.png)

My implementation of [mashup](PSET8/mashup/) and [online website](http://implaiercs50.pythonanywhere.com/).

## Final Project
`Coming soon`

## License

This project is Unlicensed - see the [LICENSE.md](LICENSE.md) file for details
