#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class hist 
{
   private:
     char data[10][100]; // It can hold at most 10 C-strings with maximum length of 100 characters
     int count;
   public:
     hist();
     void add(char[]);
     void get(int, char[]);
     void display();
};

hist::hist()
{
   count = 0;
   for (int i = 0; i < 10; ++ i)
     strcpy(data[i], "");
}

void hist::add(char x[])
{
  int i;
  if (count < 10)
  {
     strcpy(data[count], x);
     ++ count;
  }
  else   // shift if it is full
  {
    for (i = 0; i < 9; ++ i)
       strcpy(data[i], data[i+1]);
    strcpy(data[9],x);
  }
  return;       
}

void hist::get(int x, char y[])
{
   if (x <= count)
     strcpy(y, data[x - 1]);
   else
     strcpy (y, "");
   return;
}

void hist::display()
{
   for (int i = 0; i < count; ++ i)
      cout << data[i] << endl;
   return; 
}

// The following code is to test the hist class and its methods
int main()
{
   hist commands; // Declare the hist data structure
   int n;
   char x[100];

   fgets(x, 100, stdin);  // Get at most 100 character from the keyboard
   x[strlen(x)-1]='\0';    // Append null character at the end

   commands.add(x);   // Include the string in the hist object
    
  // Get another string and save in hist
  fgets(x, 100, stdin);   
   x[strlen(x)-1]='\0';
   commands.add(x);
  
  commands.display();    // Show all strings stored in hist
   
  commands.get(1, x);   // Retrieve a string at index 1 from hist object 

   cout << x << endl;       // Display the retrieved string
   return 0;
}

