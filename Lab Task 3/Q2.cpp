#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth
{
    unsigned int totalCars;
    double totalAmount;

public:
    tollBooth()
    {
        totalCars = 0;
        totalAmount = 0;
    }

    void payingCar()
    {
        totalCars++;
        totalAmount += 0.50;
    }

    void nopayCar()
    {
        totalCars++;
    }

    void display()
    {
        cout << endl;
        cout << "The total number of cars that have gone by so far are " << totalCars << endl;
        cout << "The total amount of money collected so far is " << totalAmount << " cents" << endl;
    }
};

int main()
{
    tollBooth t1;
    char choice;
    cout << "----- Welcome to the Toll Booth system -----" << endl;
    cout << "Press \'P\' for a paying car and \'N\' for a non-paying car" << endl;
    cout << "Press the Esc key to display the total cars passed and total cash collected" << endl;
    while (1)
    {
        cout << endl
             << "Enter your choice: ";
        choice = _getch();

        switch (choice)
        {
        case 'P':
        case 'p':
            t1.payingCar();
            break;

        case 'N':
        case 'n':
            t1.nopayCar();
            break;

        case char(27):
            t1.display();
            cout << "Exiting the program..." << endl;
            return 0;
        }
    }
}