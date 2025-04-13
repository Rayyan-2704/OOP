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