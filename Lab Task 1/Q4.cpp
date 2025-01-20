/* Q4: You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49. */

#include <iostream>
using namespace std;

int maxWater(int arr[], int n);

int main()
{
    int n;
    cout << "Enter the number of vertical lines: ";
    cin >> n;
    int height[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the height to be stored at index " << i << " : ";
        cin >> height[i];
    }

    cout << "The maximum amount of water a container can store is " << maxWater(height, n) << endl;
    return 0;
}

int maxWater(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int suitableHeight;
            if (arr[i] > arr[j])
            {
                suitableHeight = arr[j];
            }
            else if (arr[i] < arr[j])
            {
                suitableHeight = arr[i];
            }
            else
            {
                suitableHeight = arr[i];
            }
            int area = (j - i) * suitableHeight;
            if (area > max)
            {
                max = area;
            }
        }
    }

    return max;
}