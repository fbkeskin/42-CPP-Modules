/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:28:58 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 15:11:10 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("anonymous")
{
	this->grade = 150;
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string objectName, int grade) : name(objectName)
{
	std::cout << "parameterized constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.getName())
{
	std::cout << "copy assignment operator called" << std::endl;
	*this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
	if (this == &source)
		return (*this);
	this->grade = source.getGrade();
	std::cout << "copy constructor called" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increaseGrade()
{
	if ((this->grade - 1) < 1)
		throw GradeTooHighException();
	this->grade = this->grade - 1;
}

void Bureaucrat::decreaseGrade()
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	this->grade = this->grade + 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: The highest possible grade is 1.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: The lowest possible grade is 150.");
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &object)
{
	os << object.getName() << ", bureaucrat grade: " << object.getGrade() << std::endl;
	return (os);
}
