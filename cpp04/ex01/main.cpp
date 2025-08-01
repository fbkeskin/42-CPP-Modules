/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:15:46 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 16:28:07 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#define SIZE 4

int main()
{
    std::cout << "********POLYMORPHISM********" << std::endl;
    Animal* animals[SIZE];
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
    
    /*
    std::cout << "**********MY TESTS**********" << std::endl;
    Dog a;
    a.printDogIdeas();
    std::cout << std::endl;
    a.setDogIdea(10, "i am a little dog");
    a.setDogIdea(11, "HAV HHHAV");
    a.printDogIdeas();
    std::cout << a.getDogIdea(11) << std::endl;
    */
    return (0);
}
