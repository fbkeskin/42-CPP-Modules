/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:31:18 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/14 14:26:50 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
	this->setTarget("default Shrubbery Creation Form Target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 147)
{
	std::cout << "Shrubbery Creation Form parameterized constructor called" << std::endl;
	if(!(target.empty()))
		this->setTarget(target);
	this->setIsSigned(this->getIsSigned());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : AForm(source)
{
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
	*this = source;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	std::cout << "Shrubbery Creation Form copy assignment operator called" << std::endl;
	if(this == &source)
		return (*this);
	this->setIsSigned(source.getIsSigned());
	this->setTarget(source.getTarget());
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(this->getIsSigned())
	{
		if(executor.getGrade() <= 137)
		{
			std::ofstream outfile;

			outfile.open((this->getTarget() + std::string("_shrubbery")).c_str());
			if (!outfile.is_open())
				return ;
			outfile << "                    _" << std::endl;
			outfile << "                  _(_)_                          wWWWw     _" << std::endl;
			outfile << "      @@@@       (_)@(_)   vVVVv     _     @@@@  (___)   _(_)_" << std::endl;
			outfile << "     @@()@@ wWWWw  (_)\\    (___)   _(_)_  @@()@@   Y    (_)@(_)" << std::endl;
			outfile << "      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \\|/     (_)" << std::endl;
			outfile << "       /      Y       \\|    \\|/    /(_)    \\|      |/      |" << std::endl;
			outfile << "    \\ |     \\ |/       | / \\ | /  \\|/       |/    \\|      \\|/" << std::endl;
			outfile << "    \\\\|//   \\\\|///  \\\\\\|//\\\\\\|/// \\|///  \\\\\\|//  \\\\|//  \\\\\\|//" << std::endl;
			outfile << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
			outfile.close();
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}
