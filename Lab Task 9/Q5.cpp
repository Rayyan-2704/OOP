#include <iostream>
#include <string>
using namespace std;

class Activity{
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity{
    double distance;
    double time;

public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() override {
        return (distance / time) * 10;  // Assuming 10 calories are burned per km per hour
    }
};

class Cycling : public Activity{
    double speed;
    double time;

public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() override {
        return speed * 30;  // Assuming 30 calories are burned per km per hour
    }
};

int main(){
    Running run(7.0, 2.5);
    Cycling cycle(25.0, 3.5);

    cout << "Calories burned while running: " << run.calculateCaloriesBurned() << " calories" << endl;
    cout << "Calories burned while cycling: " << cycle.calculateCaloriesBurned() << " calories" << endl;

    return 0;
}