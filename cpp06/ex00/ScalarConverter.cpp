/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 05:49:22 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/24 13:07:25 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& source)
{
	(void)source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& source)
{
	(void)source;
	return (*this);
}

ScalarTypes detectLiteralType(const std::string str)
{
	if(isAllDigits(str))
		return(INT);
	else if(str.length() == 1)
		return(CHAR);
	else if(hasPointAndSuffix(str))
	return(FLOAT);
	else if(hasPoint(str))
		return(DOUBLE);
	else if((str == "+inff") || (str == "-inff") || (str == "nanf") || (str == "+inf") || (str == "-inf") || (str == "nan"))
		return(PSEUDO_LITERAL);
	return(INVALID);
}

void ScalarConverter::convert(const std::string str)
{
	char	ch = 'b';
	long	num = 25;
	float	f = 25.25f;
	double	d = 25.25;
	char*	endptr = NULL;
	int		p;

	ScalarTypes type = detectLiteralType(str);
	switch(type)
	{
		case CHAR:
			ch = str[0];
			if(std::isprint(ch))
				std::cout << "char: " << "'" << ch << "'" <<  std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(ch) << std::endl;
			p = 1;
			std::cout << std::fixed << std::setprecision(p);
			std::cout << "float: " << static_cast<float>(ch) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(ch) << std::endl;
			break;

		case INT:
			num = strtol(str.c_str(), &endptr, 10);
			if(num >= -128 && num <= 127)
			{
				if(std::isprint(static_cast<int>(num)))
					std::cout << "char: " << static_cast<char>(static_cast<int>(num)) << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;
			if((num >= INT_MIN) && (num <= INT_MAX))
			{
				int i = static_cast<int>(num);
				std::cout << "int: " << i << std::endl;
				p = 1;
				std::cout << std::fixed << std::setprecision(p);
				std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(i) << std::endl;
			}
			else
			{
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			break;

		case FLOAT:
			errno = 0;
			f = strtof(str.c_str(), &endptr);
			d = strtod(str.c_str(), &endptr);
			p = getPrecision(str);
			if(f < -128.0f || f > 127.0f)
				std::cout << "char: impossible" << std::endl;
			else
			{
				if(std::isprint(static_cast<int>(f)))
					std::cout << "char: " << static_cast<char>(static_cast<int>(f)) << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			if((errno == ERANGE) || (d > static_cast<double>(INT_MAX)) || (d < static_cast<double>(INT_MIN)))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			if(errno == ERANGE)
			{
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			else
			{
				if(p > 10)
					p = 10;
				std::cout << std::fixed << std::setprecision(p);
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			break;

		case DOUBLE:
			errno = 0;
			d = strtod(str.c_str(), &endptr);
			p = getPrecision(str);
			if(d < -128.0 || d > 127.0)
				std::cout << "char: impossible" << std::endl;
			else
			{
				if(std::isprint(static_cast<int>(d)))
					std::cout << "char: " << static_cast<char>(static_cast<int>(d)) << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			if((errno == ERANGE) || (d > static_cast<double>(INT_MAX)) || (d < static_cast<double>(INT_MIN)))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			if(errno == ERANGE)
			{
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			else
			{
				if(p > 10)
					p = 10;
				std::cout << std::fixed << std::setprecision(p);
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: " << d << std::endl;
			}
			break;

		case PSEUDO_LITERAL:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (str == "-inff" || str == "+inff" || str == "nanf")
			{
				std::cout << "float: " << str << std::endl;
				std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
			}
			else
			{
				std::cout << "float: " << str + "f" << std::endl;
				std::cout << "double: " << str << std::endl;
			}
			break;
		default:
			std::cerr << "entered invalid argument, not a scalar type!" << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "destructor called" << std::endl;
}
