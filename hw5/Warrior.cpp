//
//  Warrior.cpp
//  hw05
//
//  Created by Annlie Nguyen on 10/30/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Warrior.hpp"
using namespace std;

namespace WarriorCraft {
    //WARRIOR CLASS:
    ostream& operator<<(ostream& os, const Warrior& rhs) {
        os << rhs.name << ": " << rhs.strength;
        return os;
    }
    
    Warrior::Warrior (const string& name, float strength) :
    name(name), strength(strength){}
    
    bool Warrior::getStatus() const { return hired; }
    bool Warrior::getAlive() const { return alive; }
    void Warrior::changeStatus(bool newStatus) { hired = newStatus; }
    float Warrior::getStrength() const { return strength; }
    const string& Warrior::getName() const { return name; }
    
    void Warrior::die() {
        strength = 0;
        alive = false;
    }
    
    void Warrior::changeStrength(float prop) { strength = strength*prop; }
    
    void Warrior::runaway() {
        cout << name << " runs away, abandoning their lord, ";
        cout << boss->getName() << endl;
        hired = false;
        boss->warriorRunaway(this);
        boss = nullptr;
    }
    
    void Warrior::newBoss(Noble* bossMan) {
        boss = bossMan;
    }
    
    void Warrior::loseBoss() {
        boss = nullptr;
    }
}


