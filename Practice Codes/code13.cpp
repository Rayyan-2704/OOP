/* Protected Access Modifier */
#include <iostream>
using namespace std;

class Base
{
protected:
    int a;

private:
    int b;
};

/*
                        Public Derivation       Private Derivation      Protected Derivation
1. Private Members:       Not Inherited            Not Inherited          Not Inherited
2. Protected Members:     Protected                Private                Protected
3. Public Members:        Public                   Private                Protected
*/

class Derived : protected Base
{
};

int main()
{
    Base b;
    Derived d;
    // cout << d.a;  ---> will not work as 'a' is protected in both 'Base' and 'Derived' class
    return 0;
}

/*
Types of Inheritance:
1. Single Inheritance:-  A ---> B
2. Multiple Inheritance:-  A + B ---> C
3. Hierarchical Inheritance:-  A ---> B + C
4. Multilevel Inheritance:-  A ---> B ---> C
5. Hybrid Inheritance:-  A ---> (B + C) ---> D  (multiple inheritances)
*/

/* Example of a Multilevel Inheritance */
#include <iostream>
using namespace std;

class Student
{
protected:
    int rollNo;

public:
    void setRollNo(int);
    void getRollNo(void);
};

void Student :: setRollNo(int num)
{
    rollNo = num;
}

void Student :: getRollNo(void)
{
    cout << "The roll number is " << rollNo << endl;
}

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void setMarks(float, float);
    void getMarks(void);
};

void Exam :: setMarks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}

void Exam :: getMarks(void)
{
    cout << "The marks obtained in maths are " << maths << endl;
    cout << "The marks obtained in physics are " << physics << endl;
}

class Result : public Exam
{
    float percentage;

public:
    void displayResult()
    {
        getRollNo();
        getMarks();
        cout << "Your percentage is " << (maths + physics) / 2 << "%" << endl;
    }
};

int main()
{
    /*
    1. Multilevel Inheritance is inheriting B from A and C from B.
    2. A is the base class for B and B is the base class for C.
    3. A --> B --> C is called the Inheritance Path
    */
    Result rayyan;
    rayyan.setRollNo(687);
    rayyan.setMarks(87, 90);
    rayyan.displayResult();
    return 0;
}

/* Example of a Multiple Inheritance */
#include <iostream>
using namespace std;

/*
Syntax for Multiple Inheritance
class Derived : visibility-mode Base1, visibility-mode Base2{
    // Class body
};
*/

class Base1
{
protected:
    int base1_int;

public:
    void set_base1_int(int a)
    {
        base1_int = a;
    }
};

class Base2
{
protected:
    int base2_int;

public:
    void set_base2_int(int b)
    {
        base2_int = b;
    }
};

class Derived : public Base1, public Base2
{
public:
    void display()
    {
        cout << "The value of base 1 is " << base1_int << endl;
        cout << "The value of base 2 is " << base2_int << endl;
        cout << "The sum of the two bases is " << (base1_int + base2_int) << endl;
    }
};

/*
The inherited Derived class will look something like this:
Data members:
    base1_int ---> protected
    base2_int ---> protected

Member functions:
    set_base1_int() ---> public
    set_base2_int() ---> public
    display() ---> public
*/

int main()
{
    Derived rayyan;
    rayyan.set_base1_int(5);
    rayyan.set_base2_int(10);
    rayyan.display();
    return 0;
}