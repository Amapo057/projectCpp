#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <format>
using namespace std;



string hexToBin(const string&);

int main(){
    string inputHex = "cf3c0003";

    string bin = hexToBin(inputHex);
    string op = bin.substr(0, 6);

    bool n = (bin[6] == '1');
    bool i = (bin[7] == '1');
    bool x = (bin[8] == '1');
    bool b = (bin[9] == '1');
    bool p = (bin[10] == '1');
    bool e = (bin[11] == '1');

    string disp;
    disp = bin.substr(12, 20);

    string adMode;
    string ex;
    if ( n && i){
        ex = "SIC/XE";
        adMode = "Simple";
    }
    else if (n){
        ex = "SIC/XE";
        adMode = "Indirect";
    }
    else if (i){
        ex = "SIC/XE";
        adMode = "Immediate";
    }
    else {
        ex = "SIC";
        adMode = "Simple";
    }


    cout << bin << endl;
    cout << op << endl;
    cout << "nixbpe : " << n << i << x << b << p << e << endl;
    cout << "FlagBits : " <<
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