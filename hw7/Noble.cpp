//
//  Noble.cpp
//  hw07
//
//  Created by Annlie Nguyen on 11/11/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Noble.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft{
    //NOBLE CLASS
    Noble::Noble(const string& name, float strength)
        : name(name), strength(strength) {}
    const string& Noble::getName() const { return name; }
    void Noble::changeStrength(float newStrength) { strength += newStrength; }
    void Noble::setStrength(float prop) { strength = prop; }
    bool Noble::isAlive() const { return alive; }
    void Noble::dies() {
        alive = false;
        strength = 0;
    }
    void Noble::battle(Noble& enemy) {
        cout << name << " battles " << enemy.name << endl;
        if(!alive && !enemy.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else if (strength == enemy.strength) {
            dies();
            enemy.dies();
            cout << "Mutual Annihalation: ";
            cout << name << " and " << enemy.name;
            cout << " die at each other's hands" << endl;
        } else if (alive && !enemy.alive) {
            cout << "He's dead, " << name << endl;
        } else if (!alive && enemy.alive) {
            cout << "He's dead, " << enemy.name << endl;
        } else if (strength > enemy.strength) {
            float prop = 1 - (enemy.strength / strength);
            //find proportion btwn strengths
            fight();
            enemy.fight();
            wins(prop);
            enemy.dies();
            cout << name << " defeats " << enemy.name << endl;
        } else if (strength < enemy.strength) {
            float prop = 1 - (enemy.strength / strength);
            //find proportion btwn strengths
            fight();
            enemy.fight();
            enemy.wins(prop);
            dies();
            cout << enemy.name << " defeats " << name << endl;
        }
    }

    //LORD CLASS
    Lord::Lord(const string& name) : Noble(name) {}

    bool Lord::hires(Protector& protec) {
        if (protec.isHired() || !protec.isAlive() || !isAlive()) {
            cout << Noble::getName();
            cout << " could not hire" << endl;
            return false;
        }
        army.push_back(&protec);
        protec.newBoss(this); //changes boss ptr and sets hired to true
        float added = protec.getStrength();
        changeStrength(added); //changing nobles strength
        return true;
    }

    void Lord::removeFromArmy(Protector* war) {
        float loss = war->getStrength();
        changeStrength(loss*-1); //changes nobles strength
        Protector* last = army.back();
        for (Protector* each : army) {
            if (each == war) {
                each = last; //two of the last protector
                army.pop_back(); //remove one of the duplicates
                break;
            }
        }
    }

    bool Lord::fires(Protector& protec) {
        if(!isAlive() || protec.returnBoss() != this) {
            cout << "Could not fire!" << endl;
            return false;
        }
        removeFromArmy(&protec); //strength change and vector change
        protec.loseBoss(this); //ptr change and hired bool change
        return true;
    }

    void Lord::fight() {
        for (Protector* each : army) {
            each->defend();
        }
    }
    void Lord::dies() {
        for(Protector* each : army) {
            each->die();
        }
        Noble::dies();
    }
    void Lord::wins(float prop) {
        for (Protector* each : army) {
            each->changeStrength(prop); //change warrior strength proportionally
        }
        setStrength(0); //sets strength to 0
        for (Protector* each : army) {
            //change noble's strength according to new warrior strengths
            float newStrength = each->getStrength();
            changeStrength(newStrength);
        }
    }

    //PERSONWITH CLASS
    PersonWithStrengthToFight::PersonWithStrengthToFight
        (const string& name, float strength) : Noble(name, strength) {}
    void PersonWithStrengthToFight::fight() { cout << ' '; }
    void PersonWithStrengthToFight::dies() { Noble::dies(); }
    void PersonWithStrengthToFight::wins(float prop) { Noble::setStrength(prop); }
}
