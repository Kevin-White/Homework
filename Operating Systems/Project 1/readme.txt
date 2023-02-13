This program is a super basic UI and User Iteractiable Command Line Inter Face for Unix/Linux.
This is for Project1 in 3346 Operating Systems

I used code from:
https://stackoverflow.com/questions/875249/how-to-get-current-directory

To help with printing the working directory for the program.
I also got the class structure from the helpful code examples you provided, I modified it to work more like the already existing history function in Unix/Linux

ProjectMain.cpp holds code to call the hist class and its functions as well as code to break a string into char arrays in order to be accepted by the execv
function that I use in order to interact with the already existing Linux console. 

ProjectMain.cpp also gives you the ability to use the r function to call an old command from the hist class or use the exit command in order
to terminate the program.

Hist.h holds the data structure for the hist function. This will hold ten strings at a time until you type in an 11th command or more, then this will get rid of
the oldest command in the list in order to only keep ten within the data structure.
