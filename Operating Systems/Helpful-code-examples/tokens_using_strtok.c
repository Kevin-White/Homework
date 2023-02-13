// Extracting string tokens using strtok() 
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[80];
    int i;
    i = 0;
    str[i] = getchar();
    while (str[i] != '\n' && i < 80) 
    {
      str[++i] = getchar();
    } 
    if ( i >= 80)
    {
       printf("\nToo long string\n");
       return 0;
    } 
  
    // Returns first token with delimiter space
    char* token = strtok(str, " "); 
  
    // Keep extracting
    while (token != NULL) { 
        printf("%s\n", token); 
        token = strtok(NULL, " "); 
    } 
  
    return 0; 
} 
