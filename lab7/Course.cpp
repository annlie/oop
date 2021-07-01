//
//  Course.cpp
//  rec07
//
//  Created by Annlie Nguyen on 10/19/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Course.hpp"
using namespace std;

namespace BrooklynPoly {
    //COURSE METHODS
    ostream& operator<<(ostream& os, const Course& rhs) {
        os << rhs.name << ": ";
        if (rhs.students.size() == 0) {
            os << "No Students" << endl;
        } else {
            for (Student* eachStudent : rhs.students) {
                os << eachStudent->getName() << ' ';
            }
            os << endl;
        }
        return os;
    }
    Course::Course(const string& courseName) : name(courseName) {}
    const string& Course::getName() const {
        return name;
    }
    bool Course::addStudent(Student* student) {
        bool checkStudent = false;
        for (Student* eachStudent : students) {
            if (eachStudent->getName() == student->getName()) {
                checkStudent = true;
                break;
            }
        }
        if (checkStudent) {
            return false;
        } else {
            students.push_back(student);
            return true;
        }
    }
    void Course::removeStudentsFromCourse() {
        for (Student* eachStudent : students) {
            eachStudent->removedFromCourse(this);
        }
        students.clear();
    }
}
