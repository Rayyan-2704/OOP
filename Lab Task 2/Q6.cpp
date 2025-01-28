/* You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:
  --> Implement the Register and Student structures.
  --> Inherit the Register structure in the Student structure.
  --> Create an array of Student structures to store information for 5 students.
  --> Take input for each student, including their courseId, courseName, studentId, firstName,
      lastName, cellNo, and email.
  --> Display the information for all 5 students. */

#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

typedef struct
{
    int courseID;
    char courseName[50];
} Register;

typedef struct
{
    Register reg;
    int studentID;
    char firstName[50];
    char lastName[50];
    char cellNo[20];
    char email[50];
} Student;

void initializeStudentDetails(Student *&s, const int n);
void displayDetails(Student *s, const int n);

int main()
{
    Student *students = nullptr;
    const int numStudents = 5;
    int choice;

    cout << "----- Welcome to Student Registration System -----" << endl;
    cout << "Enter 1 for the initialization of student information and details." << endl;
    cout << "Enter 2 to display the information and details for all students." << endl;
    cout << "Enter 3 to exit." << endl;

    while (1)
    {
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            initializeStudentDetails(students, numStudents);
            break;

        case 2:
            displayDetails(students, numStudents);
            break;

        case 3:
            cout << "Exiting the program...." << endl;
            if (students != nullptr)
            {
                delete[] students;
            }
            return 0;

        default:
            cout << "Invalid choice entered! Try again." << endl;
        }
    }
}

void initializeStudentDetails(Student *&s, const int n)
{
    s = new Student[n];

    cout << "Enter the details of each student below" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Enter the details of student " << (i + 1) << ": " << endl;

        cout << "Student ID: ";
        cin >> s[i].studentID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "First Name: ";
        cin.getline(s[i].firstName, 50);

        cout << "Last Name: ";
        cin.getline(s[i].lastName, 50);

        cout << "Cell Number: ";
        cin.getline(s[i].cellNo, 20);

        cout << "Email: ";
        cin.getline(s[i].email, 50);

        cout << "Course ID: ";
        cin >> s[i].reg.courseID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Course Name: ";
        cin.getline(s[i].reg.courseName, 50);
    }
}

void displayDetails(Student *s, const int n)
{
    if (s == nullptr)
    {
        cout << "The student details have not been initialized yet." << endl;
        return;
    }

    cout << "Displaying the details below:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Details of student " << (i + 1) << ": " << endl;
        cout << "Student ID: " << s[i].studentID << endl;
        cout << "First Name: " << s[i].firstName << endl;
        cout << "Last Name: " << s[i].lastName << endl;
        cout << "Cell Number: " << s[i].cellNo << endl;
        cout << "Email: " << s[i].email << endl;
        cout << "Course ID: " << s[i].reg.courseID << endl;
        cout << "Course Name: " << s[i].reg.courseName << endl;
    }
}