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
    cout<<"Student constructor"<<endl;
    name = "";
    numCourses = 0;
    courseList = nullptr;
}

Student::Student(const string& name)
{
    cout<<"Student constructor with params"<<endl;
    this->name = name;
    numCourses = 0;
    courseList = new string[numCourses];
}

Student::~Student()
{
    cout<<"Student destructor"<<endl;
    delete[] courseList;
}

Student::Student(const Student& student)
{
    cout<<"Student Deep copy constructor"<<endl;
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

string Student::getName()
{
    return name;
}
int Student::getNumCourses() const
{
    return numCourses;
}

string Student::getCourseArray() const
{
    return courseList[numCourses];
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
//===========================================================================

ostream& operator<<(ostream& output, const Student& student)
{
    cout<<"Student Details"<<endl;

    output<<"Name: "<< student.name << endl;
    output<< "Number of courses: "<< student.numCourses << "\nCourses: " << endl;
    for (int i = 0; i < student.numCourses; i++)
    {
        output << student.courseList[i] << ", ";
    }
    return output << endl;
}

void Student::clear()
{
    for (int i = 0; i < numCourses; i++)
    {
        courseList[i] = "";
    }
    numCourses = 0;
}