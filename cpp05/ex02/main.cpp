/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:21:54 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 15:00:27 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	AForm* forms[3];

	forms[0] = NULL;
	forms[1] = NULL;
	forms[2] = NULL;
	try
	{
		Bureaucrat bureaucrat("Betul", 138);

		forms[0] = new ShrubberyCreationForm("Teras");
		bureaucrat.signForm(*(forms[0]));
		bureaucrat.executeForm(*(forms[0]));
		std::cout << std::endl;

		forms[1] = new RobotomyRequestForm("Pedagoji");
		bureaucrat.signForm(*(forms[1]));
		bureaucrat.executeForm(*(forms[1]));
		std::cout << std::endl;

		forms[2] = new PresidentialPardonForm("Yonetim");
		bureaucrat.signForm(*(forms[2]));
		bureaucrat.executeForm(*(forms[2]));
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(forms[0])
		delete forms[0];
	if(forms[1])
		delete forms[1];
	if(forms[2])
		delete forms[2];

	return (0);
}
