/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:42:20 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:40:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* CONSTRUCTORS */
Zombie::Zombie()
{
    // empty constructor
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

/* SETTER FUNCTIONS */
void        Zombie::setName(std::string name)
{
    if(!(name.empty()))
        this->name = name;
}

/* GETTER FUNCTIONS */
std::string Zombie::getName(void)
{
    return (this->name);
}

/* OTHER PUBLIC FUNCTIONS */
void Zombie::announce(int index)
{
    std::cout << this->name << "[" << index << "]" << " 🧟" << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* DESTRUCTORS */
Zombie::~Zombie()
{
    std::cout << "💣NO WAY!! Zombies are being destroyed💣" << std::endl;
}