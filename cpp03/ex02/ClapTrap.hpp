/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:28 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 17:28:10 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string     name;
        int             hitPoint;
        int             energyPoint;
        int             attackDamage;
    public:
        /* CONSTRUCTORS */
        ClapTrap();
        ClapTrap(std::string name);
        
        /* COPY CONSTRUCTOR */
        ClapTrap(const ClapTrap& copy);
        
        /* COPY ASSIGNMENT OPERATOR OVERLOADING */
        ClapTrap& operator=(const ClapTrap& sourceClass);
        
        /* GETTER-SETTER MEMBER FUNCTIONS */
        std::string     getName()const;
        void            setName(std::string& name);
        int             getHitPoint()const;
        int             getEnergyPoint()const;
        int             getAttackDamage()const;
        
        /* OTHER MEMBER FUNCTIONS */
        void    virtual attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        
        /* DESTRUCTOR */
        virtual ~ClapTrap();

};

#endif
