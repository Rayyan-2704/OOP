/* Constructors in C++ */
/* Default Constructor (no parameters) Example */
#include <iostream>
#include <string>
using namespace std;

class Complex
{
    int a, b;

public:
    // Creating a constructor
    /* Constructor is a special member function with the same name as of the class.
    It is used to initialize the objects of the class. It is automatically invoked/called when an object is created */
    Complex(void); // ---> constructor declaration

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i." << endl;
    }
};

Complex :: Complex(void) // ---> Default constructor (no parameters)
{
    a = 10;
    b = 5;
}

int main()
{
    Complex c;
    c.printNumber();
    return 0;
}

// ***Characteristics of Constructors: ***
//  1. It should be declared in the public section of the class
//  2. They are automatically invoked whenever an object is created
//  3. They cannot return values as they do not have any return types
//  4. It can have default arguments
//  5. We cannot refer to their address

/* Parameterized Constructor (accepts parameter) Example */
#include <iostream>
#include <string>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int, int); // ---> constructor declaration

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i." << endl;
    }
};

Complex :: Complex(int x, int y) // ---> Parameterized constructor (accepts parameters)
{
    a = x;
    b = y;
}

int main()
{
    // Implicit call
    Complex a(4, 6);

    // Explicit call
    Complex b = Complex(7, 10);

    a.printNumber();
    b.printNumber();
    return 0;
}

/* Further Example */
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Point
{
    int x, y;
    friend float distanceBetweenPoints(Point p, Point q);

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void displayPoint()
    {
        cout << "The coordinate is (" << x << "," << y << ")" << endl;
    }
};

float distanceBetweenPoints(Point p, Point q)
{
    return sqrt((pow((q.x - p.x), 2) + pow((q.y - p.y), 2)));
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of point p: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of point q: ";
    cin >> x2 >> y2;

    Point p(x1, y1);
    p.displayPoint();

    Point q(x2, y2);
    q.displayPoint();

    cout << "The distance between the coordinates of point p and point q is: " << fixed << setprecision(2) << distanceBetweenPoints(p, q) << endl;
    return 0;
}

/* Example of a Constructor Overloading */
#include <iostream>
#include <string>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }

    Complex(int x)
    {
        a = x;
        b = 0;
    }

    Complex()
    {
        a = 0;
        b = 0;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i." << endl;
    }
};

int main()
{
    int x, y;
    cout << "Enter the 'a' and 'b' values of the complex number (a+ib): ";
    cin >> x >> y;

    Complex c1(x, y);
    c1.printNumber();

    Complex c2(5);
    c2.printNumber();

    Complex c3;
    c3.printNumber();
    return 0;
}