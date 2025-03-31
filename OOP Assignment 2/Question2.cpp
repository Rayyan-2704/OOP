#include <iostream>
using namespace std;

class Ghost
{
protected:
    string name;
    int scareLevel;
    string hauntingType;

public:
    Ghost(string n, int sL, string hT) : name(n), scareLevel(sL), hauntingType(hT) {}

    virtual void haunt()
    {
        cout << "Ghost " << name << " haunting with a scare level of " << scareLevel << endl;
    };

    string getGhostName() const { return name; }
    int getScareLevel() const { return scareLevel; }
    string getHauntingType() const { return hauntingType; }

    virtual ~Ghost() {}

    friend ostream &operator<<(ostream &, const Ghost &);

    Ghost *operator+(const Ghost &other)
    {
        // Assuming that when two Ghost objects are added a new ShadowPoltergeist forms
        return new Ghost(this->name + " & " + other.name, this->scareLevel + other.scareLevel, "haunts everything");
    }
};

ostream &operator<<(ostream &out, const Ghost &g)
{
    out << endl << "--------------- Displaying Ghost Details ---------------" << endl;
    out << "Name: " << g.name << " | Scare Level: " << g.scareLevel << " | Haunting Type: " << g.hauntingType << endl;
    return out;
}

class Poltergeist : virtual public Ghost
{
protected:
    string object;

public:
    Poltergeist(string n, string obj) : Ghost(n, 4, "move objects around"), object(obj) {}

    void haunt() override
    {
        cout << "Poltergeist " << name << " is moving " << object << " around. Scare Level: " << scareLevel << endl;
    }

    string getObject() const { return object; }
};

class Banshee : virtual public Ghost
{
public:
    Banshee(string n) : Ghost(n, 6, "scream loudly") {}

    void haunt() override
    {
        cout << "Banshee " << name << " is screaming loudly. Scare Level: " << scareLevel << endl;
    }
};

class ShadowGhost : virtual public Ghost
{
public:
    ShadowGhost(string n) : Ghost(n, 7, "whisper creepily") {}

    void haunt() override
    {
        cout << "Shadow Ghost " << name << " is whispering creepily. Scare Level: " << scareLevel << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost
{
public:
    ShadowPoltergeist(string n, string obj) : Ghost(n, 9, "whisper creepily and move objects around"), Poltergeist(n, obj), ShadowGhost(n) {}

    void haunt() override
    {
        cout << "Shadow Poltergeist " << name << " is moving " << object << " around and whispering creepily. Scare Level: " << scareLevel << endl;
    }
};

class ShadowBanshee : public Banshee, public ShadowGhost
{
public:
    ShadowBanshee(string n) : Ghost(n, 8, "whisper creepily and scream loudly"), Banshee(n), ShadowGhost(n) {}

    void haunt() override
    {
        cout << "Shadow Banshee " << name << " is whispering creepily and screaming loudly. Scare Level: " << scareLevel << endl;
    }
};

class PoltergeistBanshee : public Poltergeist, public Banshee
{
public:
    PoltergeistBanshee(string n, string obj) : Ghost(n, 10, "scream loudly and move objects around"), Poltergeist(n, obj), Banshee(n) {}

    void haunt() override
    {
        cout << "Poltergeist Banshee " << name << " is moving " << object << " around and screaming loudly. Scare Level: " << scareLevel << endl;
    }
};

class Visitor
{
    string name;
    int braveryLevel;

public:
    Visitor(string n, int bL) : name(n), braveryLevel(bL) {}

    string getVisitorName() const { return name; }
    int getBraveryLevel() const { return braveryLevel; }
};

class HauntedHouse
{
    string name;
    Ghost **ghosts; // 1D pointer array of Ghost object pointers (Aggregation)
    int numGhosts;
    int maxGhosts;

public:
    HauntedHouse(string n, int max) : name(n), maxGhosts(max), numGhosts(0)
    {
        ghosts = new Ghost *[maxGhosts];
    }

    void addGhost(Ghost *g)
    {
        if (numGhosts >= maxGhosts)
        {
            cout << "Maximum limit of ghosts reached for Haunted House: " << name << endl;
            return;
        }

        ghosts[numGhosts++] = g;
        cout << "Ghost " << g->getGhostName() << " has been added successfully to Haunted House: " << name << endl;
    }

    void simulation(Visitor *v)
    {
        cout << endl << v->getVisitorName() << " is entering Haunted House: " << name << endl;

        for (int i = 0; i < numGhosts; i++)
        {
            if (ghosts[i]->getScareLevel() < v->getBraveryLevel())
            {
                cout << v->getVisitorName() << " is laughing and taunting at " << ghosts[i]->getGhostName() << endl;
            }
            else
            {
                cout << v->getVisitorName() << " is screaming and running away from " << ghosts[i]->getGhostName() << endl;
            }
        }

        cout << v->getVisitorName() << " has successfully survived Haunted House: " << name << endl;
    }

    ~HauntedHouse()
    {
        delete[] ghosts;
    }
};

void visit(Visitor **visitors, HauntedHouse *house, int numVisitors)
{
    for (int i = 0; i < numVisitors; i++)
    {
        house->simulation(visitors[i]);
    }
}

int main()
{
    HauntedHouse *houses[3] = {
        new HauntedHouse("Phantom Manor", 5),
        new HauntedHouse("Nightmare Hollow", 5),
        new HauntedHouse("Whispering Pines", 5)};

    Ghost *ghosts[12] = {
        new Poltergeist("Rattling Roger", "Shelf"),
        new Banshee("Wailing Wendy"),
        new ShadowGhost("Whispering William"),
        new ShadowPoltergeist("Murking Maxwell", "Piano"),
        new Poltergeist("Phantom Pusher", "Table"),
        new Banshee("Shreaking Sheila"),
        new ShadowGhost("Lurking Lucy"),
        new ShadowBanshee("Echoing Eleanor"),
        new Poltergeist("Banging Benny", "Bed"),
        new Banshee("Howling Heather"),
        new ShadowGhost("Gloomy Greg"),
        new PoltergeistBanshee("Raging Rowena", "Sofa")};

    Visitor *visitors[4] = {
        new Visitor("Matt", 7),
        new Visitor("Ollie", 6),
        new Visitor("Lewis", 9),
        new Visitor("Charles", 4)};

    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            houses[i]->addGhost(ghosts[counter++]);
        }
    }

    visit(visitors, houses[0], 4);
    visit(visitors, houses[1], 4);
    visit(visitors, houses[2], 4);

    /* Operator Overloading Function Test */
    cout << *ghosts[0];
    Ghost *g = *ghosts[1] + *ghosts[2];
    cout << *g;
    delete g;

    for (int i = 0; i < 3; i++)
    {
        delete houses[i];
    }

    for (int i = 0; i < 12; i++)
    {
        delete ghosts[i];
    }

    for (int i = 0; i < 4; i++)
    {
        delete visitors[i];
    }

    return 0;
}