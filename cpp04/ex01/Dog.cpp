/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:02:06 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 16:24:16 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& source) : Animal(source)
{
    std::cout << "Dog copy constructor" << std::endl;
    this->brain = NULL;
    *this = source;
}

Dog& Dog::operator=(const Dog& source)
{
    std::cout << "Dog copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);    
    this->type = source.getType();
    if(this->brain)
        delete this->brain;
    this->brain = new Brain(*(source.brain));
    for(int i = 0; i < 100; i++)
    {
        this->setDogIdea(i, source.getDogIdea(i));

    }
    return(*this);
}

void    Dog::makeSound() const
{
    std::cout << "🐶 haav hav havv 🐶" << std::endl;
}

void    Dog::setDogIdea(int index, std::string newIdea)
{
    this->brain->setIdea(index, newIdea);
}

std::string Dog::getDogIdea(int index) const
{
    return(this->brain->getIdea(index));
}

void    Dog::printDogIdeas()
{
    this->brain->printBrainIdeas();
}

Dog::~Dog()
{
    std::cout << "Dog default destructor 🐶👋" << std::endl;
    delete this->brain;
}
