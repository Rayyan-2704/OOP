#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Library {
    Book **books;
    int booksCount;
    const int maxBooks;

public:
    Library(int max);

    void addBook(Book *b);
    void removeBook(const string& isbn);
    void searchBook(const string& isbn);
    void displayAllBooks() const;

    ~Library();
};

#endif