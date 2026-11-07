//
// Created by gamef on 2026-11-02.
//

#ifndef A2_COURSES_STUDENT_H
#define A2_COURSES_STUDENT_H

#include <iostream>
#include <string>
    class Student
    {
    private:
        std::string name;
        int numCourses;
        std::string* courseList;

        static bool isCourseValid(const std::string& course)
        {
            if (course.empty() || course == " ")
            {
                return false;
            }

            return true;
        }

    public:
        Student();
        explicit Student(const std::string& name);
        Student(const Student& student);
        ~Student();

        const std::string& getName() const;
        const int& getNumCourses() const;
        const std::string* getCourseList() const;

        void setName(const std::string& n);

        int addCourse(const std::string& course);

        friend std::ostream& operator<<(std::ostream& output, const Student& student);

        Student& operator=(const Student& other);

        void print() const;

        void clear();
    };

#endif //A2_COURSES_STUDENT_H
