/*
Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.
*/

/* If we had not declared our function constant, the string could have been altered inside the function. Making the function constant ensures that the 
class data members (besides mutable members) remain constant throughout the function. */

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
            if (!((val >= 65 && val <= 90) || (val >= 97 && val <= 122)))
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
