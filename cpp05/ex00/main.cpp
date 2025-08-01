/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:22:01 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 11:24:54 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat("betul", 150);
		std::cout << bureaucrat;
		bureaucrat.decreaseGrade();
		std::cout << bureaucrat;
		bureaucrat.increaseGrade();
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
/*
		int x = 10;
		int y = 0;
		if(y == 0)
			throw std::runtime_error("Hata: Sıfıra bölme yapılamaz!");
		std::cout << x / y << std::endl;
*/
