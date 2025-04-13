/* Pointers, double pointers, struct, union and enum in C++ */
#include <iostream>
using namespace std;

typedef struct
{
    int ID;
    float salary;
} Employee;

union money
{
    int rice;
    int veg;
    float pc;
};

int main()
{
    //	int a = 3;
    //	int *b = &a;
    //	cout << "The address of a using the variable a is: " << &a << endl;
    //	cout << "The address of a using the variable b is: " << b << endl;
    //	cout << "The value of a using the variable a is: " << a << endl;
    //	cout << "The value of a using the variable b is: " << *b << endl;
    //	cout << "The address of b is: " << &b << endl << endl;
    //
    //	int **c = &b;
    //	cout << "The value of b (address of a) is: " << *c << endl;
    //	cout << "The address of b is: " << c << endl;
    //	cout << "The value of a is: " << **c << endl;

    //  **Structure example below**
    //	Employee rayyan;
    //	rayyan.ID = 10001;
    //	rayyan.salary = 40.56;
    //	cout << "ID of Rayyan is " << rayyan.ID << endl;
    //	cout << "Salary of Rayyan is " << rayyan.salary << endl;
    //  Employee arhum = {1002, 321.78};
    //	cout << "ID of Arhum is " << arhum.ID << endl;
    //	cout << "Salary of Arhum is " << arhum.salary << endl;

    //  **Union example below**
    //  **Union is used when only one member from the defined datatype has to be used (unlike struct which uses all the members)**
    //	union money m1;
    //	m1.rice = 34;
    //	m1.pc = 90.56;
    //	cout << m1.rice <<endl;  //The actual value of rice wont print, as we are using m1.pc above from the union datatype. Result is garbage value
    //	cout << m1.pc <<endl;

    //  **Enum example below**
    //  ***enum means to enumerate, meaning allocating numbers starting from 0 to each member
    //	enum Meal{breakfast, lunch, dinner};
    //	Meal m1 = lunch;
    //	cout << m1 << endl;
    //	Meal m2 = breakfast;
    //	cout << m2 << endl;

    return 0;
}