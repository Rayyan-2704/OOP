/* Q1: Write a C++ program to check whether a given number is prime or not. Allow
the user to input a number and display whether it's prime or not? */

#include <iostream>
using namespace std;

int main()
{
    int num, flag = 0;
    cout << "Enter a number to check whether it's prime or not: ";
    cin >> num;

    for (int i = 2; i < (num / 2); i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "The number entered " << num << " is not a prime number." << endl;
    }
    else
    {
        cout << "The number entered " << num << " is a prime number." << endl;
    }
    return 0;
}