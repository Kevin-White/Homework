import os.path

fileName = input("Enter the name of a file: ")
while not os.path.exists(fileName):
    print("This path does not work for the file or file does not exist")
    fileName = input("Enter the name of a file: ")

f = open(fileName, 'w')
print("You can now type into the file: ")
text = input()
while text != "SAVE":
    f.write(text + "\n")
    text = input()
print("The above content has been saved to " + fileName)
f.close()
