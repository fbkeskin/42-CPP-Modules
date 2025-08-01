/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:31 by fatkeski          #+#    #+#             */
/*   Updated: 2025/04/07 17:43:55 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#define TRUE 1
#define FALSE 0

template<typename swapType> void swap(swapType& param1, swapType& param2)
{
	swapType tmp = param1;
	param1 = param2;
	param2 = tmp;
}

template<typename minType> minType min(const minType& param1, const minType& param2)
{
	if(param1 < param2)
		return(param1);
	return(param2);
}

template<typename maxType> maxType max(const maxType& param1, const maxType& param2)
{
	if(param1 > param2)
		return(param1);
	return(param2);
}

#endif
