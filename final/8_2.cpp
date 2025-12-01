#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Vehicle{
    protected:
        string brand;
        int speed;
    public:
        virtual void displayInfo() = 0;
        void setSpeed(int s){this->speed = s;};
        virtual string toString(){
            return "Brand: " + brand + " Speed: " + to_string(speed);
        };

        Vehicle(string brand):brand(brand){};
};

class Car : public Vehicle{
    private:
        int doors;
    public:
        void displayInfo()override{
            cout << "Brand: " << brand << " Speed: " << speed << " Doors: " << doors << endl;
        };
        string toString()override{
            string base = Vehicle::toString();
            return base + " Doors: " + to_string(doors);
        };

        Car(string brand, int doors):Vehicle(brand), doors(doors){};
};

class Bike : public Vehicle{
    private:
        bool hasCarrier;
    public:
        void displayInfo()override{
            cout << "Brand: " << brand << " Speed: " << speed << " hasCarrier: " << boolalpha << hasCarrier << endl;
        };
        string toString()override{
            string base = Vehicle::toString();
            return base + " HasCarrier: " + (hasCarrier ? "true" : "false");
        };

        Bike(string brand, bool hasCarrier):Vehicle(brand), hasCarrier(hasCarrier){};

};

int main(){
    vector<Car> car;
    vector<string> carBrand ={"kia", "hyundai", "kg", "audi", "bmw"};
    vector<int> doors = {4, 4, 4, 2, 2};
    vector<int> carSpeed = {120, 150, 170, 180, 180};

    vector<Bike> bike;
    vector<string> bikeBrand = {"sam", "smart", "atex", "alton", "unkown"};
    vector<bool> carrier = {true, true, false, false, true};
    vector<int> bikeSpeed = {5, 7, 2, 4, 2};

    for (size_t i = 0; i < carBrand.size(); ++i) {
        car.push_back(Car(carBrand[i], doors[i]));
        car[i].setSpeed(carSpeed[i]);
        // car[i].displayInfo();
    }
    
    for (size_t i = 0; i < bikeBrand.size(); ++i) {
        bike.push_back(Bike(bikeBrand[i], carrier[i]));
        bike[i].setSpeed(bikeSpeed[i]);
        // bike[i].displayInfo();
    }

    ofstream outFile1("Car.txt");
    if (outFile1.is_open()){
        for(auto& c: car){
            outFile1 << c.toString() <<endl;
        }
        outFile1.close();
    }
    else{
        cerr << "Car file can't open File" << endl;
    }

    cout << "Car" << endl;
    ifstream readFile1("Car.txt");
    if (readFile1.is_open()){
        string line;
        while (getline(readFile1, line)){
            cout << line << endl;
        }
        readFile1.close();
    }

    ofstream outFile2("Bike.txt");
    if (outFile2.is_open()){
        for(auto& b : bike){
            outFile2 << b.toString() << endl;
        }
        outFile2.close();
    }
    else{
        cerr << "Bike file can't open File" << endl;
    }

    cout << "\nBike" << endl; 
    ifstream readFile2("Bike.txt");
    if (readFile2.is_open()){
        string line;
        while (getline(readFile2, line)){
            cout << line << endl;
        }
        readFile2.close();
    }

}



