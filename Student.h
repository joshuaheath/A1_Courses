//
// Created by gamef on 2026-11-02.
//

#ifndef A2_COURSES_STUDENT_H
#define A2_COURSES_STUDENT_H

#include <string>
using namespace std;
    class Student
    {
        string name;
        int numCourses;
        string* courseList;

        public:
        Student();                  // default constructor
        explicit Student(const string& name);   // constructor with params
        Student(const Student& student);        // Deep Copy constructor
        ~Student();                 // destructor

        // getters (accessors)
        string getName();
        int getNumCourses() const;
        string getCourseArray() const;

        // setters (Mutator)
        void setName(string n);

        // Considers current objects array size and if larger than "numCourse" allocate more mem and update "numCourses"
        int addCourse(const string& course);

        // Prints each property of student
        friend ostream& operator<<(ostream& output, const Student& student);

        // clears all properties of object
        void clear();
    };

#endif //A2_COURSES_STUDENT_H
