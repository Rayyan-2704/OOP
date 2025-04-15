#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book :: Book() {}
Book :: Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn) {}

string Book :: getTitle() const {
    return title;
}

string Book :: getAuthor() const {
    return author;
}

string Book :: getISBN() const {
    return ISBN;
}