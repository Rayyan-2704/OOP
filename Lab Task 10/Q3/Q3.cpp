#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream createChapter1("chapter1.txt");
    createChapter1 << "Chapter 1: The Introduction" << endl;
    createChapter1 << "Once upon a time, there lived a French boy named Jules Kounde." << endl;
    createChapter1 << "He dreamt of playing professional football." << endl;
    createChapter1.close();

    ofstream createChapter2("chapter2.txt");
    createChapter2 << "Chapter 2: The Hunt For Glory Continues" << endl;
    createChapter2 << "Jules worked hard and rose quickly through the divisions of French football." << endl;
    createChapter2 << "His hardwork was acknowledged and he signed for FC Barcelona, the Spanish giant." << endl;
    createChapter2.close();

    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios :: app);

    if(!chapter1.is_open() || !chapter2.is_open() || !book.is_open()){
        cerr << "Error in opening the files!" << endl;
        return 1;
    }

    string line;
    while(getline(chapter1, line)){
        book << line << endl;
    }

    while(getline(chapter2, line)){
        book << line << endl;
    }

    chapter1.close();
    chapter2.close();
    book.close();

    ifstream readBook("book.txt");
    cout << "Reading the contents of the book:" << endl;
    while(getline(readBook, line)){
        cout << line << endl;
    }
    readBook.close();

    return 0;
}