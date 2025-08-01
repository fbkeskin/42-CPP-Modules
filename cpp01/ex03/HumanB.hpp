#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon*     weapon;
    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon* weapon);
        std::string getName();
        void        setName(std::string name);
        void        setWeapon(Weapon& weapon);
        Weapon*     getWeapon();
        void        attack();
        ~HumanB();
};

#endif
