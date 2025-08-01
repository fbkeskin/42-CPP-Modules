/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:23:09 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/22 14:29:48 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if(argc != 2)
		return(std::cout << "Error: You must enter an argument in the reverse polish notation!" << std::endl, 1);

	RPN	expression(argv[1]);
	try
	{
		std::cout << "Result: " << expression.solvePostfixNotation() << std::endl;
	}
	catch(const char* message)
	{
		std::cerr << message << std::endl;
		return(1);
	}
	return(0);
}
