#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Employee{
    protected:
        string name;
        int id;
        int salary;
    public:
        virtual void work(){};
        void showInfo(){
            cout << "Employee Name: " << name << " ID: " << id << " Salary: " << salary << endl;
        };

        Employee(string name, int id, int salary):name(name), id(id), salary(salary){};
};

class Manager :public Employee{
    private:
        int teamSize;
    public:
        // 어따 쓰는거임?
        void work()override{cout << "team management" << endl;};

        Manager(string name, int id, int salary, int teamSize)
        : Employee(name, id, salary), teamSize(teamSize){};
};

class Engineer : public Employee{
    private:
        string specialty;
    public:
        void work()override{cout << "coding work" << endl;};

        Engineer(string name, int id, int salary, string specialty)
        :Employee(name, id, salary), specialty(specialty){};
};


int main(){
    vector<Manager> manager;
    vector<string> managerName = {"a", " b", "c", "d", "e"};
    vector<int> managerID = {1001, 1002, 1003, 1004, 1005};
    vector<int> managerSalary = {200, 210, 300, 200, 400};
    vector<int> managerSize = {100, 50, 40, 90, 200};


    vector<Engineer> engineer;
    vector<string> engineerName = {"f", "g", "h", "i", "j"};
    vector<int> engineerID = {2001, 2002, 2003, 2004, 2005};
    vector<int> engineerSalary = {300, 250, 200, 600, 300};
    vector<string> engineerSpecialty = {"a", "b", "C", "d", "e"};

    cout << "Manager" << endl;
    for(size_t i = 0; i < managerName.size(); ++i){
        manager.push_back(Manager(managerName[i], managerID[i], managerSalary[i], managerSize[i]));
        manager[i].showInfo();
    }

    ofstream outFile1("Manager.txt");
    if (outFile1.is_open()){
        for(auto& m: manager){
            outFile1 << m.toString() <<endl;
        }
        outFile1.close();
    }
    else{
        cerr << "Manager file can't open File" << endl;
    }

    cout << "Manager" << endl;
    ifstream readFile1("Manager.txt");
    if (readFile1.is_open()){
        string line;
        while (getline(readFile1, line)){
            cout << line << endl;
        }
        readFile1.close();
    }

    cout << "Engineer" << endl;
    for(size_t i = 0; i < engineerName.size(); ++i){
        engineer.push_back(Engineer(engineerName[i], engineerID[i], engineerSalary[i], engineerSpecialty[i]));
        engineer[i].showInfo();
    }

}



