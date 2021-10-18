string = input("Enter a string: ")
string = string.split()
final_string = ""
for s in string:
    first = 0
    for i in s:
        if first == 0:
            first = 1
            s = s.split(i)
            i = i.upper()
            s = i + s[1]
            final_string = final_string + s + " "


print(final_string)
