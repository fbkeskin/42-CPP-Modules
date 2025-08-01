/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:41:25 by fatkeski          #+#    #+#             */
/*   Updated: 2025/04/07 20:42:34 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 20

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	/*
	for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << ", ";
        std::cout << mirror[i] << std::endl;
    }
	*/
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": index out of range!" << '\n';
    }
	
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": index out of range!" << '\n';
    }
	
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	/*
	for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << ", ";
        std::cout << mirror[i] << std::endl;
    }
	*/
    delete [] mirror;
    return 0;
}