/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:06:15 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:37:13 by fatkeski         ###   ########.fr       */
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
void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/** DESTRUCTORS 
 * Zombies must be destroyed when you don’t need them anymore. 
 * The destructor must print a message with the name of the zombie for debugging purposes.
*/
Zombie::~Zombie()
{
    if(this->name == "gumball")
        std::cout << "gumball left the heap.." << std::endl;
    else if(this->name == "darwin")
        std::cout << "darwin left the stack.." << std::endl;
    else
        std::cout << "destructor worked" << std::endl;
}
