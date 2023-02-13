#include <stdio.h>
#include <unistd.h>
#define GetCurrentDir getcwd
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<sys/wait.h>
#include<cstring>
#include "hist.h"
#include<iostream>

using namespace std;

hist Hmain;

/*
This function gets the current working directory of the program
then return the string of the CWD back to main
*/
string GetCurrentWorkingDir(void) {
  char buff[FILENAME_MAX];
  GetCurrentDir(buff, FILENAME_MAX);
  string current_working_dir(buff);
  return current_working_dir;
}

/*
getInput takes in a string and splits it up into many smaller strngs and then converts
it to a char array to send into the command execvp
before running execvp we fork so the child runs execvp and the parrent will wait until
the child proccess and has ended at exit(0);
*/
void getInput(string pIn) {
  char * cInput[100];
  int status;
  int i = 0;

  istringstream ss(pIn);

  string middle;

  while (ss >> middle) {
    if(middle == "cd" && i == 0){
        ss >> middle;
        chdir(middle.c_str());
        return;
    }else if(middle == "r" && i == 0){
        ss >> middle;
        getInput(Hmain.get(middle));
        return;
    }
    char *cstr = new char[middle.length() + 1];
    strcpy(cstr, middle.c_str());
    cInput[i] = cstr;
    i++;
  }

  cInput[i] = NULL;
  char * inputOne = cInput[0];
  pid_t cpid = fork();

  if (cpid == 0) {
    execvp(inputOne, cInput);
    exit(0);
  } else if (cpid < 0) {
    cout << "fork Failed" << endl;
  } else {
    waitpid(cpid, & status, 0);
    if (status == 1) {
      cout << "error! oh No!" << endl;
    }
  }
}

/*
THis will check user input for the word exit. if exit it will end the program.
if not, it will check if you used any of the functions i made, if not, it will
send to get input in order to execute the command.
*/
int main() {
  string pIn;
  string inCheck;
  while (pIn != "exit") {
    cout << "[gunish " << GetCurrentWorkingDir() << "]: ";
    getline(cin, pIn);
    istringstream ss(pIn);
    ss >> inCheck;
    if(inCheck == "r"){
        ss >> inCheck;
        pIn = Hmain.get(inCheck);
    }
    Hmain.add(pIn);
    if(pIn != "hist"){
        getInput(pIn);
    }else{
        Hmain.display();
    }
    cout << endl;
  }
  return 1;
}