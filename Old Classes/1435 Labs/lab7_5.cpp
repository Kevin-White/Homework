#include <iostream>
using namespace std;

int main()
{
	
	int num1;

	cout << "Enter a number: "<< endl;
	cin >> num1;
	if(!(num1 % 2) && !(num1 % 3) && !(num1 % 5))
	{
		if(!(num1 % 2))
		{
			cout << num1 << " is divisibale by 2" << endl;;
		}
		if(!(num1 % 3))
		{
			cout << num1 << " is divisibale by 3"<< endl;
		}
		if(!(num1 % 5))
		{
			cout << num1 << " is divisibale by 5"<< endl;
		}
	}
	else
	{
		cout << num1 << " is not divisibale by 2, 3, or 5." << endl;
	}
		
	
	
}
			
		
	
	
	