/* Vectors in C++ STL */
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(const vector <T> &v){
    cout << endl << "Displaying vector elements:" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << "Element at index " << i << ": " << v[i] << endl;
    }
}

template <class T>
T sum(vector <T> &v){
    T sum = 0;
    while(!v.empty()){  // Checks if the vector is empty or not
        sum += v.back();  // Acceses the last element 
        v.pop_back();
    }
    return sum;
}

int main(){
    vector <int> v1;
    int element, size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    
    for(int i = 0; i < size; i++){
        cout << "Enter the element at index " << i << ": ";
        cin >> element;
        v1.push_back(element); // Add element at the end
    }

    // v1.pop_back(); // Delete last element
    display(v1);

    vector <int> :: iterator iter = v1.begin();   // Places the iterator to the beginning of the vector (index 0)
    iter = v1.insert(iter, 566);   // inserts at beginning and returns new iterator pointing to 566 (index 0)
    iter = v1.insert(iter + 1, 304); // insert 304 after 566 (now at index 1). Iterator now points to index 1 where value 304 is stored at
    iter = v1.insert(iter + 1, 2, 22); // inserts 22 twice after 304 (at index 2 and 3). Iterator now points to index 2 where the first 22 is stored at
    
    display(v1);
    cout << "Sum of elements of the vector: " << sum(v1) << endl;


    vector <int> vec1;  // zero length integer vector
    display(vec1);
    
    vector <char> vec2(4);  // 4-element length character vector
    vec2.push_back('?');
    display(vec2);

    vector <char> vec3(vec2);  // 4-element length character vector copied from vec2
    display(vec3);
    vec3.push_back('!');
    display(vec3);
    display(vec2);
    
    vector <int> vec4(6, 3); // 6-element length integer vector with value of 3s
    display(vec4);
    
    vector <int> vec5 = {1, 2, 3, 4}; // 4-element length integer vector with elements: 1, 2, 3 and 4
    display(vec5);
    return 0;
}

/* Pointer Array using Vectors */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size = 5;
    vector <int*> ptrArray(size);

    for (int i = 0; i < ptrArray.size(); i++) {
        ptrArray[i] = new int(i * 10);
    }

    cout << "Array of pointers using vector:\n";
    for (int i = 0; i < ptrArray.size(); i++) {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ptrArray.size(); i++) {
        delete ptrArray[i];
    }

    return 0;
}

/* 2D Array using vectors */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 3;
    vector <vector <int>> matrix(rows);

    for (int i = 0; i < rows; i++) {
        int cols = i + 2;  // Varying column sizes
        matrix[i] = vector <int> (cols, 0);  // Assign a new vector to each row
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = i * 10 + j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // int rows = 3;
    // // Create an empty 2D vector
    // vector<vector<int>> matrix;

    // // Now give each row a different number of columns
    // for (int i = 0; i < rows; ++i) {
    //     int cols = i + 2;  // Just an example: row 0 has 2 cols, row 1 has 3 cols, etc.
    //     vector<int> row(cols, 0);  // Initialize each row with 'cols' number of 0s
    //     matrix.push_back(row);
    // }

    // // Assign and print values
    // for (int i = 0; i < matrix.size(); ++i) {
    //     for (int j = 0; j < matrix[i].size(); ++j) {
    //         matrix[i][j] = i * 10 + j;
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
