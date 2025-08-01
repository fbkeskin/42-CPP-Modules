/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:21:47 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/07 13:32:57 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <iostream>
# include <string>

class	Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		/* CONSTRUCTORS */
		Bureaucrat();
		Bureaucrat(const std::string sourceName, int grade);
		/* COPY CONSTRUCTOR */
		Bureaucrat(const Bureaucrat &source);
		/* COPY ASSIGNMENT OPERATOR OVERLOADING */
		Bureaucrat &operator=(const Bureaucrat &source);
		/* GETTER/SETTER FUNCTIONS */
		const std::string getName() const;
		int getGrade() const;
		/* OTHER MEMBER FUNCTIONS */
		void increaseGrade();
		void decreaseGrade();
		void signForm(Form &form);
		/* DERIVED EXCEPTION CLASSES */
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
		/* DESTRUCTOR */
		~Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &object);

#endif
