/*
 Annlie Nguyen
 Rec06
 
 Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
    : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
        << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
    : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    const unsigned& getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    // Overload output operator
    friend ostream& operator<<(ostream& os, const Directory& rhs) {
        os << "Directory: " << endl;
        for (size_t i = 0; i < rhs.size; i++) {
            os << *rhs.entries[i] << endl;
        }
        return os;
    }
public:
    Directory () : size(0), capacity(1), entries(new Entry*[1]) {
    } //constructor
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)    {
            // something is missing!!!  Add it!
            capacity *= 2;
            Entry** bigger = new Entry*[capacity];
            for (size_t i = 0; i < size; i++) {
                bigger[i] = entries[i];
                //                delete entries[i];
            }
            delete[] entries;
            entries = bigger;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
    
    Directory(const Directory& rhs) :
    size(rhs.size), capacity(rhs.capacity), entries(new Entry*[rhs.capacity]) {
        //copy constructor
        cout << "I am copying!!" << endl;
        for (size_t i = 0; i < size; i++) {
            Entry* newEntry = new Entry(*rhs.entries[i]);
            entries[i] = newEntry;
        }
    }
    
    ~Directory() {
        //destructor
        cout << "I am deleting!!" << endl;
        for (size_t i = 0; i < size; i++) {
            delete entries[i];
        }
        delete[] entries;
    }
    
    Directory& operator=(const Directory& rhs) {
        //assignment operator
        //self assignment, free up old, allocate, copy, return self
        cout << "I am reassigning!!" << endl;
        if (this != &rhs) {
            for (size_t i = 0; i < size; i++) {
                delete entries[i];
            }
            delete[] entries;
            
            size = rhs.size;
            capacity = rhs.capacity;
            entries = new Entry*[capacity];
            
            for (size_t i = 0; i < size; i++) {
                Entry* newEntry = new Entry(*rhs.entries[i]);
                entries[i] = newEntry;
            }
        }
        return *this;
    }
    
    unsigned operator[](string name) const {
        //[] operator overload
        unsigned phone = 0;
        for (size_t i = 0; i < size; i++) {
            if (entries[i]->getName() == name) {
                phone = entries[i]->getPhone();
                break;
            }
        }
        return phone;
    }
    
private:
    Entry** entries; //array of pointers
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
    
    // Note that the Postion objects are NOT on the heap.
    //Position: title, salary
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;
    
    Directory d2 = d;    // What function is being used?? //copy constructor
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl;
    cout << d2 << endl;
    
    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";
    
    Directory d3;
    d3 = d2;
    cout << d2 << endl;
    cout << d3 << endl;
    
    // Should display 1592
    cout << d2["Carmack"] << endl;
    
} // main
