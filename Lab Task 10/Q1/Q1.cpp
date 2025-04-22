/*
Q1. You are building a student record management tool for a university system.
Requirements:
1. Define a structure Student with the following fields:
○ int id
○ string name
○ float gpa
2. Prompt the user to enter data for 5 students.
3. Write these records to a file named students.txt using ofstream with ios::out mode.
4. Then, allow the user to append 1 additional student record using ios::app mode (open in append mode and write without erasing old content).
5. Finally, read and display all student records from the file using ifstream.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct
{
    int id;
    string name;
    float gpa;
} Student;

int main()
{
    Student students[3];

    ofstream writeFile;
    writeFile.open("students.txt", ios::out);
    if (!writeFile)
    {
        cout << "Error in opening the file!" << endl;
        exit(0);
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the ID of student " << (i + 1) << ": ";
        cin >> students[i].id;
        cin.ignore();
        cout << "Enter the name of student " << (i + 1) << ": ";
        getline(cin, students[i].name);
        cout << "Enter the GPA of student " << (i + 1) << ": ";
        cin >> students[i].gpa;
        writeFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }
    writeFile.close();

    ofstream appendFile;
    appendFile.open("students.txt", ios::app);
    if (!appendFile)
    {
        cout << "Error in opening the file!" << endl;
        exit(0);
    }
    Student newStudent;
    cout << "Enter the ID of new student " << ": ";
    cin >> newStudent.id;
    cin.ignore();
    cout << "Enter the name of new student " << ": ";
    getline(cin, newStudent.name);
    cout << "Enter the GPA of new student " << ": ";
    cin >> newStudent.gpa;
    appendFile << newStudent.id << " " << newStudent.name << " " << newStudent.gpa;
    appendFile.close();

    ifstream readFile;
    readFile.open("students.txt", ios::in);
    if (!readFile)
    {
        cout << "Error in opening the file!" << endl;
        exit(0);
    }
    Student readStudent;
    while (!readFile.eof())
    {
        if (!readFile.eof())
        {
            readFile >> readStudent.id;
            readFile >> readStudent.name;
            readFile >> readStudent.gpa;
            cout << "ID: " << readStudent.id << " | Name: " << readStudent.name << " | GPA: " << readStudent.gpa << endl;
        }
    }
    readFile.close();

    return 0;
}