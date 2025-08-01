/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:41:24 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/22 15:43:55 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cerrno>
#include <limits>
#include <limits.h>
#include <cfloat>
#include <cmath>

enum	ScalarTypes
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_LITERAL,
	INVALID
};

bool	isAllDigits(const std::string str);
bool	hasPointAndSuffix(const std::string str);
bool	hasPoint(const std::string str);
int		getPrecision(const std::string str);
