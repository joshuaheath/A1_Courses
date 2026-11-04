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
}

Student::~Student()
{
    cout<<"Student destructor"<<endl;
    delete[] courseList;
}
//===========================================================================


