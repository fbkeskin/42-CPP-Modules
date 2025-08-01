/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:01:59 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/24 14:09:03 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& source)
{
	(void)source;
}

Serializer &Serializer::operator=(const Serializer& source)
{
	(void)source;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t address;

	address = reinterpret_cast<uintptr_t>(ptr);
	return (address);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* dataAddress;

	dataAddress = reinterpret_cast<Data*>(raw);
	return(dataAddress);
}

Serializer::~Serializer()
{
	std::cout << "destructor called" << std::endl;
}