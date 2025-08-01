/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:30:26 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/14 14:38:31 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
	std::cout << "intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& source)
{
	std::cout << "bureaucrat copy constructor called" << std::endl;
	*this = source;
}

Intern& Intern::operator=(const Intern& source)
{
	if (this == &source)
		return (*this);
	std::cout << "intern copy assignment operator called" << std::endl;
	return (*this);
}

AForm*	Intern::makeForm(const std::string name, std::string target)
{
	int	index = 0;
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (name == formTypes[i])
		{
			index = i + 1;
		}
	}
	AForm* form = NULL;
	switch (index)
	{
		case 1:
			std::cout << "Intern creates " << name << " form" << std::endl;
			form = new ShrubberyCreationForm(target);
			break;
		case 2:
			std::cout << "Intern creates " << name << " form" << std::endl;
			form = new RobotomyRequestForm(target);
			break;
		case 3:
			std::cout << "Intern creates " << name << " form" << std::endl;
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Intern can not creat " << name << " form" << std::endl;
	}
	return(form);
}

Intern::~Intern()
{
	std::cout << "intern destructor called" << std::endl;
}