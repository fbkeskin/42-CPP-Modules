/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:15:46 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 17:36:00 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#define SIZE 4

int main()
{
    std::cout << "********POLYMORPHISM********" << std::endl;
    AAnimal* animals[SIZE];
    int i;
    std::cout << "[1] creating Cat classes..." << std::endl;
    for(i = 0; i < SIZE/2; i++)
    {
        animals[i] = new Cat();
    }
    std::cout << "[2] creating Dog classes..." << std::endl;
    for(i = SIZE/2; i < SIZE; i++)
    {
        animals[i] = new Dog();
    }
    std::cout << "[3] calling sound funcs..." << std::endl;
    for (i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    std::cout << "[4] destroying classes..." << std::endl;
    for(i = 0; i < SIZE; i++)
    {
        delete animals[i];
    }
    
    // AAnimal animal;
    // AAnimal* a = new AAnimal();
    // AAnimal* a = new Dog();
    // a->makeSound();
    // std::cout << std::endl;
    
    return (0);
}
