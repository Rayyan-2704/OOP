/*
Q2. A user wishes to update their resume in your Resume Builder application.
Requirements:
1. Prompt the user to enter:
○ string name
○ string email
○ int yearsOfExperience
○ string summary
2. Write this data to a file called resume.txt.
3. Use ofstream with ios::trunc to ensure that any previous contents are completely
deleted before writing new data.
4. After writing, read back and display the contents to confirm that the file only has the
latest entry.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string name, email, summary;
    int yearsOfExperience;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter summary: ";
    cin >> summary;
    cout << "Enter years of experience: ";
    cin >> yearsOfExperience;

    fstream file;
    file.open("resume.txt", ios::out | ios::trunc);
    if (!file)
    {
        cout << "Error in opening the file!" << endl;
        exit(0);
    }
    file << "Name: " << name << endl;
    file << "Email: " << email << endl;
    file << "Summary: " << summary << endl;
    file << "Years of Experience: " << yearsOfExperience << endl;
    file.close();

    file.open("resume.txt", ios::in);
    if (!file)
    {
        cout << "Error in opening the file!" << endl;
        exit(0);
    }
    string line;
    cout << "Printing file details:\n";
    while (!file.eof())
    {
        if (!file.eof())
        {
           getline(file, line);
           cout << line << endl;
        }
    }
    file.close();

    return 0;
}