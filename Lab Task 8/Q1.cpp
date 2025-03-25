/* In a modern smart home, different devices such as lights, fans, air conditioners, and security systems are controlled through a central automation hub. The system must manage various electronic appliances,
allowing authorized users to monitor and control their power consumption, adjust settings, and schedule automated tasks. However, sensitive security system controls should not be accessible to regular users
and must only be accessed by authorized maintenance staff via a special diagnostic tool. The system should also be capable of calculating the power consumption of each appliance based on usage duration and
device type.
Attributes & Functionality Requirements

1. Device Management
Each device should have:
Device ID (string) – A unique identifier for each appliance.
Device Type (string) – Specifies if it is a light, fan, AC, or security system.
Power Rating (double) – Power consumption per hour in watts.
Status (bool) – Whether the device is ON or OFF.
A function void turnOn() to turn the device ON.
A function void turnOff() to turn the device OFF.
A function double calculatePowerUsage(int hours) to compute energy consumption:
Lights consume energy based on simple multiplication: powerRating * hours.
Fans have variable speed settings affecting power consumption (powerRating * hours * speedFactor).
Air Conditioners adjust power dynamically based on room temperature (powerRating * hours * (1 - (currentTemp - desiredTemp) / 100)).
Security Systems have fixed power consumption, but should include a security status check in power calculation.

2.User Management
Each user should have:
User ID (string) – A unique identifier for each person.
User Role (string) – Defines if the user is a Regular User or Maintenance Staff.
Access Level (int) – Determines whether they can view/edit security devices.
A function void viewAccessibleDevices() – Displays only the devices they are allowed to control.

3. Special Security Controls
Security system details (such as camera status and intrusion alerts) should not be accessible to regular users.
Only maintenance staff should have access through a friend function:
void accessSecurityLogs() – Allows authorized personnel to check security status.

Function Prototypes and Overriding Requirement
1. void turnOn() and void turnOff() should be present in all devices but should:
Lights & Fans: Simple ON/OFF state change.
ACs: Also adjust the temperature settings.
Security Systems: Require authorization check before turning OFF.

2. double calculatePowerUsage(int hours) should be overridden:
Lights: powerRating * hours.
Fans: powerRating * hours * speedFactor.
ACs: powerRating * hours * (1 - (currentTemp - desiredTemp) / 100).
Security Systems: Fixed consumption + log security status.

3. Friend Function: void accessSecurityLogs()
Allows only maintenance staff to view logs and system diagnostics.
Regular users cannot see logs even if they try.

4. Friend Class: MaintenanceTool
Friend of Security Systems, allowing maintenance personnel to reset security. */

#include <iostream>
using namespace std;

class DeviceManagement
{
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

public:
    DeviceManagement(string id, string type, double pR, bool s) : deviceID(id), deviceType(type), powerRating(pR), status(s) {}

    virtual void turnOn()
    {
        status = true;
    }

    virtual void turnOff()
    {
        status = false;
    }

    virtual double calculatePowerUsage(int hours) = 0;

    string getDeviceID() const { return deviceID; }
    string getDeviceType() const { return deviceType; }
    bool getStatus() const { return status; }
};

class Light : public DeviceManagement
{
public:
    Light(string id, string type, double pR, bool s) : DeviceManagement(id, type, pR, s) {}

    void turnOn() override
    {
        DeviceManagement :: turnOn();
        cout << deviceType << " [ID: " << deviceID << "] turned ON." << endl;
    }

    void turnOff() override
    {
        DeviceManagement :: turnOff();
        cout << deviceType << " [ID: " << deviceID << "] turned OFF." << endl;
    }

    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours;
    }
};

class Fan : public DeviceManagement
{
    double speedFactor;

public:
    Fan(string id, string type, double pR, bool s, double sF) : DeviceManagement(id, type, pR, s), speedFactor(sF) {}

    void turnOn() override
    {
        DeviceManagement :: turnOn();
        cout << deviceType << " [ID: " << deviceID << "] turned ON at Speed " << speedFactor << "." << endl;
    }

    void turnOff() override
    {
        DeviceManagement :: turnOff();
        cout << deviceType << " [ID: " << deviceID << "] turned OFF." << endl;
    }

    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours * speedFactor;
    }
};

class AC : public DeviceManagement
{
    double currentTemp;
    double desiredTemp;

public:
    AC(string id, string type, double pR, bool s, double cT, double dT) : DeviceManagement(id, type, pR, s), currentTemp(cT), desiredTemp(dT) {}

    void turnOn() override
    {
        if (desiredTemp < currentTemp)
        {
            DeviceManagement :: turnOn();
            cout << deviceType << " [ID: " << deviceID << "] turned ON. Cooling to " << desiredTemp << "\xF8 C." << endl;
            currentTemp = desiredTemp;
        }
    }

    void turnOff() override
    {
        if (desiredTemp == currentTemp)
        {
            DeviceManagement :: turnOff();
            cout << deviceType << " [ID: " << deviceID << "] turned OFF." << endl;
        }
    }

    double calculatePowerUsage(int hours) override
    {
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100);
    }
};

class SecuritySystems : public DeviceManagement
{
    const string password;

public:
    SecuritySystems(string id, string type, double pR, bool s, string pwd) : DeviceManagement(id, type, pR, s), password(pwd) {}

    void turnOn() override
    {
        string p;
        cout << "Enter password to turn on the security systems: ";
        cin >> p;
        if (p == password)
        {
            DeviceManagement :: turnOn();
            cout << deviceType << " [ID: " << deviceID << "] activated." << endl;
        }
        else
        {
            cout << "Incorrect password. Security system remains deactivated." << endl;
        }
    }

    void turnOff() override
    {
        string p;
        cout << "Enter password to turn off the security systems: ";
        cin >> p;
        if (p == password)
        {
            DeviceManagement :: turnOff();
            cout << deviceType << " [ID: " << deviceID << "] deactivated." << endl;
        }
        else
        {
            cout << "Incorrect password. Security system remains activated." << endl;
        }
    }

    double calculatePowerUsage(int hours) override
    {
        return (status) ? 100 * hours : 0;
    }

    friend class MaintenanceTool;
};

class UserManagement
{
protected:
    string userID;
    string userRole;
    int accessLevel;

public:
    UserManagement(string id, string role, int aL) : userID(id), userRole(role), accessLevel(aL) {}

    virtual void viewAccessibleDevices() = 0;

    string getUserID() const { return userID; }
    string getUserRole() const { return userRole; }
    int getAccessLevel() const { return accessLevel; }
};

class RegularUser : public UserManagement
{
public:
    RegularUser(string id, string role, int aL) : UserManagement(id, role, aL) {}

    void viewAccessibleDevices() override
    {
        cout << "Regular Users can view lights, fans and ACs." << endl;
    }
};

class MaintenanceStaff : public UserManagement
{
public:
    MaintenanceStaff(string id, string role, int aL) : UserManagement(id, role, aL) {}

    void viewAccessibleDevices() override
    {
        cout << "Maintenance Staff can view all devices including Security Systems." << endl;
    }

    friend void accessSecurityLogs(MaintenanceStaff &);
};

class MaintenanceTool
{
public:
    void resetSecurity(SecuritySystems &s)
    {
        s.status = false;
        cout << "Security System reset by Maintenance Tool." << endl;
    }
};

void accessSecurityLogs(MaintenanceStaff &m)
{
    cout << m.getUserID() << " has accessed the security logs." << endl;
}

int main()
{
    Light light1("L001", "LED Light", 50, false);
    Fan fan1("F001", "Ceiling Fan", 75, false, 1.5);
    AC ac1("AC001", "Split AC", 1000, false, 30, 25);
    SecuritySystems s1("S001", "Home Alarm", 100, true, "admin123");

    RegularUser regularUser("U001", "Regular User", 1);
    MaintenanceStaff maintenanceStaff("U002", "Maintenance Staff", 2);

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    s1.turnOff();

    cout << "Light Power Usage: " << light1.calculatePowerUsage(5) << " watts" << endl;
    cout << "Fan Power Usage: " << fan1.calculatePowerUsage(3) << " watts" << endl;
    cout << "AC Power Usage: " << ac1.calculatePowerUsage(6) << " watts" << endl;
    cout << "Security System Power Usage: " << s1.calculatePowerUsage(24) << " watts" << endl;

    regularUser.viewAccessibleDevices();
    maintenanceStaff.viewAccessibleDevices();

    MaintenanceTool tool;
    tool.resetSecurity(s1);

    accessSecurityLogs(maintenanceStaff);
    return 0;
}
