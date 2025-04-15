#include <iostream>
using namespace std;

class SmartDevice {
public:
    SmartDevice() {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() const = 0;

    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
    bool isOn;
    int brightness;

public:
    LightBulb(bool status, int b) : isOn(status), brightness(b) {
        while(brightness < 0 || brightness > 100){
            cout << "Invalid brightness level. Enter brightness levelo between 0% to 100%: ";
            cin >> brightness;
        }
    }

    void turnOn() override {
        isOn = true;
    }

    void turnOff() override {
        isOn = false;
    }

    bool getStatus() const override {
        return isOn;
    }
};

class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;

public:
    Thermostat(bool status, double t) : isOn(status), temperature(t) {}

    void turnOn() override {
        isOn = true;
    }

    void turnOff() override {
        isOn = false;
    }

    bool getStatus() const override {
        return isOn;
    }
};

int main(){
    SmartDevice *sd[2] = {
        new LightBulb(true, 90),
        new Thermostat(false, 26.5)
    };

    for(int i = 0; i < 2; i++) {
        cout << "\nDevice Activity Status: " << (sd[i]->getStatus() ? "On" : "Off") << endl;
        sd[i]->turnOn();
        sd[i]->turnOff();
        cout << "Device Activity Status: " << (sd[i]->getStatus() ? "On" : "Off") << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete sd[i];
    }
    return 0;
}