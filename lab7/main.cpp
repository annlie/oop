//
//  Annlie Nguyen
//  rec07
//
//  Separate compilation with the registrar
//

#include <iostream>
#include <fstream>
#include "Registrar.hpp"

using namespace std;
using namespace BrooklynPoly;

//bool findCommand(const string& name);

int main() {
    //    OPTIONAL:
//    ifstream file("registrar.txt");
//    if (!file) {
//        cerr << "Error opening file." << endl;
//        exit(1);
//    }
//
//    string check;
//    string courseName;
//    string studentName;
//    string lastCommand;
//
//    Registrar registrar;
//    cout << "No courses or students added yet\n";
//
//    while (file >> check) {
//        if (check == "PrintReport") {
//            cout << registrar << endl;
//        } else if (check == "AddStudent") {
//            file >> studentName;
//            bool commandCheck = findCommand(studentName);
//            if (commandCheck) {
//              cout << "Error: could not add student" << endl;
//        } else if (check == "AddCourse") {
//            file >> courseName;
//
//        } else if (check == "EnrollStudentInCourse") {
//            file >> studentName;
//            file >> courseName;
//
//        } else if (check == "CancelCourse") {
//            file >> courseName;
//
//        } else if (check == "Purge") {
//            cout << "Purge for start of next semester\n";
//            registrar.purge();
//            cout << registrar << endl;
//        }
//    }
    
    Registrar registrar;
    
    cout << "No courses or students added yet\n";
    cout << registrar << endl;
    
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;
    
    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;
    
    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;
    
    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;
    
    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;
    
    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
    
    
//     // [OPTIONAL - do later if time]
//     cout << "ChangeStudentName FritzTheCat MightyMouse\n";
//     registrar.changeStudentName("FritzTheCat", "MightyMouse");
//     cout << registrar << endl;  // or registrar.printReport()
//
//     cout << "DropStudentFromCourse MightyMouse CS101.001\n";
//     registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
//     cout << registrar << endl;  // or registrar.printReport()
//
//     cout << "RemoveStudent FritzTheCat\n";
//     registrar.removeStudent("FritzTheCat");
//     cout << registrar << endl;  // or registrar.printReport()
    
    
    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
    
}

bool findCommand(const string& name) {
    if (name == "PrintReport" || name == "AddCourse"
        || name == "AddStudent" || name == "EnrollStudentInCourse"
        || name == "CancelCourse" || name == "Purge") {
        return true;
    } else {
        return false;
    }
}
