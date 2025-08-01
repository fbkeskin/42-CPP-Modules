/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:38:10 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:39:54 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string name);
        void        setName(std::string name);
        std::string getName(void);
        void        announce(int index);
        ~Zombie();
};

Zombie*     zombieHorde(int N, std::string name);

#endif
