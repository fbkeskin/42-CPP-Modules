/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:58:11 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/16 15:14:01 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
    Fixed a; // a = 0.0
    Fixed const b(Fixed(5.05f) * Fixed(2)); // b(toFloat) = (1293 / 256) * (512 / 256) = 10.10156
    // std::cout << "5.05f: " << roundf(1292.8) << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl; // fixedPontValue 1 artıyor. yani artış 1/256 -> 0,00390625
    std::cout << a << std::endl;
    std::cout << a++ << std::endl; // a = b oldu
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    return (0);
}
