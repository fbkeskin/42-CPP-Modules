#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string  name;
        Weapon&      weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        std::string         getName();
        void                setName(std::string name);
        void                attack();
        ~HumanA();
};

#endif