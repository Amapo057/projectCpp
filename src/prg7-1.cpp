#include <iostream>
using namespace std;
//g++ ./src/main.cpp -o ./bin/main ; ./bin/main

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

// double Circle :: getRadius () const{
//     return radius;
// }

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
}
Circle :: Circle (const Circle& cr)
:radius(cr.radius)
{
    cout << radius << endl;
}
Circle :: ~Circle(){
    cout << "call destructor" << endl;
}

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
    // cout << "C1" << endl;
    Circle circle1(5.2);
    // circle1.setRadius(10.0);
    cout << "R " << circle1.getRadius() << endl;
    // cout << "A " << circle1.getArea() << endl;
    // cout << "P " << circle1.getPerimeter() << endl << endl;

    // cout << "C2:" << endl;
    // Circle circle2;
    // circle2.setRadius(20.0);
    // cout << "R " << circle2.getRadius() << endl;
    // cout << "A " << circle2.getArea() << endl;
    // cout << "P " << circle2.getPerimeter() << endl << endl;
    return 0;
}