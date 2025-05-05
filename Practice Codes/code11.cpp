/* Copy Constructor */
#include <iostream>
using namespace std;

class Number
{
    int a;

public:
    Number() // Default constructor
    {
        a = 0;
    }

    Number(int num)
    {
        a = num;
    }

    // When there is no copy constructor, the compiler supplies it's own copy constructor
    Number(Number &obj) // ---> Copy constructor
    {
        cout << "Copy constructor called." << endl;
        a = obj.a;
    }

    void display()
    {
        cout << "The number for this object is " << a << endl;
    }
};

int main()
{
    Number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();

    Number z1(z);  // Copy constructor invoked
    z1.display();

    z2 = z;  // Copy constructor not invoked
    z2.display();

    Number z3 = z;  // Copy constructor invoked
    z3.display();

    Number z4 = Number(z);  // Copy constructor invoked
    z4.display();
    return 0;
}

/* Destructor Example */
// Destructor never takes an argument nor returns any value
#include <iostream>
using namespace std;

int count = 0;

class num
{
public:
    num()
    {
        count++;
        cout << "This is the time when my constructor is called for object number " << count << endl;
    }

    // Destructor
    ~num()
    {
        cout << "This is the time when my destructor is called for object number " << count << endl;
        count--;
    }
};

int main()
{
    cout << "Inside main function now" << endl;
    cout << "Creating our first object" << endl;
    num n1;
    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, num3;
        cout << "Exiting this block" << endl;
    }
    cout << "Back to main" << endl;
    cout << "Exiting the program" << endl;
    return 0;
}

/* Shallow Copy & Deep Copy Example */
#include <iostream>
using namespace std;

class Info{
public:
    int *data;

    Info(int val){
        data = new int(val);
    }

    // Shallow Copy Constructor (Default Copy Constructor)
    // Info(const Info &other){
    //     data = other.data;  // copying the address, NOT the value
    // }

    // Deep Copy Constructor
    Info(const Info &other){
        data = new int(*(other.data));  // allocating new memory and copying the value
    }

    ~Info(){
        delete data;  //Incase of a shallow copy, this will result in double deletion. For a deep copy, the issue won't arise
    }
};

int main(){
    Info obj1(10);
    Info obj2 = obj1;

    cout << "The data of object 1: " << *(obj1.data) << endl;
    cout << "The data of object 2: " << *(obj2.data) << endl;
    return 0;
}

/* Further Example */
#include <iostream>
using namespace std;

class Test{
    int *x;
    float y;

public:
    // Default Constructor
    Test(){
        // this->x = new int(10); ---> same thing as below
        this->x = new int;
        *(this->x) = 10;
        this->y = 9.99;
    }

    // Parameterized Constructor
    Test(int x, float y){
        // this->x = new int(x); ---> same thing as below
        this->x = new int;
        *(this->x) = x;
        this->y = y;
    }

    // Deep Copy Constructor
    Test(const Test & copy){
        // this->x = new int(*(copy.x)); ---> same thing as below
        this->x = new int;
        *(this->x) = *(copy.x);
        this->y = copy.y;
    }

    ~Test(){
        delete x;
    }

    void setX(int _x){
        *(this->x) = _x;
    }

    void display(){
        cout << *(this->x) << "  " << this->y << endl;
    }
};

int main(){
    Test obj(20, 15.5);  // Calls parameterized constructor
    obj.display();

    Test obj2(obj);  // Calls copy constructor
    obj2.setX(50);   // Modify obj2, obj remains unchanged

    obj.display();   // obj remains the same
    obj2.display();  // obj2 reflects the change
    return 0;
}
