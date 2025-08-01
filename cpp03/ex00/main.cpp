/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:37:14 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 13:43:16 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printScore(ClapTrap& player)
{
    std::cout << "==================SCORE TABLE==================" << std::endl;
    std::cout << "Hit Points: " << player.getHitPoint() << std::endl;
    std::cout << "Energy Points: " << player.getEnergyPoint() << std::endl;
    std::cout << "Attack Damage: " << player.getAttackDamage() << std::endl;
}

int main(void)
{
    ClapTrap player("Kabil");
    
    std::cout << "\n" << std::endl;
    player.attack("Habil");
    printScore(player);
    
    std::cout << "\n" << std::endl;
    player.takeDamage(5);
    printScore(player);
    
    std::cout << "\n" << std::endl;
    player.beRepaired(3);
    printScore(player);

    std::cout << "\n" << std::endl;
    player.takeDamage(20);
    printScore(player);

    std::cout << "\n" << std::endl;
    player.attack("Habil");
    printScore(player);
    std::cout << "\n" << std::endl;
    
    return (0);
}
