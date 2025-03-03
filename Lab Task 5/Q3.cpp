#include <iostream>
using namespace std;

class ValidateString
{
    string str;

public:
    ValidateString() : str("") {}
    ValidateString(const string userString) : str(userString) {}

    bool isValid() const
    {
        for (int i = 0; i < str.length(); i++)
        {
            int val = int(str.at(i));
            if (!(val >= 65 && val <= 122))
            {
                return false;
            }
        }

        return true;
    }

    string getString() { return str; }
};

int main()
{
    ValidateString v1("Rayyan");
    cout << "String \"" << v1.getString() << "\": " << (v1.isValid() ? "Valid" : "Not Valid") << endl;

    ValidateString v2("Rayyan-2704");
    cout << "String \"" << v2.getString() << "\": " << (v2.isValid() ? "Valid" : "Not Valid") << endl;

    ValidateString v3("Usaid");
    cout << "String \"" << v3.getString() << "\": " << (v3.isValid() ? "Valid" : "Not Valid") << endl;

    ValidateString v4("Usaid!!!");
    cout << "String \"" << v4.getString() << "\": " << (v4.isValid() ? "Valid" : "Not Valid") << endl;
    return 0;
}