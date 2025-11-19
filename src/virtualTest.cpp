
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Shape{
    protected:
        virtual bool isValid() const = 0;
    public:
        virtual void print() const = 0;
        virtual double getArea() const = 0;
};

class Square : public Shape{
    private:
        double side;
        bool isValid() const;
    public:
        Square(double side);
        void print() const;
        double getArea() const;
};

bool Square::isValid() const {
    return (side > 0.0);
}

Square::Square(double s)
:side(s){
    if(!isValid()){
        cout << "invalid square: " << side << endl;
        assert(false);
    }
}

void Square::print() const{
    cout << "square size = " << side << endl;
}

double Square::getArea() const{
    return side * side;
}

class Rectangle : public Shape{
    private:
        double length;
        double width;
        bool isValid() const;
    public:
        Rectangle(double, double);
        void print() const;
        double getArea() const;
};
bool Rectangle::isValid() const{
    return (length > 0.0 && width > 0.0);
}

Rectangle::Rectangle(double lg, double wd)
:length(lg), width(wd){
    if(!isValid()){
        cout << "invalid rectangle: " << length << "X" << width << endl;
        assert(false);
    }
}
void Rectangle::print() const{
    cout << "rectangle size : " << length << "X" << width << endl;
}

double Rectangle::getArea() const{
    return length * width;
}

int main(){
    Square sq(12);
    sq.print();
    cout << "Square Area: " << sq.getArea() << endl;

    Rectangle rt(7, 8);
    rt.print();
    cout << "Rectangle Area: " << rt.getArea() << endl;
}