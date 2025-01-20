/* Q3: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1]. */

#include <iostream>
using namespace std;

int main()
{
    int n, target, flag = 0;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the target number: ";
    cin >> target;

    int nums[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << " : ";
        cin >> nums[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (target == (nums[i] + nums[j]))
            {
                cout << "[" << i << "," << j << "]" << endl;
                return 0;
            }
        }
    }

    cout << "Error! No solution found." << endl;
    return 0;
}