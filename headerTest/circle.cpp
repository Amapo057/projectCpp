#include "circle.h"
#include <iostream>
using namespace std;

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
    return (PI * this -> radius * (*this).radius);
}
double Circle :: getPerimeter () const{
    const double PI = 3.14;
    return (2 * PI * this -> radius);
}
void Circle :: setRadius (double radius){
    this -> radius = radius;
}