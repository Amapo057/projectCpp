#include <iostream>
// ���ڿ� ��ȯ
#include <string>
#include <sstream>
// ������ ��ȯ
#include <bitset>
#include <format>
// std ����
using namespace std;
// g++ -std=c++20 ./systemProgram/project1.cpp -o ./bin/a ; ./bin/a

// Ŭ������ �ڵ� �и�
class SIC{
    public:
        // �����ڷ� ���� �ʱ�ȭ
        SIC(const string& hex){
            hexValue = hex;
            binValue = hexToBin(hexValue);
            parsingBits();
            checkType();
        }
        string getBin(){
            return format("Binary    : {}", binValue);
        }
        string getopCode(){
            return format("Opcode    : {}", opCode);
        }
        string getNIXBPE(){
            // nixbpe ����. :d�� bool�� 0�� 1�� ���
            return format("nixbpe    : {:d}{:d}{:d}{:d}{:d}{:d}", n, i, x, b, p, e);
        }
        string getFlagBits(){
            return format("FlagBits    : {}, {}, {}, {}, {}", ex, adMode, idxMode, taMode, formatMode);
        }
    private:
        // ���Ǵ� ������
        string hexValue;
        string binValue;
        string opCode;
        bool n, i, x, b, p ,e;
        string ex;
        string adMode;
        string idxMode;
        string taMode;
        string formatMode;
        string disp;
        // 16���� ���ڿ��� �ּ� �޾� �������� ��ȯ
        string hexToBin(string&);
        // �÷��� ��Ʈ �ɰ���
        void parsingBits();
        // nixbpe������ ��� Ȯ��
        void checkType();
};


int main(){
    string inputHex = "cf3c0003";

    SIC decodeSIC(inputHex);

    cout << decodeSIC.getBin() << endl;
    cout << decodeSIC.getopCode() << endl;
    cout << decodeSIC.getNIXBPE() << endl;
    cout << decodeSIC.getFlagBits() << endl;
    // cout << disp << endl;
    // cout << ta << endl;
    // cout << regA << endl;
}


string SIC :: hexToBin(string& hexValue){
    unsigned long intValue;
    stringstream ss;
    ss << hex << hexValue;
    ss >> intValue;

    bitset<32> bits(intValue);

    return bits.to_string();
}

void SIC :: parsingBits(){
    opCode = binValue.substr(0, 6);

    n = (binValue[6] == '1');
    i = (binValue[7] == '1');
    x = (binValue[8] == '1');
    b = (binValue[9] == '1');
    p = (binValue[10] == '1');
    e = (binValue[11] == '1');

    disp = binValue.substr(12, 20);
}

void SIC :: checkType(){

    // n�� i�� sic/xe���ο� ���� ��� üũ
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

    // x�� �ε��� ��� üũ
    if (x){
        idxMode = "Indexed";
    }
    else{
        idxMode = "Directed";
    }

    // e�� formatModeȮ��
    if (e){
        formatMode = "Format4";
        taMode = "DirectMode";
    }
    else{
        formatMode = "Format3";

        if (b){
            taMode = "BaseRelative";
        }
        else if (p){
            taMode = "PCRelative";
        }
        else{
            taMode = "DirectMode";
        }
    }
    
}