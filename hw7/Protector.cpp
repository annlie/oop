//
//  Protector.cpp
//  hw07
//
//  Created by Annlie Nguyen on 11/11/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Protector.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft{
    //PROTECTOR CLASS
    Protector::Protector(const string& name, float strength) :
    name(name), strength(strength) {}

    bool Protector::isHired() const { return hired; }
    bool Protector::isAlive() const { return alive; }
    float Protector::getStrength() const { return strength; }
    Lord* Protector::returnBoss() const { return boss; }
    const string& Protector::getName() const { return name; }
    void Protector::die() {
        strength = 0;
        alive = false;
    }

    void Protector::newBoss(Lord* boss) {
        this->boss = boss;
        hired = true;
    }

    void Protector::loseBoss(Lord* boss) {
        this->boss = nullptr;
        hired = false;
    }

    void Protector::quit() {
        if (!hired) { //checks if hired at all
            cout << "Could not quit!" << endl;
            return;
        }
        boss->removeFromArmy(this); //removes warrior from boss's vector
        boss = nullptr;
        hired = false;
    }

    void Protector::changeStrength(float prop) {
        strength *= prop;
    }

    //WIZARD CLASS
    Wizard::Wizard (const string& name, float strength) : Protector(name, strength) {}
    void Wizard::defend() {
        cout << "POOF!" << endl;
    }

    //WARRIOR CLASS
    Warrior::Warrior(const string& name, float strength) : Protector(name, strength) {}
    void Warrior::defend() {
        cout << getName() << " says: Take that in the name of my lord, ";
        cout << returnBoss()->getName() << endl;
    }

    //ARCHER CLASS
    Archer::Archer (const string& name, float strength) : Warrior(name, strength) {}
    void Archer::defend() {
        cout << "TWANG! ";
        if (returnBoss() != nullptr) {
            Warrior::defend();
        }
    }

    //SWORDSMAN CLASS
    Swordsman::Swordsman (const string& name, float strength)
    : Warrior(name, strength) {}
    void Swordsman::defend() {
        cout << "CLANG! ";
        if (returnBoss() != nullptr) {
            Warrior::defend();
        }
    }
}
