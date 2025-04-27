/* Q5. You're building a tool to search and replace a specific word in a text file without
rewriting the entire file.
Requirements:

1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
future. AI will transform the world. Embrace AI now.)
2. Prompt the user to enter:
○ A searchWord (e.g., "AI")
○ A replacementWord (e.g., "ML")
3. Open the file using fstream in ios::in | ios::out mode.
4. Search for the searchWord using seekg() and read sequentially.
5. When found:
○ Use tellg() to get the current read pointer location.
○ Use seekp() to position the write pointer.
○ Replace the word only if the replacement is of equal or smaller length to
avoid shifting content.

6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
"XX").
7. After all replacements, display the updated file. */

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream createFile("data.txt");
    if(!createFile){
        cerr << "Error in opening data.txt" << endl;
        return 1;
    }

    createFile << "AI is the future." << endl;
    createFile << "AI will transform the world." << endl;
    createFile << "Embrace AI now." << endl;
    createFile.close();

    string searchWord, replacementWord;
    cout << "Enter a word to search: ";
    cin >> searchWord;
    cout << "Enter a word to replace the searched word: ";
    cin >> replacementWord;

    do
    {
        if (replacementWord.length() > searchWord.length())
        {
            cout << "Replacement word must be equal or smaller in length than the search word." << endl;
            cout << "Enter replaced word again: " << endl;
            cin >> replacementWord;
        }
    } while (replacementWord.length() > searchWord.length());

    fstream file("data.txt", ios::in | ios::out);
    if(!file){
        cerr << "Cannot open data.txt" << endl;
        return 1;
    }

    char ch;
    string word;
    streampos pos;
    while(1){
        pos = file.tellg();
        word = "";

        for(int i = 0; i < searchWord.length(); i++){
            file.get(ch);
            if(file.eof()){
                break;
            }
            word += ch;
        }

        if(file.eof()){
            break;
        }

        if(word == searchWord){
            file.seekp(pos);
            file << replacementWord;

            for (int i = replacementWord.length(); i < searchWord.length(); i++){
                file.put(' ');
            }

            file.seekg(pos + (streamoff)searchWord.length());
        }
        else{
            file.seekg(pos + (streamoff)1);
        }
    }

    file.close();

    ifstream readFile("data.txt");
    if (!readFile){
        cerr << "Cannot open the file!" << endl;
        return 1;
    }
    
    cout << endl << "Updated File Content:" << endl;
    string line;
    while (getline(readFile, line)){
        cout << line << endl;
    }
    readFile.close();

    return 0;
}