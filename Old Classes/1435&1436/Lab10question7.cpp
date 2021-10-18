#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	ofstream outFile;
	outFile.open("Numbers.txt");
	
    for(int i = 1; i <= 100; i++ ){
        outFile << i << endl;
    }
    
	cout << "Done writing numbers 1-100 to file Numbers.txt"<<endl;
	outFile.close();
	return 0;
}
