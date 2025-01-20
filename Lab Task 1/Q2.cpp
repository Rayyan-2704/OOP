/* Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    float subjects[n][3];
    float totalMarks[n] = {0}, avgMarks[n];
    char grade[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter the marks of student " << (i + 1) << " for subject " << (j + 1) << " : ";
            cin >> subjects[i][j];
            totalMarks[i] += subjects[i][j];
        }
        avgMarks[i] = totalMarks[i] / 3;
        if (avgMarks[i] >= 90.0)
        {
            grade[i] = 'A';
        }
        else if (avgMarks[i] >= 80.0 && avgMarks[i] < 90.0)
        {
            grade[i] = 'B';
        }
        else if (avgMarks[i] >= 70.0 && avgMarks[i] < 80.0)
        {
            grade[i] = 'C';
        }
        else if (avgMarks[i] >= 60.0 && avgMarks[i] < 70.0)
        {
            grade[i] = 'D';
        }
        else
        {
            grade[i] = 'F';
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Grade Details of Student " << (i + 1) << " : " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Marks for subject " << (j + 1) << " : " << subjects[i][j] << endl;
        }
        cout << "Total Marks: " << fixed << setprecision(2) << totalMarks[i] << endl;
        cout << "Average Marks: " << fixed << setprecision(2) << avgMarks[i] << endl;
        cout << "Grade: " << grade[i] << endl;
    }

    return 0;
}