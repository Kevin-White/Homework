// Write your name here

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  char* argv[10];
  char* folder;
  int process_id;
  int status;

  // The following lines of code is to prepare arguments for execv() function

  folder = malloc(200);      // Allocate 20 character positions
  argv[0] = malloc (50);
  argv[1] = malloc(50);
  argv[2] = malloc(50);

  strcpy(argv[0], "ls");     // Command goes in argv[0]
  strcpy(argv[1], "-l");     // option
  argv[2] = (char *) 0;      // last argument must be NULL
  //argv[1] = (char *) 0;
  folder = strcpy(folder, "/bin/");
  folder =strcat(folder, argv[0]);     // Here the folder is â€œbin/lsâ€

  // All arguments are ready to call execv() function at this point

  // Create a child process
  process_id = fork();
  if (process_id == 0)  // in child process
  {
    execv(folder, argv); // call to the function in child process; execute and exit from the child process
    printf("Unknown command\n"); // this statement will be executed if excecv() fails
  }
  else                // in parent process
  {
    wait(&status);    // parent process waits
    printf("Parent process continues\n");
  }
  
return 0;
}

