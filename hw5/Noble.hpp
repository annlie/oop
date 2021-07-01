//
//  Noble.hpp
//  hw05
//
//  Created by Annlie Nguyen on 10/30/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Warrior.hpp"

namespace WarriorCraft {
    class Warrior;
    
    class Noble {
        friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
    public:
        Noble (const std::string& name);
        const std::string& getName() const;
        bool hire(Warrior& war);
        bool warriorRunaway(Warrior* war);
        size_t findWar(const Warrior& war);
        bool fire(Warrior& war);
        void changeAllStrength(float prop);
        void battle(Noble& enemy);
        
    private:
        std::string name;
        float strength = 0;
        bool alive = true;
        std::vector<Warrior*> army;
        
    };
}
#endif /* Noble_hpp */
