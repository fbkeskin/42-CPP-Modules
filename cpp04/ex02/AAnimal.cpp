/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:19:20 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 16:35:45 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor" << std::endl;
    this->type = "default aanimal";
}

AAnimal::AAnimal(std::string type)
{
    std::cout << "AAnimal parametrized constructor" << std::endl;
    if(!(type.empty()))
        this->type = type;
}

AAnimal::AAnimal(const AAnimal& source)
{
    std::cout << "AAnimal copy constructor" << std::endl;
    *this = source;
}

AAnimal& AAnimal::operator=(const AAnimal& source)
{
    std::cout << "AAnimal copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

std::string AAnimal::getType()const
{
    return(this->type);
}

void AAnimal::setType(std::string type)
{
    if(!(type.empty()))
        this->type = type;
}

void    AAnimal::makeSound() const
{
    std::cout << "🦋 i am aanimal 🦋" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal default destructor 🧹" << std::endl;
}
