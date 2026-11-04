//
// Created by gamef on 2026-11-02.
//

#ifndef A2_COURSES_STUDENT_H
#define A2_COURSES_STUDENT_H

#include <string>
using namespace std;
    class Student
    {
        private:
        string name;
        int numCourses;
        string* courseList;

        public:
        Student();                  // default constructor
        explicit Student(string n); // constructor with params
        ~Student();                 // destructor

        // getters (accessors)
        string getName();
        int getNumCourses();
        string getCourseList();

        // setters (Mutator)
        void setName(string n);
        void addCourse(string course);
    };

#endif //A2_COURSES_STUDENT_H
