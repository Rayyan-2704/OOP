/* Default arguments and recursive functions in C++ */
#include <iostream>
using namespace std;

int product(int num1, int num2)
{
    return num1 * num2;
}

float moneyReceived(const int currentMoney, float factor = 1.04)
{
    // currentMoney++; ----> this is not valid as it is a constant argument

    // factor here is used as a default argument, if no value of factor is passed in the main() then the default value of 1.04 will be used
    // default argument has to be written last
    return currentMoney * factor;
}

int factorial(int n)
{
    // Example of a recursive function
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    // int a, b;
    // cout << "Enter the values of a and b: " << endl;
    // cin >> a >> b;
    // cout << "The product of a and b is " << product(a, b);

    // int money = 10000;
    // cout << "If you have " << money << " Rs in your bank account, you will receive a " << moneyReceived(money) << " Rs after 1 year" << endl;
    // cout << "For VIP: If you have " << money << " Rs in your bank account, you will receive a " << moneyReceived(money, 1.10) << " Rs after 1 year" << endl;

    int num;
    cout << "Enter the number you want the factorial for: ";
    cin >> num;
    cout << num << "! = " << factorial(num);
    return 0;
}