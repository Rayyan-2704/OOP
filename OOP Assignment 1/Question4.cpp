/*
Class Diagrams for Question 4: (Excluding getters and setters as the class diagrams were becoming way too long)
+---------------------+
|      Student        |
+---------------------+
| - studentID: string |
| - studentName: string|
| - feesPaid: bool    |
| - cardActive: bool  |
| - stopName: string  |
+---------------------+
| + registerStudent(): void    |
| + payFees(): void           |
| + verifyCard(): void        |
+---------------------+

+---------------------+
|   Transportation    |
+---------------------+
| - routeID: string   |
| - routeName: string |
| - stops: string[MAX_STOPS] |
| - numStops: int     |
+---------------------+
| + addStop(string): void    |
| + assignStudent(Student&, string): void |
+---------------------+

+---------------------+
|        Bus          |
+---------------------+
| - busID: string     |
| - busName: string   |
| - assignedRoute: Transportation* |
+---------------------+
| + assignRoute(Transportation&): void |
| + recordAttendance(Student&): void |
+---------------------+
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_STOPS = 50;

class Student
{
    string studentID;
    string studentName;
    bool feesPaid;
    bool cardActive;
    string stopName;

public:
    Student() : studentID(""), studentName(""), feesPaid(false), cardActive(false), stopName("") {}
    Student(string id, string name) : studentID(id), studentName(name), feesPaid(false), cardActive(false), stopName("") {}

    string getStudentID() { return studentID; }
    string getName() { return studentName; }
    bool isCardActive() { return cardActive; }
    bool isFeePaid() { return feesPaid; }
    string getStopName() { return stopName; }

    void setStudentID(string id) { studentID = id; }
    void setStudentName(string name) { studentName = name; }
    void setFeesPaid(bool val) { feesPaid = val; }
    void setCardActive(bool val) { cardActive = val; }
    void setStopName(string stop) { stopName = stop; }

    void registerStudent()
    {
        cout << "Student " << studentName << " with student ID \"" << studentID << "\" has been registered for transportation." << endl;
    }

    void payFees()
    {
        feesPaid = true;
        cardActive = true;
        cout << "Fees paid. Card is now active for " << studentName << "." << endl;
    }

    void verifyCard()
    {
        if (cardActive)
        {
            cout << "Card is active for " << studentName << "." << endl;
        }
        else
        {
            cout << "Card is not active for " << studentName << ". Please pay fees." << endl;
        }
    }
};

class Transportation
{
    string routeID;
    string routeName;
    string stops[MAX_STOPS];
    int numStops;

public:
    Transportation() : routeID(""), routeName(""), numStops(0) {}
    Transportation(string id, string name) : routeID(id), routeName(name), numStops(0) {}

    string getRouteID() { return routeID; }
    string getRouteName() { return routeName; }
    int getStopCount() { return numStops; }

    void setRouteID(string id) { routeID = id; }
    void setRouteName(string name) { routeName = name; }

    void addStop(const string &stop)
    {
        if (numStops < MAX_STOPS)
        {
            stops[numStops++] = stop;
            cout << "Stop \"" << stop << "\" has been added to route " << routeName << "." << endl;
        }
        else
        {
            cout << "Cannot add more stops. Maximum limit reached." << endl;
            return;
        }
    }

    void assignStudent(Student &student, string stop)
    {
        int flag = 0;
        for (int i = 0; i < numStops; i++)
        {
            if (stops[i] == stop)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            student.setStopName(stop);
            cout << "Student " << student.getName() << " assigned to stop \"" << stop << "\"." << endl;
        }
        else
        {
            cout << "Stop \"" << stop << "\" not found in route " << routeName << "." << endl;
            ;
        }
    }
};

class Bus
{
    string busID;
    string busName;
    Transportation *assignedRoute;

public:
    Bus() : busID(""), busName(""), assignedRoute(nullptr) {}
    Bus(string id, string name) : busID(id), busName(name), assignedRoute(nullptr) {}

    string getBusID() { return busID; }
    string getBusName() { return busName; }
    Transportation *getAssignedRoute() { return assignedRoute; }

    void setBusID(string id) { busID = id; }
    void setBusName(string name) { busName = name; }

    void assignRoute(Transportation &route)
    {
        assignedRoute = &route;
        cout << "Route \"" << route.getRouteName() << "\" assigned to bus " << busName << "." << endl;
    }

    void recordAttendance(Student &student)
    {
        if (student.isCardActive())
        {
            cout << "Attendance recorded for " << student.getName() << " on bus " << busName << "." << endl;
        }
        else
        {
            cout << "Card not active. Attendance not recorded for " << student.getName() << "." << endl;
        }
    }
};

int main()
{
    Student students[100];
    Transportation routes[10];
    Bus buses[10];

    int studentCount = 0, routeCount = 0, busCount = 0;
    int choice;

    cout << "========= TRANSPORTATION SYSTEM MENU =========" << endl;
    cout << "Enter 1 to Register a Student" << endl;
    cout << "Enter 2 to Pay Fees" << endl;
    cout << "Enter 3 to Verify Card" << endl;
    cout << "Enter 4 to Create a Route" << endl;
    cout << "Enter 5 to Add Stop to a Route" << endl;
    cout << "Enter 6 to Assign Student to a Stop" << endl;
    cout << "Enter 7 to Create a Bus" << endl;
    cout << "Enter 8 to Assign Route to Bus" << endl;
    cout << "Enter 9 to Record Attendance" << endl;
    cout << "Enter 0 to Exit" << endl;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            if (studentCount < 100)
            {
                string id, name;
                cout << "Enter Student ID: ";
                getline(cin, id);
                cout << "Enter Student Name: ";
                getline(cin, name);
                students[studentCount] = Student(id, name);
                students[studentCount].registerStudent();
                studentCount++;
            }
            else
            {
                cout << "Maximum student limit reached." << endl;
            }
            break;
        }

        case 2:
        {
            string id;
            cout << "Enter Student ID to pay fees: ";
            getline(cin, id);
            int found = 0;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].getStudentID() == id)
                {
                    students[i].payFees();
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Student not found!" << endl;
            break;
        }

        case 3:
        {
            string id;
            cout << "Enter Student ID to verify card: ";
            getline(cin, id);
            int found = 0;
            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].getStudentID() == id)
                {
                    students[i].verifyCard();
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Student not found!" << endl;
            break;
        }

        case 4:
        {
            if (routeCount < 10)
            {
                string id, name;
                cout << "Enter Route ID: ";
                getline(cin, id);
                cout << "Enter Route Name: ";
                getline(cin, name);
                routes[routeCount] = Transportation(id, name);
                cout << "Route " << name << " created successfully." << endl;
                routeCount++;
            }
            else
            {
                cout << "Maximum routes reached." << endl;
            }
            break;
        }

        case 5:
        {
            string id, stop;
            cout << "Enter Route ID to add stop: ";
            getline(cin, id);
            int found = 0;
            for (int i = 0; i < routeCount; i++)
            {
                if (routes[i].getRouteID() == id)
                {
                    cout << "Enter Stop Name: ";
                    getline(cin, stop);
                    routes[i].addStop(stop);
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Route not found!" << endl;
            break;
        }

        case 6:
        {
            string studentID, routeID, stop;
            cout << "Enter Student ID: ";
            getline(cin, studentID);
            cout << "Enter Route ID: ";
            getline(cin, routeID);
            cout << "Enter Stop Name: ";
            getline(cin, stop);

            Student *studentPtr = nullptr;
            Transportation *routePtr = nullptr;

            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].getStudentID() == studentID)
                {
                    studentPtr = &students[i];
                    break;
                }
            }

            for (int i = 0; i < routeCount; i++)
            {
                if (routes[i].getRouteID() == routeID)
                {
                    routePtr = &routes[i];
                    break;
                }
            }

            if (studentPtr && routePtr)
            {
                routePtr->assignStudent(*studentPtr, stop);
            }
            else
            {
                cout << "Student or Route not found!" << endl;
            }
            break;
        }

        case 7:
        {
            if (busCount < 10)
            {
                string id, name;
                cout << "Enter Bus ID: ";
                getline(cin, id);
                cout << "Enter Bus Name: ";
                getline(cin, name);
                buses[busCount] = Bus(id, name);
                cout << "Bus " << name << " created successfully." << endl;
                busCount++;
            }
            else
            {
                cout << "Maximum buses reached." << endl;
            }
            break;
        }

        case 8:
        {
            string busID, routeID;
            cout << "Enter Bus ID: ";
            getline(cin, busID);
            cout << "Enter Route ID: ";
            getline(cin, routeID);

            Bus *busPtr = nullptr;
            Transportation *routePtr = nullptr;

            for (int i = 0; i < busCount; i++)
            {
                if (buses[i].getBusID() == busID)
                {
                    busPtr = &buses[i];
                    break;
                }
            }

            for (int i = 0; i < routeCount; i++)
            {
                if (routes[i].getRouteID() == routeID)
                {
                    routePtr = &routes[i];
                    break;
                }
            }

            if (busPtr && routePtr)
            {
                busPtr->assignRoute(*routePtr);
            }
            else
            {
                cout << "Bus or Route not found!" << endl;
            }
            break;
        }

        case 9:
        {
            string studentID, busID;
            cout << "Enter Student ID: ";
            getline(cin, studentID);
            cout << "Enter Bus ID: ";
            getline(cin, busID);

            Student *studentPtr = nullptr;
            Bus *busPtr = nullptr;

            for (int i = 0; i < studentCount; i++)
            {
                if (students[i].getStudentID() == studentID)
                {
                    studentPtr = &students[i];
                    break;
                }
            }

            for (int i = 0; i < busCount; i++)
            {
                if (buses[i].getBusID() == busID)
                {
                    busPtr = &buses[i];
                    break;
                }
            }

            if (studentPtr && busPtr)
            {
                busPtr->recordAttendance(*studentPtr);
            }
            else
            {
                cout << "Student or Bus not found!" << endl;
            }
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}