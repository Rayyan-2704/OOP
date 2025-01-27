/* Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
  --> Calculate the average of the numbers.
  --> Find the number closest to the average.
  --> Print the average and the number closest to it.
  --> Use pointer notation wherever possible. */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    float *arr = new float(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element to be stored at index " << i << ": ";
        cin >> arr[i];
    }

    float avg, total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    avg = total / n;

    float closestNum = arr[0];
    float minimumDifference = abs(avg - arr[0]);
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        float difference = abs(avg - arr[i]);
        if (difference < minimumDifference)
        {
            minimumDifference = difference;
            closestNum = arr[i];
            index = i;
        }
    }

    cout << "The average of the elements in the array is " << fixed << setprecision(2) << avg << " and the closest number to the average is " << fixed << setprecision(2) << closestNum << " at index " << index << "." << endl;

    return 0;
}