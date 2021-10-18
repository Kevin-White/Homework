#include <iostream>
using namespace std;

int main (){
    
  double input1, input2, answer;
  char alg;
  cout << "Enter the first Number for your equation:\n";
  cin >> input1;
  
  cout << "Enter / to divide\nEnter * to multiply" << endl
  << "Enter + to add\nEnter - to subract\n";
  
  cin >> alg;
  
  cout << "Enter the second number for your equation:\n";
  cin >> input2;
  switch (alg)
    {
    case '/':
       answer = input1 / input2;
       cout << input1 << alg << input2 << "=" << answer;
      break;

    case '*':
      answer = input1 * input2;
      cout << input1 << alg << input2 << "=" << answer;
      break;

    case '+':
      answer = input1 + input2;
      cout << input1 << alg << input2 << "=" << answer;
      break;

    case '-':
      answer = input1 - input2;
      cout << input1 << alg << input2 << "=" << answer;
      break;

    default:
      cout << "Invalid Input" << endl;
    }
}
