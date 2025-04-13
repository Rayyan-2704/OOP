/* Example 1: Nesting of member functions example */
#include <iostream>
#include <string>
using namespace std;

class Binary
{
    // By default, the members and methods in a class are private
    string s;
    void checkBin();

public:
    void readBin();
    void onesCompliment();
    void display();
};

void Binary :: readBin()
{
    cout << "Enter the binary number: " << endl;
    cin >> s;
}

void Binary :: checkBin()
{
    // .length() is a string function which gives the length of the string
    // .at() is a string function which allows traversing/linear search in a string for each character
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Invalid binary number entered." << endl;
            exit(0);
        }
    }
    cout << "The binary number entered is valid." << endl;
}

void Binary :: onesCompliment()
{
    checkBin(); // Nesting of member function here
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
    }

    cout << "The binary number after ones complement is " << s << endl;
}

void Binary :: display()
{
    // for(int i = 0 ; i < s.length() ; i++){    --->  This will work as well
    //     cout << s.at(i);
    // }
    cout << s << endl;
}

int main()
{
    Binary binNum;
    binNum.readBin();
    // binNum.checkBin(); ---> cannot call checkBin() in main() as it is private
    binNum.display();
    binNum.onesCompliment();
    binNum.display();
    return 0;
}


/* Example 2: Using arrays in classes */
#include <iostream>
#include <string>
using namespace std;

class Shop
{
    int itemID[100];
    int itemPrice[100];
    int counter;

public:
    void initializeCounter()
    {
        counter = 0;
    }
    void setPrice();
    void displayPrice();
};

void Shop :: setPrice()
{
    cout << "Enter the ID of the item " << (counter + 1) << " : ";
    cin >> itemID[counter];
    cout << "Enter the price of the item: ";
    cin >> itemPrice[counter];
    counter++;
}

void Shop :: displayPrice()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with ID " << itemID[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop imtiaz;
    imtiaz.initializeCounter();
    imtiaz.setPrice();
    imtiaz.setPrice();
    imtiaz.setPrice();
    imtiaz.displayPrice();
    return 0;
}