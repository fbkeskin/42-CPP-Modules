/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:57:35 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 14:45:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        /* COPY CONSTRUCTOR */
        ScavTrap(const ScavTrap& copy);
        /* COPY ASSIGNMENT OPERATOR OVERLOADING */
        ScavTrap& operator=(const ScavTrap& sourceClass);

        /* OTHER FUNCTIONS */
        void    attack(const std::string& target);
        void    guardGate();
        /* DESTRUCTOR */
        ~ScavTrap();
};

#endif
