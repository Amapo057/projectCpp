#include <iostream>
using namespace std;
//g++ ./src/main.cpp -o ./bin/main ; ./bin/main

int globalVar = 10;

void exampleFunction(){
    int globalVar = 20;
    cout << "globalVar = " << ::globalVar++ << endl;
    // cout << globalVar << endl;
}

int main(){
    int mainVar = 30;
    // if(true){
    //     int blockVar = 40;
    //     cout << "Inside block: bloackVar = " << blockVar << endl;
    // }
    exampleFunction();
    exampleFunction();
    exampleFunction();
    // cout << "global variable: globalVar = " << globalVar << endl;
    // cout << "Main variable: mainVar = " << mainVar<< endl;
}
