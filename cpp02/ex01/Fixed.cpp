/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:50:11 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 14:24:07 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int    Fixed::fractBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(const int integerNumber)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = integerNumber * (1 << this->fractBits);
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatNumber * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    //this->fixedPointValue = otherFixed.getRawBits();
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& sourceClass)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &sourceClass)
        return (*this);
    this->fixedPointValue = sourceClass.getRawBits();
    return (*this);
}

float   Fixed::toFloat(void) const
{
    return((float)(this->fixedPointValue) / (float)( 1 << this->fractBits));
}

int     Fixed::toInt(void) const
{
    return((this->fixedPointValue) / (1 << this->fractBits));
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return(this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream&  operator<<(std::ostream& output, const Fixed& classREF)
{
    output << classREF.toFloat();
    return (output);
}
