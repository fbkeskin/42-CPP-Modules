/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:28:39 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/17 17:17:38 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void printScore(ScavTrap& player)
{
    std::cout << "==================SCORE TABLE==================" << std::endl;
    std::cout << "Hit Points: " << player.getHitPoint() << std::endl;
    std::cout << "Energy Points: " << player.getEnergyPoint() << std::endl;
    std::cout << "Attack Damage: " << player.getAttackDamage() << std::endl;
}

int main(void)
{
    ScavTrap player("Kabil");
    
    std::cout << "\n" << std::endl;
    player.attack("Habil");
    printScore(player);
    
    std::cout << "\n" << std::endl;
    player.takeDamage(5);
    printScore(player);

    std::cout << "\n" << std::endl;
    player.beRepaired(3);
    printScore(player);
    player.guardGate();
    
    std::cout << "\n" << std::endl;
    player.takeDamage(99);
    printScore(player);
    
    std::cout << "\n" << std::endl;
    player.attack("Habil");
    printScore(player);
    player.guardGate();
    std::cout << "\n" << std::endl; 

    /*
    ClapTrap c("clap");
    ScavTrap s("scav");
    
    c.attack("x");
    s.attack("x");

    ClapTrap* arr[2];
    arr[0] = &c;
    // Virtual fonksiyon çağrısı, pointer'ın türüne değil, nesnenin gerçek türüne göre yapılır
    arr[1] = &s;
    std::cout << std::endl;
    arr[0]->attack("X");
    arr[1]->attack("X");
    */
    
    return (0);
}
