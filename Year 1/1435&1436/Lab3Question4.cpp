//Introduction to Pointers

#include <iostream>
using namespace std;
//g++ pointers.cpp -std=c++11;

int main(){

	int length;
	int width;
	int area;

	int *lengthPtr = nullptr;	// int pointer that will be set to point to length
	int *widthPtr = nullptr;	// int pointer that will be set to point to width

	cout << "Enter the length of the rectangle" << endl;
	cin >> length;

	cout << "Enter the width of the rectangle" << endl;
	cin >> width;

	// Fill in code to make lengthPtr point to length (store its address)
    lengthPtr = &length;
	// Fill in code to make widthPtr point to width (store its address)
    widthPtr = &width;
	area =	*lengthPtr * *widthPtr; // Fill in code to find the area by using only the pointer variables

	cout << "The area is " << area << endl;

	if (*lengthPtr > *widthPtr){
		cout << "The length is greater than the width" << endl;
	}
	else if ( *widthPtr > *lengthPtr){
		cout << "The width is greater than the length" << endl;
    }
	else{
		cout << "The width and length are the same" << endl;
	}
	return 0;
}