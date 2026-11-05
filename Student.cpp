//
// Created by gamef on 2026-11-03.
//
# include <iostream>
# include <string>
# include "Student.h"

using namespace std;
// string name;
// int numCourses;
// string* courseList;

//===========================================================================
Student::Student()
{
    cout<<"-- Student Default constructor-- "<<endl;
    name = "";
    numCourses = 0;
    courseList = nullptr;
}

Student::Student(const string& name)
{
    cout<<"-- Student constructor with params --"<<endl;
    this->name = name;
    numCourses = 0;
    courseList = new string[numCourses];
}

Student::~Student()
{
    cout<<"-- Student destructor --"<<endl;
    delete[] courseList;
}

Student::Student(const Student& student)
{
    cout<<"-- Student Deep copy constructor --"<<endl;
    name = student.name;
    numCourses = student.numCourses;
    courseList = new string[numCourses]; //Allocate new memory to store copied params

    // Copy Array Elements
    for (int i = 0; i < numCourses; i++)
    {
        courseList[i] = student.courseList[i];
    }
}
//===========================================================================

string Student::getName() const
{
    return name;
}
int Student::getNumCourses() const
{
    return numCourses;
}

string* Student::getCourseList() const
{
    return courseList;
}
//===========================================================================

void Student::setName(string name)
{
    this->name = name;
}

int Student::addCourse(const string& course)
{
    cout << "Adding course to student"<<endl;
    if (course.empty())
    {
        return -1;
    }

    string* tempArray = new string[numCourses + 1];
    for (int i = 0; i < numCourses; i++)
    {
        tempArray[i] = courseList[i];
    }

    tempArray[numCourses] = course;

    delete[] courseList; // Deletes old array
    courseList = tempArray;

    numCourses++;
    return 0;
}
//================================== OPERATORS =========================================

ostream& operator<<(ostream& output, const Student& student)
{
    cout<<"-- OPERATOR '<<' - Student Details --"<<endl;

    output<<"Name: "<< student.name << endl;
    output<< "Number of courses: "<< student.numCourses << "\nCourses: " << endl;
    for (int i = 0; i < student.numCourses; i++)
    {
        output << student.courseList[i] << ", ";
    }
    return output << endl;
}

Student& Student::operator=(const Student& other)
{
    cout << "-- OPERATOR '=' Assignment --" <<endl;
    if (this == &other) // Prevent self-assignment
    {
        return *this;
    }
    // if theres a difference of allocated memory between blueprint list and other array
    if (courseList != nullptr)
    {
        delete[] courseList;    // Clear existing memory
        courseList = nullptr;   // Prevent dangling pointer
    }
    name = other.getName();
    numCourses = other.getNumCourses();

    if (numCourses > 0)
    {
        courseList = new string[numCourses]; //allocates mem to populate
        for (int i = 0; i < numCourses; i++)
        {
            courseList[i] = other.courseList[i]; //Deep copy of courses
        }
    }
    else
    {
        courseList = nullptr; // If there were no courses to copy in the first place
    }
    return *this;
}

void Student::print() const
{
    cout<<"-- PRINT - Student Details --"<<endl;
    cout <<"Name: "<< name << endl;
    cout <<"Number of courses: "<< numCourses << endl;
    cout <<"Courses: " << endl;
    for (int i = 0; i < numCourses; i++)
    {
        cout << courseList[i] << ", ";
    }
    cout << endl;
}

void Student::clear()
{
    cout<<"-- Clearing Student --"<<endl;
    // for (int i = 0; i < numCourses; i++)
    // {
    //     courseList[i] = "";
    // }
    numCourses = 0;
    delete[] courseList;
    courseList = nullptr;
}