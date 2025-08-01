/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:02:06 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 15:41:51 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& source) : Animal(source)
{
    std::cout << "Dog copy constructor" << std::endl;
    *this = source;
}

Dog& Dog::operator=(const Dog& source)
{
    std::cout << "Dog copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

void    Dog::makeSound() const
{
    std::cout << "🐶 haav hav havv 🐶" << std::endl;
}


Dog::~Dog()
{
    std::cout << "Dog default destructor 🐶👋" << std::endl;
}
