#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Student{
    private:
        int studentID;
        string name;
        double score;
    public:
        Student(int id, string n, double s) : studentID(id), name(n), score(s) {}

        void displayInfo() const{
            cout << "id: " << studentID << ", name: " << name << ", socre: " << score << endl;
        }

        string toString() const{
            return to_string(studentID) + "," + name + "," + to_string(score);
        }
};

int main(){
    vector<Student> students;

    students.push_back(Student(101, "Alice", 95.5));
    students.push_back(Student(102, "bob", 88.0));
    students.push_back(Student(103, "Charlie", 72.3));
    cout << "student list: " << endl;

    for (const auto& s : students){
        s.displayInfo();
    }
    ofstream outFile("student.txt");
    if (outFile.is_open()){
        for (const auto& s : students) {
            outFile << s.toString() << endl;
        }
        outFile.close();
        cout << "save complete" << endl;
    }
    else {
        cerr << "can't open file" << endl;
    }
    return 0;
}
