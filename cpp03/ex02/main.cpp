/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:39 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 18:03:37 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void printScore(FragTrap& player)
{
    std::cout << "==================SCORE TABLE==================" << std::endl;
    std::cout << "Hit Points: " << player.getHitPoint() << std::endl;
    std::cout << "Energy Points: " << player.getEnergyPoint() << std::endl;
    std::cout << "Attack Damage: " << player.getAttackDamage() << std::endl;
}

int main(void)
{
    FragTrap player("Kabil");
    
    std::cout << "\n" << std::endl;
    player.attack("Habil");
    printScore(player);
    
    std::cout << "\n" << std::endl;
    player.takeDamage(5);
    printScore(player);
    
    std::cout << "\n" << std::endl;
    player.beRepaired(3);
    printScore(player);
    player.highFivesGuys();

    std::cout << "\n" << std::endl;
    player.takeDamage(100);
    printScore(player);

    std::cout << "\n" << std::endl;
    player.attack("Habil");
    printScore(player);
    player.highFivesGuys();

    std::cout << "\n" << std::endl;
    return (0);
}
