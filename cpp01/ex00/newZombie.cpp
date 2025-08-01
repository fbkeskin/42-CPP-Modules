/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:14:47 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/15 13:12:35 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * It creates a zombie, name it, and return it 
 * so you can use it outside of the function scope.
 */
Zombie* newZombie(std::string name)
{
    Zombie* heapZombie = new Zombie(name);
    return(heapZombie);
}
