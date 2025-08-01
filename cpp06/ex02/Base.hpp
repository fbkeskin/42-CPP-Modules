/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:42:14 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/22 19:05:53 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base(){
			std::cout << "Base destructor called" << std::endl;
		}
};

#endif