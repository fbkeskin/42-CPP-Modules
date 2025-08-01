/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:21:47 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/04 10:38:41 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <fstream>

class	Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			signGrade;
		const int			executeGrade;
		bool				isSigned;
		std::string			target;

	public:
		// CONSTRUCTORS
		AForm();
		AForm(const std::string objName, const int objSignGrade, const int objExecuteGrade);
		// COPY CONSTRUCTOR
		AForm(const AForm &source);
		// COPY ASSIGNMENT OPERATOR OVERLOADING
		AForm &operator=(const AForm &source);
		// GETTER/SETTER FUNCTIONS
		std::string getName() const;
		int			getRequireSignGrade() const;
		int			getRequireExecuteGrade() const;
		bool		getIsSigned() const;
		std::string	getTarget() const;
		void		setTarget(std::string target);
		void		setIsSigned(bool isSigned);
		// OTHER MEMBER FUNCTIONS
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
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
		class FormIsNotSignedException: public std::exception
		{
			const char *what() const throw();
		};
		class FormIsAlreadySignedException: public std::exception
		{
			const char *what() const throw();
		};
		// DESTRUCTOR
		virtual ~AForm();
};

std::ostream &operator<<(std::ostream &os, const AForm &object);

#endif
