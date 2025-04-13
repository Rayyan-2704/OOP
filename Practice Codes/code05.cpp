/* Basic beginner OOP code */
#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a1, int b1, int c1); // Declaration
    void getData()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
};

void Employee :: setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee rayyan;
    // rayyan.a = 1; ---> this will give error as a is private
    rayyan.d = 7;
    rayyan.e = 10;
    rayyan.setData(1, 2, 4);
    rayyan.getData();
    return 0;
}


/* Below is an example code written by myself */
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
    float salary;
    int teacherID;

public:
    string first_name;
    string last_name;
    int hoursTaught;
    void setData(float sal, int ID); // Also called setter function
    void getData() // Also called getter function
    {
        cout << "First name: " << first_name << endl;
        cout << "Last name: " << last_name << endl;
        cout << "Hours taught: " << hoursTaught << endl;
        cout << "Salary: " << salary << endl;
        cout << "Teacher ID: " << teacherID << endl;
    }
};

void Teacher :: setData(float sal, int ID)
{
    salary = sal;
    teacherID = ID;
}

int main()
{
    Teacher t1; // ---> t1 here is an object of the "Teacher" class 
    float sal;
    int ID;
    cout << "Enter the first name of the teacher: ";
    cin >> t1.first_name;
    cout << "Enter the last name of the teacher: ";
    cin >> t1.last_name;
    cout << "Enter the hours taught by the teacher: ";
    cin >> t1.hoursTaught;
    cout << "Enter the salary of the teacher: ";
    cin >> sal;
    cout << "Enter the ID of the teacher: ";
    cin >> ID;
    t1.setData(sal, ID);
    t1.getData();
    return 0;
}