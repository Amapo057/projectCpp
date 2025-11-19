#pragma once

#include "person.h"

using namespace std;

class Student : public Person { 
    private: 
        double gpa; 

    public: 
        Student();
        Student(long id, double gp);
        Student(const Student& student);
        ~Student();

        void print() const; 
};
