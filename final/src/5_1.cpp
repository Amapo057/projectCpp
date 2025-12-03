#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
// g++ ./final/src/5_3.cpp -o ./bin/main; ./bin/main

// 기본 학생 클래스
class Student{
    private:        // 공통으로 사용될 멤버 변수
        string name;
        int studentID;
        double gpa;
    public:
        virtual void displayInfo();             // 오버라이드 가능한 가상 함수
        void setGPA(double g){this->gpa = g;};  // gpa 값 적용 함수
        virtual string toString();              // 문자열 출력 함수
        
        Student():name("Hong"), studentID(00000000){};     // 기본 생성자
        Student(string name, int id)                       // 변수 생성자
            :name(name), studentID(id){};
        virtual ~Student(){};                              // 메모리 누수 방지용 가상 소멸자
};

// 정보 출력 함수
void Student :: displayInfo(){
    cout << "Student Name: "<< name << 
    "  Student ID: " << studentID << 
    "  Student GPA: " << gpa;
}

// 멤버 변수 문자열로 리턴하는 함수
string Student :: toString(){
    return name + ", " + to_string(studentID) + ", " + to_string(gpa);
}

// Student클래스에서 상속받아 자식 클래스 생성
class GraduateStudent : public Student{
    private:
        string researchTopic;               // 주제 멤버 변수 추가
    public:
        void displayInfo() override;        // 정보 출력 함수 상속
        // topic 값 적용 함수
        void setResearchTopic(string topic){this->researchTopic = topic;};  
        // 부모 함수로 기본 멤버 변수를 문자열로 담고, 추가 변수와 같이 출력
        string toString() override{         
            string basic = Student::toString();
            return basic + ", " + researchTopic;
        };
        // 기본생성자. 부모 클래스르 사용해 초기화
        GraduateStudent():Student("Hong", 00000000){};
        // 변수 생성자. 부모 클래스를 사용해 초기화
        GraduateStudent(string name, int id):Student(name, id){};   
};

// 부모 함수를 호출해 사용하면서 추가 정보 출력
void GraduateStudent :: displayInfo(){
    Student::displayInfo();
    cout << "  ResearchTopic: " << researchTopic << endl;
}

int main(){
    // 필요한 벡터 초기화
    vector<GraduateStudent> graduateStudent;
    vector<string> name = {"Jun", "Min", "Sol", "Hana", "Yuna"};
    vector<int> id = {2021351, 20225482, 20216540, 2023648, 2022146};
    vector<double> gpa = {4.5, 3.2, 4.2, 2.1, 3.9};
    vector<string> topic = {"cpp", "java", "c", "python", "c#"};

    // 객체 벡터의 값 초기화 하며 멤버 변수 출력
    cout << "Display Info" << endl;
    for (size_t i = 0; i < name.size(); ++i){
        graduateStudent.push_back(GraduateStudent(name[i], id[i]));
        graduateStudent[i].setGPA(gpa[i]);
        graduateStudent[i].setResearchTopic(topic[i]);
        graduateStudent[i].displayInfo();
    }

    // 저장할 파일 열기/생성 후 toString 함수로 내용 작성
    ofstream outFile("student.txt");
    if (outFile.is_open()){         // 파일이 열렸는지 확인
        for(auto& s : graduateStudent){
            outFile << s.toString() << endl;
        }
        outFile.close();
    }
    else{cerr << "Can't open File" << endl;}

    
    // 읽을 파일 연 후 줄 단위로 잘라 출력
    cout << "\nRead File" << endl;
    ifstream readFile("student.txt");
    if (readFile.is_open()){
        string line;            // 라인 저장용 변수 선언
        while (getline(readFile, line)){    // 파일이 끝나면 종료
            cout << line << endl;
        }
        readFile.close();
    }
    else{cout << "cant' read file" << endl;}

    return 0; 
}