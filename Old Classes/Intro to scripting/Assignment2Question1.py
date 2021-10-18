number = int(input("Enter a number: "))
while 1 > number > 50:
    number = int(input("The number is out of range! Try again: "))

if number % 2:
    print("Weird")
elif 3 <= number <= 6:
    print("Not Weird")
elif 8 <= number <= 19:
    print("Weird")
elif number > 20:
    print("Not Weird")
else:
    print("Not Weird")


