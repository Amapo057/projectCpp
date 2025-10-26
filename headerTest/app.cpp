#include "circle.h"
#include <iostream>
using namespace std;

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
    circle3.setRadius(99.0);
    cout << "R " << circle3.getRadius() << endl;
    cout << "A " << circle3.getArea() << endl;
    cout << "P " << circle3.getPerimeter() << endl;
    cout << endl;

    return 0;
}