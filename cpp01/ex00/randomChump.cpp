/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:14:58 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/15 13:12:47 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * It creates a zombie, name it, and the zombie announces itself.
 */
void randomChump(const std::string& name)
{
    Zombie stackZombie = Zombie(name);
    stackZombie.announce();
}
