/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:32 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 17:58:31 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        /* COPY CONSTRUCTOR */
        FragTrap(const FragTrap& copy);
        /* COPY ASSIGNMENT OPERATOR OVERLOADING */
        FragTrap& operator=(const FragTrap& sourceClass);

        /* OTHER FUNCTIONS */
        void    highFivesGuys(void);
        /* DESTRUCTOR */
        ~FragTrap();
};

#endif
