#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  char* argv[10];
  char* folder;
  folder = malloc(200);      // Allocate 20 character positions
  argv[0] = malloc (50);
  argv[1] = malloc(50);;
  argv[2] = malloc(50);;
  
  strcpy(argv[0], "ls");     // Command goes in argv[0]
  strcpy(argv[1], "-l");     // option 
  argv[2] = (char *) 0;      // last argument must be NULL

   folder = strcpy(folder, "/bin/");
   folder =strcat(folder, argv[0]);     // Here the folder is "bin/ls"

  execv(folder, argv);          // call to the function; execute and exit
   
  printf("Unknown command\n"); // this statement will not be executed if excecv() is successful
  return 0;
}

