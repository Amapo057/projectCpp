#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;



string hexToBin(const string&);

int main(){
    string inputHex = "AAAAAA";

    string bin;
    bin = hexToBin(inputHex);
    string op;
    op = bin.substr(0, 6);
    string flagBit;
    flagBit = bin.substr(6, 2);

    cout << bin << endl;
    cout << op << endl;
    cout << flagBit << endl;
    // cout << adMode << endl;
    // cout << disp << endl;
    // cout << ta << endl;
    // cout << regA << endl;
}


string hexToBin(const string& hexValue){
    unsigned long intValue;
    stringstream ss;
    ss << hex << hexValue;
    ss >> intValue;

    bitset<24> bits(intValue);

    return bits.to_string();
}