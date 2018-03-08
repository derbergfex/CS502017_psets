import cs50
import sys

def main():

    if len(sys.argv) != 2:
        print("Provide the shifting factor")
        exit(1)

    print("plaintext: ", end = "")
    plainText = cs50.get_string()

    print("ciphertext: ")
    k = int(sys.argv[1])

    if k < 0:
        print("Provide a valid shifting factor")
        exit(1)

    for i in range(len(plainText)):

        if plainText[i].islower():
            print("{}".format(((ord(plainText[i]) - 96 + k) % 26) + 96), end = "")

        elif plainText[i].isupper():
            temp = ((ord(plainText[i]) - 64 + k) % 26) + 64
            print("{}".format(chr(temp)), end = "")

        else:
            print("{}".format(plainText[i]), end = "")

    print()
    exit(0)

if __name__ == "__main__":
    main()

