//Write your name here

#include <iostream>

using namespace std;

 

//function prototype
double adjustGrades(int [], int);

int main()

{
    int grades[3] = {50, 75, 70};
    int bpoints;
    double ave;
    cout << "How many pointes would you like to add to all the grades: ";
    cin >> bpoints;
    ave = adjustGrades(grades, bpoints);
    cout << "The average is: " << ave;

}

 

//function definition
double adjustGrades(int grades[], int more){
    double sum = 0;
    for(int i = 0; i < 3; i++){
        grades[i] += more;
        sum += grades[i];
    }
    return sum/3;
}
