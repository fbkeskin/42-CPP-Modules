/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:27 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/22 15:03:56 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utilities.hpp"

bool	isAllDigits(const std::string str)
{
	size_t index = 0;
	if(str[0] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (!(std::isdigit(str[i])))
			return (false);
	}
	return (true);
}

bool	hasPointAndSuffix(const std::string str)
{
	int	pointCount;
	int	suffixCount;
	size_t i;
	size_t index = 0;

	pointCount = 0;
	suffixCount = 0;
	if(str[0] == '-')
		index++;
	for (i = index; i < str.length(); i++)
	{
		if (str[i] == '.')
			pointCount++;
		else if (str[i] == 'f')
		{
			i++;
			suffixCount++;
			break;
		}
		else if (!(std::isdigit(str[i])))
			return (false);
	}
	if (str[i])
		return(false);
	if ((pointCount == 1) && (suffixCount == 1))
		return (true);
	return (false);
}

bool	hasPoint(const std::string str)
{
	int	pointCount = 0;
	size_t index = 0;

	if(str[0] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (str[i] == '.')
			pointCount++;
		else if (!(std::isdigit(str[i])))
			return (false);
	}
	if (pointCount == 1)
		return (true);
	return (false);
}

int getPrecision(const std::string str)
{
	size_t	i = 0;
	int precision = 0;

	while(str[i] != '.')
		i++;
	if(str[i] == '.')
		i++;
	while((i < str.length()) && (str[i] != 'f'))
	{
		precision++;
		i++;
	}
	return(precision);
}
