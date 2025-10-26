#pragma once

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