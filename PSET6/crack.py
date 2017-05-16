try:
    import sys
    import crypt
    import string
except ModuleNotFoundError:
    import platform

    if platform.system() == "Windows":
        sys.exit("Crypt module not supported on Windows")
    else:
        sys.exit("Can't load crypt module")


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: ./crack hash")

    salt = str(50)
    hash = sys.argv[1]
    alphabet_letters = string.ascii_letters

    word = ""
    alpha_len = len(alphabet_letters)

    for i in range(alpha_len):
        for j in range(alpha_len):
            for k in range(alpha_len):
                for n in range(alpha_len):
                    if crypt.crypt(str(word), salt) == hash:
                        print(word)
                        exit(0)
                    word = alphabet_letters[n] + word[1:]
                word = word[:1] + alphabet_letters[k] + word[2:]
            word = word[:2] + alphabet_letters[j] + word[3:]
        word = word[:3] + alphabet_letters[i]


if __name__ == "__main__":
    main()
