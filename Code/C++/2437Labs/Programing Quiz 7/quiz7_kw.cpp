//name:

#include<iostream>

#include<stack>  //STL stack

using namespace std;

 

template<class T>

T secondFunction(stack<T>&);

 

int main()

{

    stack <int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    //demonstrate the function
    cout << "2nd value: " << secondFunction(st1) << endl << endl;
    //display the values of st1 after calling the function

    cout << "All values in stack:\n";
    while(!st1.empty()){
        cout << st1.top() << " ";
        st1.pop();
    }

   

}

template<class T>

T secondFunction(stack<T> &s)
{
   // do not define other stacks or other data structures
    T temp1,temp2;
    temp1 = s.top();
    s.pop();
    temp2 = s.top();
    s.push(temp1);
    return temp2;
}