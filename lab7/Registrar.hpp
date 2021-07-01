//
//  Registrar.hpp
//  rec07
//
//  Created by Annlie Nguyen on 10/19/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Registrar_hpp
#define Registrar_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Course.hpp"
#include "Student.hpp"

namespace BrooklynPoly {
    class Course;
    class Student;

    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        bool addCourse(const std::string&);
        bool addStudent(const std::string&);
        bool enrollStudentInCourse(const std::string& studentName,
                                   const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();
        
    private:
        size_t findStudent(const std::string&) const;
        size_t findCourse(const std::string&) const;
        
        std::vector<Course*> courses;
        std::vector<Student*> students;
    }; //end of registrar

}
#endif /* Registrar_hpp */
