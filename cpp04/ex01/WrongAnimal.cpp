/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:55 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/25 16:38:15 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Wrong Animal default constructor" << std::endl;
    this->type = "default wrong animal";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal parametrized constructor" << std::endl;
    if(!(type.empty()))
        this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source)
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = source;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& source)
{
    std::cout << "WrongAnimal copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

std::string WrongAnimal::getType()const
{
    return(this->type);
}

void WrongAnimal::setType(std::string type)
{
    if(!(type.empty()))
        this->type = type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "🦍 i am wrong animal 🦍" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal default destructor 🧹" << std::endl;
}
