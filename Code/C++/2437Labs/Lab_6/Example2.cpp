#include <iostream>
#include <list>
using namespace std;
int main()
{
 list<int> lst;
 int i;

 //create a list of random integers
 for(i = 0; i < 10; i++)
 lst.push_back(rand());

 cout << "Original list: " << endl;
 // create an iterator object and make it point to the
 // beginning of the list
 list<int>::iterator p = lst.begin();
 while(p != lst.end()){
 cout << *p << " ";
 p++;
 }

 cout << endl << endl;

 // sort the list
 lst.sort();

 cout <<"Sorted contents:\n";
 p = lst.begin();
 while(p != lst.end()){
 cout << *p << " " ;
 p++;
 }
 cout << endl << endl;
 return 0;
}