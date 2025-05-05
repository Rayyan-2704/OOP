#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>
using namespace std;

class FileException : public exception
{
    string message;

public:
    FileException(const string &m) : message(m) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class User
{
protected:
    char userID[50];
    char userName[50];
    char stopName[50];
    bool isCardActive;

public:
    User() {}

    User(const char *id, const char *n, const char *stop, bool card = true) : isCardActive(card)
    {
        strcpy(userID, id);
        strcpy(userName, n);
        strcpy(stopName, stop);
    }

    virtual void payFees() = 0;

    void updateStop(const char *stop)
    {
        strcpy(stopName, stop);
        cout << "Stop updated successfully to " << stopName << endl;
    }

    virtual void displayUserInfo() const
    {
        cout << endl
             << "User Name: " << userName << endl;
        cout << "User ID: " << userID << endl;
        cout << "User's Stop Name: " << stopName << endl;
        cout << "Card: " << ((isCardActive) ? "Active" : "Not Active") << endl;
    }

    virtual void saveToFile(ofstream &out) const
    {
        out.write(userID, sizeof(userID));
        out.write(userName, sizeof(userName));
        out.write(stopName, sizeof(stopName));
        out.write(reinterpret_cast<const char *>(&isCardActive), sizeof(isCardActive));
    }

    virtual void readFromFile(ifstream &in)
    {
        in.read(userID, sizeof(userID));
        in.read(userName, sizeof(userName));
        in.read(stopName, sizeof(stopName));
        in.read(reinterpret_cast<char *>(&isCardActive), sizeof(isCardActive));
    }

    const char *getUserID() const { return userID; }
    const char *getUserName() const { return userName; }
    const char *getStopName() const { return stopName; }
    bool getIsCardActive() const { return isCardActive; }

    virtual ~User() {}
};

class Student : public User
{
    bool attendanceList[31];

public:
    Student() {}

    Student(const char *id, const char *n, const char *stop, bool card = true) : User(id, n, stop, card)
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

        cout << endl
             << "Displaying attendance for " << userName << endl;
        for (int i = 0; i < 31; i++)
        {
            cout << "Day " << (i + 1) << ": " << ((attendanceList[i]) ? "Present" : "Absent") << endl;
        }
    }

    void saveToFile(ofstream &out) const override
    {
        User::saveToFile(out);
        out.write(reinterpret_cast<const char *>(attendanceList), sizeof(attendanceList));
    }

    void readFromFile(ifstream &in) override
    {
        User::readFromFile(in);
        in.read(reinterpret_cast<char *>(attendanceList), sizeof(attendanceList));
    }
};

class Teacher : public User
{
public:
    Teacher() {}

    Teacher(const char *id, const char *n, const char *stop, bool card = true) : User(id, n, stop, card) {}

    void payFees() override
    {
        cout << "Transport monthly fees paid successfully for teacher: " << userName << endl;
    }
};

class Staff : public User
{
public:
    Staff() {}

    Staff(const char *id, const char *n, const char *stop, bool card = true) : User(id, n, stop, card) {}

    void payFees() override
    {
        cout << "Transport weekly fees paid successfully for staff: " << userName << endl;
    }
};

class Bus
{
    char busID[50];
    char busName[50];
    char (*stops)[50]; // dynamic 1D array of C-strings (char[50])
    int numStops;
    const int maxStops;

public:
    Bus(const char *id, const char *n, int mStops) : maxStops(mStops), numStops(0)
    {
        strncpy(busID, id, sizeof(busID));
        busID[sizeof(busID) - 1] = '\0';

        strncpy(busName, n, sizeof(busName));
        busName[sizeof(busName) - 1] = '\0';

        stops = new char[maxStops][50];
    }

    void addStop(const char *stopName)
    {
        if (numStops >= maxStops)
        {
            cout << "The maximum limit of stops for bus " << busName << "(" << busID << ") has been reached. Cannot add further stops." << endl;
            return;
        }

        strncpy(stops[numStops], stopName, 50);
        stops[numStops][49] = '\0';
        numStops++;

        cout << "Stop: " << stopName << " has been added to the route of bus " << busName << " (" << busID << ")." << endl;
    }

    void removeStop(const char *stopName)
    {
        int i, flag = 0;
        for (i = 0; i < numStops; i++)
        {
            if (strcmp(stops[i], stopName) == 0)
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
            strncpy(stops[j], stops[j + 1], 50);
        }
        numStops--;
        cout << "Stop: " << stopName << " removed from bus " << busName << "'s route." << endl;
    }

    void displayBusInfo() const
    {
        cout << endl
             << "Bus Name: " << busName << endl;
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
            if (strcmp(stops[i], other.stops[i]) != 0)
            {
                return false;
            }
        }

        return true;
    }

    const char *getBusID() const { return busID; }

    void saveToFile(ofstream &out) const
    {
        out.write(busID, sizeof(busID));
        out.write(busName, sizeof(busName));
        out.write(reinterpret_cast<const char *>(&numStops), sizeof(numStops));
        for (int i = 0; i < numStops; i++)
        {
            out.write(stops[i], 50);
        }
    }

    void readFromFile(ifstream &in)
    {
        in.read(busID, sizeof(busID));
        in.read(busName, sizeof(busName));
        in.read(reinterpret_cast<char *>(&numStops), sizeof(numStops));
        for (int i = 0; i < numStops; i++)
        {
            in.read(stops[i], 50);
        }
    }

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
            users[numUsers++] = new Student(id.c_str(), userName.c_str(), stopName.c_str());
        }
        else if (userType == "teacher")
        {
            users[numUsers++] = new Teacher(id.c_str(), userName.c_str(), stopName.c_str());
        }
        else if (userType == "staff")
        {
            users[numUsers++] = new Staff(id.c_str(), userName.c_str(), stopName.c_str());
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

        buses[numBuses++] = new Bus(id.c_str(), busName.c_str(), maxStops);
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
            buses[i]->addStop(stop.c_str());
        }

        cout << "Stops defined for bus ID: " << buses[i]->getBusID() << " successfully." << endl;
    }

    static int getTotalUser()
    {
        return totalUsers;
    }

    void saveUsersToFile(ofstream &out) const
    {
        if (!out)
            throw FileException("Error opening user file for saving!");

        out.write(reinterpret_cast<const char *>(&numUsers), sizeof(numUsers));
        for (int i = 0; i < numUsers; i++)
        {
            char type;
            if (dynamic_cast<Student *>(users[i]))
                type = 'S';
            else if (dynamic_cast<Teacher *>(users[i]))
                type = 'T';
            else
                type = 'F';

            out.write(&type, sizeof(type));
            users[i]->saveToFile(out);
        }
    }

    void saveBusesToFile(ofstream &out) const
    {
        if (!out)
            throw FileException("Error opening bus file for saving!");

        out.write(reinterpret_cast<const char *>(&numBuses), sizeof(numBuses));
        for (int i = 0; i < numBuses; i++)
        {
            buses[i]->saveToFile(out);
        }
    }

    void readUsersFromFile(ifstream &in)
    {
        if (!in)
            throw FileException("Error opening user file for reading!");

        in.read(reinterpret_cast<char *>(&numUsers), sizeof(numUsers));
        users = new User *[maxUsers];
        for (int i = 0; i < numUsers; i++)
        {
            char type;
            in.read(&type, sizeof(type));
            if (type == 'S')
                users[i] = new Student();
            else if (type == 'T')
                users[i] = new Teacher();
            else if (type == 'F')
                users[i] = new Staff();
            else
                throw FileException("Unknown user type in user file.");

            users[i]->readFromFile(in);
        }
    }

    void readBusesFromFile(ifstream &in)
    {
        if (!in)
            throw FileException("Error opening bus file for reading!");

        in.read(reinterpret_cast<char *>(&numBuses), sizeof(numBuses));
        buses = new Bus *[maxBuses];
        for (int i = 0; i < numBuses; i++)
        {
            buses[i] = new Bus("", "", 0);
            buses[i]->readFromFile(in);
        }
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
    cout << "Rayyan Aamir, 24K-0687, BCS-2F" << endl
         << endl;
    int maxUsers, maxBuses;
    cout << "Enter the maximum number of users: ";
    cin >> maxUsers;
    cout << "Enter the maximum number of buses: ";
    cin >> maxBuses;
    cin.ignore();

    Transportation transport(maxUsers, maxBuses);

    ifstream userFile("users.dat", ios::binary);
    if (userFile)
    {
        try
        {
            transport.readUsersFromFile(userFile);
            cout << "User data loaded successfully from users.dat.\n";
        }
        catch (const exception &e)
        {
            cerr << "Error loading user data: " << e.what() << endl;
        }
        userFile.close();
    }
    else
    {
        cout << "No previous user data file found. Starting fresh.\n";
    }

    ifstream busFile("buses.dat", ios::binary);
    if (busFile)
    {
        try
        {
            transport.readBusesFromFile(busFile);
            cout << "Bus data loaded successfully from bus.dat.\n";
        }
        catch (const exception &e)
        {
            cerr << "Error loading bus data: " << e.what() << endl;
        }
        busFile.close();
    }
    else
    {
        cout << "No previous bus data file found. Starting fresh.\n";
    }

    int choice;
    do
    {
        cout << endl
             << "------- Transportation System Menu -------" << endl;
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
            cout << "Total registered users: " << Transportation::getTotalUser() << endl;
            break;

        case 7:
        {
            ofstream outUsers("users.dat", ios::binary);
            if (outUsers)
            {
                transport.saveUsersToFile(outUsers);
                outUsers.close();
                cout << "User data saved to users.dat.\n";
            }
            else
            {
                cerr << "Error opening users.dat for saving.\n";
            }

            ofstream outBuses("buses.dat", ios::binary);
            if (outBuses)
            {
                transport.saveBusesToFile(outBuses);
                outBuses.close();
                cout << "Bus data saved to bus.dat.\n";
            }
            else
            {
                cerr << "Error opening bus.dat for saving.\n";
            }

            cout << "Exiting program. Thank you!\n";
            break;
        }

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
