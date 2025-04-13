/* Ambiguity Resolution in Inheritance */
#include <iostream>
using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "Hello, how are you?" << endl;
    }
};

class Base2
{
public:
    void greet()
    {
        cout << "Hi, it's a pleasure to meet you!" << endl;
    }
};

class Derived : public Base1, public Base2
{
    int a;

public:
    // Resolving the ambiguity by specifying to invoke the Base1 greet() function
    void greet()
    {
        Base1 :: greet();
    }
};

class B
{
public:
    void say()
    {
        cout << "Hello world" << endl;
    }
};

class D : public B
{
public:
    // this say() function will overwrite the inherited say() function from base "B" class
    void say()
    {
        cout << "Hello fellow programmers" << endl;
    }
};

int main()
{
    // ***Ambiguity 1***
    // Base1 base1obj;
    // Base2 base2obj;
    // base1obj.greet();
    // base2obj.greet();
    // Derived d;

    // /* Before resolving the ambiguity */
    // // d.greet(); ---> Ambiguity arises as the compiler is not sure which greet() function to invoke from both the base class

    // /* After resolving the ambiguity */
    // d.greet();

    // ***Ambiguity 2***
    D obj;
    obj.say();
    return 0;
}

/* Example of a Virtual Base Class */
/* A virtual base class in C++ is used to prevent multiple copies of a base class when inherited by multiple derived classes. */
#include <iostream>
using namespace std;

class Student{
protected:
    int rollNo;

public:
    void setNumber(int a){
        rollNo = a;
    }

    void displayNum(){
        cout << "Your roll number is " << rollNo << endl;
    }
};

// Can also write public virtual 
class Tests : virtual public Student{
protected:
    float maths, physics;

public:
    void setMarks(float m1, float m2){
        maths = m1;
        physics = m2;
    }

    void displayMarks(){
        cout << "Your test marks are as follows" << endl
             << "Maths: " << maths << endl
             << "Physics: " << physics << endl;
    }
};

class Sports : virtual public Student{
protected:
    float score;

public:
    void setScore(float s){
        score = s;
    }

    void displayScore(){
        cout << "Your PE score is " << score << endl;
    }
};

class Result : public Tests, public Sports{
private:
    float total;

public:
    void display(){
        total = maths + physics + score;
        displayNum();
        displayMarks();
        displayScore();
        cout << "Your total score is " << total << endl;
    }
};

int main(){
    Result ray;
    ray.setNumber(687);
    ray.setMarks(87.4, 84.3);
    ray.setScore(9);
    ray.display();
    return 0;
}

/* Further Example */
#include<iostream>
using namespace std;

// Base Class
class A {
public:
    int a = 0;
    A(int a) {
        this->a = a;
        cout << "A Parameterized Constructor\n";
    }
    A() {
        cout << "A Constructor\n";
    }
    void name() {
        cout << a;
        cout << "This is class A \n";
    }
};

// Intermediate Class I
class B : virtual public A {
public:
    B() : A(1) {
        cout << "B Constructor\n";
    }
    void name() {
        cout << a;
        cout << "This is class B \n";
    }
    void name(string h) {
        cout << " hello \n";
    }
};

// Intermediate Class II 
class C : virtual public A {
public:
    C() : A(2) {
        cout << "C Constructor\n";
    }
};

// Final Derived Class
class D : public B, public C {
public:
    // The derived class is now responsible to invoke the base class constructor (if parameterized)
    D() : A(1), B(), C(){
        cout << "D Constructor\n";
    }
};

int main()
{
    D d; 
    d.A::name();
    cout << d.a;
    B b;
    b.name();
    b.A::name();
    b.name("abc");
    return 0;
}