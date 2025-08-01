/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:19:20 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/18 17:32:48 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor" << std::endl;
    this->type = "default animal";
}

Animal::Animal(std::string type)
{
    std::cout << "Animal parametrized constructor" << std::endl;
    if(!(type.empty()))
        this->type = type;
}

Animal::Animal(const Animal& source)
{
    std::cout << "Animal copy constructor" << std::endl;
    *this = source;
}

Animal& Animal::operator=(const Animal& source)
{
    std::cout << "Animal copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

std::string Animal::getType()const
{
    return(this->type);
}

void Animal::setType(std::string type)
{
    if(!(type.empty()))
        this->type = type;
}

void    Animal::makeSound() const
{
    std::cout << "🦋 i am animal 🦋" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal default destructor 🧹" << std::endl;
}
