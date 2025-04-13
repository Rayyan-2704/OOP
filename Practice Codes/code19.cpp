/* File I/O: Reading and Writing Files in C++ */
#include <iostream>
#include <fstream>
using namespace std;

/* 
The useful classes for working with files in C++ are:
1. fstreambase 
2. ifstream ---> derived from fstreambase
3. ofstream ---> derived from fstreambase

In order to work with files in C++, you will have to open it. Primarly, there are 2 ways to open a file:
1. Using the constructor
2. Using the member function open() of the class
*/

int main(){
    string str1 = "Visca el Barca, Visca el Catalonia";
    
    // // Opening files using constructor and writing to it 
    // ofstream out("sample1.txt"); // Write operation
    // out << str1;

    // Opening files using constructor and reading it
    string str2;
    ifstream in("sample2.txt");
    // in >> str2;  ---> this doesn't read whitespaces and newline
    getline(in, str2);
    cout << str2 << endl;
    return 0;
}

/* Read/Write in the same program and closing files */
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream hout("sample3.txt");
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    hout << "My name is " << name;
    hout.close();

    ifstream hin("sample3.txt");
    string content;
    getline(hin, content);
    cout << "The content of this file is: " << content << endl;
    hin.close();
    return 0;
}

/* Using open() and eof() member functions */
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out;
    out.open("sample4.txt");
    out << "This is me" << endl;
    out << "Rayyan Aamir" << endl;
    out.close();

    ifstream in;
    string str, str1, str2;
    in.open("sample4.txt");
    // getline(in, str1); // ---> reading line by line manually, not efficient
    // getline(in, str2);
    // cout << str1 << ", " << str2 << endl;

    // Reading the file via loop
    while(in.eof() == 0){  // ---> eof stands for end of file
        getline(in, str);
        cout << str << endl;
    }
    in.close();

    return 0;
}