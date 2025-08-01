/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 05:20:09 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/24 12:35:46 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	if(argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cerr << "argument count must be 2!" << std::endl;
		return(1);
	}
	return (0);
}
