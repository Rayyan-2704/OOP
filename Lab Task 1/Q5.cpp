/* Q5: Design Event Management System in C++ to facilitate the organization of
events. The program should empower the user to seamlessly manage event
details, including the event name, date, venue, and organizer. Incorporate key
features such as the ability to add events, display comprehensive details of all
events, and perform event searches based on specific dates. To enhance
flexibility and scalability, leverage dynamic memory allocation for storing event
details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input:
   --> Event Name
   --> Date
   --> Venue
   --> Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date. */

#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    string name;
    Date d;
    string venue;
    string organizer;
} Event;

void initializeEvents(Event **e, int *n)
{
    cout << "Enter the total number of events: ";
    cin >> *n;

    if (*n <= 0)
    {
        cout << "Invalid number of events. Please enter a positive number." << endl;
        return;
    }

    if (*e != nullptr)
    {
        delete[] *e;
        *e = nullptr;
    }

    *e = new Event[*n];

    for (int i = 0; i < *n; i++)
    {
        cout << endl
             << "Enter the details of event " << (i + 1) << " : " << endl;
        cout << "Enter the name of the event: ";
        cin >> (*e)[i].name;
        cout << "Enter the date of the event (dd mm yyyy): ";
        cin >> (*e)[i].d.day >> (*e)[i].d.month >> (*e)[i].d.year;
        cout << "Enter the venue of the event: ";
        cin >> (*e)[i].venue;
        cout << "Enter the organizer of the event: ";
        cin >> (*e)[i].organizer;
    }
}

void displayEvents(Event *e, int n)
{
    if (e == nullptr || n <= 0)
    {
        cout << "No events have been initialized yet." << endl;
        return;
    }

    cout << endl
         << "Displaying the details of the events below: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Event " << (i + 1) << " : " << endl;
        cout << "Name: " << e[i].name << endl;
        cout << "Venue: " << e[i].venue << endl;
        cout << "Organizer: " << e[i].organizer << endl;
        cout << "Date (dd/mm/yyyy): " << e[i].d.day << "/" << e[i].d.month << "/" << e[i].d.year << endl;
    }
}

void searchEvents(Event *e, int n)
{
    if (e == nullptr || n <= 0)
    {
        cout << "No events have been initialized yet." << endl;
        return;
    }

    int userDay, userMonth, userYear;
    cout << "Enter the date (dd mm yyyy): ";
    cin >> userDay >> userMonth >> userYear;

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (userDay == e[i].d.day && userMonth == e[i].d.month && userYear == e[i].d.year)
        {
            cout << "Event found:" << endl;
            cout << "Name: " << e[i].name << endl;
            cout << "Venue: " << e[i].venue << endl;
            cout << "Organizer: " << e[i].organizer << endl;
            cout << "Date (dd/mm/yyyy): " << e[i].d.day << "/" << e[i].d.month << "/" << e[i].d.year << endl;
            flag = 1;
        }
    }

    if (!(flag))
    {
        cout << "No event found that corresponds to your search." << endl;
    }
}

void addEvent(Event **e, int *n)
{
    if (e == nullptr || n <= 0)
    {
        cout << "No events have been initialized yet." << endl;
        return;
    }

    Event *newEvents = new Event[*n + 1]; // Creating a new array

    for (int i = 0; i < (*n); i++) // Copying the existing events into the new array
    {
        newEvents[i] = (*e)[i];
    }

    delete[] *e;
    *e = newEvents;

    // Taking input for the new event
    cout << endl
         << "Enter the details of the new event: " << endl;
    cout << "Enter the name of the event: ";
    cin >> (*e)[*n].name;
    cout << "Enter the date of the event (dd mm yyyy): ";
    cin >> (*e)[*n].d.day >> (*e)[*n].d.month >> (*e)[*n].d.year;
    cout << "Enter the venue of the event: ";
    cin >> (*e)[*n].venue;
    cout << "Enter the organizer of the event: ";
    cin >> (*e)[*n].organizer;

    (*n)++; // Incrementing the total number of events
}

int main()
{
    int num;
    Event *events = nullptr;
    int choice;

    cout << "----- Design Event Management System Menu -----" << endl;
    cout << "Enter 1 for initialization of events" << endl;
    cout << "Enter 2 to display all the events" << endl;
    cout << "Enter 3 to search events by date" << endl;
    cout << "Enter 4 to add a new event" << endl;
    cout << "Enter 5 to exit" << endl;

    while (1)
    {
        cout << endl
             << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            initializeEvents(&events, &num);
            break;
        case 2:
            displayEvents(events, num);
            break;
        case 3:
            searchEvents(events, num);
            break;
        case 4:
            addEvent(&events, &num);
            break;
        case 5:
            cout << "Exiting the program...." << endl;
            delete[] events;
            return 0;
        }
    }
}