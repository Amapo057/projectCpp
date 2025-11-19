#include <iostream>
#include <cassert>

using namespace std;

class Person{
    protected:
        long identity;
    public:
        void setID(long);
        long getID() const;
};
void Person :: setID(long id){
    assert (id >= 1000 && id <= 9999);
    this -> identity = id;
}
long Person :: getID() const{
    return this -> identity;
}

class Student : public Person{
    private:
        double gpa;
    public:
        void set(long, double);
        void setGPA(double);
        double getGPA() const;
};
void Student :: set(long id, double gpa){
    // Person :: setID(id);
    this->identity = id;
    this->gpa = gpa;
}
void Student :: setGPA(double gpa){
    assert (gpa >= 0 && gpa <= 4.0);
    this -> gpa = gpa;
}
double Student :: getGPA() const{
    return this -> gpa;
}

int main(){
    Person psn;
    psn.setID(1111L);
    cout << "Person ID: " << psn.getID() << "\n" << endl;

    Student std;
    std.setID(2222L);
    std.setGPA(3.9);
    cout << "std id: " << std.getID() << endl;
    cout << "std gpa: " << std.getGPA() << "\n" << endl;

    Student std2;
    std2.set(3333L, 3.5);
    cout << "std2 id: " << std2.getID() << endl;
    cout << "std2 gpa: " << std2.getGPA() << endl;
    return 0;
}