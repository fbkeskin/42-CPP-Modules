/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:14:02 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 15:42:46 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& source) : Animal(source)
{
    std::cout << "Cat copy constructor" << std::endl;
    *this = source;
}

Cat& Cat::operator=(const Cat& source)
{
    std::cout << "Cat copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

void    Cat::makeSound() const
{
    std::cout << "😽 meow meooow meow 😽" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat default destructor 😿👋" << std::endl;
}
