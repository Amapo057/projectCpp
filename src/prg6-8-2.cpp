#include <iostream>
using namespace std;

int greeting(int*, int*);
int greeting(int, int);

int main() {
    int a, b;

    int x = 10;
    int y = 20;

    a = greeting(x, y);
    cout << x <<" "<< y <<"\n"<<endl;

    b = greeting(&x, &y);
    cout << x <<" "<< y <<endl;  

    return 0;
}

int greeting(int u, int v){
    cout << "**Call-by-v**"<<endl;

    u = u+v;
    return u+v;
}

int greeting(int* u, int* v){
    cout << "**Call-by-p**"<<endl;

    (*u) = (*u) + (*v);
    return (*u);
}


//g++ ./src/main.cpp -o ./bin/main ; ./bin/maing