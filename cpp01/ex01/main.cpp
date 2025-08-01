/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:55:09 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:40:40 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define N 7

int main()
{
    Zombie* zombies;
    
    zombies = zombieHorde(N, "BETUL'S ZOMBIES");
    for(int i = 0; i < N; i++)
        zombies[i].announce(i + 1);
    std::cout << std::endl;
    delete[] zombies;
    return (0);
}
