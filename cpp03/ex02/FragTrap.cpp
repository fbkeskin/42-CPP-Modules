/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:23:39 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 17:56:02 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "default";
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
    this->name = name;
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& sourceClass)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if(this == &sourceClass)
        return(*this);
    this->name = getName();
    return(*this);
}

void FragTrap::highFivesGuys(void)
{
    if (this->hitPoint > 0)
		std::cout << "FragTrap wants to see a high five!" << std::endl;
	else
		std::cout << "FragTrap is already dead :(" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;  
}
