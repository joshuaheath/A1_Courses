

//FROM CLASS REQUIREMENTS
// 1) Constuct a class named 'Student' that has name, numCourses, courseList (Dynamic array)
// 2) For 'Student' Class create constructors, mutator, accessors
// 3) A default constructor (i.e., creates a student object without a name and an empty course
// 4) The “big three / rule of three” (i.e., copy constructor, assignment operator, destructor).
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
int main()
{
    return 0;
}

