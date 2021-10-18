numOfBook = int(input("How many books do you want: "))
while numOfBook < 1:
    numOfBook = int(input("Enter a valied number: "))
price = (24.95 * 0.60) * numOfBook
price = price + 3
numOfBook = numOfBook - 1
while numOfBook != 0:
    price += 0.75
    numOfBook -= 1
print("${:0.2f} for your books".format(price))
