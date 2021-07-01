//
//  Annlie Nguyen
//  rec04
//
//
// Understanding pointers

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int x;
    x = 10; // originally x = 0;
    cout << "x = " << x << endl; // x = 10;
    //for watch window --> right click in local variable window
    //add expression or right click on variable and click watch
    
    /*
     cout << 0xB << endl; //prints out 11, hexadecimal
     cout << hex << 0xB << endl; //prints out b, asks for hexadecimal output
     cout << dec << 0xB << endl; //prints out 11, reverts hex back to decimal output
     */
    
    int* p; //p is a pointer to an int
    p = &x; //same "int *" type for &x and p, ADDRESS-OF OPERATOR
    //p is dereferecing a pointer, p points to where x is, 10 is stored in x
    //p = 0x7ffeefbff598;
    //p = 1000000;
    cout << "p = " << p << endl; //0x7ffeefbff598 in debugger, matches
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    //*p is DEREFERENCE OPERATOR, a memory location too
    //follow pointer value stored in p, get value where p points to
    //*p referring to x
    
    *p = -2763; //changes p and x
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    //since p a variable, can assign things to it as long as we're assigning pointer values
    //made p point to y, used p to chage y
    
    int* q;
    q = p;
    //pointer q = pointer p which is pointing to y (y=980)
    //types of q and p are both int *
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    
    double d(33.44); //d is a double, d = 33.44
    double* pD(&d); //pD is a pointer to double d, holding address of d
    //*pD = 33.44 rn
    *pD = *p; //*pD now = 980, *p = 980
    *pD = 73.2343; //*pD now = 73.2343
    *p  = *pD; //*p = 73 --> p is a pointer to an INT not a double
    *q  = *p; //*q = 73
    //p and q holding same address (73), pD holding address of 73.2343
    /*
     can't assign doubles to int (pointers or regular) and vice versa
     pD  = p;
     p   = pD;
     */
    
    int joe = 24;
    const int sal = 19;
    int*  pI; //pointer to an int, pointers hold addresses
    pI = &joe; //pI points to joe, *pI holding 24
    *pI = 234; //changes joe to 234
    //  pI = &sal; //error, can't assign a const int* to a regular int*
    *pI = 7623; //changes joe to 7623
    
    const int* pcI; //pcI is a pointer to an int that is constant
    pcI = &joe;
    // *pcI = 234; //error, pcI points to a constant int so you can't change joe
    pcI = &sal;
    // *pcI = 7623; //error pcI points to a const int so you can't change sal
    
    //int* const cpI; //cpI is a constant pointer to an int
    //have to set it equal to something as a default bc you can't change it
    //int* const cpI(&joe); //cpI is constant so can't change its value
    //int* const cpI(&sal);
    //  cpI = &joe;
    // *cpI = 234; //no error bc going directly to the int its holding
    //  cpI = &sal;
    // *cpI = 7623;
    
    //const int* const cpcI; //cpcI is a const pointer to a constant int
    //error bc u have to initialize it to something since u can't change it later
    //const int* const cpcI(&joe); //error, can't change a const
    //const int* const cpcI(&sal); //error, can't change a const
    //  cpcI = &joe;  // *cpcI = 234;
    //  cpcI = &sal;
    // *cpcI = 7623; //said its holding a const int, can't change the int
    
    
    
    
    struct Complex {
        double real;
        double img;
    };
    
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    //cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    //dereferences a pointer to complex object
    
    class PlainOldClass {
    public:
        PlainOldClass() : x(-72) {}
        int getX() const { return x; } //bc of const method cannot change anything in the class
        void setX( int val )  { x = val; }
    private:
        int x;
    };
    
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc ); //ppoc is a pointer holding the address of poc
    cout << ppoc->getX() << endl; //pointer accessing a method directly
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    class PlainOldClassV2 {
    public:
        PlainOldClassV2() : x(-72) {}
        int getX() const { return x; }
        void setX( int x )  { this->x = x; } // HMMMM???
    private:
        int x;
    };
    
    PlainOldClassV2 poc1;
    PlainOldClassV2* ppoc1( &poc1 ); //ppoc1 is a pointer holding the address of poc1
    cout << ppoc1->getX() << endl; //pointer accessing a method directly
    ppoc1->setX( 2837 ); //doesn't change it without adding "this->"
    //was assigning parameter x to itself inititally
    cout << ppoc1->getX() << endl;
    
    
    
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    cout << "The " << *pDyn
    << " is stored at address " << pDyn
    << " which is in the heap\n";
    cout << pDyn << endl;
    delete pDyn; //gives back space to heap, doesn't affect pointer variable
    cout << pDyn << endl;
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    //not supposed to be able to access the deleted space but c++ still lets us
    pDyn = nullptr;
    double* pDouble = nullptr;
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    double* pTest = new double(12);
    //delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    short* pShrt = new short(5);
    delete pShrt;
    //delete pShrt;
    //program can't touch the pointer anymore bc we gave it back
    
    /*
     long jumper = 12238743;
     delete jumper;
     long* ptrTolong = &jumper;
     delete ptrTolong;
     Complex cmplx;
     delete cmplx;
     
     delete won't work on anything outside of the heap
     */
    
    
    
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
    }
    // clear the vector
    complV.clear();
    
    
    
    class Colour {
    public:
        Colour(const string& name, unsigned r, unsigned g, unsigned b)
        : name(name), r(r), g(g), b(b) {}
        void display() const {
            cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
        }
    private:
        string name;      // what we call this colour
        unsigned r, g, b; // red/green/blue values for displaying
    };
    
    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // ^^^ type in ctrl(^) D on a new line
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
    }
    
    // display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        colours[ndx]->display();
        cout << endl;
    }
    
    
    
    
    
    
    
    class SpeakerSystem {
    public:
        void vibrateSpeakerCones(unsigned signal) const {
            
            cout << "Playing: " << signal << "Hz sound..." << endl;
            cout << "Buzz, buzzy, buzzer, bzap!!!\n";
        }
    };
    
    class Amplifier {
    public:
        void attachSpeakers(const SpeakerSystem& spkrs)
        {
            if(attachedSpeakers)
                cout << "already have speakers attached!\n";
            else
                attachedSpeakers = &spkrs;
            //error bc attachedSpeakers is a pointer to SpeakerSystem object
            //attachedSpeakers holds an ADDRESS, can be changed bc its not a const
            //spkrs is SpeakerSystem object that is passed in by reference, can't be changed
            //can't pass in a non-const variable to a const parameter
        }
        
        void detachSpeakers() { // should there be an "error" message if not attached?
            attachedSpeakers = nullptr;
        }
        
        void playMusic( ) const {
            if (attachedSpeakers)
                attachedSpeakers -> vibrateSpeakerCones(440);
            else
                cout << "No speakers attached\n";
        }
    private:
        const SpeakerSystem* attachedSpeakers = nullptr;
    };
    
    
    
    
    
    // add in tests: if already have roommate, roommate being added is not yourself
    class Person {
    public:
        Person(const string& name) : name(name) {}
        void movesInWith(Person& newRoomate) {
            if (roomie) {
                cout << "Already have a roommate!" << endl;
            } else if (&newRoomate == this) {
                cout << "Can't room by yourself" << endl;
            } else if (newRoomate.roomie) {
                cout << "Roommate already has someone" << endl;
            } else {
                roomie = &newRoomate;        // now I have a new roomie
                newRoomate.roomie = this;    // and now they do too
            }
        }
        const string& getName() const { return name; }
        // Don't need to use getName() below, just there for you to use in debugging.
        const string& getRoomiesName() const { return roomie->getName(); }
    private:
        Person* roomie = nullptr;
        string name;
    };
    
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    Person annlie("Annlie");
    Person julie("Julie");
    
    joeBob.movesInWith(joeBob); //can't room with urself
    billyJane.movesInWith(annlie); //success
    
    // now model these two becoming roommates
    joeBob.movesInWith(billyJane); //roommate already has someone
    
    joeBob.movesInWith(julie); //success
    
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    
    
    return 0;
}
