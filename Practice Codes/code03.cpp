/* Call by reference and call by value in C++ */
#include <iostream>
using namespace std;

int sum(int a, int b);
void swapPointers(int *x, int *y);
void swapReferenceVar(int &x, int &y);

int main()
{
    // int num1, num2;
    // cout << "Enter the first number: ";
    // cin >> num1;
    // cout << "Enter the second number: ";
    // cin >> num2;
    // int answer = sum(num1, num2);
    // cout << "The addition of " << num1 << " and " << num2 << " is " << answer << endl;

    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    // ***Swapping using call by reference through pointers***
    // cout << "The values before swapping of a and b are " << a << " and " << b << endl;
    // swapPointers(&a, &b);
    // cout << "The values after swappping of a and b are " << a << " and " << b << endl;

    // ***Swapping using call by reference through reference variables***
    cout << "The values before swapping of a and b are " << a << " and " << b << endl;
    swapReferenceVar(a, b);
    cout << "The values after swappping of a and b are " << a << " and " << b << endl;
    return 0;
}

int sum(int a, int b)
{
    // This function uses call by value
    return a + b;
}

void swapPointers(int *x, int *y)
{
    // This function uses call by reference using pointers
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapReferenceVar(int &x, int &y)
{
    // This function uses call by reference using reference variables
    int temp = x;
    x = y;
    y = temp;
}