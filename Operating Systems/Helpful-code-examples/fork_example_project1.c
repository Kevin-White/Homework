#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int pid;
        pid = getpid();        
        printf("Parent process ID: %d\n", pid);
        pid = fork();
        if (pid == 0) // Child process executes this block
        {  
           printf("Return value in child process: %d\n", pid);
	   pid = getpid();
           printf("Process ID reported by child process: %d\n", pid); 
        } 
        else   // Parent process executes this block  
        {
           printf("Return value in parent process: %d\n", pid);
           pid = getpid();
           printf("Process ID reported by parent process: %d\n", pid); 
        }
        return 0;
}

