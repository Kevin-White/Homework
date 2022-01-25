
#include <iostream>
using namespace std;

void dynamicSort(int score[], string name[], int size); 
int dynamicAverage(const int score[], int size);

int main()
{
    int size;
    string * name = nullptr;
    int * score = nullptr;
    
    cout << "How many test scores will you enter? ";
    cin >> size;
    while(size < 1){
        cout << "The number cannot be less than 1." << endl << "Enter another number: ";
        cin >> size;
    }
    cout << endl;
    
    name = new string[size];
    score = new int[size];
    
    for(int i = 0; i < size; i++){
        cout << "Enter student "<< i + 1 <<"'s name: ";
        cin >> name[i];
        cout << "Enter that student's test score: ";
        cin >> score[i];
        while(score[i] < 0){
            cout << "Negative scores are not allowed." << endl << "Enter another score for this test: ";
            cin >> score[i];
        }
        cout << endl;
    }
    
    dynamicSort(score, name, size);
    
    cout << "The test scores in ascending order: \n\nName         Score \n----------------------------------------\n";
    for(int i = 0; i < size; i++){
        cout << name[i] << "       " << score[i] << endl;
    }
    cout << endl;
    
    cout << "Average after dropping lowest score: " << dynamicAverage(score, size);
    
}


void dynamicSort(int score[], string name[], int size){
    int pivot = 1;
    while(pivot < size){
        int tempa = score[pivot];
        string tempb = name[pivot];
        int i = pivot -1;
        while(i >= 0 && score[i] > tempa){
            score[i + 1] = score[i];
            name[i + 1] = name[i];
            i--;
        }
        score[i + 1] = tempa;
        name[i + 1] = tempb;
        pivot++;
    }
}

int dynamicAverage(const int score[], int size){
    int average = 0;
    for(int i = 1; i < size; i++){
        average += score[i];
    }
    average = average/(size-1);
    return average;
}

