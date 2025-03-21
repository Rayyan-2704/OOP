#include <iostream>
using namespace std;

class User
{
protected:
    string userID;
    string userName;
    string stopName;
    bool isCardActive;

public:
    User(string id, string n, string stop, bool card = true) : userID(id), userName(n), stopName(stop), isCardActive(card) {}

    virtual void payFees() = 0;

    void updateStop(string stop)
    {
        this->stopName = stop;
        cout << "Stop updated successfully to " << stopName << endl;
    }

    virtual void displayUserInfo() const
    {
        cout << endl << "User Name: " << userName << endl;
        cout << "User ID: " << userID << endl;
        cout << "User's Stop Name: " << stopName << endl;
        cout << "Card: " << ((isCardActive) ? "Active" : "Not Active") << endl;
    }

    string getUserID() const { return userID; }
    string getUserName() const { return userName; }
    string getStopName() const { return stopName; }
    bool getIsCardActive() const { return isCardActive; }

    virtual ~User() {}
};

class Student : public User
{
    bool attendanceList[31];

public:
    Student(string id, string n, string stop, bool card = true) : User(id, n, stop, card)
    {
        for (int i = 0; i < 31; i++)
        {
            attendanceList[i] = false;
        }
    }

    void payFees() override
    {
        isCardActive = true;
        cout << "Transport semester fees paid successfully for student: " << userName << endl;
    }

    void recordAttendance(int day)
    {
        if (day < 1 || day > 31)
        {
            cout << "Invalid input! Enter a day between 1 and 31." << endl;
            return;
        }

        if (isCardActive)
        {
            attendanceList[day - 1] = true;
            cout << "Attendance marked for " << userName << " on day " << day << endl;
        }
        else
        {
            cout << "Attendance cannot be marked as card is inactive for " << userName << ". Kindly pay the transport fees to activate the card." << endl;
        }
    }

    void displayAttendance() const
    {
        if (!isCardActive)
        {
            cout << "Card is inactive for " << userName << ". Kindaly pay the transport fees to activate the card." << endl;
            return;
        }

        cout << endl << "Displaying attendance for " << userName << endl;
        for (int i = 0; i < 31; i++)
        {
            cout << "Day " << (i + 1) << ": " << ((attendanceList[i]) ? "Present" : "Absent") << endl;
        }
    }
};

class Teacher : public User
{
public:
    Teacher(string id, string n, string stop, bool card = true) : User(id, n, stop, card) {}

    void payFees() override
    {
        cout << "Transport monthly fees paid successfully for teacher: " << userName << endl;
    }
};

class Staff : public User
{
public:
    Staff(string id, string n, string stop, bool card = true) : User(id, n, stop, card) {}

    void payFees() override
    {
        cout << "Transport weekly fees paid successfully for staff: " << userName << endl;
    }
};

class Bus
{
    string busID;
    string busName;
    string *stops; // dynamic 1D string array of stops
    int numStops;
    const int maxStops;

public:
    Bus(string id, string n, int mStops) : busID(id), busName(n), maxStops(mStops), numStops(0)
    {
        stops = new string[maxStops];
    }

    void addStop(const string &stopName)
    {
        if (numStops >= maxStops)
        {
            cout << "The maximum limit of stops for bus " << busName << "(" << busID << ") has been reached. Cannot add further stops." << endl;
            return;
        }

        stops[numStops++] = stopName;
        cout << "Stop: " << stopName << " has been added to the route of bus " << busName << " (" << busID << ")." << endl;
    }

    void removeStop(const string &stopName)
    {
        int i, flag = 0;
        for (i = 0; i < numStops; i++)
        {
            if (stops[i] == stopName)
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            cout << "Stop: " << stopName << " was not found in bus " << busName << "'s route." << endl;
            return;
        }

        for (int j = i; j < (numStops - 1); j++)
        {
            stops[j] = stops[j + 1];
        }
        numStops--;
        cout << "Stop: " << stopName << " removed from bus " << busName << "'s route." << endl;
    }

    void displayBusInfo() const
    {
        cout << endl << "Bus Name: " << busName << endl;
        cout << "Bus ID: " << busID << endl;
        cout << "Number of Stops: " << numStops << " stops" << endl;
        for (int i = 0; i < numStops; i++)
        {
            cout << "Stop " << (i + 1) << ": " << stops[i] << endl;
        }
    }

    bool operator==(const Bus &other)
    {
        if (numStops != other.numStops)
        {
            return false;
        }

        for (int i = 0; i < numStops; i++)
        {
            if (stops[i] != other.stops[i])
            {
                return false;
            }
        }

        return true;
    }

    string getBusID() const { return busID; }

    ~Bus()
    {
        delete[] stops;
    }
};

class Transportation
{
    User **users; // pointer 1D array of User objects (Aggregation)
    int numUsers;
    int maxUsers;
    Bus **buses; // pointer 1D array of Bus objects (Aggregation)
    int numBuses;
    int maxBuses;
    static int totalUsers;

public:
    Transportation(int mUsers, int mBuses) : numUsers(0), maxUsers(mUsers), numBuses(0), maxBuses(mBuses)
    {
        users = new User *[maxUsers];
        buses = new Bus *[maxBuses];
    }

    void registerUser()
    {
        if (numUsers >= maxUsers)
        {
            cout << "User registration limit reached!" << endl;
            return;
        }

        string userType, id, userName, stopName;
        cout << "Enter the type of user (make sure to use lowercase here)\nstudent, teacher or staff?: ";
        getline(cin, userType);
        cout << "Enter the ID of user: ";
        getline(cin, id);
        cout << "Enter the name of user: ";
        getline(cin, userName);
        cout << "Enter the stop name of user: ";
        getline(cin, stopName);

        if (userType == "student")
        {
            users[numUsers++] = new Student(id, userName, stopName);
        }
        else if (userType == "teacher")
        {
            users[numUsers++] = new Teacher(id, userName, stopName);
        }
        else if (userType == "staff")
        {
            users[numUsers++] = new Staff(id, userName, stopName);
        }
        else
        {
            cout << "Invalid user type. Please try again." << endl;
            return;
        }

        totalUsers++;
        cout << userName << " has been registered successfully!" << endl;
    }

    void addBus()
    {
        if (numBuses >= maxBuses)
        {
            cout << "Bus limit reached!" << endl;
            return;
        }

        string busName, id;
        int maxStops;
        cout << "Enter the id of bus: ";
        getline(cin, id);
        cout << "Enter the name of bus: ";
        getline(cin, busName);
        cout << "Enter the maximum stops of the bus: ";
        cin >> maxStops;
        cin.ignore();

        buses[numBuses++] = new Bus(id, busName, maxStops);
        cout << "Bus: " << busName << " has been added successfully!" << endl;
    }

    void displayAllUsers() const
    {
        for (int i = 0; i < numUsers; i++)
        {
            users[i]->displayUserInfo();
        }
    }

    void displayAllBuses() const
    {
        for (int i = 0; i < numBuses; i++)
        {
            buses[i]->displayBusInfo();
        }
    }

    void defineStops()
    {
        string id;
        cout << "Enter the ID of the bus to define stops for: ";
        getline(cin, id);

        int i, flag = 0;
        for (i = 0; i < numBuses; i++)
        {
            if (buses[i]->getBusID() == id)
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            cout << "Bus ID not found!" << endl;
            return;
        }

        int n;
        cout << "Enter the number of stops to be defined: ";
        cin >> n;
        cin.ignore();

        for (int j = 0; j < n; j++)
        {
            string stop;
            cout << "Enter stop " << (j + 1) << ": ";
            getline(cin, stop);
            buses[i]->addStop(stop);
        }

        cout << "Stops defined for bus ID: " << buses[i]->getBusID() << " successfully." << endl;
    }

    static int getTotalUser()
    {
        return totalUsers;
    }

    ~Transportation()
    {
        for (int i = 0; i < numUsers; i++)
        {
            delete users[i];
        }
        delete[] users;

        for (int i = 0; i < numBuses; i++)
        {
            delete buses[i];
        }
        delete[] buses;
    }
};

int Transportation ::totalUsers = 0;

int main()
{
    int maxUsers, maxBuses;
    cout << "Enter the maximum number of users: ";
    cin >> maxUsers;
    cout << "Enter the maximum number of buses: ";
    cin >> maxBuses;
    cin.ignore();

    Transportation transport(maxUsers, maxBuses);

    int choice;
    do
    {
        cout << endl << "------- Transportation System Menu -------" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Add a Bus" << endl;
        cout << "3. Define Stops for a Bus" << endl;
        cout << "4. Display All Users" << endl;
        cout << "5. Display All Buses" << endl;
        cout << "6. Display Total Users" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            transport.registerUser();
            break;

        case 2:
            transport.addBus();
            break;

        case 3:
            transport.defineStops();
            break;

        case 4:
            transport.displayAllUsers();
            break;

        case 5:
            transport.displayAllBuses();
            break;

        case 6:
            cout << "Total registered users: " << Transportation ::getTotalUser() << endl;
            break;

        case 7:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 7);

    /* Operator Overloading Function Test */
    // Bus b1("B-1001", "Point 6-B", 5);
    // b1.addStop("Sakhi Hasan");
    // b1.addStop("DC Office");

    // Bus b2("B-1002", "Point 5", 4);
    // b2.addStop("Dolmen Mall");
    // b2.addStop("Lucky One");

    // cout << ((b1 == b2) ? "Same Routes" : "Different Routes") << endl;

    return 0;
}