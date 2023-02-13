This program was built in C for a Linux computer. 

The purpose of this program is to try and solve a dynamic Consumer Producer problem by taking in variables from the user.
using these variables to build a scenario for the computer to test/run. At the end of the code, the computer will show the user statistics
of statistics gathered during run time.

./kwhiteProj3.exe ARG1 ARG2 ARG3 ARG 4 ARG 5

ARG1: Time it takes for the program to run once ALL threads have been made. (In Seconds)

ARG2: Maximum wait time for each thread (In Seconds)

ARG3: Number of threads producing numbers

ARG4: Number of threads consuming numbers and calculating whether they are prime.

ARG5: if you want to show every action made by producer and consumer threads (Yes or No)


you can make the .exe file by using the make file.

with this make file in your current directory type "make"

to clean up all of the extra files type "make clean"