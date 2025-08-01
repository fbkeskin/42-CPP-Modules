/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:58:42 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 15:11:40 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string name);
        void        setName(std::string name);
        std::string getName(void);
        void announce(void);
        ~Zombie();
};

void randomChump(const std::string& name);
Zombie* newZombie(std::string name);

#endif
