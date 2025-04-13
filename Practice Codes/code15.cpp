/* Practice Question */
#include <iostream>
#include <cmath>
using namespace std;

class SimpleCalculator
{
    int a, b;

public:
    void getDataSimple()
    {
        cout << "Enter the data of a: ";
        cin >> a;
        cout << "Enter the data of b: ";
        cin >> b;
    }

    void performOperationsSimple()
    {
        cout << "The value of a + b is " << (a + b) << endl;
        cout << "The value of a - b is " << (a - b) << endl;
        cout << "The value of a * b is " << (a * b) << endl;
        cout << "The value of a / b is " << (a / b) << endl;
    }
};

class ScientificCalculator
{
    int a;

public:
    void getDataScientific()
    {
        cout << "Enter the data of a: ";
        cin >> a;
    }

    void performOperationsScientific()
    {
        cout << "The value of cos(a) is " << (cos(a)) << endl;
        cout << "The value of sin(a) is " << (sin(a)) << endl;
        cout << "The value of tan(a) is " << (tan(a)) << endl;
        cout << "The value of exp(a) is " << (exp(a)) << endl;
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
};

int main()
{
    // SimpleCalculator simple_calc;
    // simple_calc.getDataSimple();
    // simple_calc.performOperationsSimple();

    // ScientificCalculator sci_calc;
    // sci_calc.getDataScientific();
    // sci_calc.performOperationsScientific();

    HybridCalculator h_calc;
    h_calc.getDataSimple();
    h_calc.performOperationsSimple();
    h_calc.getDataScientific();
    h_calc.performOperationsScientific();
    return 0;
}

/* Constructors in Derived Class */
#include <iostream>
using namespace std;

/*
Case 1:
class A : public B{
    // Order of execution of constructor ---> first B() then A()
};

Case 2:
class A : public B, public C{
    // Order of execution of constructor ---> first B() then C() and then A()
};

Case 3:
class A : public B, virtual public C{
    // Order of execution of constructor ---> first C() then B() and then A()
};
*/

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base 1 class constructor called" << endl;
    }

    void printData()
    {
        cout << "The value of data 1 is " << data1 << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base 2 class constructor called" << endl;
    }

    void printData()
    {
        cout << "The value of data 2 is " << data2 << endl;
    }
};

class Derived : public Base1, public Base2
{
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }

    void printData()
    {
        Base1 :: printData();
        Base2 :: printData();
        cout << "The value of derived 1 is " << derived1 << endl;
        cout << "The value of derived 2 is " << derived2 << endl;
    }
};

int main()
{
    Derived der(1, 3, 5, 7);
    der.printData();
    return 0;
}

/* Initialization List in Constructors */
#include <iostream>
using namespace std;

/*
Syntax for Initialization List:
constructor (argument-list) : initialization-section{
    // assignment + other code
}
*/

class Test
{
    int a, b;

public:
    // Test(int i, int j) : a(i), b(i + j)  ---> will work
    // Test(int i, int j) : a(i), b(2 * j)  ---> will work
    // Test(int i, int j) : a(i), b(a + j)  ---> will work
    // Test(int i, int j) : b(j), a(b + i)  ---> will NOT work as 'a' should be initialized first as it is declared first
    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor executed" << endl;
    }

    void display()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
    }
};

int main()
{
    Test t(4, 6);
    t.display();
    return 0;
}