/* Example 1: Using Templates */
#include <iostream>
using namespace std;

// making a template for a class vector such that the array of class (arr) can be of any data type (int, float and char) and replacing the necessary data type declarations with T (the template declaration).
template <class T>
class Vector{
public:
    T *arr;
    int size;

    Vector(int m) : size(m) {
        arr = new T[size];
    }

    T dotProduct(Vector &v){
        T d = 0;
        for(int i = 0; i < size; i++){
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};

int main(){
    Vector <int> v1(3);
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;

    Vector <int> v2(3);
    v2.arr[0] = 1;
    v2.arr[1] = 0;
    v2.arr[2] = 1;

    cout << "\nFor Int Data Type:\n";
    cout << "The dot product of the vectors (v1 and v2) is " << v1.dotProduct(v2) << endl;
    
    Vector <float> v3(3);
    v3.arr[0] = 4.5;
    v3.arr[1] = 3.1;
    v3.arr[2] = 1.7;

    Vector <float> v4(3);
    v4.arr[0] = 7.1;
    v4.arr[1] = 2.8;
    v4.arr[2] = 5.5;

    cout << "\nFor Float Data Type:\n";
    cout << "The dot product of the vectors (v3 and v4) is " << v3.dotProduct(v4) << endl; 
    return 0;
}

/* Example 2: Templates with Multiple Parameters */
#include <iostream>
using namespace std;

template <class T1, class T2>
class myClass{
    T1 data1;
    T2 data2;

public:
    myClass(T1 d1, T2 d2) : data1(d1), data2(d2) {}

    void display() const {
        cout << "Data 1: " << data1 << " | Data 2: " << data2 << endl;
    }
};

int main(){
    myClass <string, int> c1("Rayyan Aamir", 18);
    c1.display();

    myClass <char, double> c2('A', 5400.567);
    c2.display();
    return 0;
}

/* Example 3: Templates with Default Parameters */
#include <iostream>
using namespace std;

template <class T1 = int, class T2 = float>
class tempClass{
    T1 data1;
    T2 data2;

public:
    tempClass(T1 d1, T2 d2) : data1(d1), data2(d2) {}

    void display() const {
        cout << "Data 1: " << data1 << " | Data 2: " << data2 << endl;
    }
};

int main(){
    tempClass <string, int> c1("Rayyan Aamir", 18);
    c1.display();

    tempClass <char, double> c2('A', 5400.567);
    c2.display();

    tempClass <> c3(24, 89.4); // default data types int and float will be used.
    c3.display();

    tempClass <string> c4("Hello", 56.34); // default data type float will be used for data2.
    c4.display();
    return 0;
}

/* Example 4: Function Templates */
#include <iostream>
using namespace std;

template <class T>
void swapped(T &, T &);

int main(){
    int x = 5, y = 7;
    swapped(x, y);
    cout << "x = " << x << " | y = " << y << endl;
    return 0;
}

template <class T>
void swapped(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

/* Example 5: Defining Template Member Functions outside class */
#include <iostream>
#include <string>
using namespace std;

template <class T>
class newClass{
    T data;

public:
    newClass(T a) : data(a) {}

    void display() const;
};

template <class T>
void newClass <T> :: display() const{
    cout << "Data: " << data << endl;
}

int main(){
    newClass <int> c1(10);
    c1.display();

    newClass <string> c2("Hello world!");
    c2.display();
    return 0;
}

/* Example 6: Overloading the Template Function */
#include <iostream>
using namespace std;

void func(int a){
    cout << "Normal func | Data: " << a << endl;
}

template <class T>
void func(T a){
    cout << "Templatized func | Data: " << a << endl;
}

int main(){
    func(10); // This will call the normal func() as exact match takes priority
    func(90.565); // This will call the templatized func()
    return 0;
}