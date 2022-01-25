// Kevin White
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
   char choice1, choice2;
   int bill;
   bool next = false;
   cout << "Please input 'I' if you are in-state or 'O' if you are out-of-state:\n";
   
   
   while (!next){
       
        cin >> choice1;
        switch(choice1){
            case 'I': bill = 3000;
            next = true;
            break;
            
            case 'O': bill = 4500;
            next = true;
            break;
            
            default: cout << "Try another input\n";
            break;
        }
   }
   
   next = false;
   cout << "Please input 'Y' if you require room & board and 'N' if you do not:\n";
   
   
   while (!next){
       
        cin >> choice2;
        
        switch(choice2){
            case 'Y':
                if(choice1 == 'I'){
                    bill += 2500;
                } else{
                    bill += 3500;
                }
            next = true;
            break;
            
            case 'N': // Do nothing;
            next = true;
            break;
            
            default: cout << "Try another input\n";
            break;
        }
   }
   
   cout << "Your total bill for this semester is $" << bill;
   return 0;
}
