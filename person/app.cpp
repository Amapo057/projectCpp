#include "student.h" 

int main ( ) { 

    Person person (1111); 
    cout << "Information about person: " << endl; 
    person.print (); 
    cout << endl; 

    Student student (2222, 3.9); 
    cout << "Information about student: " << endl; 
    student.print (); 
    cout << endl; 

    return 0; 
}
