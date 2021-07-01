//
//  Noble.hpp
//  hw07
//
//  Created by Annlie Nguyen on 11/11/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Protector.hpp"

namespace WarriorCraft{

    class Protector;

    class Noble {
    public:
        Noble(const std::string& name, float strength=0);
        const std::string& getName() const;
        virtual void battle(Noble& enemy);
        virtual void fight() = 0;
        virtual void dies() = 0;
        virtual void wins(float prop) = 0;
    private:
        std::string name;
        bool alive = true;
        float strength;
    protected:
        bool isAlive() const;
        void changeStrength(float newStrength);
        void setStrength(float reset);
    }; //end noble

    class Lord : public Noble {
    public:
        Lord(const std::string& name);
        bool hires(Protector& protec);
        void removeFromArmy(Protector* war);
        bool fires(Protector& protec);
        void fight();
        void dies();
        void wins(float prop);
    private:
        std::vector<Protector*> army;
    }; //end lord


    class PersonWithStrengthToFight : public Noble {
    public:
        PersonWithStrengthToFight(const std::string& name, float strength);
        void fight();
        void dies();
        void wins(float prop);
    private:
    }; //end personwithstrengthtofight

}
#endif /* Noble_hpp */
