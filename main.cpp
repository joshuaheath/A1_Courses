

//FROM CLASS REQUIREMENTS
// 1) DONE Constuct a class named 'Student' that has name, numCourses, courseList (Dynamic array)
// 2) DONE For 'Student' Class create constructors, mutator, accessors
// 3) DONE A default constructor (i.e., creates a student object without a name and an empty course
// 4) DONE The “big three / rule of three” (i.e., copy constructor, assignment operator, destructor).
// 5) An add function that will allow courses to be added to a student’s list of courses. This function
//      will demonstrate a deep copy using a ‘dynamically’ changing array to support the input for an
//      arbitrary number of courses. This is for educational purposes only, so you may not use a vector
//      or list as you would in production.
// 6) A string constructor (i.e., constructor with arguments Student S1(“Bo
// 7) A ‘print’ function that outputs the name and list of all courses.
// 8) Overloaded << as a friend function that outputs the name and list of all courses.
// 9) A function that resets the number of courses to 0 and the courseList array to an empty list.

// OTHER REQUIREMENTS
// 10) Demos all methods of student class
// 11) Allows looping or exiting, all class properties are entered by user
// 12) Key methods identify itself when called
// 13) Solution implements heads with appropriate pre-processor directives and guards
// 14) Solution implements a correct copy constructor (Deep copy)
// 15) implements correctly functioning assignment operator
// 16) Includes programmer made destructor that frees memory with no leaks
// 17) Implements a Dynamic array on the heap
// 18) Destructor is called appropriate amount of times
// 19) Solution contains a method that resets the num of classes to 0 and list of courses to empty
// 20) Implements a correctly functioning String constructor

// FLOW OF SOLUTION
// Ask for the 1st students name and courses until student is finished (no constant array size)
// Populate Student object
// Display properties of student object to user
// Ask for name of second student
// Store new student name and use deep copy constructor to create 2nd object with new name
// Reset all properties of student 1 and display properties
// Display student 2 properties
// Enter third student and use custom assignment operator (Ie. 3rd student = 2nd student)
// Alow for looping back to the beginning


#include <iostream>
#include <string>
#include <ostream>
using namespace std;
class ArrayTestClass
{
    public:
    int arraySize;          // allocate mem
    string *stringArray;    // allocates mem for pointer to the array (not an array)

    // Default constructor
    ArrayTestClass()
    {
        cout<<"ArrayTestClass Default constructor"<<endl;

        // Done so the deconstructor de-allocates safely
        arraySize = 0;
        stringArray = nullptr; // its safe to delete a nullptr
    }
    // Constructor w params
    explicit ArrayTestClass(const int size)
    {
        cout << "ArrayTestClass constructor params" << endl;
        arraySize = size;
        stringArray = new string[size];
    }

    //Copy constructor (Deep Copy)
    ArrayTestClass(const ArrayTestClass &obj)
    {
        cout << "ArrayTestClass Copy Constructor" << endl;
        arraySize = obj.arraySize; // Applies to the class property
        stringArray = new string[arraySize]; // Makes new array of string using classes updated "arraySize"

        // Copy array elements
        for (int i = 0; i < arraySize; i++)
        {
            stringArray[i] = obj.stringArray[i];
        }
    }

    // Operator overload for << for only "ArrayTest" class
    friend void operator<<(ostream &outputStream, ArrayTestClass &obj)
    {
        cout << "Printing ArrayTestClass Report..." << endl;

        // get an array size based of the size of the array to use for loop indexing
        int localArraySize = obj.arraySize; //Used for loop

        // For when the "clearArray" method is run
        if (obj.stringArray[0].empty())
        {
            obj.arraySize = 0;
        }
        outputStream << "Array Size: " << obj.arraySize << endl;
        for (int i = 0; i < localArraySize; i++)
        {
            outputStream << "Element " << i << ": " << obj.stringArray[i] << endl;
        }
    }
    void ClearArray() const
    {
        cout<<"Clearing Array"<<endl;
        for (int i = 0; i < arraySize; i++)
        {
            stringArray[i] = "";
        }

    }
    ~ArrayTestClass()
    {
        cout << "ArrayTestClass destructor" << endl;
        delete[] stringArray;
    }
};
int main()
{
    int arrSize = 4;
    string element1 = "Hello";
    string element2 = "This";
    string element3 = "Is";
    string element4 = "A test";

    string element5 = "I WAS REPLACED";

    // Create an object with constructor w params
    ArrayTestClass array(arrSize);

    // Add each string to each index of the stringArray property
    array.stringArray[0] = element1;
    array.stringArray[1] = element2;
    array.stringArray[2] = element3;
    array.stringArray[3] = element4;

    cout << array;

    // Do a Deep copy of "array"
    ArrayTestClass array2 = array;    // One method

    // ArrayTestClass array2(array);          // Other Method

    // Clear array
    array.ClearArray();

    array2.stringArray[0] = element5;

    cout << "====================================" << endl;

    // uses operator overload to print "ArrayTestClass" object
    cout << array;

    cout << "====================================" << endl;

    cout << array2;

    return 0;
}

class MyClass
{
    public:
    int *classProp;
    int *otherProp;

    MyClass(const int val, const int otherVal) // Constructor w params
    {
        classProp = new int; // allocates a new int on the heap and stores its address in classProp
        *classProp = val; // deref allocated memory store in "classProp" and writes "val" to it

        otherProp = new int;
        *otherProp = otherVal;
    };

    //Deep Copy Constructor
    MyClass(const MyClass &obj)
    {
        classProp = new int; // allocates new mem, aka new address
        *classProp = *(obj.classProp); //Copys passed in object params into allocated mem (De-reference)

        otherProp = new int;
        *otherProp = *(obj.otherProp);
    }

    //Create a destructor
    ~MyClass()
    {
        delete classProp;
        delete otherProp;
    }
};
    // const MyClass obj1(10, 100); //Creates first object of "MyClass"
    // MyClass obj2 = obj1;
    //
    // *obj2.classProp = 50; // deref
    //
    // cout << "Obj1 properties:" << endl;
    // cout << *obj1.classProp << endl;
    // cout << *obj1.otherProp << endl;
    // cout << "Obj2 properties:" << endl;
    // cout << *obj2.classProp << endl;
    // cout << *obj2.otherProp << endl;

