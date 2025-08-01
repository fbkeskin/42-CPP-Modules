/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:29:41 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/06 01:22:24 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		/* CONSTRUCTORS */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string	target);
		/* COPY CONSTRUCTOR */
		PresidentialPardonForm(const PresidentialPardonForm& source);
		/* COPY ASSIGNMENT OPERATOR OVERLOADING */
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& source);
		/* OTHER MEMBER FUNCTIONS */
		void	execute(const Bureaucrat& executor) const;
		/* DESTRUCTOR */
		~PresidentialPardonForm();
};

#endif
