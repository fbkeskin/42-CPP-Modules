/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:21:54 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 13:32:51 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat bureaucrat("Betul", -10);
			Form form("Ic Yonerge", 70, 50);
			std::cout << std::endl;
			std::cout << bureaucrat;
			std::cout << form;
			std::cout << std::endl;
			bureaucrat.signForm(form);
			std::cout << form;
			std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "=====================================================================================================" << std::endl;
	{
		Bureaucrat bureaucrat1("Betul", 90);
		Bureaucrat bureaucrat2("Zuleyha", 70);
		Form form("Ic Yonerge", 70, 50);
		try
		{
			std::cout << std::endl;

			std::cout << bureaucrat1;
			std::cout << bureaucrat2;
			std::cout << form;
			std::cout << std::endl;

			bureaucrat1.signForm(form);
			bureaucrat2.signForm(form);
			std::cout << form;
			std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "=====================================================================================================" << std::endl;
	{
		try
		{
			Bureaucrat bureaucrat("Betul", 50);
			Form form1("Ic Yonerge", 70, 50);
			Form form2("Adil Yonetim", 5, 10);
			std::cout << std::endl;

			std::cout << bureaucrat;
			std::cout << form1;
			std::cout << form2;
			std::cout << std::endl;

			bureaucrat.signForm(form1);
			std::cout << std::endl;
			bureaucrat.signForm(form2);
			std::cout << form1;
			std::cout << form2;
			std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
