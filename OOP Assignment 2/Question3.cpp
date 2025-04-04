#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string vehicleID;
    double speed;
    double capacity;
    double energyEfficiency;
    static int activeDeliveries;

public:
    Vehicle(string id, double s, double c, double e) : vehicleID(id), speed(s), capacity(c), energyEfficiency(e)
    {
        activeDeliveries++;
    }

    static int getActiveDeliveries() { return activeDeliveries; }

    virtual double estimatedDeliveryTime(double distance) = 0;
    virtual void optimalDeliveryRoute() = 0;
    virtual void command(const string &command, const string &packageID) {}
    virtual void command(const string &command, const string &packageID, const string &urgencyLevel) {}

    friend bool operator==(const Vehicle &, const Vehicle &);
    friend void resolveConflict(const Vehicle &, const Vehicle &);

    virtual ~Vehicle() {}
};

bool operator==(const Vehicle &v1, const Vehicle &v2)
{
    return (v1.speed == v2.speed && v1.capacity == v2.capacity && v1.energyEfficiency == v2.energyEfficiency);
}

int Vehicle ::activeDeliveries = 0;

class RamzanDrone : public Vehicle
{
public:
    RamzanDrone(string id, double s, double c, double e) : Vehicle(id, s, c, e) {}

    double estimatedDeliveryTime(double distance) override
    {
        cout << "Calculating estimated delivery time for Drone " << vehicleID << "'s aerial route..." << endl;
        return (distance / speed);
    }

    void optimalDeliveryRoute() override
    {
        cout << "Deciding optimal route for aerial route delivery for Drone " << vehicleID << endl;
    }

    void command(const string &command, const string &packageID) override
    {
        if (command == "Deliver")
        {
            cout << "Drone " << vehicleID << " delivering package " << packageID << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Drone " << vehicleID << " picking up package " << packageID << endl;
        }
    }

    void command(const string &command, const string &packageID, const string &urgencyLevel) override
    {
        if (command == "Deliver")
        {
            if (urgencyLevel == "High")
            {
                cout << "Drone delivering package " << packageID << " in high-speed mode for Iftar." << endl;
            }
            else
            {
                cout << "Drone " << vehicleID << " delivering package " << packageID << " in standard mode." << endl;
            }
        }
        else if (command == "Pick-up")
        {
            cout << "Drone " << vehicleID << " picking up package " << packageID << endl;
        }
    }
};

class RamzanTimeShip : public Vehicle
{
public:
    RamzanTimeShip(string id, double s, double c, double e) : Vehicle(id, s, c, e) {}

    double estimatedDeliveryTime(double distance) override
    {
        cout << "Ensuring time sensitivity for Time Ship " << vehicleID << "..." << endl;
        return (distance / speed);
    }

    void optimalDeliveryRoute() override
    {
        cout << "Deciding optimal route for historical delivery for Time Ship " << vehicleID << endl;
    }

    void command(const string &command, const string &packageID) override
    {
        if (command == "Deliver")
        {
            cout << "Time Ship " << vehicleID << " delivering package " << packageID << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Time Ship " << vehicleID << " picking up package " << packageID << endl;
        }
    }

    void command(const string &command, const string &packageID, const string &urgencyLevel) override
    {
        if (command == "Deliver")
        {
            if (urgencyLevel == "High")
            {
                cout << "Time Ship " << vehicleID << " delivering historically sensitive package " << packageID << " for Iftar." << endl;
            }
            else
            {
                cout << "Time Ship " << vehicleID << " delivering package " << packageID << " in standard mode." << endl;
            }
        }
        else if (command == "Pick-up")
        {
            cout << "Time Ship " << vehicleID << " picking up package " << packageID << endl;
        }
    }
};

class RamzanHyperPod : public Vehicle
{
public:
    RamzanHyperPod(string id, double s, double c, double e) : Vehicle(id, s, c, e) {}

    double estimatedDeliveryTime(double distance) override
    {
        cout << "Navigating underground tunnel network for Hyper Pod " << vehicleID << "..." << endl;
        return (distance / speed);
    }

    void optimalDeliveryRoute() override
    {
        cout << "Deciding optimal route for bulk transport for Hyper Pod " << vehicleID << endl;
    }

    void command(const string &command, const string &packageID) override
    {
        if (command == "Deliver")
        {
            cout << "Hyper Pod " << vehicleID << " delivering package " << packageID << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Hyper Pod " << vehicleID << " picking up package " << packageID << endl;
        }
    }

    void command(const string &command, const string &packageID, const string &urgencyLevel) override
    {
        if (command == "Deliver")
        {
            if (urgencyLevel == "High")
            {
                cout << "Hyper Pod " << vehicleID << " prioritizing bulk delivery for package " << packageID << "." << endl;
            }
            else
            {
                cout << "Hyper Pod " << vehicleID << " delivering package " << packageID << " in standard mode." << endl;
            }
        }
        else if (command == "Pick-up")
        {
            cout << "Hyper Pod " << vehicleID << " picking up package " << packageID << endl;
        }
    }
};

void resolveConflict(const Vehicle &v1, const Vehicle &v2)
{
    if (v1.energyEfficiency > v2.energyEfficiency)
    {
        cout << "Vehicle " << v1.vehicleID << " is chosen for delivery." << endl;
    }
    else if (v1.energyEfficiency < v2.energyEfficiency)
    {
        cout << "Vehicle " << v2.vehicleID << " is chosen for delivery." << endl;
    }
    else
    {
        cout << "Both vehicles have the same efficiency. Additional criteria needed." << endl;
    }
}

int main()
{
    RamzanDrone drone1("D001", 80.0, 5.0, 90.0);
    RamzanTimeShip ship1("S001", 50.0, 100.0, 85.0);
    RamzanHyperPod pod1("P001", 120.0, 500.0, 92.0);
    
    double distance = 200.0;
    cout << "Estimated delivery time (Drone 1): " << drone1.estimatedDeliveryTime(distance) << " hours" << endl;
    cout << "Estimated delivery time (Time Ship 1): " << ship1.estimatedDeliveryTime(distance) << " hours" << endl;
    cout << "Estimated delivery time (Hyper Pod 1): " << pod1.estimatedDeliveryTime(distance) << " hours" << endl;
    cout << endl << endl;

    drone1.optimalDeliveryRoute();
    ship1.optimalDeliveryRoute();
    pod1.optimalDeliveryRoute();
    cout << endl << endl;

    drone1.command("Deliver", "PKG123");
    ship1.command("Pick-up", "PKG456");
    pod1.command("Deliver", "PKG789", "High");
    cout << endl << endl;

    RamzanDrone drone2("D002", 80.0, 5.0, 90.0);
    if (drone1 == drone2)
    {
        cout << "Drone 1 and Drone 2 are considered identical in specs." << endl;
    }
    else
    {
        cout << "Drone 1 and Drone 2 have different specifications." << endl;
    }
    cout << endl << endl;

    cout << "Active deliveries: " << Vehicle::getActiveDeliveries() << endl;
    cout << endl << endl;

    cout << "Resolving conflict between Time Ship and Hyper Pod..." << endl;
    resolveConflict(ship1, pod1);

    return 0;
}
