/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:58:08 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 15:01:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int    Fixed::fractBits = 8;

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(const int integerNumber)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = integerNumber * (1 << this->fractBits);
}

Fixed::Fixed(const float floatNumber)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(floatNumber * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed& otherFixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    //this->fixedPointValue = otherFixed.getRawBits();
    *this = otherFixed;
}

Fixed& Fixed::operator=(const Fixed& otherFixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if(this == &otherFixed)
        return (*this);
    this->fixedPointValue = otherFixed.getRawBits();
    return (*this);
}

/* COMPARISON OPERATORS OVERLOADING */
bool  Fixed::operator>(const Fixed& otherFixed)const
{
    bool ret = this->toFloat() > otherFixed.toFloat();
    return(ret);
}

bool  Fixed::operator<(const Fixed& otherFixed)const
{
    bool ret = this->toFloat() < otherFixed.toFloat();
    return(ret);
}

bool  Fixed::operator>=(const Fixed& otherFixed)const
{
    bool ret = this->toFloat() >= otherFixed.toFloat();
    return(ret);
}

bool  Fixed::operator<=(const Fixed& otherFixed)const
{
    bool ret = this->toFloat() <= otherFixed.toFloat();
    return(ret);
}

bool  Fixed::operator==(const Fixed& otherFixed)const
{
    bool ret = this->toFloat() == otherFixed.toFloat();
    return(ret);
}

bool  Fixed::operator!=(const Fixed& otherFixed)const
{
    bool ret = this->toFloat() != otherFixed.toFloat();
    return(ret);
}

/* ARITHMETIC OPERATORS OVERLOADING */
float  Fixed::operator+(const Fixed& otherFixed)const
{
    float value = (this->toFloat()) + (otherFixed.toFloat());
    return(value);
}

float  Fixed::operator-(const Fixed& otherFixed)const
{
    float value = (this->toFloat()) - (otherFixed.toFloat());
    return(value);
}

float  Fixed::operator*(const Fixed& otherFixed)const
{
    float value = (this->toFloat()) * (otherFixed.toFloat());
    return(value);
}

float  Fixed::operator/(const Fixed& otherFixed)const
{
    float value = (this->toFloat()) / (otherFixed.toFloat());
    return(value);
}

/* (PRE/POST) INCREMENT-DECREMENT OPERATORS OVERLOADING */
Fixed&  Fixed::operator++()
{
    this->fixedPointValue = this->fixedPointValue + 1;
    return(*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixedPointValue = this->fixedPointValue + 1;
    return(temp);
}

Fixed&  Fixed::operator--()
{
    this->fixedPointValue = this->fixedPointValue - 1;
    return(*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixedPointValue = this->fixedPointValue - 1;
    return(temp);
}

/* OTHER FUNCTIONS */
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

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
    if(obj1.fixedPointValue <= obj2.fixedPointValue)
        return (obj1);
    return(obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
    if(obj1.fixedPointValue <= obj2.fixedPointValue)
        return (obj1);
    return(obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
    if(obj1.fixedPointValue >= obj2.fixedPointValue)
        return (obj1);
    return(obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
    if(obj1.fixedPointValue >= obj2.fixedPointValue)
        return (obj1);
    return(obj2);
}

/* DESTRUCTOR */
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

/* INSERTION OPERATOR OVERLOADING */
std::ostream&  operator<<(std::ostream& output, const Fixed& classREF)
{
    output << classREF.toFloat();
    return (output);
}
