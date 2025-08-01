/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:14:02 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 16:25:57 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& source) : Animal(source)
{
    std::cout << "Cat copy constructor" << std::endl;
    this->brain = NULL;
    *this = source;
}

Cat& Cat::operator=(const Cat& source)
{
    std::cout << "Cat copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    this->type = source.getType();
    if(this->brain)
        delete this->brain;
    this->brain = new Brain(*(source.brain));
    for(int i = 0; i < 100; i++)
    {
        this->setCatIdea(i, source.getCatIdea(i));

    }
    return(*this);
}

void    Cat::makeSound() const
{
    std::cout << "😽 meow meooow meow 😽" << std::endl;
}

void    Cat::setCatIdea(int index, std::string newIdea)
{
    this->brain->setIdea(index, newIdea);
}

std::string Cat::getCatIdea(int index) const
{
    return(this->brain->getIdea(index));
}

void    Cat::printCatIdeas()
{
    this->brain->printBrainIdeas();
}

Cat::~Cat()
{
    std::cout << "Cat default destructor 😿👋" << std::endl;
    delete this->brain;
}
