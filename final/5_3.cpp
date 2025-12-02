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
        string toString(){
            return name + ", " + to_string(id) + ", " + to_string(salary);};

        

        Employee(string name, int id, int salary):name(name), id(id), salary(salary){};
};

class Manager :public Employee{
    private:
        int teamSize;
    public:
        void work()override{cout << "team management" << endl;};
        string toString(){
            return Employee::toString() + ", " + to_string(teamSize);};

        Manager(string name, int id, int salary, int teamSize)
        : Employee(name, id, salary), teamSize(teamSize){};
};

class Engineer : public Employee{
    private:
        string specialty;
    public:
        void work()override{cout << "coding work" << endl;};
        string toString(){
            return Employee::toString() + ", " + specialty;};


        Engineer(string name, int id, int salary, string specialty)
        :Employee(name, id, salary), specialty(specialty){};
};


int main(){
    vector<Manager> manager;
    vector<string> managerName = {"James", "Olivia", "John", "Emma", "Robert"};
    vector<int> managerID = {1001, 1002, 1003, 1004, 1005};
    vector<int> managerSalary = {200, 210, 300, 200, 400};
    vector<int> managerSize = {100, 50, 40, 90, 200};


    vector<Engineer> engineer;
    vector<string> engineerName = {"Ava", "Michael", "Sophia", "William", "Isabella"};
    vector<int> engineerID = {2001, 2002, 2003, 2004, 2005};
    vector<int> engineerSalary = {300, 250, 200, 600, 300};
    vector<string> engineerSpecialty = {"Software Engineer", "Mechanical Engineer", "Electrical Engineer", "Civil Engineer", "AI/Machine Learning Engineer"};

    cout << "Manager" << endl;
    for(size_t i = 0; i < managerName.size(); ++i){
        manager.push_back(Manager(managerName[i], managerID[i], managerSalary[i], managerSize[i]));
        // manager[i].showInfo();
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
    ifstream readFile1("Manager.txt");
    if (readFile1.is_open()){
        string line;
        while (getline(readFile1, line)){
            cout << line << endl;
        }
        readFile1.close();
    }
    cout << "" << endl;

    cout << "Engineer" << endl;
    for(size_t i = 0; i < engineerName.size(); ++i){
        engineer.push_back(Engineer(engineerName[i], engineerID[i], engineerSalary[i], engineerSpecialty[i]));
        // engineer[i].showInfo();
    }

    ofstream outFile2("Engineer.txt");
    if (outFile2.is_open()){
        for(auto& e: engineer){
            outFile2 << e.toString() <<endl;
        }
        outFile2.close();
    }
    else{
        cerr << "Engineer file can't open File" << endl;
    }

    ifstream readFile2("Engineer.txt");
    if (readFile2.is_open()){
        string line;
        while (getline(readFile2, line)){
            cout << line << endl;
        }
        readFile1.close();
    }

}



