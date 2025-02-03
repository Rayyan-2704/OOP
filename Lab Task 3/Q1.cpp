#include <iostream>
using namespace std;

class Time
{
    int hours, minutes, seconds;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void displayTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    Time addTime(const Time &a, const Time &b)
    {
        Time total;
        total.hours = a.hours + b.hours;
        total.minutes = a.minutes + b.minutes;
        total.seconds = a.seconds + b.seconds;

        if (total.minutes >= 60)
        {
            total.hours++;
            total.minutes -= 60;
        }

        if (total.seconds >= 60)
        {
            total.minutes++;
            total.seconds -= 60;
        }
        return total;
    }
};

int main()
{
    int h1, m1, s1, h2, m2, s2;
    cout << "Enter the hours, minutes and seconds for time 1 respectively: ";
    cin >> h1 >> m1 >> s1;

    cout << "Enter the hours, minutes and seconds for time 2 respectively: ";
    cin >> h2 >> m2 >> s2;

    Time t1(h1, m1, s1), t2(h2, m2, s2), t3;
    cout << "Time 1:- ";
    t1.displayTime();
    cout << "Time 2:- ";
    t2.displayTime();
    t3 = t3.addTime(t1, t2);
    cout << "The added time is ";
    t3.displayTime();
    return 0;
}