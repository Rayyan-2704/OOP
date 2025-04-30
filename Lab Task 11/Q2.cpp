#include <iostream>
#include <string>
#include <exception>
using namespace std;

class StackOverflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <class T>
class Stack
{
    T *arr;
    int currentSize;
    int maxCapacity;

public:
    Stack(int max) : maxCapacity(max)
    {
        currentSize = 0;
        arr = new T[maxCapacity];
    }

    int getCurrentSize() const { return currentSize; }

    void push(T value)
    {
        if (currentSize >= maxCapacity)
        {
            throw StackOverflowException();
        }

        arr[currentSize++] = value;
    }

    T pop()
    {
        if (currentSize == 0)
        {
            throw StackUnderflowException();
        }

        T removedValue = arr[currentSize - 1];
        currentSize--;
        return removedValue;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<double> s(5);

    try
    {
        s.push(4.5);
        s.push(7.9);
        s.push(4.1);
        s.push(3.4);
        s.push(2.0);
        s.push(9.8);
    }
    catch (const StackOverflowException &e)
    {
        cout << "Pushing to a full stack: " << e.what() << endl;
    }

    try
    {
        for (int i = s.getCurrentSize() - 1; i >= 0; i--)
        {
            cout << "Removed value: " << s.pop() << endl;
        }

        int temp = s.pop();
        cout << "Testing underflow: " << temp << endl;
    }
    catch (const StackUnderflowException &e)
    {
        cout << "Popping from an empty stack: " << e.what() << endl;
    }

    return 0;
}
