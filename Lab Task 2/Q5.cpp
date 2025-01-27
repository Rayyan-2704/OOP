#include <iostream>
#include <cstring>
using namespace std;

char* shifting(char* str, int n){
    int length = strlen(str);
    if(n > length || n<=0){
        cout << "Invalid value of \'n\' entered.";
        return nullptr;
    }

    char *newStr = new char[length + 1]; // length + 1 to include the null terminator '\0'
    int index = 0;
    for(int i = length-n ; i<length ; i++){
        newStr[index] = str[i];
        index++;
    }

    for(int i=0 ; i < length-n ; i++){
        newStr[index] = str[i];
        index++;
    }
    newStr[index] = '\0';
    return newStr;
}

int main(){
    char str[50];
    cout << "Enter a string: ";
    cin.getline(str, 50);

    int n;
    cout << "Enter the number of characters to shift (n): ";
    cin >> n;

    char *newStr = shifting(str, n);
    if(newStr != nullptr){
        cout << "Shifted string after shifting last " << n << " characters: " << newStr << endl;
        delete[] newStr;
    }

    return 0;
}
