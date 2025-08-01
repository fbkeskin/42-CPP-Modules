/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:44:59 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/26 12:42:13 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog()
{
    std::cout << "WrongDog default constructor" << std::endl;
    this->type = "Wrong Dog";
}

WrongDog::WrongDog(const WrongDog& source) : WrongAnimal(source)
{
    std::cout << "WrongDog copy constructor" << std::endl;
    *this = source;
}

WrongDog& WrongDog::operator=(const WrongDog& source)
{
    std::cout << "WrongDog copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

void    WrongDog::makeSound() const
{
    std::cout << "🐶 vaah vah vvah 🐶" << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog default destructor 🐶👋" << std::endl;
}
