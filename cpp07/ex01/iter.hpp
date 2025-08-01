/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:40:35 by fatkeski          #+#    #+#             */
/*   Updated: 2025/04/07 20:31:52 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstring>


template<typename T> 
void printArray(T element)
{
	std::cout << element;
}

template<typename iterType, typename T2> 
void iter(iterType* array, size_t length, void (*iterFunc)(T2))
{
	for(size_t i = 0; i <length; i++)
	{
		iterFunc(array[i]);
		if(i != length - 1)
			std::cout << ", ";
	}
}

#endif
