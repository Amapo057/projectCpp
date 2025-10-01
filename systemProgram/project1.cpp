// C++강의를 수강중이기에 한번 사용해보기로 결정
#include <iostream>
// 문자열 변환
#include <string>
#include <sstream>
// 이진수 변환
#include <bitset>
#include <format>
// 주소용 map 사용
#include <map>
// std 생략
using namespace std;
// 터미널 명령어
// g++ -std=c++20 ./systemProgram/project1.cpp -o ./bin/a ; ./bin/a

// 레지스터 값 선언
string regiB = "006000";
string regiPC = "003000";
string regiX = "000090";
string regiA;
// 메모리 역할 map 전역으로 선언
map<string, string> ram;

// 클래스 사용
class Decoder{
    public:
        // 생성자로 변수 초기화, 함수 호출해 계산
        Decoder(const string& hex){
            hexValue = hex;
            binValue = hexToBin(hexValue);
            parsingBits();
            checkType();
            clacTA();
            ramToRegi();
        }
        // get함수로 값 추출
        string getBin(){
            // format으로 깔끔하게 정리
            return format("Binary               : {}", binValue);
        }
        string getopCode(){
            return format("Opcode               : {}", opCode);
        }
        string getNIXBPE(){
            // nixbpe 리턴. :d로 bool을 0과 1로 출력
            // 수를 지정해서 원하는 변수 출력
            return format("nixbpe               : {0:d}{1:d}{2:d}{3:d}{4:d}{5:d} (n={0:d} i={1:d} x={2:d} b={3:d} p={4:d} e={5:d})", n, i, x, b, p, e);
        }
        string getFlagBits(){
            return format("FlagBits             : {}, {}, {}, {}, {}", ex, adMode, idxMode, taMode, formatMode);
        }
        string getDisp(){
            if (b or p){
                return format("Disp                 : {}", disp);
            }
            else{
                // direct인 경우 disp가 아닌 addr로 표시
                return format("Addr                 : {}", disp);
            }
        }
        string getTA(){
            // 0x를 붙여 16진수 표시
            return format("TA                   : 0x{}", ta);
        }
        string getRegi(){
            return format("Register A value     : 0x{}", registerValue);
        }
    private:
        // 사용되는 변수들
        string hexValue, binValue;
        string opCode;
        bool n, i, x, b, p ,e;
        string ex, adMode, idxMode, taMode, formatMode;
        string disp;
        string ta;
        string registerValue;
        // 16진수 문자열로 주소 받아 이진수로 변환
        string hexToBin(string&);
        // 플래그비트 쪼개기
        void parsingBits();
        // nixbpe값으로 모드 확인
        void checkType();
        // ta값 게산
        void clacTA();
        // 값 추적
        void ramToRegi();
};


int main(){
    // map 값 배정
    // 교재 예시 값 참고
    ram["3030"] = "003600";
    ram["3600"] = "103000";
    ram["6390"] = "00c303";
    ram["c303"] = "003030";
    // 문자열 생성해 주소 입력받도록 함
    string inputHex;
    cout << "Input Hex : ";
    cin >> inputHex;
    // 객체 생성
    Decoder sicDecoder(inputHex);
    // 객체에서 값 얻어와 출력
    cout << sicDecoder.getBin() << endl;
    cout << sicDecoder.getopCode() << endl;
    cout << sicDecoder.getNIXBPE() << endl;
    cout << sicDecoder.getFlagBits() << endl;
    cout << sicDecoder.getDisp() << endl;
    cout << sicDecoder.getTA() << endl;
    // 레지스터에 값 저장
    regiA = sicDecoder.getRegi();
    cout << regiA << endl;
}


string Decoder :: hexToBin(string& hexValue){
    unsigned long intValue;
    stringstream ss;
    string bitValue;

    // 정수를 16진수로 바꿔서 출력
    ss << hex << hexValue;
    ss >> intValue;
    
    // 주소값의 길이에 따라 다른 크기로 이진수 변환
    if (hexValue.size() == 6){
        bitset<24> bits(intValue);
        bitValue = bits.to_string();
    }
    else {
        bitset<32> bits(intValue);
        bitValue = bits.to_string();
    }

    return bitValue;
}

void Decoder :: parsingBits(){
    // 이진수를 잘라 분리
    opCode = binValue.substr(0, 6);
    
    // nixbpe bool로 저장
    n = (binValue[6] == '1');
    i = (binValue[7] == '1');
    x = (binValue[8] == '1');
    b = (binValue[9] == '1');
    p = (binValue[10] == '1');
    e = (binValue[11] == '1');

    // sic, sic/xe 여부에 따라 다른 길이를 disp에 배정
    if (!n && !i){
        // SIC은 b부터 주소값으로 사용
        // substr 두번째 인자를 지정하지 않아서 끝까지 지정하기
        disp = binValue.substr(9);
    }
    else{
        disp = binValue.substr(12);
    }
    
}

void Decoder :: checkType(){

    // x로 인덱스 모드 체크
    if (x){
        idxMode = "Indexed";
    }
    else{
        idxMode = "Directed";
    }

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
        formatMode = "Format3";
        taMode = "DirectMode";
        // sic의 경우 bpe는 계산하지 않음
        return;
    }

    // e로 formatMode확인
    if (e){
        formatMode = "Format4";
        taMode = "DirectMode";
    }
    else{
        formatMode = "Format3";
        // format3의 경우에만 bp 체크
        if (b){
            taMode = "Base-Relative";
        }
        else if (p){
            taMode = "PC-Relative";
        }
        else{
            taMode = "DirectMode";
        }
    }
    
}

void Decoder :: clacTA(){
    int iDisp, iregibp = 0, iregiX = 0, intTA;
    stringstream ss;

    // 이진수를 정수로 변환해 저장
    // 너무 길어서 long타입 사용
    iDisp = stol(disp, nullptr, 2);
    if (x){
        iregiX = stoi(regiX, nullptr, 16);
    }
    
    // 레지스터를 사용할 때만 불러와서 적용
    if (taMode != "DirectMode"){
        if (b){
            iregibp = stoi(regiB, nullptr, 16);
        }
        else if (p){
            iregibp = stoi(regiPC, nullptr, 16);
        }
    }

    // 전부 더해 16진수로 다시 변환해 문자열로 저장
    intTA = iDisp + iregibp + iregiX;
    ss << hex << intTA;
    ss >> ta;
}

void Decoder :: ramToRegi(){
    string tempAddr;
    int tempTA;
    stringstream ss;

    // simple방식은 바로 ta를 사용해 map에 접근
    if (n == i){
        registerValue = ram[ta];
    }
    else if(n){
        // 메모리에 저장된 값이 003060같은 경우 16진수 메모리 주소를 못찾기에 16진수로 한번 변환해 사용
        tempAddr = ram[ta];
        tempTA = stoi(tempAddr, nullptr, 16);
        ss << hex << tempTA;
        ss >> tempAddr;
        registerValue = ram[tempAddr];
    }
    else if(i){
        // 바로 ta값 사용
        registerValue = ta;
    }
}