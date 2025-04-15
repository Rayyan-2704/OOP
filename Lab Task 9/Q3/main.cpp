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

    do {
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                string title, author, isbn;
                cin.ignore();
                cout << "Enter the title of the book: ";
                getline(cin, title);
                cout << "Enter the author of the book: ";
                getline(cin, author);
                cout << "Enter the ISBN of the book: ";
                getline(cin, isbn);
                lib.addBook(new Book(title, author, isbn));
                break;
            }

            case 2: {
                string isbn;
                cin.ignore();
                cout << "Enter the ISBN of the book you want to remove: ";
                getline(cin, isbn);
                lib.removeBook(isbn);
                break;
            }

            case 3: {
                string isbn;
                cin.ignore();
                cout << "Enter the ISBN of the book you want to search: ";
                getline(cin, isbn);
                lib.searchBook(isbn);
                break;
            }
            case 4: 
                lib.displayAllBooks();
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid choice entered." << endl;
        }
    } while(choice != 5);

    return 0;
}