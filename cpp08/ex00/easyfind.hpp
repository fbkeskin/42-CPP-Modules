/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:45:52 by fatkeski          #+#    #+#             */
/*   Updated: 2025/05/16 18:29:09 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>   
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

/**
 * Searches for num and returns the first place it finds.
 * If the number is not found, it throws an exeception.
 */
template<typename T>
typename T::iterator easyfind(T& integerContainer, int num)
{
	typename T::iterator start = integerContainer.begin();
	typename T::iterator end = integerContainer.end();
	typename T::iterator ret = std::find(start, end, num);
	if(ret == end)
		throw("no value found in container!");
	return(ret);
}

template<typename I>
void printContainer(I start, I end)
{
	while (start != end)
	{
		std::cout << *start << " ";
		start++;
	}
	std::cout << std::endl;
}

#endif
