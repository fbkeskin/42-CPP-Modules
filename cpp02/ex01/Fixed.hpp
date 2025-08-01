/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:50:06 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 13:50:07 by fatkeski         ###   ########.fr       */
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
        /* PARAMETERIZED CONSTRUCTORS */
        Fixed(const int integerNumber);
        Fixed(const float floatNumber);
        /* COPY CONSTRUCTOR */
        Fixed(const Fixed& copy);
        /* COPY ASSIGNMENT OPERATOR OVERLOADING */
        Fixed&  operator=(const Fixed& sourceClass);
        /* GETTER-SETTER FUNCTIONS */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        /* OTHER FUNCTIONS */
        float   toFloat(void) const; // fixed point num -> float value
        int     toInt(void) const; // fixed point num -> int value
        /* DESTRUCTOR */
        ~Fixed();
};

/* INSERTION OPERATOR OVERLOADING */
std::ostream&  operator<<(std::ostream& output, const Fixed& classREF);

#endif
