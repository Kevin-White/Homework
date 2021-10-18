//Kevin White

#include <iostream>

#include <iomanip>

using namespace std;

int
main ()
{
  int a1, a2, l1, l2, w1, w2;

  // Getting length and width of both rooms from user
  cout << "Enter the length of room 1\n";
  cin >> l1;
  cout << "Enter the width of room 1\n";
  cin >> w1;
  cout << "Enter the length of room 2\n";
  cin >> l2;
  cout << "Enter the width of room 2\n";
  cin >> w2;

  // Calculating Area of the rooms
  a1 = l1 * w1;
  a2 = l2 * w2;
  
  // Displaying if a room is bigger than the other
  if (a1 > a2)
    {
      cout << "Room 1 is bigger than room 2";
    }
  else if (a2 > a1)
    {
      cout << "Room 2 is bigger than room 1";
    }
  else
    {
      cout << "Both of the rooms are the same size.";
    }

}
