#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// 뼈대 클래스 선언
class Vehicle{
    protected:      // 공통으로 사용될 멤버 변수
        string brand;
        int speed;
    public:
        virtual void displayInfo() = 0;             // 순수 가상 함수
        void setSpeed(int s){this->speed = s;};     // speed 적용 함수
        virtual string toString(){
            return brand + ", " + to_string(speed);};     // 문자열 출력 함수
        Vehicle():brand("None"){};                  // 기본 생성자
        Vehicle(string brand):brand(brand){};       // 변수 생성자
        virtual ~Vehicle(){};                       // 메모리 누수를 막기위한 가상 소멸자
};

// Vehicle에서 상속받아 자식 클래스 생성
class Car : public Vehicle{
    private:
        int doors;
    public:
        void displayInfo()override{   // 부모의 순수 가상함수인 displayInfo 정의
            cout << "Brand: " << brand << 
            "  Speed: " << speed << 
            "  Doors: " << doors << endl;
        };
        // 부모 함수로 기본 멤버 변수를 문자열로 담고, 추가 변수와 같이 출력
        string toString()override{
            string base = Vehicle::toString();
            return base + ", " + to_string(doors);
        };
        Car():Vehicle("None"), doors(0){};      // 기본 생성자
        Car(string brand, int doors)
            :Vehicle(brand), doors(doors){};    // 변수 생성자
};

// Vehicle에서 상속받아 자식 클래스 생성
class Bike : public Vehicle{
    private:
        bool hasCarrier;
    public:
        void displayInfo()override{     // 부모의 순수 가상함수인 displayInfo 정의
            cout << "Brand: " << brand << 
            "  Speed: " << speed << 
            "  hasCarrier: " << boolalpha << hasCarrier << endl;
        };
        string toString()override{          // 부모 함수로 기본 멤버 변수를 문자열로 담고, 추가 변수와 같이 출력
            string base = Vehicle::toString();
            return base + ", " + (hasCarrier ? "true" : "false");
        }; 
        Bike():Vehicle("None"), hasCarrier(false){};          // 기본 생성자
        Bike(string brand, bool hasCarrier)                   // 변수 생성자
            :Vehicle(brand), hasCarrier(hasCarrier){};
};

int main(){
    // 각 객체의 벡터와 객체별 필요 정보 벡터 초기화
    vector<Car> car;
    vector<string> carBrand ={"kia", "hyundai", "kg", "audi", "bmw"};
    vector<int> doors = {4, 4, 4, 2, 2};
    vector<int> carSpeed = {120, 150, 170, 180, 180};

    vector<Bike> bike;
    vector<string> bikeBrand = {"sam", "smart", "atex", "alton", "unkown"};
    vector<bool> carrier = {true, true, false, false, true};
    vector<int> bikeSpeed = {20, 33, 32, 27, 30};

    // car 객체 벡터의 값 초기화 하며 멤버 변수 출력
    cout << "---Car---\n" << "DisplayInfo" << endl;
    for (size_t i = 0; i < carBrand.size(); ++i) {
        car.push_back(Car(carBrand[i], doors[i]));
        car[i].setSpeed(carSpeed[i]);
        car[i].displayInfo();
    }
    // 저장할 파일 열기/생성 후 toString 함수로 내용 작성
    ofstream outFile1("Car.txt");
    if (outFile1.is_open()){         // 파일이 열렸는지 확인
        for(auto& c: car){
            outFile1 << c.toString() <<endl;
        }
        outFile1.close();
    }
    else{cerr << "Car file can't open File" << endl;}
    // 읽을 Car 파일 연 후 줄 단위로 잘라 출력
    cout << "\nRead file" << endl;
    ifstream readFile1("Car.txt");
    if (readFile1.is_open()){
        string line;            // 라인 저장용 변수 선언
        while (getline(readFile1, line)){    // 파일이 끝나면 종료
            cout << line << endl;
        }
        readFile1.close();
    }

    // bike 객체 벡터의 값 초기화 하며 멤버 변수 출력
    cout << "\n---Bike---\n" << "DisplayInfo" << endl;
    for (size_t i = 0; i < bikeBrand.size(); ++i) {
        bike.push_back(Bike(bikeBrand[i], carrier[i]));
        bike[i].setSpeed(bikeSpeed[i]);
        bike[i].displayInfo();
    }
    // 겹치지 않도록 outFile2로 파일 열기
    ofstream outFile2("Bike.txt");      
    if (outFile2.is_open()){
        for(auto& b : bike){
            outFile2 << b.toString() << endl;
        }
        outFile2.close();
    }
    else{cerr << "Bike file can't open File" << endl;}
    // 읽을 Bike 파일 연 후 줄 단위로 잘라 출력
    cout << "\nRead file" << endl; 
    ifstream readFile2("Bike.txt");
    if (readFile2.is_open()){
        string line;
        while (getline(readFile2, line)){
            cout << line << endl;
        }
        readFile2.close();
    }
    return 0;
}



