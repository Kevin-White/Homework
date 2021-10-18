#include <iostream>
using namespace std;

template <class T> //you can use keyword typename instead of class
class Array {
    private:
        T *ptr;
        int size;
    public:
        Array(int s);
        Array(T arr[], int s); //or Array(T* arr, int s);
        void print();
        void setAt(int i, T val);
        void sort();
};

int main() {
    int arr[5] = {5, 2, 3, 1, 4};
    string arr1[4] = {"Hello ","Prof.","Hassan","21!"};
    Array<int> a(arr, 5);
    Array<string> s(arr1, 4);
    cout << "Unsorted:\n";
    a.print();
    s.print();

    a.sort();
    s.sort();
    cout << "\nSorted:\n";
    a.print();
    s.print();

    a.setAt(0, 5);
    s.setAt(1, "Yasmin");
    cout << "\nAfter inserting new values\n";
    a.print();
    s.print();
}

template <class T>
Array<T>::Array(int s){
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++){
        ptr[i] = {};
    }
}

template <class T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
        for(int i = 0; i < size; i++){
            ptr[i] = arr[i];
        }
}

template <class T>
void Array<T>::print() {
    for (int i = 0; i < size; i++){
        cout<<" "<<*(ptr + i);
    }
    cout<<endl;
}

template <class T>
void Array<T>::setAt(int i, T val){
    if(i <= size){
        ptr[i] = val;
    }
}

template<class T>
void Array<T>::sort(){
    for (int step = 0; step < size - 1; step++) {
    int min = step;
    for (int i = step + 1; i < size; i++) {
        
      if (ptr[i] < ptr[min])
        min = i;
        
    }
    T temp = ptr[min];
    ptr[min] = ptr[step];
    ptr[step] = temp;
    }
}

