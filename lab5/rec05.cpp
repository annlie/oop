//
//  Annlie Nguyen
//  rec05
//
//  Code to model SOE CS lab administration
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section {
    friend ostream& operator<<(ostream& os, const Section& rhs) {
        os << "Section: " << rhs.name << ", Time slot: " << rhs.time;
        os << "], Students: ";
        if (rhs.records.size() == 0) {
            os << "None" << endl;
        } else {
            os << endl;
            for (size_t i = 0; i < rhs.records.size(); i++) {
                os << *rhs.records[i];
            }
        }
        return os;
    }
    
    class TimeSlot {
        friend ostream& operator<<(ostream& os, const TimeSlot& rhs) {
            os << "[Day: " << rhs.day << ", Start time: ";
            int newTime = rhs.hour % 12;
            string period;
            if (rhs.hour <= 11) { period = "am";}
            else { period = "pm"; }
            os << newTime << period;
            return os;
        }
    public:
        TimeSlot (const string& day, const int hour) : day(day), hour(hour) {}
    private:
        string day;
        int hour;
    };
    
    
    class StudentRecord {
        friend ostream& operator<<(ostream& os, const StudentRecord& rhs) {
            os << "Name: " << rhs.name << ", Grades: ";
            for (int each : rhs.grades) {
                os << each << " ";
            }
            os << endl;
            return os;
        }
    public:
        StudentRecord (const string& name) : name(name), grades(14, -1) {}
        
        void changeGrade(const int pos, const int val) {
            grades[pos] = val;
        }
        
        string getName() {
            return name;
        }
    private:
        vector<int> grades;
        string name;
        
    };
    
public:
    Section (const string& name, const string& day,
             const int hour) : name(name), time(day, hour) {}
    
    Section (const Section& anotherSec) : name(anotherSec.name), time(anotherSec.time) {
        for (size_t i = 0; i < anotherSec.records.size(); i++) {
            StudentRecord* newStudent = new StudentRecord(*anotherSec.records[i]);
            records.push_back(newStudent);
        }
    }
    
    void addStudent (const string& stuName) {
        StudentRecord* newStudent = new StudentRecord(stuName);
        records.push_back(newStudent);
    }
    
    void changeRecord(const string& name, const int grade, const int week) {
        size_t pos = 0;
        for (size_t i = 0; i < records.size(); i++) {
            if (records[i]->getName() == name) {
                pos = i;
                break;
            }
        }
        records[pos]->changeGrade((week-1), grade);
    }
    
    
    ~Section () {
        for (size_t i = 0; i < records.size(); i++) {
            delete records[i];
            records[i] = nullptr;
        }
    }
    
private:
    string name;
    TimeSlot time;
    vector<StudentRecord*> records;
    
    
};


class LabWorker {
    friend ostream& operator<<(ostream& os, const LabWorker& rhs) {
        os << rhs.name;
        if (rhs.sec == nullptr) {
            os << " does not have a section";
        } else {
            os << " has section " << *rhs.sec << endl;
        }
        return os;
    }
    
public:
    LabWorker (const string& name) : name(name) {};
    void addSection(Section& newSec) {
        sec = &newSec;
    }
    
    void addGrade(const string& name, const int grade, const int week) {
        sec->changeRecord(name, grade, week);
    }
private:
    string name;
    Section* sec = nullptr;
};

// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;
    
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;
    
    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;
    
    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;
    
    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;
    
    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
    << "those students (or rather their records?)\n";
    
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
    << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
    return 0;
}
