/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:14:50 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 15:42:25 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// derived class
class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& source);
        Dog& operator=(const Dog& source);
        void    makeSound() const;
        ~Dog();
};

#endif
