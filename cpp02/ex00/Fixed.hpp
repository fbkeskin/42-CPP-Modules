/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:34:58 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 13:47:41 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class  Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fractBits;
    public:
        /* DEAFULT CONSTRUCTOR */
        Fixed();
        /* COPY CONSTRUCTOR */
        Fixed(const Fixed& sourceClass);
        /* COPY ASSIGNMENT OPERATOR OVERLOADING */
        Fixed&  operator=(const Fixed& sourceClass);
        /* GETTER-SETTER FUNCTIONS */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        /* DESTRUCTOR */
        ~Fixed();
};

#endif
