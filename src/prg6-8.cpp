#include <iostream>
using namespace std;


int greeting(int, int);

int main() {
    int a;

    a = greeting(5, 7);
    cout << a <<endl;
    return 0;
}

int greeting(int x, int y){
    cout << "*************" <<endl;
    cout << "**¾È³çÇÏ¼¼¿ä**"<<endl;
    cout << "*************" <<endl;
    cout << x + y <<endl;

    return x+y;
}

//g++ ./src/main.cpp -o ./bin/main ; ./bin/maing