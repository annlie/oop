//
//  Warrior.hpp
//  hw05
//
//  Created by Annlie Nguyen on 10/30/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Warrior_hpp
#define Warrior_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Noble.hpp"

namespace WarriorCraft {
    class Noble;

    class Warrior {
        friend std::ostream& operator<<(std::ostream& os, const Warrior& rhs);
        
    public:
        Warrior (const std::string& name, float strength);
        bool getStatus() const;
        bool getAlive() const;
        void changeStatus(bool newStatus);
        float getStrength() const;
        const std::string& getName() const;
        void die();
        void changeStrength(float prop);
        void runaway();
        void newBoss(Noble* bossMan);
        void loseBoss();
        
    private:
        std::string name;
        float strength;
        bool hired = false;
        bool alive = true;
        Noble* boss = nullptr;
    };
}
#endif /* Warrior_hpp */
