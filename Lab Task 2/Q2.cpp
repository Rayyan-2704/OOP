/* Write a C++ program that:
  --> Reads n strings from the user and stores them in a dynamically allocated array of char*.
  --> Prints the strings in reverse order using pointer arithmetic.
  --> Finds and prints the string with the most vowels (a, e, i, o, u).
  --> Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    char **strings = new char *[n];
    for (int i = 0; i < n; i++)
    {
        strings[i] = new char[50];
    }

    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << (i + 1) << ": ";
        cin.getline(strings[i], 50);
    }

    cout << "Printing the strings in reverse order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "String " << i << ": ";
        int startingIndex = strlen(strings[i]) - 1;
        char *ptr = strings[i] + startingIndex;
        while (ptr >= strings[i])
        {
            cout << *ptr;
            ptr--;
        }
        cout << endl;
    }

    int maxVowels = 0;
    char *mostVowelWord;
    for (int i = 0; i < n; i++)
    {
        int vowelCount = 0;
        for (int j = 0; j < strlen(strings[i]); j++)
        {
            if (strings[i][j] == 'a' || strings[i][j] == 'A' || strings[i][j] == 'e' || strings[i][j] == 'E' || strings[i][j] == 'i' || strings[i][j] == 'I' || strings[i][j] == 'o' || strings[i][j] == 'O' || strings[i][j] == 'u' || strings[i][j] == 'U')
            {
                vowelCount++;
            }
        }
        if (vowelCount > maxVowels)
        {
            maxVowels = vowelCount;
            mostVowelWord = strings[i];
        }
    }
    cout << "The string with the most vowel is: \"" << mostVowelWord << "\"" << endl;

    float avgLength, totalLength = 0;
    for(int i=0 ; i<n ; i++){
        totalLength += strlen(strings[i]);
    }
    avgLength = totalLength/n;

    cout << "The average length of all the strings is " << fixed << setprecision(2) << avgLength << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] strings[i];
    }
    delete[] strings;

    return 0;
}