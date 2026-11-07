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
    bool responseYNBool = true;
    bool validUserResponse = true;

    do
    {
        cout<< prompt;
        getline(cin, userInput);

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
        else
        {
            validUserResponse = false;
            cout << "Invalid Response, Try Again"<<endl;

        }
    } while (!validUserResponse);

    return responseYNBool;
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

static void assignStudentCourses(Student& student)
{
    while (true)
    {
        string curCourse = getCourseString();
        if (curCourse.empty()){cout<<"You shouldnt be here"<<endl;}

        student.addCourse(curCourse);
        cout << "Added Course: " << curCourse << endl;

        cout<<"=================================================="<<endl;

        if (!userResponseYNBool("Add Another Course? (Y/N): "))
        {
            break;
        }
    }
}

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

        Student student1 = Student(student1Name);

        assignStudentCourses(student1);
        student1.print();

        cout << "=========================================" << endl;

        string student2Name = getValidName("Enter Student2 name: ");
        // Create a copy of student 1
        Student student2(student1);
        student2.setName(student2Name);

        student1.clear();
        cout << "=============== AFTER CLEAR AND DEEP COPY ===============" << endl;

        cout << student1;
        cout << student2;

        cout << "=============== ASSIGNMENT OPERATOR DEMO ===============" << endl;

        Student student3;
        student3 = student2;

        cout << "=============== ALL ACCESSORS DEMO ===============" << endl;

        displayStudentInfo(student3);

        cout<<"=================================================="<<endl;

        repeatBool = userResponseYNBool("Repeat? (Y/N): ");
    } while (repeatBool);

    return 0;
}

