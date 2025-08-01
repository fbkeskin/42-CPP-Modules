/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:21 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 14:48:50 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->name = "default";
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap: " << name << " constructor called" << std::endl;
    this->name = name;
    this->hitPoint = 10;
    this->energyPoint = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& sourceClass)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if(this == &sourceClass)
        return(*this);
    this->name = getName();
    return(*this);
}

/* GETTER-SETTER MEMBER FUNCTIONS */
std::string ClapTrap::getName()const
{
    return(this->name);
}

void ClapTrap::setName(std::string& name)
{
    if(!(name.empty()))
        this->name = name;
}

int ClapTrap::getHitPoint()const
{
    return(this->hitPoint);
}

int ClapTrap::getEnergyPoint()const
{
    return(this->energyPoint);

}

int ClapTrap::getAttackDamage()const
{
    return(this->attackDamage);
}

/* OTHER MEMBER FUNCTIONS */
void ClapTrap::attack(const std::string& target)
{
    if ((this->hitPoint > 0) && (this->energyPoint > 0))
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " 🪓" << std::endl;
        this->energyPoint = this->energyPoint - 1;
    }
    else if (this->energyPoint == 0)
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", not enough energy points." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " already dead 💀" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitPoint > 0)
    {
        this->hitPoint = this->hitPoint - amount;
        std::cout << "ClapTrap " << this->name << " take damage as " << amount<< " hit points 🤕" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " not enough hitpoints." << std::endl;
}   

void        ClapTrap::beRepaired(unsigned int amount)
{
    if ((this->hitPoint > 0) && (this->energyPoint > 0))
    {
        this->hitPoint = this->hitPoint + amount;
        this->energyPoint = this->energyPoint - 1;
        std::cout << "ClapTrap " << this->name << " be repaired as " << amount << " hit points 😝" << std::endl;
    }
    else if (this->energyPoint == 0)
        std::cout << "ClapTrap " << this->name << " not enough energy points." << std::endl;
    else
		std::cout << "ClapTrap " << this->name << " already dead 💀" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}
