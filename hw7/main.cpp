//
//  Annlie Nguyen
//  hw07
//
//  Nobles and Protectors with inheritance
//

#include <iostream>
#include "Noble.hpp"
#include "Protector.hpp"
using namespace std;
using namespace WarriorCraft;

int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);  //1
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy); //1
    janet.hires(stout); //1
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha); //0 samantha already hired
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora); //0 janet dead
    janet.hires(thora); //0 janet dead
    cout << "Try" << endl;
    sam.hires(merlin); //1
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}
