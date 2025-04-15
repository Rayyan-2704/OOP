#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

int main() {
    Library lib(100);
    int choice;

    cout << "--------- Welcome to Library Management System ---------" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Remove a Book" << endl;
    cout << "3. Search a Book" << endl;
    cout << "4. Display All Books" << endl;
    cout << "5. Exit the program." << endl;
    cout << "Enter your choice:";
    cin >> choice;

    do {
    switch(choice) {
        case 1: {
            
        }

        case 2: {

        }

        case 3: {

        }
        case 4: 
            lib.displayAllBooks();
            break;

        default:
            cout << "Invalid choice entered.";
    }
    } while(choice != 4);

    return 0;
}