#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

Library::Library(int max) : booksCount(0), maxBooks(max) {
    books = new Book*[max];
}

void Library::addBook(Book *b) {
    if(booksCount >= maxBooks) {
        cout << " Maximum book limit has been reached" << endl;
        return;
    }

    books[booksCount] = b;
    booksCount++;
    cout << "Book: " << b->getTitle() << " has been added to the Library inventory!" << endl;
}

void Library::removeBook(const string& isbn) {
    int index = -1;

    for(int i = 0; i < booksCount; i++) {
        if(books[i]->getISBN() == isbn) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        cout << "Book with ISBN " << isbn << " not found!" << endl;
        return;
    }

    string removedTitle = books[index]->getTitle();
    delete books[index];

    for(int i = index; i < booksCount - 1; i++) {
        books[i] = books[i + 1];
    }

    booksCount--;
    books[booksCount] = nullptr;

    cout << "Book: " << removedTitle << " has been removed from the Library inventory!" << endl;
}

void Library::searchBook(const string& isbn) {
    int flag = 0;
    int index;

    for(int i = 0; i < booksCount; i++) {
        if(books[i]->getISBN() == isbn) {
            flag = 1;
            index = i;
        }
    }

    if(!flag) {
        cout << "Book with ISBN " << isbn << " not found!" << endl;
        return;
    }

    cout << "Book with ISBN " << isbn << " found! Displaying details below:" << endl;
    cout << "Title: " << books[index]->getTitle() << " | Author: " << books[index]->getAuthor() << " | ISBN: " << books[index]->getISBN() << endl;
}

void Library::displayAllBooks() const {
    if(booksCount == 0) {
        cout << "No books have been initialized yet." << endl;
        return;
    }
    
    for(int i = 0; i < booksCount; i++) {
        cout << "\nTitle: " << books[i]->getTitle() << " | Author: " << books[i]->getAuthor() << " | ISBN: " << books[i]->getISBN() << endl;
    }
}

Library::~Library() {
    for(int i = 0; i < booksCount; ++i) {
        delete books[i];
    }
    delete[] books;
}
