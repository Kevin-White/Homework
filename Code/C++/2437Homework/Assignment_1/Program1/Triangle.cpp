#include <iostream>
using namespace std;

class Triangle{
    private:
        double width;
        double hight;

    public:
        Triangle(){
            cout << "Enter triangle width: ";
            cin >> width;
            cout << "Enter triangle hight: ";
            cin >> hight;
            cout << endl;
        }
        double getArea(){
            return (width * hight)/2;
        }
        void setWidth(double w){
            width = w;
        }
        void setHight(double h){
            hight = h;
        }
        double getWidth(){
            return width;
        }
        double getHight(){
            return hight;
        }

};

int main(){
    Triangle * triList;
    int size;
    cout << "Enter # of Triangles: ";
    cin >> size;
    triList = new Triangle[size];

    int largest = 0; 
    for(int i = 1; i < size; i++){
        if(triList[largest].getArea() < triList[i].getArea()){
            largest = i;
        }
    }

    cout << "The Largest triangle was Triangle #" << largest + 1 << endl
        << "Triangle #" << largest + 1 << " dimentions:" << endl
        << "Width: " << triList[largest].getWidth() << endl
        << "Hight: " << triList[largest].getHight() << endl
        << "Area: " << triList[largest].getArea() << endl;
}