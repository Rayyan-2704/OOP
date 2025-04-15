#include <iostream>
using namespace std;

class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r) {}

    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() const override {
        cout << "This is Car's getDailyRate() overridden function." << endl;
        return rate;
    }

    void displayDetails() const override {
        cout << "\n----------- Displaying Car Details -----------" << endl;
        cout << "Model: " << model << " | Rate: $" << rate << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double r) : Vehicle(m, r) {}

    double getDailyRate() const override {
        cout << "This is Bike's getDailyRate() overriden function." << endl;
        return rate;
    }

    void displayDetails() const override {
        cout << "----------- Displaying Bike Details -----------" << endl;
        cout << "Model: " << model << " | Rate: $" << rate << endl;
    }
};

int main(){
    Vehicle *v[2] = {
        new Car("Ferrari LaFerrari", 25000.50),
        new Bike("BMW S1000RR", 1500.754)
    };

    for(int i = 0; i < 2; i++) {
        cout << endl;
        double rate = v[i]->getDailyRate();
        cout << "Rate: $" << rate << endl;
        v[i]->displayDetails();
    }

    for(int i =0; i < 2; i++) {
        delete v[i];
    }
    return 0;
}