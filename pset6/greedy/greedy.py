import cs50

def main():
    print("O hai! How much change is owed?")
    cash = cs50.get_float()

    while True:
        if cash < 0:
            print("O hai! How much change is owed?")
            cash = cs50.get_float()
        else:
            break

    x = round(cash * 100)
    numberOfCoins = 0

    while True:
        if x >= 25:
            x -= 25
            numberOfCoins += 1
        else:
            break

    while True:
        if x >= 10:
            x -= 10
            numberOfCoins += 1
        else:
            break

    while True:
        if x >= 5:
            x -= 5
            numberOfCoins += 1
        else:
            break

    while True:
        if x >= 1:
            x -= 1
            numberOfCoins += 1
        else:
            break

    print("{}".format(numberOfCoins))


if __name__ == "__main__":
    main()