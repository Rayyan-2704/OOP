#include <iostream>
#include <cmath>
#include <exception>
#include <typeinfo>
using namespace std;

class NegativeNumberException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

double sqrt_custom(int num)
{
    if (num < 0)
    {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

double sqrt_custom(float num)
{
    if (num < 0)
    {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

double sqrt_custom(double num)
{
    if (num < 0)
    {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

template <class T>
T sqrt_custom(T num)
{
    if (typeid(T) != typeid(int) && typeid(T) != typeid(float) && typeid(T) != typeid(double))
    {
        throw InvalidTypeException();
    }

    return " ";
}

int main()
{
    try
    {
        cout << "sqrt(16) = " << sqrt_custom(16) << endl;
        cout << "sqrt(-9) = " << sqrt_custom(-9) << endl;
    }
    catch (const NegativeNumberException &e)
    {
        cout << "sqrt(-9): " << e.what() << endl;
    }
    catch (const InvalidTypeException &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << "sqrt(\"hello\"): " << sqrt_custom("hello") << endl;
    }
    catch (const NegativeNumberException &e)
    {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException &e)
    {
        cout << "sqrt(\"hello\"): " << e.what() << endl;
    }

    return 0;
}
