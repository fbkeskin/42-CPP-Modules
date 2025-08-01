/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:41:20 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 15:43:06 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor" << std::endl;
    this->type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal(source)
{
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = source;
}

WrongCat& WrongCat::operator=(const WrongCat& source)
{
    std::cout << "WrongCat copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    return(*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "😽 woem woooem woem 😽" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destructor 😿👋" << std::endl;
}
