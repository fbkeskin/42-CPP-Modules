/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:34:51 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 13:40:32 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractBits = 8;

/* DEAFULT CONSTRUCTOR */
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

/* COPY CONSTRUCTOR */
Fixed::Fixed(const Fixed& sourceClass)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = sourceClass.getRawBits();
}

/* COPY ASSIGNMENT OPERATOR OVERLOADING */
Fixed& Fixed::operator=(const Fixed& sourceClass)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &sourceClass)
        return (*this);
    this->fixedPointValue = sourceClass.getRawBits();
    return (*this);
}

/* GETTER-SETTER FUNCTIONS */
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

/* DESTRUCTOR */
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
