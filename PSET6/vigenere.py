#!/usr/bin/env python3
import sys
import string


def main():
    try:
        if len(sys.argv) != 2 or not sys.argv[1].isalpha():
            raise ValueError("Wrong key provided")
        else:
            keyword = sys.argv[1]
    except (ValueError, IndexError):
        print("Usage: ./vigenere k")
        sys.exit(1)

    plaintext = input("plaintext: ")

    ciphertext = encrypt_vigenere(plaintext, keyword)

    print("plaintext: {}".format(ciphertext))


def encrypt_vigenere(text, keyword):
    key_pos = 0
    text = list(text)
    key_len = len(keyword)
    alpha_len = len(string.ascii_lowercase)
    keyword = [ord(char.upper()) - ord('A') for char in keyword]

    for i, char in enumerate(text):
        if char.isalpha():
            if char.isupper():
                text[i] = chr((ord(char) - ord('A') + keyword[key_pos]) % alpha_len + ord('A'))
            else:
                text[i] = chr((ord(char) - ord('a') + keyword[key_pos]) % alpha_len + ord('a'))
            key_pos = (key_pos + 1) % key_len

    text = ''.join(text)
    return text


if __name__ == "__main__":
    main()
