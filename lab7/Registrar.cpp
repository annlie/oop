//
//  Registrar.cpp
//  rec07
//
//  Created by Annlie Nguyen on 10/19/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Registrar.hpp"
using namespace std;

namespace BrooklynPoly {
    //REGISTRAR METHODS
    ostream& operator<<(ostream& os, const Registrar& rhs) {
        os << "Registrar's Report" << endl;
        os << "Courses: " << endl;
        for (Course* eachCourse : rhs.courses) {
            cout << *eachCourse;
        }
        os << "Students: " << endl;
        for (Student* eachStudent : rhs.students) {
            cout << *eachStudent;
        }
        return os;
    }
    Registrar::Registrar() {
        
    }
    bool Registrar::addCourse(const string& name) {
        size_t checkCourse = findCourse(name);
        if (checkCourse != courses.size()) {
            cout << "Failed to add course" << endl;
            return false;
        }
        Course* newCourse = new Course(name);
        courses.push_back(newCourse);
        return true;
    }
    bool Registrar::addStudent(const string& student) {
        size_t checkStudent = findStudent(student);
        if (checkStudent != students.size()) {
            cout << "Failed to add student" << endl;
            return false;
        }
        Student* newStudent = new Student(student);
        students.push_back(newStudent);
        return true;
    }
    bool Registrar::enrollStudentInCourse(const string& studentName,
                                          const string& courseName){
        size_t studentPos = findStudent(studentName);
        size_t coursePos = findCourse(courseName);
        if (studentPos == students.size() || coursePos == courses.size()) {
            cout << "Failed to enroll student" << endl;
            return false;
        }
        courses[coursePos]->addStudent(students[studentPos]);
        students[studentPos]->addCourse(courses[coursePos]);
        return true;
    }
    bool Registrar::cancelCourse(const string& courseName){
        bool checkCourse = false;
        for (Course* eachCourse : courses) {
            if (eachCourse->getName() == courseName) {
                checkCourse = true;
                break;
            }
        }
        if (!checkCourse) {
            return false;
        } else {
            Course* last = courses.back();
            size_t coursePos = findCourse(courseName);
            courses[coursePos]->removeStudentsFromCourse();
            delete courses[coursePos];
            courses[coursePos] = last;
            courses.pop_back();
            return true;
        }
    }
    void Registrar::purge() {
        for (Course* eachCourse : courses) {
            cancelCourse(eachCourse->getName());
        }
        for (size_t i = 0; i < students.size(); i++) {
            delete students[i];
            students[i] = nullptr;
        }
        students.clear();
    }
    size_t Registrar::findStudent(const string& name) const {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i]->getName() == name) {
                return i;
            }
        }
        return students.size();
    }
    size_t Registrar::findCourse(const string& name) const {
        for (size_t j = 0; j < courses.size(); j++) {
            if (courses[j]->getName() == name) {
                return j;
            }
        }
        return students.size();
    }

}
