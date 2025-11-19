#include "person.h"

Person :: Person()
:identity (0.0){
}

Person :: Person(long id)
:identity (id){
}

Person :: Person (const Person& person)
:identity (person.identity){
}

Person :: ~Person(){
}

void Person :: print() const {
    cout << "identity : " << identity << endl;
}
