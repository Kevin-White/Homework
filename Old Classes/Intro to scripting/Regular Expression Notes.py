import re

wordList = []

#wordList = re.findall(r"#movies", "Love #movies! I had fun yesterday going to the #movies")


#wordList = re.findall(r"User\d+", "The winners are: User9, UserN, User7, User88")
    #\d is all numbers but ONLY 1 in LENGTH!
    #\d+ is all numbers with ANY LENGTH!

#wordList = re.findall(r"User\D", "The winners are: User9, UserN, User7, User8, UserK, User&")
    #\D is all non numbers

#wordList = re.findall(r"User\w", "The winners are: User9, UserN, User7, User8, UserK, User&")
    #\w Anything with normal char's

#wordList = re.findall(r"User\W", "The winners are: User9, UserN, User7, User8, UserK, User&")
    #\W Anything with special char's

#wordList = re.findall(r"Greenkid\d?\d?", "Greenkid01, Greenkid")
    #? adding a ? means it is optional to pull from string

#wordList = re.findall(r"\w{4}", "Rock, Love, Man, adding")
    #{INT} a length of somthing you want to find
    #{3,5} a Range of lenghts that you want to find

print("IMPORTANT!!! IF you want to add \"Quotes\" You need to use the \"\\\" You need to use it for Special Chars like a . period or even the \\ when using the regular expressions")

wordList = re.findall("\d+?,?\d{1,3}\.\d{2}", "13,423.12  132.25  443  12.23  9.9  100,000.00  ")
    #\d+? Looks For all numbers but is optional
    # ,? looks for a comma  but is optional
    #\d{1,3} Looks for any number with a length between 1 and 3
    #\. a period or decimal for the number
    #\d{2} looks for 2 digets after the decimal place

print(wordList)
