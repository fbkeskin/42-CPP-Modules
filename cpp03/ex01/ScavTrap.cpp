/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:57:37 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 15:40:05 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->name = "default";
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& sourceClass)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if(this == &sourceClass)
        return(*this);
    this->name = getName();
    return(*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if ((this->hitPoint > 0) && (this->energyPoint > 0))
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " 🪓" << std::endl;
        this->energyPoint = this->energyPoint - 1;
    } 
    else if (this->energyPoint == 0)
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", not enough energy points." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " already dead 💀" << std::endl;
}

void ScavTrap::guardGate()
{
    if(this->hitPoint > 0)
        std::cout << "ScavTrap " << getName() << " is now in Gate Keeper Mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;  
}
