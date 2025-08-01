/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:15:46 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/21 15:36:13 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    /*
    std::cout << "[1] creating Dog class..." << std::endl;
    Animal* a1 = new Dog();
    a1->makeSound();
    std::cout << std::endl;

    std::cout << "[2] creating Cat class..." << std::endl;
    Animal* a2 = new Cat();
    a2->makeSound();
    std::cout << std::endl;

    std::cout << "[3] destroying Dog class..." << std::endl;
    delete a1;
    std::cout << std::endl;
    std::cout << "[4] destroying Cat class..." << std::endl;
    delete a2;
    */

    // with virtual
    std::cout << "[1] with virtual pointer" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    // without virtual
    std::cout << "[2] without virtual pointer" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wj = new WrongDog();
    const WrongAnimal* wi = new WrongCat();
    std::cout << wj->getType() << " " << std::endl;
    std::cout << wi->getType() << " " << std::endl;
    wi->makeSound(); //will output the cat sound!
    wj->makeSound();
    wmeta->makeSound();

    // heap cleanup

    std::cout << std::endl << "[3] delete and destruct" << std::endl;
    delete meta;
    delete i;
    delete j;
    delete wmeta;
    delete wi;
    delete wj;

    return (0);
}
