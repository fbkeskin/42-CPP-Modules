/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:14:50 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 16:13:16 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// derived class
class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const Dog& source);
        Dog& operator=(const Dog& source);
        void    makeSound() const;
        void    setDogIdea(int index, std::string newIdea);
        std::string getDogIdea(int index) const;
        void    printDogIdeas();
        ~Dog();
};

#endif
