/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:30:02 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 15:10:58 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), signGrade(150), executeGrade(150)
{
	this->isSigned = false;
	std::cout << "form default constructor called" << std::endl;
}

Form::Form(const std::string objName, const int objSignGrade, const int objExecuteGrade) : name(objName), signGrade(objSignGrade), executeGrade(objExecuteGrade)
{
	this->isSigned = false;
	std::cout << "form parameterized constructor called" << std::endl;
	if ((signGrade > 150) || (executeGrade > 150))
		throw Bureaucrat::GradeTooLowException();
	else if ((signGrade < 1) || (executeGrade < 1))
		throw Bureaucrat::GradeTooHighException();
}

Form::Form(const Form &source) : name(source.getName()), signGrade(source.getRequireSignGrade()), executeGrade(source.getRequireExecuteGrade())
{
	std::cout << "form copy assignment operator called" << std::endl;
	*this = source;
}

Form &Form::operator=(const Form &source)
{
	if (this == &source)
		return (*this);
	this->isSigned = source.getIsSigned();
	std::cout << "form copy constructor called" << std::endl;
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getRequireSignGrade() const
{
	return (this->signGrade);
}

int Form::getRequireExecuteGrade() const
{
	return (this->executeGrade);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

void Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if(this->getIsSigned())
		throw FormIsAlreadySignedException();
	else if ((bureaucrat.getGrade()) <= (this->getRequireSignGrade()))
	{
		std::cout << "bureaucrat " << bureaucrat.getName() << " signed form. ";
		this->setIsSigned(true);
	}
	else
	{
		std::cout << "bureaucrat " << bureaucrat.getName() << " could not sign form! ";
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Exception: current sign grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Exception: current sign grade is too low");
}

const char* Form::FormIsAlreadySignedException::what() const throw()
{
	return ("Exception: form is already signed");
}

Form::~Form()
{
	std::cout << "form destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &object)
{
	os << object.getName() << ", require sign grade: " << object.getRequireSignGrade();
	os << ", require execute grade: " << object.getRequireExecuteGrade();
	os << ", sign status: " << object.getIsSigned() << std::endl;
	return (os);
}
