/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:51:10 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/24 14:32:22 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>

typedef unsigned long uintptr_t;

class Data
{
	private:
		int iData;
		float fData;
	public:
		char cData;
		Data(int iData, float fData)
		{
			this->iData = iData;
			this->fData = fData;
			this->cData = 'B';
		}
};

/*
// struct örneği
typedef struct s_data
{
	int		i_data;
	float	f_data;
	bool	b_data;
	char	c_data;
	char*	p_data;

	s_data(){
		i_data = 25;
		f_data = 25.25f;
		b_data = true;
		c_data = 'B';
		p_data = &c_data;
	}
}Data;
*/

// utility class, not be instantiable
class Serializer
{
	private:
		Serializer();
		~Serializer();
	public:
		Serializer(const Serializer &source);
		Serializer			&operator=(const Serializer &source);
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
