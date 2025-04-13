/* Dynamically Allocated Memory (DMA) in C++ */
#include <iostream>
using namespace std;

int main()
{
    // // Basic Pointers
    // int a = 4;
    // int *ptr = &a;
    // cout << "The value of a is " << (*ptr) << endl;

    // // using the "new" keyboard
    // float *p = new float(40.87);
    // cout << "The value at address p is " << (*p) << endl;
    // delete p;

    // dynamically allocating memory for an array
    int *arr = new int[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the value at index " << i << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "The value at index " << i << " is " << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}

/* Pointers to Objects Example */
#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }

    void getData()
    {
        cout << "The value of the real number is " << real << endl;
        cout << "The value of the imaginary number is " << imaginary << endl;
    }
};

int main()
{
    // Complex c1;
    // Complex *ptr = &c1;
    Complex *ptr = new Complex;
    //(*ptr).setData(1, 54); is exactly the same as
    ptr->setData(1, 54);
    //(*ptr).getData(); is exactly the same as
    ptr->getData();
    delete ptr;
    return 0;
}

/* Array of Objects using Pointers */
#include <iostream>
using namespace std;

class Item
{
    int id;
    float price;

public:
    void setData(int a, float b)
    {
        id = a;
        price = b;
    }

    void getData(void)
    {
        cout << "ID of this item is " << id << endl;
        cout << "Price of this item is " << price << endl;
    }
};

int main()
{
    int size = 3;
    Item *ptr = new Item[size];
    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the id and price of item " << (i + 1) << ": ";
        cin >> p >> q;
        // ptr[i].setData(p, q); this is the same statement as below
        (ptr + i)->setData(p, q);
    }

    for (int i = 0; i < size; i++)
    {
        cout << endl << "Item number " << (i + 1) << ": " << endl;
        (ptr + i)->getData();
    }

    delete[] ptr;
    return 0;
}

/* Using "this" pointer */
#include <iostream>
using namespace std;

class A{
    int a;

public:
    void setData(int a){
        this->a = a;
    }

    A & setData2(int a){
        this->a = a;
        return *this;
    }

    void getData(){
        cout << "The value of a is " << a << endl;
    }
};

int main(){
    A a;
    a.setData(78);
    a.getData();

    A b;
    b.setData2(4).getData();
    return 0;
}