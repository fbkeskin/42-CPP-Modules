/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:13:53 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/14 14:20:42 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		/* CONSTRUCTORS */
		RobotomyRequestForm();
		RobotomyRequestForm(std::string	target);
		/* COPY CONSTRUCTOR */
		RobotomyRequestForm(const RobotomyRequestForm& source);
		/* COPY ASSIGNMENT OPERATOR OVERLOADING */
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& source);
		/* OTHER MEMBER FUNCTIONS */
		void	execute(Bureaucrat const & executor) const;
		/* DESTRUCTOR */
		~RobotomyRequestForm();
};

#endif
