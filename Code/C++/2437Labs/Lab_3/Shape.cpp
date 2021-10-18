#include <iostream>
using namespace std;

class Shape{
    private:
        double area;

    public:
    double getArea(){
        return area;
    }
    void setArea(double a){
        area = a;
    }
    virtual void findArea() = 0;
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r){
            radius = r;
            findArea();
        }
        void findArea(){
            setArea(3.14 * radius * radius);
        }
};

class Square : public Shape {
    private:
        double side;
    
    public:
        Square(double s){
            side = s;
            findArea();
        }
        double getSide(){
            return side;
        }
        void findArea(){
            setArea(side * 4);
        }
};

int main(){
    int remove;
    Circle c(10);
    cout << "Circle Area: " << c.getArea() << endl;
    Square s(5);
    cout << "Square Area: " << s.getArea() << endl;
    cin >> remove;
}