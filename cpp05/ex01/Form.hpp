/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:21:47 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/14 11:35:40 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class	Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int signGrade;
		const int executeGrade;
		bool isSigned;

	public:
		// CONSTRUCTORS
		Form();
		Form(const std::string objName, const int objSignGrade, const int objExecuteGrade);
		// COPY CONSTRUCTOR
		Form(const Form &source);
		// COPY ASSIGNMENT OPERATOR OVERLOADING
		Form &operator=(const Form &source);
		// GETTER/SETTER FUNCTIONS
		std::string getName() const;
		int		getRequireSignGrade() const;
		int		getRequireExecuteGrade() const;
		bool	getIsSigned() const;
		void	setIsSigned(bool isSigned);
		// OTHER MEMBER FUNCTIONS
		void	beSigned(Bureaucrat &bureaucrat);
		// DERIVED EXCEPTION CLASSES
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormIsAlreadySignedException: public std::exception
		{
			const char *what() const throw();
		};
		// DESTRUCTOR
		~Form();
};

std::ostream &operator<<(std::ostream &os, const Form &object);

#endif
