//Kevin White

#include <iostream>

using namespace std;

int main()

{
    int num, sum = 0;
   cout << "Enter a integer larger than 0: ";
    cin >> num;
    while(num < 1){
        cout << "ERROR try again\n";
        cout << "Enter a integer larger than 0: ";
        cin >> num;
    }
    for(int i = 0; i <= num; i++){
        sum += i;
    }
    cout << "The sum is: " << sum;
    return 0;
     

}
