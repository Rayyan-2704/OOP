#ifndef BOOK
#define BOOK

#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    string ISBN;

public:
    Book();
    Book(string t, string a, string isbn);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
};

#endif