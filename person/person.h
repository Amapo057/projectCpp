#pragma once

#include <cassert>
#include <iostream>

using namespace std;

class Person {
    private:
        long identity;
    public:
        Person();
        Person(long id);
        Person(const Person& Person);

        ~Person();

        void print() const;
};