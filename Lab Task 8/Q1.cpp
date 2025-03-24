#include <iostream>
using namespace std;

class Device{
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

public:
    Device(string id, string type, double pR, bool s) : deviceID(id), deviceType(type), powerRating(pR), status(s) {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

};

int main(){

    return 0;
}


/*
Account operator=(Account &obj, double balance){
    obj.amount -= 2000;
    return Amount(this->amount + 2000, this->accountNumber, this->accountHolderName)
}*/
