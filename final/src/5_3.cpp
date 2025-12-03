#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// 뼈대 클래스 선언
class Employee{
    protected:      // 공통으로 사용될 멤버 변수
        string name;
        int id;
        int salary;
    public:
        virtual void work(){};      // 가상 함수로 선언해 상속 가능하게 선언
        void showInfo(){            // 변수 출력
            cout << "Employee Name: " << name << 
            " ID: " << id << 
            " Salary: " << salary << endl;
        };
        string toString(){          // 변수 문자열로 출력
            return name + ", " + to_string(id) + ", " + to_string(salary);};

        Employee():name("Jane Doe"), id(0), salary(0){};    // 기본 생성자
        Employee(string name, int id, int salary)           // 변수 생성자
            :name(name), id(id), salary(salary){};
        virtual ~Employee(){};                              // 메모리 누수 방지용 가상 소멸자
};

// Employee에서 상속받아 자식 클래스 생성
class Manager :public Employee{
    private:
        int teamSize;
    public:
        // work 오버라이드하고 역할인 팀관리 출력
        void work()override{cout << "team management" << endl;};
        string toString(){      // 문자열 출력
            return Employee::toString() + ", " + to_string(teamSize);};

        Manager():Employee("Jane Doe", 0, 0), teamSize(1){};        // 기본 생성자
        Manager(string name, int id, int salary, int teamSize)      // 변수 생성자
        : Employee(name, id, salary), teamSize(teamSize){};
};

// Employee에서 상속받아 자식 클래스 생성
class Engineer : public Employee{
    private:
        string specialty;
    public:
        // work 오버라이드하고 역할인 전문 분야 출력
        void work()override{cout << specialty << endl;};
        string toString(){      // 문자열 출력
            return Employee::toString() + ", " + specialty;};
        Engineer()              // 기본 생성자
            :Employee("Jane Doe", 0, 0), specialty("None"){};   
        Engineer(string name, int id, int salary, string specialty) // 변수 생성자
        :Employee(name, id, salary), specialty(specialty){};
};

int main(){
    // 각 객체의 벡터와 객체별 필요 정보 벡터 초기화
    vector<Manager> manager;
    vector<string> managerName = {"James", "Olivia", "John", "Emma", "Robert"};
    vector<int> managerID = {1001, 1002, 1003, 1004, 1005};
    vector<int> managerSalary = {200, 210, 300, 200, 400};
    vector<int> managerSize = {100, 50, 40, 90, 200};

    vector<Engineer> engineer;
    vector<string> engineerName = 
        {"Ava", "Michael", "Sophia", "William", "Isabella"};
    vector<int> engineerID = {2001, 2002, 2003, 2004, 2005};
    vector<int> engineerSalary = {300, 250, 200, 600, 300};
    vector<string> engineerSpecialty = 
        {"Software Engineer", "Mechanical Engineer", 
        "Electrical Engineer", "Civil Engineer", "AI/Machine Learning Engineer"};

    // manager 객체 벡터의 값 초기화 하며 멤버 변수 출력
    cout << "---Manager---\n" << "DisplayInfo" << endl;
    for(size_t i = 0; i < managerName.size(); ++i){
        manager.push_back(Manager(managerName[i], managerID[i], managerSalary[i], managerSize[i]));
        manager[i].showInfo();
    }

    // 저장할 파일 열기/생성 후 toString 함수로 내용 작성
    ofstream outFile1("Manager.txt");
    if (outFile1.is_open()){         // 파일이 열렸는지 확인
        for(auto& m: manager){
            outFile1 << m.toString() <<endl;
        }
        outFile1.close();
    }
    else{cerr << "Manager file can't open File" << endl;}

    // 읽을 파일 연 후 줄 단위로 잘라 출력
    cout << "\nRead file" << endl;
    ifstream readFile1("Manager.txt");
    if (readFile1.is_open()){
        string line;            // 라인 저장용 변수 선언
        while (getline(readFile1, line)){    // 파일이 끝나면 종료
            cout << line << endl;
        }
        readFile1.close();
    }

    // engineer 객체 벡터의 값 초기화 하며 멤버 변수 출력
    cout << "\n---Engineer---\n" << "DisplayInfo" << endl;
    for(size_t i = 0; i < engineerName.size(); ++i){
        engineer.push_back(Engineer(engineerName[i], engineerID[i], engineerSalary[i], engineerSpecialty[i]));
        engineer[i].showInfo();
    }

    ofstream outFile2("Engineer.txt");      // 겹치지 않도록 outFile2로 파일 열기
    if (outFile2.is_open()){
        for(auto& e: engineer){
            outFile2 << e.toString() <<endl;
        }
        outFile2.close();
    }
    else{cerr << "Engineer file can't open File" << endl;}

    cout << "\nRead file" << endl; 
    ifstream readFile2("Engineer.txt");
    if (readFile2.is_open()){
        string line;
        while (getline(readFile2, line)){
            cout << line << endl;
        }
        readFile1.close();
    }
    return 0;
}



