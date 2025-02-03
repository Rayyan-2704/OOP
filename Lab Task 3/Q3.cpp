#include <iostream>
using namespace std;

class FAST
{
    static int counter;
    int serialNumber;

public:
    FAST()
    {
        serialNumber = (++counter);
    }

    void displaySerialnumber()
    {
        cout << "I am object number " << serialNumber << "." << endl;
    }

    static void showCounter()
    {
        cout << "The total number of objects created so far are " << counter << "." << endl;
    }
};

int FAST :: counter = 0;

int main()
{
    FAST obj1, obj2, obj3;
    obj1.displaySerialnumber();
    obj2.displaySerialnumber();
    obj3.displaySerialnumber();
    FAST :: showCounter();
    return 0;
}