//
//  Noble.cpp
//  hw05
//
//  Created by Annlie Nguyen on 10/30/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#include "Noble.hpp"
using namespace std;

namespace WarriorCraft {
    //NOBLE CLASS:
    ostream& operator<<(ostream& os, const Noble& rhs) {
        os << rhs.name << " has an army of ";
        os << rhs.army.size() << endl;
        if (rhs.army.size() != 0) {
            for (Warrior* each : rhs.army) {
                cout << *each << endl; //calls warrior's << operator overload
            }
        }
        return os;
    }
    Noble::Noble (const string& name) : name(name) {}
    const string& Noble::getName() const { return name; }
    
    bool Noble::hire(Warrior& war) {
        bool checkStatus = war.getStatus();
        bool checkAlive = war.getAlive();
        if (checkStatus || !checkAlive || alive == false) {
            return false;
        } else {
            war.changeStatus(true);
            float newstrength = war.getStrength();
            strength += newstrength;
            army.push_back(&war);
            war.newBoss(this);
            return true;
        }
    }
    
    bool Noble::warriorRunaway(Warrior* war) {
        size_t index = findWar(*war);
        if (index == army.size()) {
            cout << "Could not runaway!" << endl;
            return false;
        } else {
            strength -= war->getStrength();
            army[index] = army.back(); //change pointer to last warrior
            army.pop_back(); //will have two of last warrior, so remove one of them
            return true;
        }
    }
    
    size_t Noble::findWar(const Warrior& war) {
        for (size_t i = 0; i < army.size(); i++) {
            if (army[i] == &war) {
                return i; //returns index of warrior
            }
        }
        return army.size();
    }
    
    
    //CHANGE WARRIOR'S BOSS POINTER TO NULLPTR
    bool Noble::fire(Warrior& war) {
        size_t index = findWar(war);
        
        if (index == army.size() || alive == false) {
            cout << "Could not fire!" << endl;
            return false;
        } else {
            const float currStrength = war.getStrength();
            strength -= currStrength;
            war.changeStatus(false);
            
            war.loseBoss(); //warrior's boss ptr set to nullptr
            
            string warName = war.getName();
            cout << warName << ", you're fired! -- " << name << endl;
            
            //change pointer to last warrior, has two of last so remove one
            army[index] = army.back();
            army.pop_back();
            return true;
        }
    }
    
    void Noble::changeAllStrength(float prop) {
        for (Warrior* each : army) {
            //change each warrior's strength proportionally
            each->changeStrength(prop);
        }
        
        strength = 0;
        for (Warrior* each : army) {
            //change noble's strength according to new warrior strengths
            float newStrength = each->getStrength();
            strength += newStrength;
        }
    }
    
    void Noble::battle(Noble& enemy) {
        cout << name << " battles " << enemy.name << endl;
        if (!alive && !enemy.alive) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else if (strength == enemy.strength) {
            cout << "Mutual Annihalation: ";
            cout << name << " and " << enemy.name;
            cout << " die at each other's hands" << endl;
            alive = false;
            enemy.alive = false;
            
            for (Warrior* each : army) {
                //noble is dead so all warriors dead
                each->die();
            }
            for (Warrior* eachEnemy : enemy.army) {
                //noble is dead so all warriors dead
                eachEnemy->die();
            }
            
            strength = 0;
            enemy.strength = 0;
            
        } else if (alive && !enemy.alive) {
            cout << "He's dead " << name << endl;
        } else if (!alive && enemy.alive) {
            cout << "He's dead " << enemy.name << endl;
        } else if (strength > enemy.strength) {
            cout << name << " defeats " << enemy.name << endl;
            enemy.alive = false;
            
            float prop = 1 - (enemy.strength / strength);
            //find proportion btwn strengths
            this->changeAllStrength(prop); //change strengths proportionally
            
            for (Warrior* eachEnemy : enemy.army) {
                //noble is dead so all warriors dead
                eachEnemy->die();
            }
            
            enemy.strength = 0;
            
        } else if (strength < enemy.strength) {
            cout << enemy.name << " defeats " << name << endl;
            alive = false;
            
            float prop = 1 - (enemy.strength / strength);
            //find proportion btwn strengths
            enemy.changeAllStrength(prop); //change strengths proportionally
            
            for (Warrior* each : army) {
                //noble is dead so all warriors dead
                each->die();
            }
            
            strength = 0;
        }
    }

}
