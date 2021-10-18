//Kevin White

#include <iostream>
  
using namespace std;

 
 
int
main () 
{
  
 
int testScore;
  
cout << "Enter your test score: ";
  
 
cin >> testScore;
  
 
while (testScore < 0 || testScore > 100)
    
    {
      
 
cout << "That is an invalid score.\n";
      
 
cout << "Enter your test score: ";
      
 
cin >> testScore;
    
 
 
}
  
 
 
    // Determine the letter grade.
    if (testScore >= 90)
    
 
cout << "Your grade is A.\n";
  
 
  else if (testScore >= 80)
    
 
cout << "Your grade is B.\n";
  
 
  else if (testScore >= 70)
    
 
cout << "Your grade is C.\n";
  
 
  else if (testScore >= 60)
    
 
cout << "Your grade is D.\n";
  
 
  else
    
 
cout << "Your grade is F.\n";
  
 
 
 
return 0;

 
}


