/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:05:45 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/07 11:41:03 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		/* CONSTRUCTORS */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string	target);
		/* COPY CONSTRUCTOR */
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		/* COPY ASSIGNMENT OPERATOR OVERLOADING */
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &source);
		/* OTHER MEMBER FUNCTIONS */
		void	execute(const Bureaucrat& executor) const;
		/* DESTRUCTOR */
		~ShrubberyCreationForm();
};

#endif
