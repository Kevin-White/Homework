#include <iostream>
using namespace std;
int
main ()
{
  int input;
  cout << "Enter a number from 1 to 5: ";
  cin >> input;
  cout;
  switch (input)
    {
    case 1:
      cout << input << " is represented by " << "I" << endl;
      break;

    case 2:
      cout << input << " is represented by " << "II" << endl;
      break;

    case 3:
      cout << input << " is represented by " << "III" << endl;
      break;

    case 4:
      cout << input << " is represented by " << "IV" << endl;
      break;

    case 5:
      cout << input << " is represented by " << "V" << endl;
      break;

    default:
      cout << "Invalid Input" << endl;
    }
}
