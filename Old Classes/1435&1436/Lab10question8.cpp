#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
    int num;
	ifstream inFile;
	inFile.open("Numbers.txt");

	
	if(!inFile)
	{
        cout<<"File not found!\n";
        exit(EXIT_FAILURE);
    }
    
    cout<<"The numbers in file Numbers.txt:\n";
    while (inFile >> num) //read line by line
    {
        cout << num << endl;
    }
    inFile.close();
    cout << "There are no more numbers in Numbers.txt, file has been closed";
		
	return 0;
}
