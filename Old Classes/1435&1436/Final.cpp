
#include <iostream>
#include <vector> 
using namespace std;

int main()
{
    vector<int> vec;
    int temp;
    cout << "Enter a number or 0 to quit: ";
    cin >> temp;
    while(temp != 0){
        vec.push_back(temp);
        cout << "Enter a number or 0 to quit: ";
        cin >> temp;
    }
    cout << endl;
    for(int i = vec.size() - 1; i >= 0; i--){
        cout << vec[i] << " ";
    }
}
