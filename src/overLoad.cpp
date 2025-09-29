#include <iostream>
using namespace std;
//g++ ./src/main.cpp -o ./bin/main ; ./bin/main

void fun(int, int);
void fun(int);
void fun(int, float);
// int fun(int);

int main(){
    int a = 10;
    int b = 20;
    fun(a, b);
    fun(a);
    fun(3, 4.1f);
    // int c = 30;
    // c = fun(b);
}

void fun(int x, int y){
    cout << x+y;
    cout << endl;
}
void fun(int x){
    cout << x;
    cout << endl;
}
void fun(int x, float y){
    cout << x*y;
}
// int fun(int x){
//     return x;
// }
