/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:54:31 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/12 20:49:19 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::HumanB(std::string name, Weapon* weapon)
{
    this->name = name;
    this->weapon = weapon;
}

std::string HumanB::getName()
{
    return (this->name);
}

void HumanB::setName(std::string name)
{
    this->name = name;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

Weapon*    HumanB::getWeapon()
{
    return (weapon);
}

void    HumanB::attack()
{
     std::cout << name << " use " << weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
    // empty
}