//********************************************************************
// Name: Kevin White
// Class: COSC 1435 Fall 20
// Instructor: Marwa Hassan
// Assignment 6 Problem 3
// Date: 10/16/2020
// Program description: Gives simple math problems to the user based on what they choose from a menu.
//*********************************************************************
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

int
main ()
{

  int pick;
  int ran1, ran2;
  int userAnswer, answer;
  while (true)
    {
      cout << "   Quick Math Menu\n"
	<< "------------------------------\n"
	<< "1. Addition problem\n"
	<< "2. Subtraction problem\n"
	<< "3. Multiplication problem\n"
	<< "4. Quit this program\n"
	<< "------------------------------\n" << "Enter your choice (1-4): ";
      cin >> pick;


      while (pick < 1 || pick > 4)
	{
	  cout << "The valid choices are 1, 2, 3, and 4. Please try again: ";
	  cin >> pick;
	}
      cout << endl;

    unsigned seed = time(0);
    srand(seed);

      switch (pick)
	{
	case 1:
	  ran1 = (rand () % (1 - 500 + 1)) + 1;
	  ran2 = (rand () % (1 - 500 + 1)) + 1;
	  answer = ran1 + ran2;
	  cout << " " << setw (4) << ran1 << endl
	    << "+" << setw (4) << ran2 << endl
	    << " " << "----" << endl << "  ";
	  cin >> userAnswer;
	  cout << endl << endl;
	  if (answer == userAnswer)
	    {
	      cout << "Good Job! That's right.\n" << endl;
	    }
	  else
	    {
	      cout << "Sorry, the correct answer is " << answer << ".\n" <<
		endl;
	    }
	  break;

	case 2:
	  ran1 = (rand () % (1 - 599 + 1)) + 1;
	  ran2 = (rand () % (1 - 100 + 1)) + 1;
	  answer = ran1 - ran2;
	  cout << " " << setw (4) << ran1 << endl
	    << "-" << setw (4) << ran2 << endl
	    << " " << "----" << endl << "  ";
	  cin >> userAnswer;
	  cout << endl << endl;
	  if (answer == userAnswer)
	    {
	      cout << "Good Job! That's right.\n" << endl;
	    }
	  else
	    {
	      cout << "Sorry, the correct answer is " << answer << ".\n" <<
		endl;
	    }
	  break;

	case 3:
	  ran1 = (rand () % (1 - 100 + 1)) + 1;
	  ran2 = (rand () % (1 - 9 + 1)) + 1;
	  answer = ran1 * ran2;
	  cout << " " << setw (4) << ran1 << endl
	    << "*" << setw (4) << ran2 << endl
	    << " " << "----" << endl << "  ";
	  cin >> userAnswer;
	  cout << endl << endl;
	  if (answer == userAnswer)
	    {
	      cout << "Good Job! That's right.\n" << endl;
	    }
	  else
	    {
	      cout << "Sorry, the correct answer is " << answer << ".\n" <<
		endl;
	    }
	  break;

	case 4:
	  cout << "Thank you for using Quick Math.";
	  return 0;

	}
    }
}

