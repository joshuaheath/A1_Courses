

//FROM CLASS REQUIREMENTS
// 1) DONE Constuct a class named 'Student' that has name, numCourses, courseList (Dynamic array)
// 2) DONE For 'Student' Class create constructors, mutator, accessors
// 3) DONE A default constructor (i.e., creates a student object without a name and an empty course
// 4) DONE The “big three / rule of three” (i.e., copy constructor, assignment operator, destructor).
// 5) DONE An add function that will allow courses to be added to a student’s list of courses. This function
//      will demonstrate a deep copy using a ‘dynamically’ changing array to support the input for an
//      arbitrary number of courses. This is for educational purposes only, so you may not use a vector
//      or list as you would in production.
// 6) DONE A string constructor (i.e., constructor with arguments Student S1(“Bo
// 7) DONE A ‘print’ function that outputs the name and list of all courses.
// 8) DONE Overloaded << as a friend function that outputs the name and list of all courses.
// 9) DONE Solution implements a correctly functioning overloaded assignment operator. i.e. S2 = S1
// 10) DONE A function that resets the number of courses to 0 and the courseList array to an empty list.

// OTHER REQUIREMENTS
// 10) DONE Demos all methods of student class
// 11) DONE Allows looping or exiting, all class properties are entered by user
// 12) DONE Key methods identify itself when called
// 13) DONE Solution implements heads with appropriate pre-processor directives and guards
// 14) DONE Solution implements a correct copy constructor (Deep copy)
// 15) DONE implements correctly functioning assignment operator
// 16) DONE Includes programmer made destructor that frees memory with no leaks
// 17) DONE Implements a Dynamic array on the heap
// 18) DONE Destructor is called appropriate amount of times
// 19) DONE Solution contains a method that resets the num of classes to 0 and list of courses to empty
// 20) DONE Implements a correctly functioning String constructor

// FLOW OF SOLUTION
// DONE Ask for the 1st students name and courses until student is finished (no constant array size)
// DONE Populate Student object
// DONE Display properties of student object to user
// DONE Ask for name of second student
// DONE Store new student name and use deep copy constructor to create 2nd object with new name
// DONE Reset all properties of student 1 and display properties
// DONE Display student 2 properties
// DONE Enter third student and use custom assignment operator (Ie. 3rd student = 2nd student)
// DONE Alow for looping back to the beginning


#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

static string getValidName(const string& prompt)
{
    string name;
    bool isValidName;
    do
    {
        isValidName = true;

        cout << prompt;
        getline(cin, name);
        if (name.empty() || name == " ")
        {
            isValidName = false;
            cout << "Student name cannot be empty"<<endl;
        }
    } while (!isValidName);
    return name;
}

static bool userResponseYNBool(const string& prompt)
{
    string userInput;
    bool responseYNBool = true; // Wether to stop entering courses
    bool validUserResponse = true; // Wether the gives a y,Y,n,N input
    do
    {
        cout<< prompt;
        getline(cin, userInput);

        //Catches new lines/nothing
        if (userInput.empty())
        {
            validUserResponse = false;
            cout << "Invalid Response, Try Again"<<endl;
            continue;
        }

        if (userInput == "n" || userInput == "N" || userInput == "y" || userInput == "Y")
        {
            validUserResponse = true;
            if (userInput == "y" || userInput == "Y") { responseYNBool = true; } else { responseYNBool = false; }
        }
        else //Catches anything else
        {
            validUserResponse = false;
            cout << "Invalid Response, Try Again"<<endl;

        }
    } while (!validUserResponse);

    return responseYNBool; //Returns
}
string getCourseString()
{
    string course;
    do
    {
        cout << "Enter Course name: ";
        getline(cin, course);
        if (course == "")
        {
            cout << "====================================================" <<endl;
            cout << "Course cannot be empty, Try Again"<<endl;
        }
    } while (course.empty());
    return course;
}

// Adds as many courses to provided student param
static void assignStudentCourses(Student& student)
{
    while (true)
    {
        string curCourse = getCourseString();
        if (curCourse.empty()){cout<<"You shouldnt be here"<<endl;}

        //Adds verifeid course string to Student array
        student.addCourse(curCourse);
        cout << "Added Course: " << curCourse << endl;

        cout<<"=================================================="<<endl;

        if (!userResponseYNBool("Add Another Course? (Y/N): "))
        {
            break;
        }
    }
}

//Displays all student properties with getters
static void displayStudentInfo(const Student& student)
{

    cout << "Name: " << student.getName() << endl;
    cout << "numCourses: " << student.getNumCourses() << endl;

    for (int i = 0; i < student.getNumCourses(); i++)
    {
        cout << "Array Element " << i <<": " << student.getCourseList()[i] << endl;
    }
}
int main()
{
    bool repeatBool = false;
    do
    {
        cout << "=========================================" << endl;
        string student1Name = getValidName("Enter Student1 name: ");

        //Create Student with valid name
        Student student1 = Student(student1Name);

        assignStudentCourses(student1);
        student1.print();

        cout << "=========================================" << endl;

        string student2Name = getValidName("Enter Student2 name: ");
        // Create a copy of student 1
        Student student2(student1);
        student2.setName(student2Name);

        //Clear student 1 properties
        student1.clear();
        cout << "=============== AFTER CLEAR AND DEEP COPY ===============" << endl;

        cout << student1;
        cout << student2;

        cout << "=============== ASSIGNMENT OPERATOR DEMO ===============" << endl;

        // Creates Blank student
        Student student3;
        student3 = student2;

        cout << "=============== ALL ACCESSORS DEMO ===============" << endl;

        displayStudentInfo(student3);

        cout<<"=================================================="<<endl;

        repeatBool = userResponseYNBool("Repeat? (Y/N): ");
    } while (repeatBool);

    return 0;
}

