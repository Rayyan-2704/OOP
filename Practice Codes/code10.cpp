/* Example of a Parameterized Constructor with Default Argument */
#include <iostream>
using namespace std;

class Simple
{
    int data1, data2;

public:
    Simple(int a, int b = 9)
    {
        // b is a default argument here
        // If no value of b is passed onto the function, the default value of 9 will be used
        data1 = a;
        data2 = b;
    }

    void printData()
    {
        cout << "The value of datas are: " << data1 << " and " << data2 << endl;
    }
};

int main()
{
    int x, y;
    cout << "Enter the values of the two datas: ";
    cin >> x >> y;
    Simple s(x, y);
    s.printData();

    Simple c(1);
    c.printData();
    return 0;
}

/* Further Example */
#include <iostream>
using namespace std;

class Complex
{
    int a, b;
    friend void sumOfComplex(Complex c1, Complex c2);

public:
    Complex(int x, int y = 10)
    {
        a = x;
        b = y;
    }

    void printComplex()
    {
        cout << "Your complex number is: " << a << " + " << b << "i." << endl;
    }
};

void sumOfComplex(Complex c1, Complex c2)
{
    int sum_a = c1.a + c2.a;
    int sum_b = c1.b + c2.b;
    cout << "The sum of the two complexes is: " << sum_a << " + " << sum_b << "i." << endl;
}

int main()
{
    int x, y;
    cout << "Enter the a and b values of the first complex (a+bi): ";
    cin >> x >> y;

    Complex c1(x, y);
    c1.printComplex();
    Complex c2(4);
    c2.printComplex();

    sumOfComplex(c1, c2);
    return 0;
}

/* Dynamic Initialization of Objects using Constructors */
#include <iostream>
using namespace std;

class BankDeposit
{
    int principle, years;
    float interestRate, returnValue;

public:
    BankDeposit() {} // Default Blank Constructor (sets garbage value)
    BankDeposit(int p, int y, float r); // r can be a value like 0.04 (4% in decimal)
    BankDeposit(int p, int y, int r);   // r can be a value like 14 (14%)
    void display();
};

BankDeposit :: BankDeposit(int p, int y, float r)
{
    principle = p;
    years = y;
    interestRate = r;
    returnValue = principle;

    // Compound Interest
    for (int i = 0; i < y; i++)
    {
        returnValue *= (1 + interestRate);
    }
}

BankDeposit :: BankDeposit(int p, int y, int r)
{
    principle = p;
    years = y;
    interestRate = float(r) / 100;
    returnValue = principle;

    // Compound Interest
    for (int i = 0; i < y; i++)
    {
        returnValue *= (1 + interestRate);
    }
}

void BankDeposit :: display()
{
    cout << endl << "The principle amount was " << principle << ". ";
    cout << "The return value after " << years << " year(s) is " << returnValue << "." << endl;
}

int main()
{
    BankDeposit bd1, bd2, bd3;
    // A default constructor would be needed in this situation as when an object is made, the compiler always calls a constructor
    // The other two constructors cannot be called as they require arguments for which we have not taken input yet
    // Here, the default constructor is called for all three objects
    int p, y, R;
    float r;

    cout << endl << "Enter the values of principle amount (p), years (y) and interest rate as a decimal (r): ";
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r); // The default constructor has been overwritten for bd1 object
    bd1.display();

    cout << endl << "Enter the values of principle amount (p), years (y) and interest rate as a percentage (R): ";
    cin >> p >> y >> R;
    bd2 = BankDeposit(p, y, R); // The default constructor has been overwritten for bd2 object
    bd2.display();

    bd3.display(); // ---> prints out garbage value as for bd3 object, the default constructor has not been overwritten
    return 0;
}