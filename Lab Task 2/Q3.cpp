/* Write a C++ program that:
  --> Dynamically allocates a 2D array using pointers (not using vector or standard containers).
  --> Fills the array with random integers between 1 and 100.
  --> Pass the 2D array to function to perform these tasks:
  --> Calculates and prints The sum of all elements in the array.
  --> Calculates and prints The sum of each row and each column.
  --> Calculates and prints The row and column with the highest sum.
  --> Pass the 2D array to a function to transpose the matrix and print the resulting matrix.
Free the dynamically allocated memory.
Note:
Use functions to perform the calculations and matrix operations (do not write all code inside main()).
Handle edge cases, such as when the array has no elements or is improperly allocated. */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sumOfAllElements(int **arr, int rows, int columns);
void calcRowsColumnsSum(int **arr, int rows, int columns);
void transposeMatrix(int **arr, int rows, int columns);

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int rows, columns;
    cout << "Enter the number of rows and columns, respectively, needed for the 2D array: ";
    cin >> rows >> columns;

    if (rows <= 0 || columns <= 0)
    {
        cout << "Invalid matrix size. Rows and columns must be greater than 0." << endl;
        return 1;
    }

    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "[ ";
        for (int j = 0; j < columns; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";

    sumOfAllElements(arr, rows, columns);
    calcRowsColumnsSum(arr, rows, columns);
    transposeMatrix(arr, rows, columns);

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

void sumOfAllElements(int **arr, int rows, int columns)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += arr[i][j];
        }
    }

    cout << "Sum of all elements: " << sum << endl;
}

void calcRowsColumnsSum(int **arr, int rows, int columns)
{
    int rowSum[rows] = {0};
    int colSum[columns] = {0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    cout << "Row sums:";
    for (int i = 0; i < rows; i++)
    {
        if (i != (rows - 1))
        {
            cout << " " << rowSum[i] << ",";
        }
        else
        {
            cout << " " << rowSum[i] << endl;
        }
    }

    cout << "Column sums:";
    for (int j = 0; j < columns; j++)
    {
        if (j != (columns - 1))
        {
            cout << " " << colSum[j] << ",";
        }
        else
        {
            cout << " " << colSum[j] << endl;
        }
    }

    int maxRowIndex = 0, maxColIndex = 0;
    for (int i = 1; i < rows; i++)
    {
        if (rowSum[i] > rowSum[maxRowIndex])
        {
            maxRowIndex = i;
        }
    }

    for (int j = 1; j < columns; j++)
    {
        if (colSum[j] > colSum[maxColIndex])
        {
            maxColIndex = j;
        }
    }

    cout << "Row with highest sum: Row " << (maxRowIndex + 1) << endl;
    cout << "Column with highest sum: Column " << (maxColIndex + 1) << endl;
}

void transposeMatrix(int **arr, int rows, int columns)
{
    int **transpose = new int *[columns];
    for (int i = 0; i < columns; i++) {
        transpose[i] = new int[rows];
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }

    cout << "Transpose Matrix:" << endl;
    for (int j = 0; j < columns; j++)
    {
        cout << "[ ";
        for (int i = 0; i < rows; i++)
        {
            cout << transpose[j][i] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";

    for (int i = 0; i < columns; i++) {
        delete[] transpose[i];
    }
    delete[] transpose;
}