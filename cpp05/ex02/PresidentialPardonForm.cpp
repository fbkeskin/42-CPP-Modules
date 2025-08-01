/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:16:34 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/14 14:27:28 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	std::cout << "Presidential Pardon Form default constructor called" << std::endl;
	this->setTarget("default Presidential Pardon Form Target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
	std::cout << "Presidential Pardon Form parameterized constructor called" << std::endl;
	if(!(target.empty()))
		this->setTarget(target);
	this->setIsSigned(this->getIsSigned());
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source)
{
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
	*this = source;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
	std::cout << "Presidential Pardon Form copy assignment operator called" << std::endl;
	if(this == &source)
		return (*this);
	this->setIsSigned(source.getIsSigned());
	this->setTarget(source.getTarget());
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(this->getIsSigned())
	{
		if((executor.getGrade() <= 5))
		{
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
			std::cout << "bureaucrat " << executor.getName() << " executed " << this->getName() << " for " << this->getTarget() << std::endl;
		}
		else
		{
			std::cout << "bureaucrat " << executor.getName() << " could not execute " << this->getName() << " for " << this->getTarget() << " ";
			throw AForm::GradeTooLowException();
		}
	}
	else
	{
		std::cout << "bureaucrat " << executor.getName() << " could not execute " << this->getName() << " for " << this->getTarget() << " ";
		throw AForm::FormIsNotSignedException();
	}
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}
