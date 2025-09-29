#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;



string hexToBin(const string&);

int main(){
    string inputHex = "cf3c0003";

    string bin;
    bin = hexToBin(inputHex);
    string op;
    op = bin.substr(0, 6);
    string ni;
    ni = bin.substr(6, 2);
    string x;
    x = bin.substr(8, 1);
    string bp;
    bp = bin.substr(9, 2);
    string e;
    e = bin.substr(11, 1);


    string disp;
    disp = bin.substr(12, 20);


    cout << bin << endl;
    cout << op << endl;
    cout << "flagbit :" << ni << x << bp << e << endl;
    // cout << adMode << endl;
    cout << disp << endl;
    // cout << ta << endl;
    // cout << regA << endl;
}


string hexToBin(const string& hexValue){
    unsigned long intValue;
    stringstream ss;
    ss << hex << hexValue;
    ss >> intValue;

    bitset<32> bits(intValue);

    return bits.to_string();
}