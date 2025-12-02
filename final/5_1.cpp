#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Student{
    private:
        string name;
        int studentID;
        double gpa;
    public:
        virtual void displayInfo();
        void setGPA(double g){this->gpa = g;};
        virtual string toString(){return name + ", " + to_string(studentID) + ", " + to_string(gpa);}

        Student() :name("asdf"), studentID(0000){};
        Student(string name, int id) :name(name), studentID(id){};
};

void Student :: displayInfo(){
    cout<< "Student Name: "<< name << "\nStudent ID: " << studentID << "\nStudent GPA: " << gpa << endl;
}

class GraduateStudent : public Student{
    private:
        string researchTopic;
    public:
        void setResearchTopic(string topic){this->researchTopic = topic;};
        void displayInfo()override;
        string toString()override;
        // 부모의 생성자 호출
        GraduateStudent(string name, int id):Student(name, id){};
};

void GraduateStudent :: displayInfo(){
    Student::displayInfo();
    cout << "ResearchTopic: " << researchTopic << endl;
}
string GraduateStudent::toString(){
    string base = Student::toString();
    return base + ", " + researchTopic;
}

int main(){
    vector<GraduateStudent> graduateStudent;
    graduateStudent.push_back(GraduateStudent("kjs", 2021));
    graduateStudent.push_back(GraduateStudent("asd", 2022));
    graduateStudent.push_back(GraduateStudent("fgh", 2023));
    graduateStudent.push_back(GraduateStudent("qwe", 2024));
    graduateStudent.push_back(GraduateStudent("zxc", 2025));

    vector<double> gpa = {4.5, 3.2, 4.0, 2.1, 3.9};
    vector<string> topic = {"cpp", "java", "c", "python", "c#"};

    int cnt = 0;

    // 저장할 파일 열어서 값 넣으며 저장
    ofstream outFile("student.txt");
    if (outFile.is_open()){
        for(auto& s : graduateStudent){
            // set함수 호출해 정보 저장
            s.setGPA(gpa[cnt]);
            s.setResearchTopic(topic[cnt]);
            // 정보 출력하는 함수 호출해 파일에 저장
            outFile << s.toString() << endl;
            cnt = cnt + 1;
        }
        outFile.close();
    }
    else{
        cerr << "Can't open File" << endl;
    }

    // 읽을 파일 열기
    ifstream readFile("student.txt");
    if (readFile.is_open()){
        // 사용할 변수 선언
        string line;
        while (getline(readFile, line)){
            // 파일을 줄마다 읽어 출력
            cout << line << endl;
        }
        readFile.close();
    }
    else{
        cout << "cant' read file" << endl;
    }

    return 0; 
}