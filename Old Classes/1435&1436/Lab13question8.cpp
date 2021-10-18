//Write your name here

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main ()
{
  ifstream inFile;
  inFile.open("fifteen.txt");
  int fifteen[15];
  int sum = 0, av;
  for(int i = 0; i < 15; i++){
      inFile >>fifteen[i];
  }
  for(int i = 0; i < 15; i++){
      sum += fifteen[i];
  }
  av = sum/15;
  cout << "The sum is: " << sum << endl
  << "The average is: " << av;
}
