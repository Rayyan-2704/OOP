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