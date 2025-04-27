#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outputFile("info.txt", ios::out);
    if(!outputFile){
        cerr << "Error in opening info.txt for writing." << endl;
        return 1;
    }

    outputFile << "C++ is a powerful programming language." << endl;
    outputFile.close();

    fstream file("info.txt", ios::in | ios::out);
    if(!file){
        cerr << "Error in opening info.txt for reading and writing." << endl;
        return 1;
    }

    cout << "Initial position of get pointer: " << file.tellg() << endl;
    cout << "Initial position of put pointer: " << file.tellp() << endl;

    file.seekg(9);
    string word;
    file >> word;
    cout << "Word at position 9: " << word << endl;

    file.seekp(9);
    file << "dynamic ";
    file.flush();

    cout << "New position of get pointer: " << file.tellg() << endl;
    cout << "New position of put pointer: " << file.tellp() << endl;

    file.seekg(0);
    string line;
    cout << "Updated content of the file: ";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();

    return 0;
}