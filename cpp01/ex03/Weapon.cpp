/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:21:36 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/12 16:26:45 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* CONSTRUCTORS */
Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

/* SETTER FUNCTIONS */
void Weapon::setType(std::string type)
{
    if(!(type.empty()))
        this->type = type;
}

/* GETTER FUNCTIONS */
const std::string& Weapon::getType()
{
    return(this->type);
}

/* DESTRUCTORS */
Weapon::~Weapon()
{

}
