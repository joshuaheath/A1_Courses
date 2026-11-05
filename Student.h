//
// Created by gamef on 2026-11-02.
//

#ifndef A2_COURSES_STUDENT_H
#define A2_COURSES_STUDENT_H

#include <iostream>
#include <string>
    class Student
    {
        public:
        std::string name;
        int numCourses;
        std::string* courseList;

        Student();                  // default constructor
        explicit Student(const std::string& name);   // constructor with params
        Student(const Student& student);        // Deep Copy constructor
        ~Student();                 // destructor

        // getters (accessors)
        std::string getName() const;
        int getNumCourses() const;
        std::string* getCourseList() const;

        // setters (Mutator)
        void setName(std::string n);

        // Adds a course to courseList array with consideration of numCourses and allocated already allocated array mem
        int addCourse(const std::string& course);

        // Prints each property of student
        friend std::ostream& operator<<(std::ostream& output, const Student& student);

        // Assignment Operator
        Student& operator=(const Student& other);

        // Does the same as the "<<" operator overload but is instead a method
        void print() const;

        // clears all properties of object
        void clear();
    };

#endif //A2_COURSES_STUDENT_H
