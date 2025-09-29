#include <iostream>
using namespace std;

void fun(int* y){
    (*y)++;
}
int main(){
    int x = 10;
    fun(&x);
    cout << x << endl;
}