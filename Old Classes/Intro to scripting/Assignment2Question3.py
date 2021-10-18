string = input("Enter a string: ")
vowels = ['a', 'e', 'i', 'o', 'u']
for vowel in vowels:
    string = string.replace(vowel, '')
print(string)
