//
//  Student.cpp
//  rec07
//
//  Created by Annlie Nguyen on 10/19/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Student.hpp"
#include "Course.hpp"
using namespace std;

namespace BrooklynPoly {
    //STUDENT METHODS
    ostream& operator<<(ostream& os, const Student& stu) {
        os << stu.name << ": ";
        if (stu.courses.size() == 0) {
            os << "No Courses" << endl;
        } else {
            for (Course* eachCourse : stu.courses) {
                os << eachCourse->getName() << ' ';
            }
            os << endl;
        }
        return os;
    }
    Student::Student(const string& name) : name(name) {}
    const string& Student::getName() const {
        return name;
    }
    bool Student::addCourse(Course* course) {
        bool checkCourse = false;
        for (Course* eachCourse : courses) {
            if (eachCourse->getName() == course->getName()) {
                checkCourse = true;
                break;
            }
        }
        if (checkCourse) {
            return false;
        } else {
            courses.push_back(course);
            return true;
        }
    }
    void Student::removedFromCourse(Course* remove) {
        Course* last = courses.back();
        for (size_t i = 0; i < courses.size(); i++) {
            if (courses[i] == remove) {
                courses[i] = last;
                courses.pop_back();
                break;
            }
        }
    }
}
