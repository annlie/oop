//
//  Course.hpp
//  rec07
//
//  Created by Annlie Nguyen on 10/19/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Student.hpp"

namespace BrooklynPoly {
    class Course {
        friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
    public:
        // Course methods needed by Registrar
        Course(const std::string& courseName);
        const std::string& getName() const;
        bool addStudent(Student*);
        void removeStudentsFromCourse();
        
    private:
        std::string name;
        std::vector<Student*> students;
    }; //end of course
}
#endif /* Course_hpp */
