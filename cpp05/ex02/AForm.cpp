/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:30:02 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/04 10:43:29 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), signGrade(150), executeGrade(150)
{
	this->isSigned = false;
	this->target = "default AForm";
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string objName, const int objSignGrade, const int objExecuteGrade) : name(objName), signGrade(objSignGrade), executeGrade(objExecuteGrade)
{
	std::cout << "AForm parameterized constructor called" << std::endl;
	this->target = "default Target";
	this->isSigned = false;
	if ((signGrade > 150) || (executeGrade > 150))
		throw Bureaucrat::GradeTooLowException();
	else if ((signGrade < 1) || (executeGrade < 1))
		throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(const AForm &source) : name(source.getName()), signGrade(source.getRequireSignGrade()), executeGrade(source.getRequireExecuteGrade())
{
	std::cout << "Aform copy assignment operator called" << std::endl;
	*this = source;
}

AForm &AForm::operator=(const AForm &source)
{
	if (this == &source)
		return (*this);
	this->isSigned = source.getIsSigned();
	std::cout << "Aform copy constructor called" << std::endl;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getRequireSignGrade() const
{
	return (this->signGrade);
}

int AForm::getRequireExecuteGrade() const
{
	return (this->executeGrade);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

std::string	AForm::getTarget() const
{
	return(this->target);
}

void AForm::setTarget(std::string target)
{
	this->target = target;
}

void AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Exception: current grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Exception: current grade is too low");
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
	return ("Exception: form is not signed");
}

const char* AForm::FormIsAlreadySignedException::what() const throw()
{
	return ("Exception: form is already signed");
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(this->getIsSigned())
		throw FormIsAlreadySignedException();
	else if ((bureaucrat.getGrade()) <= (this->getRequireSignGrade()))
	{
		std::cout << "bureaucrat " << bureaucrat.getName() << " signed " << this->getName() << "." << std::endl;
		this->setIsSigned(true);
	}
	else
	{
		std::cout << "bureaucrat " << bureaucrat.getName() << " could not sign " << this->getName() << ".";
		throw GradeTooLowException();
	}
}

AForm::~AForm()
{
	std::cout << "Aform destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &object)
{
	os << object.getName() << ", require sign grade: " << object.getRequireSignGrade();
	os << ", require execute grade: " << object.getRequireExecuteGrade();
	os << ", sign status: " << object.getIsSigned() << std::endl;
	return (os);
}
