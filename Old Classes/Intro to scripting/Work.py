#!!!Print!!!
#print("Hello World")
#print('Hello World2')

#!!!Number!!!
#print(5+6)
#print(5.5+6)
#print(5.5*5)
#print(5/6)
#print(5//6)
#print(17%3)
#print(2**3)


#!!!Variable!!!
#apple = 6
#pear = 7
#total = apple + pear
#print(total)


#cube_len = 2
#cube_vol = cube_len**3
#print(cube_vol)


#!!!String!!!
#firstString = "Hello "
#secondString = "World"
#print(firstString + secondString)
#full = "Introduction Script " + firstString + secondString
#print(full)
#print(firstString[0:3])
#print(len(secondString))


#!!!Input and output!!!
#cube_len = int(input("Please input the length:"))
#print(cube_len)
#cube_vol = cube_len**3
#print("volume of the cube:" , cube_vol)
#print("volume of the cube:{}".format(cube_vol))

num = int(input("Please input a number:"))
cube = num**3
sq = num**2

result = "The square ={} and the cube ={}".format(sq, cube)
print(result)
result = "The square ={s} and the cube ={c}".format(s=sq, c=cube)
print(result)

