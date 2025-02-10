/* You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
    --> `carID` (int)
    --> `model` (string)
    --> `year` (int)
    --> `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
    --> `rentCar()`: Marks the car as rented.
    --> `returnCar()`: Marks the car as available.
    --> `isVintage()`: Returns `true` if the car's year is before 2000.
5. Create a few `Car` objects and test the methods. */

#include <iostream>
using namespace std;

class Car
{
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car()
    {
        carID = 0;
        model = " ";
        year = 0;
        isRented = false;
    }

    Car(int carID, string model, int year, bool isRented)
    {
        this->carID = carID;
        this->model = model;
        this->year = year;
        this->isRented = isRented;
    }

    void rentCar()
    {
        if (isRented)
        {
            cout << "The car \"" << model << "\" is already marked as rented." << endl;
            return;
        }

        isRented = true;
        cout << "The car \"" << model << "\" has been rented successfully." << endl;
    }

    void returnCar()
    {
        if (!(isRented))
        {
            cout << "The car \"" << model << "\" is already available." << endl;
            return;
        }

        isRented = false;
        cout << "The car \"" << model << "\" has been marked as available successfully." << endl;
    }

    bool isVintage()
    {
        if (year < 2000)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        cout << endl << "Car ID: " << carID << " | Car Model: " << model << " | Year: " << year << endl;
        cout << "Rented: " << (isRented ? "Yes" : "No") << endl;
    }
};

int main()
{
    Car c1, c2, c3, c4, c5;

    c1 = Car(782, "Ferrari LaFerrari", 2013, false);
    c1.display();
    c1.rentCar();
    c1.rentCar();
    c1.returnCar();
    c1.returnCar();
    c1.display();
    cout << "Vintage: " << (c1.isVintage() ? "Yes" : "No") << endl;

    c2 = Car(687, "Ford GT40", 1965, true);
    c2.display();
    c2.rentCar();
    c2.returnCar();
    c2.display();
    cout << "Vintage: " << (c2.isVintage() ? "Yes" : "No") << endl;

    c3 = Car(123, "Mercedes 300SL", 1957, false);
    c3.display();
    c3.rentCar();
    c3.returnCar();
    c3.display();
    cout << "Vintage: " << (c3.isVintage() ? "Yes" : "No") << endl;

    c4 = Car(456, "Bugatti Veyron", 2006, true);
    c4.display();
    c4.rentCar();
    c4.returnCar();
    c4.display();
    cout << "Vintage: " << (c4.isVintage() ? "Yes" : "No") << endl;

    c5.display();
    return 0;
}
