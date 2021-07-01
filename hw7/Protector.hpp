//
//  Protector.hpp
//  hw07
//
//  Created by Annlie Nguyen on 11/11/18.
//  Copyright © 2018 Annlie Nguyen. All rights reserved.
//

#ifndef Protector_hpp
#define Protector_hpp

#include <stdio.h>
#include <string>
#include "Noble.hpp"
namespace WarriorCraft{
    class Lord;
    class Protector {
    public:
        Protector(const std::string& name, float strength);
        virtual void defend() = 0;
        bool isHired() const;
        bool isAlive() const;
        void newBoss(Lord* boss);
        void loseBoss(Lord* boss);
        float getStrength() const;
        void quit();
        Lord* returnBoss() const;
        void changeStrength(float prop);
        void die();
    private:
        std::string name;
        float strength;
        bool hired = false;
        bool alive = true;
        Lord* boss;
    protected:
        const std::string& getName() const;
    }; //end of protector

    class Wizard : public Protector {
    public:
        Wizard (const std::string& name, float strength);
        void defend();
    private:
    }; //end wizard

    class Warrior : public Protector {
    public:
        Warrior(const std::string& name, float strength);
        void defend();
    private:
    }; //end warrior

    class Archer : public Warrior {
    public:
        Archer (const std::string& name, float strength);
        void defend();
    private:
    }; //end archer

    class Swordsman : public Warrior {
    public:
        Swordsman (const std::string& name, float strength);
        void defend();
    private:
    }; //end swordsman
}
#endif /* Protector_hpp */
