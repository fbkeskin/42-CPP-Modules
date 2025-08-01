/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:55:09 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 18:14:05 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie;

    randomChump("darwin");
    heapZombie = newZombie("gumball");
    heapZombie->announce();
    delete heapZombie;
    return (0);
}
