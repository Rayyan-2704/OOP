/* Pointers to Derived Classes (Compile-time Binding) */
#include <iostream>
using namespace std;

class BaseClass{
public:
    int varBase;
    void display(){
        cout << "1. Displaying the Base class variable: " << varBase << endl;
    }
};

class DerivedClass : public BaseClass{
public:
    int varDerived;
    void display(){
        cout << "2. Displaying the Derived class variable: " << varDerived << endl;
        BaseClass :: display();
    }
};

int main(){
    BaseClass *BC_ptr;
    BaseClass obj_B;
    DerivedClass obj_D;
    BC_ptr = &obj_D;  // Pointing base class pointer to derived class

    BC_ptr->varBase = 34;
    // BC_ptr->varDerived = 90; ---> this will give an error as the base class pointer can access the base class variables/member functions only
    BC_ptr->display();  // this will call the base class display(), NOT the derived class display()

    DerivedClass *DC_ptr;
    DC_ptr = &obj_D;
    // Derived class pointer can access both the derived class and the base class variables/member functions
    DC_ptr->varBase = 12;
    DC_ptr->varDerived = 98;
    DC_ptr->display();

    BC_ptr->display(); 
    return 0;
}

/* Virtual Functions (Runtime Polymorphism) */
/* Same example as above, but trying to call the derived class function instead of base class via base class pointer */
#include <iostream>
using namespace std;

class BaseClass
{
public:
    int varBase = 30;
    // virtual is used to make sure that when the base class pointer calls the display() function, it gives priority to the derived class display() function
    // can also write void virtual
    virtual void display()
    {
        cout << "1. Displaying the Base class variable: " << varBase << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    int varDerived = 20;
    void display() override
    {
        cout << "2. Displaying the Derived class variable: " << varDerived << endl;
        BaseClass :: display();
    }
};

int main()
{
    BaseClass *BC_ptr;
    BaseClass obj_B;
    DerivedClass obj_D;

    BC_ptr = &obj_D;
    BC_ptr->display(); // ---> derived class display() is being invoked here
    // If the derived class display() function gets commented out, the base class display() function will be invoked instead

    BC_ptr = &obj_B;
    BC_ptr->display(); // ---> the base class display() is invoked as the object is of base class
    return 0;
}

/* Detailed Example using Virtual Functions */
#include <iostream>
using namespace std;

class Movie
{
protected:
    string title;
    float rating;

public:
    Movie(string s, float r)
    {
        title = s;
        rating = r;
    }

    virtual void display() {}
};

class MovieVid : public Movie
{
    float vidLength;

public:
    MovieVid(string s, float r, float len) : Movie(s, r)
    {
        vidLength = len;
    }

    void display() override
    {
        cout << "The title of this movie is " << title << endl;
        cout << "The rating of this movie is " << rating << " out of 5 stars" << endl;
        cout << "The length of this movie is " << vidLength << " minutes" << endl;
    }
};

class MovieText : public Movie
{
    int words;

public:
    MovieText(string s, float r, int w) : Movie(s, r)
    {
        words = w;
    }

    void display() override
    {
        cout << "The title of this movie with subtitles is " << title << endl;
        cout << "The rating of this movie with subtitles is " << rating << " out of 5 stars" << endl;
        cout << "The words of this movie with subtitles is " << words << " words" << endl;
    }
};

int main()
{
    string title;
    float rating, vLen;
    int words;

    title = "The Life Of Pi: Visuals";
    vLen = 120.46;
    rating = 4.7;
    MovieVid lifeOfPiVis(title, rating, vLen);
    // lifeOfPiVis.display();

    title = "The Life Of Pi: Subtitles";
    words = 3500;
    rating = 4.2;
    MovieText lifeOfPiWords(title, rating, words);
    // lifeOfPiWords.display();

    Movie *ptr[2];
    ptr[0] = &lifeOfPiVis;
    ptr[1] = &lifeOfPiWords;

    ptr[0]->display();
    ptr[1]->display();
    return 0;
}

/* 
Rules for virtual functions:
1. They cannot be static.
2. They are accessed by object pointers.
3. Virtual functions can be a friend of another class.
4. A virtual function in the base class might not be used.
5. If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class.
*/

/* Abstract Base Class & Pure Virtual Functions */
/* taking a closer look at the previous example */

// "Movie" is an abstract base class here; an abstract base class is such a base class which is solely used for inheritance and is not used to create objects of its own.
// An abstract base class has to have atleast 1 pure virtual function.
class Movie
{
protected:
    string title;
    float rating;

public:
    Movie(string s, float r)
    {
        title = s;
        rating = r;
    }

    //virtual void display() {} ---> Simple virtual function, if the derived class display() had not been present then this base class function would have been invoked
    virtual void display() = 0; // ---> do-nothing function / pure virtual function
    // It is necessary for the pure virtual function to be overridden by the derived class function. If not, then this function will not be invoked and will throw an error
};