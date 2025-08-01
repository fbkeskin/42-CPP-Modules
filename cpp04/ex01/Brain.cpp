/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:49:06 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 14:23:49 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor 🧠" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = "tabula rasa";
    }
}

Brain::Brain(const Brain& source)
{
    std::cout << "Brain copy constructor" << std::endl;
    *this = source;
}

Brain& Brain::operator=(const Brain& source)
{
    std::cout << "Brain copy assignment overloading" << std::endl;
    if(this == &source)
        return(*this);
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = source.ideas[i];
    }
    return(*this);
}

void    Brain::setIdea(int index, std::string newIdea)
{
    if((index >= 0) && (index <= 99))
        this->ideas[index] = newIdea;
    else
        std::cout << "Index is outside the range 0-100, can't set idea." << std::endl;
}

std::string Brain::getIdea(int index)
{
    if((index >= 0) && (index <= 99))
        return(this->ideas[index]);
    std::cout << "Index is outside the range 0-100, can't get idea." << std::endl;
    return("");
}

void    Brain::printBrainIdeas()
{
    for(int i = 0; i < 100; i++)
    {
        std::cout << i << ". index idea-> " << this->ideas[i] << std::endl;
    }
}

Brain::~Brain()
{
    std::cout << "Brain default destructor 🤯" << std::endl;
}
