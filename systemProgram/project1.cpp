#include <iostream>
// 문자열 변환
#include <string>
#include <sstream>
// 이진수 변환
#include <bitset>
#include <format>
// std 생략
using namespace std;
// g++ -std=c++20 ./systemProgram/project1.cpp -o ./bin/a ; ./bin/a

// 클래스로 코드 분리
class SIC{
    public:
        // 생성자로 변수 초기화
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
            // nixbpe 리턴. :d로 bool을 0과 1로 출력
            return format("nixbpe    : {:d}{:d}{:d}{:d}{:d}{:d}", n, i, x, b, p, e);
        }
        string getFlagBits(){
            return format("FlagBits    : {}, {}, {}, {}, {}", ex, adMode, idxMode, taMode, formatMode);
        }
    private:
        // 사용되는 변수들
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
        // 16진수 문자열로 주소 받아 이진수로 변환
        string hexToBin(string&);
        // 플래그 비트 쪼개기
        void parsingBits();
        // nixbpe값으로 모드 확인
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

    // n과 i로 sic/xe여부와 접근 모드 체크
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

    // x로 인덱스 모드 체크
    if (x){
        idxMode = "Indexed";
    }
    else{
        idxMode = "Directed";
    }

    // e로 formatMode확인
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