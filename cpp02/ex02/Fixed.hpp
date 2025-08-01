/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:58:02 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 14:58:04 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class  Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractBits; // scale factor
    public:
        /* DEAFULT CONSTRUCTOR */
        Fixed();
        Fixed(const int integerNumber);
        Fixed(const float floatNumber);
        /* COPY CONSTRUCTOR */
        Fixed(const Fixed& copy);
        /* COPY ASSIGNMENT OPERATOR OVERLOADING */
        Fixed&  operator=(const Fixed& sourceClass);

        /* COMPARISON OPERATORS OVERLOADING */
        bool  operator>(const Fixed& otherFixed)const;
        bool  operator<(const Fixed& otherFixed)const;
        bool  operator>=(const Fixed& otherFixed)const;
        bool  operator<=(const Fixed& otherFixed)const;
        bool  operator==(const Fixed& otherFixed)const;
        bool  operator!=(const Fixed& otherFixed)const;

        /* ARITHMETIC OPERATORS OVERLOADING */
        float  operator+(const Fixed& otherFixed)const;
        float  operator-(const Fixed& otherFixed)const;
        float  operator*(const Fixed& otherFixed)const;
        float  operator/(const Fixed& otherFixed)const;

        /* (PRE/POST) INCREMENT-DECREMENT OPERATORS OVERLOADING */
        Fixed&  operator++();
        Fixed  operator++(int);
        Fixed&  operator--();
        Fixed  operator--(int);

        /* OTHER FUNCTIONS */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        static Fixed&           min(Fixed& obj1, Fixed& obj2);
        static const Fixed&     min(const Fixed& obj1, const Fixed& obj2);
        static Fixed&           max(Fixed& obj1, Fixed& obj2);
        static const Fixed&     max(const Fixed& obj1, const Fixed& obj2);
        ~Fixed();
};

/* INSERTION OPERATOR OVERLOADING */
std::ostream&  operator<<(std::ostream& output, const Fixed& classREF);

#endif
