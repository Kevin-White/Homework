num1 = int(input("Enter a number: "))
num2 = int(input("Enter another number: "))
if num2 < num1:
    hold = num1
    num1 = num2
    num2 = hold

while num1 <= num2:
    if 1 <= num1 <= 9:
        switcher = {1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}
        print(switcher.get(num1))
    elif num1 % 2:
        print("odd")
    else:
        print("even")
    num1 += 1
