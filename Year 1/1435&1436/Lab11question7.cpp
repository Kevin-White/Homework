/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <iostream>

using namespace std;

void sumAvg(int, int);

int main()
{
    int x; 
    int y;
    cout << "Enter two numbers with a space in between\n";
    cin >> x >> y;
    sumAvg(x,y);
}

void sumAvg(int x, int y){
    int sum = x + y;
    int avg = sum/2;
    cout << "The average of the two numbers is: " << avg;
    
}
