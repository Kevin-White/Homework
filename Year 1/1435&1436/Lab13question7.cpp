//Write your name here

#include <iostream>

#include <iomanip>

using namespace std;


int main ()
{
  int nums[20];
  int give = 200;
  for(int i = 0; i < 20; i++)
    {
      nums[i] = give;
      give += 2;
    }
  for(int i = 0; i < 20; i++)
    {
      cout << nums[i] << " ";
    }
}
