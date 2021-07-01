//
//  Annlie Nguyen
//  rec10
//
//  Created by Annlie Nguyen on 11/9/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    Instrument() {}
    
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
}; //end of instrument ABSTRACT CLASS

void Instrument::makeSound() const {
    cout << "To make a sound...";
}

//----------

class Brass : public Instrument {
public:
    Brass(unsigned size) : mouthSize(size) {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << mouthSize << endl;
    }
    
private:
    unsigned mouthSize;
}; //end brass

class Trombone : public Brass {
public:
    Trombone(unsigned size) : Brass(size) {}
    
    void makeSound() const {
        Brass::makeSound();
    }
    
    void play() const {
        cout << "Blat";
    }
}; //end trombone

class Trumpet : public Brass {
public:
    Trumpet(unsigned size) : Brass(size) {}
    
    void makeSound() const {
        Brass::makeSound();
    }
    
    void play() const {
        cout << "Toot";
    }
}; //end trumpet

//----------

class String : public Instrument {
public:
    String(unsigned pitch) : pitch(pitch) {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
}; //end string

class Cello : public String {
public:
    Cello(unsigned pitch) : String(pitch) {}
    
    void makeSound() const {
        String::makeSound();
    }
    
    void play() const {
        cout << "Squawk";
    }
}; //end cello

class Violin : public String {
public:
    Violin(unsigned pitch) : String(pitch) {}
    
    void makeSound() const {
        String::makeSound();
    }
    
    void play() const {
        cout << "Screech";
    }
}; //end violin

//----------

class Percussion : public Instrument {
public:
    Percussion() {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
};

class Drum : public Percussion {
public:
    //    using Percussion::Percussion;
    
    void makeSound() const {
        Percussion::makeSound();
    }
    
    void play() const {
        cout << "Boom";
    }
};


class Cymbal : public Percussion {
public:
    //    using Percussion::Percussion;
    
    void makeSound() const {
        Percussion::makeSound();
    }
    void play() const {
        cout << "Crash";
    }
};

//----------

class Musician {
public:
    Musician() : instr(nullptr) {}
    
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }
    
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }
    
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
    void play() const {
        if(instr) {
            instr->play();
        }
        cerr << ' ';
    }
    
private:
    Instrument* instr;
};

//----------

class MILL {
public:
    MILL() {}
    
    void dailyTestPlay() {
        for(size_t i = 0; i < storage.size(); i++) {
            if (storage[i] != nullptr) {
                storage[i]->makeSound();
            } else {
                cout << "null" << endl;
            }
        }
    }
    
    void receiveInstr(Instrument& inst) {
        inst.makeSound();
        
        for (size_t i = 0; i < storage.size(); i++) {
            if (storage[i] == nullptr) {
                storage[i] = &inst;
                return;
            }
        }
        storage.push_back(&inst);
    }
    
    Instrument* loanOut() {
        for (size_t i = 0; i < storage.size(); i++) {
            if (storage[i] != nullptr) {
                Instrument* ptr = storage[i];
                storage[i] = nullptr;
                return ptr;
            }
        }
        return nullptr;
    }
    
private:
    vector<Instrument*> storage;
}; //end of mill

//----------

class Orch {
public:
    Orch () {}
    void addPlayer(Musician& mus) {
        players.push_back(&mus);
    }
    void play() {
        for (Musician* each : players) {
            each->play();
        }
    }
private:
    vector<Musician*> players;
};

//// PART ONE
//int main() {
//
//     cout << "Define some instruments ------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12) ;
//     Violin violin(567) ;
//
//     // use the debugger to look at the mill
//     cout << "Define the MILL --------------------------------------------\n";
//     MILL mill;
//
//     cout << "Put the instruments into the MILL --------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//     cout << "Daily test -------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << "Define some Musicians---------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     groucho.testPlay();
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay(); //null on top
//
//     cout << endl << endl;
//
//     groucho.testPlay();
//     mill.receiveInstr(*groucho.giveBackInstr()); //size 12
//     mill.dailyTestPlay();
//     harpo.acceptInstr(mill.loanOut()); //size 12
//     groucho.acceptInstr(mill.loanOut()); //pitch 567
//     groucho.testPlay();
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;
//}
//
// PART TWO
int main() {
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);
    
    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    cout << "nothing" << endl;
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    cout << "mill getting something" << endl;
    mill.receiveInstr(*ralph.giveBackInstr());
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    cout << endl;
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    cout << endl;
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    cout << endl;
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    cout << endl;
} // main

