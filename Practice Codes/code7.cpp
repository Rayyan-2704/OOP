/* Example 1: Static data members and static methods in a class */
#include <iostream>
using namespace std;

class Employee
{
    int id;
    static int count; // already initialized by 0
    // static int count = 1000 ---> this will give error

public:
    void setData(void)
    {
        cout << "Enter the ID of the employee: ";
        cin >> id;
        count++;
    }

    void getData(void)
    {
        cout << "The ID of employee is: " << id << endl;
        cout << "Total number of employees are: " << count << endl;
    }

    // Static method/function
    static void getCount(void)
    {
        // cout << id; ---> this gives error as a static function has access to other static functions and static data members only
        // Static methods can run without making any object for the class
        cout << "The value of count is " << count << endl;
    }
};

int Employee :: count;
// count is the static data member (Class variable) of "Employee" class & default value is 0
// If count needs to be incremented from a different value
// int Employee :: count = 1000;

int main()
{
    Employee rayyan, arhum, aamir;

    rayyan.setData();
    rayyan.getData();
    Employee :: getCount();

    arhum.setData();
    arhum.getData();
    Employee :: getCount();

    aamir.setData();
    aamir.getData();
    Employee :: getCount();

    return 0;
}

/* Example 2: Using an array of objects */
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int id;
    int salary;
    string name;

public:
    void setID()
    {
        cout << "Enter the name of the employee: ";
        cin >> name;
        cout << "Enter the ID of employee: ";
        cin >> id;
        salary = 250;
    }

    void getID()
    {
        cout << "The name of employee is: " << name << endl;
        cout << "The ID of this employee is: " << id << endl;
        cout << "Salary of this employee is: " << salary << endl;
    }
};

int main()
{
    Employee listEmployees[5];
    for (int i = 0; i < 5; i++)
    {
        listEmployees[i].setID();
    }
    cout << "Details of employees: " << endl;
    for (int i = 0; i < 5; i++)
    {
        listEmployees[i].getID();
    }
    return 0;
}

/* Example 3: Passing objects as function arguments */
#include <iostream>
#include <string>
using namespace std;

class complex
{
    int a;
    int b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void setDataBySum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }

    void printNumber()
    {
        cout << "Your complex number is: " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();

    c3.setDataBySum(c1, c2);
    c3.printNumber();
    return 0;
}