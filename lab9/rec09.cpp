//
//  main.cpp
//  rec09
//
//  Created by Annlie Nguyen on 11/1/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
    //    friend ostream& operator<<(ostream& os, const PrintedMaterial& rhs) {
    //        os << "Printing pages: " << rhs.pageNum;
    //        return os;
    //    }
public:
    PrintedMaterial(unsigned pages) : pageNum(pages) {}
    //    virtual void displayNumPages() const { cout << "Printing pages: " << pageNum << endl; }
    
    virtual void displayNumPages() const = 0;
    
    //    PrintedMaterial& operator=(const PrintedMaterial& rhs) {
    //        pageNum = rhs.pageNum;
    //        return *this;
    //    }
    
protected:
private:
    unsigned pageNum;
}; //end of printed material

void PrintedMaterial::displayNumPages() const {
    cout << "Printing pages:" << pageNum << endl;
}





class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned pages) : PrintedMaterial(pages) {}
    
    void displayNumPages() const {
        cout << "Magazine pages: " << endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
}; //end of magazine






class Book : public PrintedMaterial {
public:
    Book(unsigned pages) : PrintedMaterial(pages) {}
    void displayNumPages() const {
        cout << "Book pages: " << endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
}; //end of book





class TextBook : public Book {
public:
    TextBook(unsigned pages, unsigned index) : Book(pages), numOfIndexPages(index) {}
    void displayNumPages() const {
        cout << "Textbook pages: " << endl;
        PrintedMaterial::displayNumPages();
        cout << "Textbook index: " << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
}; //end of textbook






class Novel : public Book {
public:
    Novel(unsigned pages) : Book(pages) {}
    void displayNumPages() const {
        cout << "Novel pages: " << endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
}; //end of novel





//void displayNumberOfPages(const PrintedMaterial& other) {
//    other.displayNumPages();
//}




int main() {
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);
    
    //    cout << "Printing m: " << m << endl;
    
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    //    PrintedMaterial pm(711);
    //    cout << "Printing pm!" << endl; //711
    //    pm.displayNumPages();
    //    pm = t;
    //    cout << "Printing pm after passing in textbook!" << endl; //5430
    //    pm.displayNumPages(); //only prints pages, NOT index too - SLICING
    //base class doesn't have the extra stuff that a derived class has so the extra stuff isnt copied over!!
    
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    cout << "PRINTING PMPTR" << endl;
    pmPtr->displayNumPages(); //still only printes pages and not index
    //dereferencing a BASE class so will get the BASE's method
    //regardless of if u set pointer to a derived
    //UNLESS method marked as virtual
    
    
    //    cout << "regular function printing:" << endl;
    //    displayNumberOfPages(m);
    //    displayNumberOfPages(n);
    //    displayNumberOfPages(t);
    
    
    cout << endl << endl << "Printing from vector!" << endl;
    vector<PrintedMaterial*> printList;
    printList.push_back(&t);
    printList.push_back(&n);
    printList.push_back(&m);
    for (PrintedMaterial*& each : printList) {
        each->displayNumPages();
    }
}
