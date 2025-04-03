#include <iostream>
using namespace std;

#define MAX_PERMISSIONS 20
#define MAX_ASSIGNMENTS 5
#define MAX_PROJECTS 2

long int generateHash(const string &password)
{
    long int hash = 5381;
    for (char c : password)
    {
        hash = hash * 33 + c;
    }
    return hash;
}

class User
{
protected:
    string name, id, email;
    long int hashed_password;
    string permissions[MAX_PERMISSIONS];
    int numPermissions;

public:
    User(string n, string i, string e, string p) : name(n), id(i), email(e), hashed_password(generateHash(p)), numPermissions(0) {}

    virtual void addPermissions(const string &perm)
    {
        if (numPermissions >= MAX_PERMISSIONS)
        {
            cout << "Maximum limit for permissions reached." << endl;
            return;
        }
        permissions[numPermissions++] = perm;
        cout << "\"" << perm << "\" has been added to the permissions list of user: " << name << endl;
    }

    virtual bool authenticate(const string &password)
    {
        return hashed_password == generateHash(password);
    }

    virtual void display()
    {
        cout << endl
             << "--------- Displaying Information Below ---------" << endl;
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << endl;
        cout << "Permissions:" << endl;
        for (int i = 0; i < numPermissions; i++)
        {
            cout << "\t" << (i + 1) << ". " << permissions[i] << endl;
        }
    }

    virtual bool accessLab()
    {
        for (int i = 0; i < numPermissions; i++)
        {
            if (permissions[i] == "access lab")
            {
                return true;
            }
        }
        return false;
    }

    virtual bool hasPermission(const string &perm)
    {
        for (int i = 0; i < numPermissions; i++)
        {
            if (permissions[i] == perm)
            {
                return true;
            }
        }
        return false;
    }

    string getName() const { return name; }

    virtual ~User() {}
};

class Student : public User
{
    int assignments[MAX_ASSIGNMENTS];

public:
    Student(string n, string i, string e, string p) : User(n, i, e, p)
    {
        for (int i = 0; i < MAX_ASSIGNMENTS; i++)
        {
            assignments[i] = 0;
        }
    }

    void submitAssignment(int index)
    {
        if (index >= 0 && index < MAX_ASSIGNMENTS)
        {
            assignments[index] = 1;
            cout << "Assignment " << (index + 1) << " submitted successfully for student: " << name << endl;
        }
        else
        {
            cout << "Invalid assignment number entered." << endl;
        }
    }

    void display() override
    {
        User ::display();
        cout << "Assignments:" << endl;
        for (int i = 0; i < MAX_ASSIGNMENTS; i++)
        {
            cout << "\tAssignment " << (i + 1) << ": " << (assignments[i] ? "Submitted" : "Not Submitted") << endl;
        }
    }
};

class TA : public Student
{
    string projects[MAX_PROJECTS];
    int numProjects;
    Student **studentsAssigned;
    int maxStudents = 10;
    int numStudents;

public:
    TA(string n, string i, string e, string p) : Student(n, i, e, p), numProjects(0), numStudents(0)
    {
        studentsAssigned = new Student *[maxStudents];
    }

    void addProject(const string &p)
    {
        if (numProjects >= MAX_PROJECTS)
        {
            cout << "Maximum limit for projects reached." << endl;
            return;
        }
        projects[numProjects++] = p;
        cout << "Project " << p << " has been added to TA: " << name << endl;
    }

    void assignStudent(Student *s)
    {
        if (numStudents >= maxStudents)
        {
            cout << "Maximum limit for students assigned reached." << endl;
            return;
        }
        studentsAssigned[numStudents++] = s;
        cout << "Student: " << s->getName() << " has been assigned to TA: " << name << endl;
    }

    void display() override
    {
        Student ::display();
        cout << "Projects:" << endl;
        for (int i = 0; i < numProjects; i++)
        {
            cout << "\t" << (i + 1) << ". " << projects[i] << endl;
        }
        cout << "Students Assigned:" << endl;
        for (int i = 0; i < numStudents; i++)
        {
            cout << "\t" << (i + 1) << ". " << studentsAssigned[i]->getName() << endl;
        }
    }

    ~TA()
    {
        delete[] studentsAssigned;
    }
};

class Professor : public User
{
    TA **assignedTA;
    int maxTA = 3;
    int numTA;

public:
    Professor(string n, string i, string e, string p) : User(n, i, e, p), numTA(0)
    {
        assignedTA = new TA *[maxTA];
    }

    void assignTA(TA *t)
    {
        if (numTA >= maxTA)
        {
            cout << "Maximum limit for TAs reached." << endl;
            return;
        }
        assignedTA[numTA++] = t;
        cout << "TA: " << t->getName() << " has been assigned to professor: " << name << endl;
    }

    void display() override
    {
        User ::display();
        cout << "TAs assigned:" << endl;
        for (int i = 0; i < numTA; i++)
        {
            cout << "\t" << (i + 1) << ". " << assignedTA[i]->getName() << endl;
        }
    }

    ~Professor()
    {
        delete[] assignedTA;
    }
};

void authenticateAndPerformAction(User *user, string action, string password)
{
    if (user->authenticate(password))
    {
        if (user->hasPermission(action))
        {
            cout << "Action \"" << action << "\" is permitted." << endl;
        }
        else
        {
            cout << "Permission denied for \"" << action << "\"" << endl;
        }
    }
    else
    {
        cout << "Authentication failed!" << endl;
    }
}

int main()
{
    Student s1("Rayyan Aamir", "24K-0687", "k240687@nu.edu.pk", "pass1234");
    s1.addPermissions("access lab");
    s1.addPermissions("do assignments");
    s1.submitAssignment(0);
    s1.submitAssignment(2);
    s1.display();
    cout << (s1.accessLab() ? "Access Granted" : "Access Not Granted") << endl << endl;

    TA ta1("Hammad Haider", "24K-0634", "k240634@nu.edu.pk", "skdlekw456");
    ta1.addPermissions("attend labs");
    ta1.addPermissions("access lab");
    ta1.addPermissions("guide students");
    ta1.assignStudent(&s1);
    ta1.assignStudent(new Student("Usaid Khan", "24K-0732", "k240732@nu.edu.pk", "dku3u3923"));
    ta1.addProject("Conway's Game Of Life");
    ta1.addProject("Student Performance Prediction System");
    ta1.submitAssignment(4);
    ta1.display();
    cout << endl;

    Professor p1("Miss Abeeha Sattar", "P-1002", "abeeha.sattar@nu.edu.pk", "oop10923");
    p1.addPermissions("grade mid term papers");
    p1.addPermissions("take quizzes");
    p1.addPermissions("teach students");
    p1.addPermissions("give assignments");
    p1.assignTA(&ta1);
    p1.display();
    cout << endl;

    authenticateAndPerformAction(&p1, "give assignments", "oop10923");
    return 0;
}