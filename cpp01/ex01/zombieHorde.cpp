/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:45:33 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/11 21:56:36 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*     zombieHorde(int N, std::string name)
{    
    if(N > 0)
    {
        int i;
        Zombie* zombies;
    
        zombies = new Zombie[N];
        for(i = 0; i < N; i++)
            zombies[i].setName(name);
        return(zombies);   
    }
    std::cout << "Invalid zombie count!" << std::endl;
    return(NULL);
}