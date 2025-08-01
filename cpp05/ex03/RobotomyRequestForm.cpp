/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:16:34 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/14 14:27:54 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "Robotomy Request Form default constructor called" << std::endl;
	this->setTarget("default Robotomy Request Form Target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	std::cout << "Robotomy Request Form parameterized constructor called" << std::endl;
	if(!(target.empty()))
		this->setTarget(target);
	this->setIsSigned(this->getIsSigned());
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source)
{
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
	*this = source;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	std::cout << "Robotomy Request Form copy assignment operator called" << std::endl;
	if(this == &source)
		return (*this);
	this->setIsSigned(source.getIsSigned());
	this->setTarget(source.getTarget());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	num = rand() % 2;

	if(this->getIsSigned())
	{
		if(executor.getGrade() <= 45)
		{
			if(num == 1)
			{
				std::cout << "RrRrrrrrRRrrrR ";
				std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
				std::cout << "bureaucrat " << executor.getName() << " executed " << this->getName() << " for " << this->getTarget() << std::endl;
			}
			else
				std::cout << this->getTarget() << " has been not robotomized!" << std::endl;
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

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}
