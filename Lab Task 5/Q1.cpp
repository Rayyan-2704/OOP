/*
Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of those Square objects. After each time the area method is called, call that square’s getters for area and allareas to display the updated values.
*/

#include <iostream>
using namespace std;

class Square
{
    float sideLength;
    float area;
    static float allareas;

public:
    Square() : sideLength(0.0), area(0.0) {}
    Square(float sideLength)
    {
        this->sideLength = sideLength;
        area = 0.0;
    }

    void calculateArea()
    {
        area = sideLength * sideLength;
        allareas += area;
    }

    void setSideLength(float sideLength) { this->sideLength = sideLength; }
    void setArea(float area) { this->area = area; }
    static void setAllAreas(float allAreas) { allareas = allAreas; }

    float getSideLength() { return sideLength; }
    float getArea() { return area; }
    static float getAllAreas() { return allareas; }
};

float Square ::allareas = 0.0;

int main()
{
    Square s1(5), s2(4), s3(3);
    s1.calculateArea();
    cout << "The area of square 1 with side length (" << s1.getSideLength() << ") is " << s1.getArea() << "." << endl;
    cout << "The value of all areas currently is " << Square ::getAllAreas() << "." << endl << endl;

    s2.calculateArea();
    cout << "The area of square 2 with side length (" << s2.getSideLength() << ") is " << s2.getArea() << "." << endl;
    cout << "The value of all areas currently is " << Square ::getAllAreas() << "." << endl << endl;

    s3.calculateArea();
    cout << "The area of square 3 with side length (" << s3.getSideLength() << ") is " << s3.getArea() << "." << endl;
    cout << "The value of all areas currently is " << Square ::getAllAreas() << "." << endl << endl;

    return 0;
}
