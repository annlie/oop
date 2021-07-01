//
//  Student.hpp
//  rec07
//
//  Created by Annlie Nguyen on 10/19/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
    class Course;
    
    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    public:
        // Student methods needed by Registrar
        Student(const std::string& name);
        const std::string& getName() const;
        bool addCourse(Course*);
        
        // Student method needed by Course
        void removedFromCourse(Course*);
        
    private:
        std::string name;
        std::vector<Course*> courses;
    }; //end of student
}
#endif /* Student_hpp */
