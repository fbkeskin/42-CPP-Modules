/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:21:54 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 14:39:32 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat bureaucrat("Betul", 138);
	Intern intern;
	AForm* form = NULL;
	try
	{
		form = intern.makeForm("shrubbery creation", "Teras");
		std::cout << std::endl;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(form)
		delete form;
	return (0);
}
