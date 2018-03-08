import cs50

def main():
    print("Height: ", end = "")
    height = cs50.get_int()

    while True:
        if height > 23 or height < 0:
            print("Height: ", end = "")
            height = cs50.get_int()
        else:
            break

    for i in range(1, height + 1):
        say(" ", height - i)
        say("#", i)
        print("  ", end = "")
        say("#", i)
        print()

def say(string, n):
    for j in range(n):
        print("{}".format(string), end = "")

if __name__ == "__main__":
    main()