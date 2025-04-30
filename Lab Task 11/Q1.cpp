#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InvalidValueException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void validateUserAge(const int age)
{
    if (age < 0 || age > 120)
    {
        throw InvalidValueException();
    }

    cout << "Age " << age << " is valid!" << endl;
}

int main()
{
    int age;
    cout << "Enter the age: ";
    cin >> age;

    try
    {
        validateUserAge(age);
    }
    catch (const InvalidValueException &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}