/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:07:38 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/07 13:32:43 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const	std::string name;
		int		grade;
	public:
		/* CONSTRUCTORS */
		Bureaucrat();
		Bureaucrat(const std::string objectName, int grade);
		/* COPY CONSTRUCTOR */
		Bureaucrat(const Bureaucrat &source);
		/* COPY ASSIGNMENT OPERATOR OVERLOADING */
		Bureaucrat &operator=(const Bureaucrat &source);
		/* GETTER/SETTER FUNCTIONS */
		std::string	getName() const;
		int			getGrade() const;
		/* OTHER MEMBER FUNCTIONS */
		void		increaseGrade();
		void		decreaseGrade();
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
