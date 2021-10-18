//Kevin White
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void print(int a[], int size);
int sum(int a[], int arraySize);
int getVowels(string word, int size);
void reverse(string & word, int l, int h);
void reverse(int a[], int l, int h);
bool isPalindrome(string word, int check = 0);

int main(){
    //Question 1
    const int size = 5;
    int array[size] = {1, 2, 3, 4, 5};

    cout << "list: ";
    print(array, size);
    cout<< "\nSum: " << sum(array, size) << endl;

    //Question 2;
    string q2 = "Hello World";
    cout << "There are "<< getVowels(q2, q2.size()) << " vowels in \"" << q2 << "\"" << endl;

    //Question 3;
    string q3 = "batman";
    reverse(q3, 0, 5);
    cout << "Reverse: " << q3 << endl;

    //Question 4
    cout << "List: ";
    print(array, size);
    cout << "\nList Reverse: ";
    reverse(array, 0, 4);
    print(array, size);
    
    //Question 5
    string q5 = "tacocat";
    cout << boolalpha << "\nIs " << q5 << " a palindrome?\n" << isPalindrome(q5) << endl;

}

void print(int a[], int size){
    if(size != 0){
        print(a, size-1);
        cout << a[size-1] << " ";
    }
}

int sum(int a[], int arraySize){
    if(arraySize-1 == 0){
        return a[0];
    }else{
        return a[arraySize-1] + sum(a, arraySize - 1);
    }
}

int getVowels(string word, int size){
    int count = 0;
    if(size == 0){
        return 0;
    }else if(tolower(word[size - 1]) == 'a' || tolower(word[size - 1]) == 'e' || tolower(word[size - 1]) == 'i' || tolower(word[size - 1]) == 'o' || tolower(word[size - 1]) == 'u'){
        count++;
    }
    count += getVowels(word, size-1);
    return count;
}

void reverse(string & word, int l, int h){
    if(l < h){
        swap(word[l], word[h]);
        reverse(word, l+1, h-1);
    }
}

void reverse(int a[], int l, int h){
    if(l < h){
        int hold = a[h];
        a[h] = a[l];
        a[l] = hold;
        reverse(a, l+1 , h-1);
    }
}

bool isPalindrome(string word, int check){
    if(check < word.length()/2){
        if(word[word.length()-check-1] == word[check]){
            return isPalindrome(word, check + 1);
        }else{
            return false;
        }
    }else{
        return true;
    }
}