/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:14:50 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/18 17:32:41 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// base class
class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& source);
        Animal& operator=(const Animal& source);
        std::string getType()const;
        void setType(std::string type);
        virtual void makeSound() const;
        virtual ~Animal();
};

#endif
