/* You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
    --> `studentID` (int)
    --> `name` (string)
    --> `age` (int)
    --> `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
    --> `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
    --> `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
    --> `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods. */

#include <iostream>
using namespace std;

class Student
{
    int studentID;
    string name;
    int age;
    char grade;

public:
    Student()
    {
        grade = 'N';
    }

    Student(int studentID, string name, int age, char grade)
    {
        this->studentID = studentID;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    void promoteStudent()
    {
        if (grade == 'A')
        {
            cout << "The student already has the highest grade possible. Cannot be further promoted." << endl;
            return;
        }

        grade -= 1;
    }

    bool isEligibleForScholarship()
    {
        if (grade == 'A')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void displayDetails()
    {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student *students = new Student[n];

    int id, age;
    string name;
    char grade;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the student ID of student " << (i + 1) << ": ";
        cin >> id;
        cin.ignore();
        cout << "Enter the name of student " << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter the age of student " << (i + 1) << ": ";
        cin >> age;
        cout << "Enter the grade of student " << (i + 1) << ": ";
        cin >> grade;
        students[i] = Student(id, name, age, grade);
    }

    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Displaying details before upgrading the grade of student " << (i + 1) << ": " << endl;
        (students + i)->displayDetails();

        (students + i)->promoteStudent();

        cout << endl
             << "Displaying details after upgrading the grade of student " << (i + 1) << ": " << endl;
        (students + i)->displayDetails();

        if ((students + i)->isEligibleForScholarship())
        {
            cout << "Student " << (i + 1) << " is eligible for scholarship." << endl;
        }
        else
        {
            cout << "Student " << (i + 1) << " is not eligible for scholarship." << endl;
        }
    }

    delete[] students;
    return 0;
}
