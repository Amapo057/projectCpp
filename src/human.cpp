#include <string>
#include <iostream>
using namespace std;
//g++ human.cpp -o ./bin/main ; ./bin/main

class Person{
    private:
        int age;
        string name;
    public:
        Person();
        Person(string, int);

        string getName();
        int getAge();
};

Person :: Person()
:name("jiseong"), age(20)
{
    cout << "Basic" << endl;
}
Person :: Person(string name, int age)
:name(name), age(age)
{
    this -> name = name;
    this -> age = age;
    cout << "Parameter" << endl;
}

string Person :: getName(){
    return this->name;
}

int Person :: getAge(){
    return age;
}

int main(){
    std::string name = "KimJiseong";
    int age = 24;

    
    Person kim20;
    cout << kim20.getName() << "  " <<  kim20.getAge() << "\n" << endl;


    Person kim24(name, age);
    cout << kim24.getName() << "  " <<  kim24.getAge() << endl;
    
    return 0;
}