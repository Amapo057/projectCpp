#include <iostream>
using namespace std;
//g++ ./src/main.cpp -o ./bin/main ; ./bin/main

// 함수 선언
class Circle {
    private:
        double radius;
    public:
        double getRadius () const{return radius;};
        double getArea () const;
        double getPerimeter () const;
        void setRadius (double value);
    public:
		Circle(double radius);
        Circle();
        Circle(const Circle& circle);
        
        ~Circle ();
};

// 생성자
Circle :: Circle (double rds)
:radius(rds)
{
    cout << radius << endl;
    cout << "member" << endl;
}
Circle :: Circle ()
:radius(0.0)
{
    cout << radius << endl;
    cout << "none" << endl;
}
Circle :: Circle (const Circle& cr)
:radius(cr.radius)
{
    cout << radius << endl;
    cout << "point" << endl;
}

// 소멸자
Circle :: ~Circle(){
    cout << "call destructor" << endl;
}

// 함수 정의
double Circle :: getArea () const{
    const double PI = 3.14;
    return (PI * radius * radius);
}
double Circle :: getPerimeter () const{
    const double PI = 3.14;
    return (2 * PI * radius);
}
void Circle :: setRadius (double value){
    radius = value;
}


int main(){
    Circle circle1(5.2);
    cout << "R " << circle1.getRadius() << endl;
    cout << "A " << circle1.getArea() << endl;
    cout << "P " << circle1.getPerimeter() << endl;
    cout << endl;

    Circle circle2(circle1);
    cout << "R " << circle2.getRadius() << endl;
    cout << "A " << circle2.getArea() << endl;
    cout << "P " << circle2.getPerimeter() << endl << endl;

    Circle circle3;
    cout << "R " << circle3.getRadius() << endl;
    cout << "A " << circle3.getArea() << endl;
    cout << "P " << circle3.getPerimeter() << endl;
    cout << endl;

    return 0;
}