/* Example 1: Use of a friend function in a class */
/* A friend function is allowed to access the private members of the class, but it is NOT in the scope of the class 
   Usually, contains the objects as the arguments. Can be declared in the public or private section of class */
#include <iostream>
#include <string>
using namespace std;

class Complex
{
    int a, b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }

    friend Complex sumComplex(Complex o1, Complex o2); // Declaration of a friend function (NOT a member function)
};

Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    // --> the above line would have given an error (as a and b are private members), if we hadn't declared this function as a friend function in the class
    return o3;
}

int main()
{
    Complex c1, c2, sum;

    c1.setNumber(1, 4);
    c2.setNumber(5, 8);
    c1.printNumber();
    c2.printNumber();

    sum = sumComplex(c1, c2);
    // c1.sumComplex() ---> invalid as sumComplex() is not a member function
    sum.printNumber();
    return 0;
}

/* Example 2: Friend Classes and Member Friend Functions */
#include <iostream>
using namespace std;

// Forward declaration of the "Complex" class which will be defined later on
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    // **Below lines of code are incorrect as the compiler isn't able to identify the members of the "Complex" class which is yet to be defined**
    // int sumOfRealComplex(Complex o1, Complex o2)
    // {
    //     return (o1.a + o2.a);
    // }

    // **So we will only declare the function as for now and then later on write the whole function after defining the "Complex" class**
    int sumOfRealComplex(Complex , Complex );
    int sumOfCompComplex(Complex , Complex );
};

class Complex
{
    int a, b;

    // Individually declaring functions of "Calculator" class as friends (not effective)
    // friend int Calculator :: sumOfRealComplex(Complex o1, Complex o2);
    // friend int Calculator :: sumOfCompComplex(Complex o1, Complex o2);

    // Effective method: Declaring the entire "Calculator" class as friend
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// Now defining the function of "Calculator" class
int Calculator :: sumOfRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator :: sumOfCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);

    Calculator calc;
    cout << "The sum of real components of o1 and o2 is " << calc.sumOfRealComplex(o1, o2) << endl;
    cout << "The sum of complex components of o1 and o2 is " << calc.sumOfCompComplex(o1, o2) << endl;
    return 0;
}

/* Further example */
#include <iostream>
#include <string>
using namespace std;

class Y;

class X
{
    int data;
    friend void add(X, Y);

public:
    void setValue(int value)
    {
        data = value;
    }
};

class Y
{
    int num;
    friend void add(X, Y);

public:
    void setData(int value)
    {
        num = value;
    }
};

void add(X o1, Y o2)
{
    cout << "Sum of data of X and Y objects is " << o1.data + o2.num << endl;
}

int main()
{
    X a1;
    Y b1;
    a1.setValue(3);
    b1.setData(5);
    add(a1, b1);
    return 0;
}

/* Further example */
#include <iostream>
#include <string>
using namespace std;

class c2;

class c1
{
    int val1;
    friend void swapData(c1 &, c2 &);

public:
    void setData(int a)
    {
        val1 = a;
    }

    void displayData()
    {
        cout << val1;
    }
};

class c2
{
    int val2;
    friend void swapData(c1 &, c2 &);

public:
    void setData(int a)
    {
        val2 = a;
    }

    void displayData()
    {
        cout << val2;
    }
};

// Call by reference using reference variables
void swapData(c1 &x, c2 &y)
{
    int temp;
    temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}

int main()
{
    c1 oc1;
    c2 oc2;
    oc1.setData(34);
    oc2.setData(47);

    cout << "The values of oc1 and oc2 before swapping are: ";
    oc1.displayData();
    cout << " and ";
    oc2.displayData();
    cout << " respectively." << endl;

    swapData(oc1, oc2);

    cout << "The values of oc1 and oc2 after swapping are: ";
    oc1.displayData();
    cout << " and ";
    oc2.displayData();
    cout << " respectively." << endl;

    return 0;
}