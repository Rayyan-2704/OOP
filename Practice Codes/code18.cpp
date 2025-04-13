/* Operator Overloading: As Member Functions */
#include <iostream>
using namespace std;

class A
{
    int a;
    string s;

public:
    A(int A = 0, string S = "zero")
    {
        a = A;
        s = S;
    }
    void display()
    {
        cout << "a: " << a << ", s: " << s << endl;
    }

    A operator+(A operand2)
    {
        int resA = this->a + operand2.a;
        string resS = this->s + operand2.s;
        return A(resA, resS);
    }

    A operator++()
    {
        return A(1, "");
    }

    A operator++(int)
    {
        A oldVal = *this;
        // A oldVal(a, s);
        this->a++;
        this->s = this->s + "!";

        return oldVal;
    }
};

int main()
{
    A obj1(1, "one"), obj2(2, "two");
    A obj3 = obj2 + obj1;
    obj3 = obj1++;

    return 0;
}

/* Operator Overloading: As Friend Functions */
#include <iostream>
using namespace std;
class A
{
    int x;
    int y;

public:
    // add const to all aliases
    friend A operator+(int, const A &);
    friend A operator-(const A &, int);
    friend const ostream &operator<<(const ostream &out, const A &obj);

    A(int a, int b)
    {
        x = a;
        y = b;
    }

    A operator+(A &obj)
    {
        return A(x + obj.x, y + obj.y);
    }

    void display()
    {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

A operator-(const A &obj, int dec)
{
    return A(obj.x - dec, obj.y - dec);
}

A operator+(int inc, const A &obj)
{
    return A(obj.x + inc, obj.y + inc);
}

const ostream &operator<<(const ostream &out, const A &obj)
{
    cout << "Custom out:\nx: " << obj.x << ", y: " << obj.y << endl;
    return out;
}

int main()
{
    A obj1(1, 1), obj2(2, 2);
    obj1 = obj1 + obj2;
    obj1.display();
    obj1 = obj1 - 2;
    obj1.display();
    obj1 = 5 + obj1 - 1; // works now
    obj1.display();
    cout << obj1;
    return 0;
}