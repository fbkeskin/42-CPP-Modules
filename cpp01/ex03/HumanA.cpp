/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:01:49 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:25:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// initializer list'te tanımlaman lazım
// Eğer initializer list kullanmazsanız, referans üyeler default (varsayılan) olarak başlatılmaya çalışılır, ancak referansların varsayılan bir başlatıcısı yoktur.
HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
    this->name = name;
}

std::string HumanA::getName()
{
    return (this->name);
}

void HumanA::setName(std::string name)
{
    this->name = name;
}

void    HumanA::attack()
{
     std::cout << name << " use " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    // empty
}