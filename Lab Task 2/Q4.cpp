/* You are required to write a C++ program that will creates a function named unique that will take array
as input . the array may contains the duplicates values but you have to process on the array and have to
return the array which must contains only unique values not duplicates. */

#include <iostream>
using namespace std;

int *unique(int arr[], int n, int &newSize);

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int sizeOfNewArray;
    int *arr = new int[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *newArr = unique(arr, n, sizeOfNewArray);
    cout << "Unique elements in the array are:";
    for (int i = 0; i < sizeOfNewArray; i++)
    {
        cout << " " << newArr[i];
    }

    delete[] arr;

    return 0;
}

int *unique(int arr[], int n, int &newSize)
{
    int freq[100] = {0};
    static int uniqueElements[100];
    newSize = 0;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        if (freq[arr[i]] == 1)
        {
            uniqueElements[newSize] = arr[i];
            newSize++;
        }
    }

    return uniqueElements;
}