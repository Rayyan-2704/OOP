/* Single Inheritance in OOP C++ */
#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inputID)
    {
        id = inputID;
        salary = 30000;
    }
    Employee() {} // default constructor
};

// Derived Class
/*
Syntax:
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc
};

Note:
1. Default visibilty mode is private
2. Public Visibility Mode: Public members of the base class becomes public members of the derived class
3. Private Visibility Mode: Public members of the base class becomes private members of the derived class
4, Private members of the base class are never inherited
*/

class Programmer : public Employee
{
public:
    int languageCode;

    Programmer(int inputID)
    {
        id = inputID;
        languageCode = 9;
    }

    /* Constructor for programmer can also be written like this:
    Programmer(int inputID) : Employee(inputID) { // No need for the employee default constructor in this scenario
        languageCode = 9;
    } */
};

int main()
{
    Employee rayyan(101), arhum(102);
    cout << rayyan.salary << endl;
    cout << arhum.salary << endl;
    Programmer Ray(105); // When the progammer object is initialized, it calls its constructor and since it is a derived class of Employee, it also calls the Employee constructor hence a default constructor is needed here
    cout << Ray.languageCode << "\t" << Ray.id << endl;
    return 0;
}

// /* Further Single Inheritance Example */
#include <iostream>
using namespace std;

class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    void setData();
    int getData1();
    int getData2();
};

void Base :: setData(void)
{
    data1 = 10;
    data2 = 20;
}

int Base :: getData1()
{
    return data1;
}

int Base :: getData2()
{
    return data2;
}

class Derived : public Base
{
    int data3;

public:
    void process();
    void display();
};

void Derived :: process()
{
    data3 = data2 * getData1();
}

void Derived :: display()
{
    cout << "Value of data 1 is " << getData1() << endl;
    cout << "Value of data 2 is " << data2 << endl;
    cout << "Value of data 3 is " << data3 << endl;
}

int main()
{
    Derived der;
    der.setData();
    der.process();
    der.display();
    return 0;
}

/* Same Example as before, but privately inherited from "Base" class here */
#include <iostream>
using namespace std;

class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    void setData();
    int getData1();
    int getData2();
};

void Base :: setData(void)
{
    data1 = 10;
    data2 = 20;
}

int Base :: getData1()
{
    return data1;
}

int Base :: getData2()
{
    return data2;
}

class Derived : private Base // inheriting privately now 
{
    int data3;

public:
    void process();
    void display();
};

void Derived :: process()
{
    setData(); // ---> can call setData() here instead of main
    data3 = data2 * getData1();
}

void Derived :: display()
{
    cout << "Value of data 1 is " << getData1() << endl;
    cout << "Value of data 2 is " << data2 << endl;
    cout << "Value of data 3 is " << data3 << endl;
}

int main()
{
    Derived der;
    // der.setData(); --> since we privately inherited "Base", we cannot directly call its member functions in main()
    der.process();
    der.display();
    return 0;
}