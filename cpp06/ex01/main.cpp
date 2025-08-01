/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:03:32 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/24 14:32:50 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	{
		Data data(25, 25.25);

		uintptr_t serialAddress = Serializer::serialize(&data);
		Data* deserialAddress = Serializer::deserialize(serialAddress);

		std::cout << "Decimal Notation:" << std::endl;
		std::cout << "Serialization Address:   " << serialAddress << std::endl;
		std::cout << "Deserialization Address: " << reinterpret_cast<uintptr_t>(deserialAddress) << std::endl;
		std::cout << std::endl;
		std::cout << "Hexadecimal Notation:" << std::endl;
		std::cout << std::hex << "Serialization Address:   0x" << serialAddress << std::endl;
		std::cout << "Deserialization Address: " << deserialAddress << std::endl;
	}
	/*
	{
		Data data;

		uintptr_t serialAddress = Serializer::serialize(&data);
		Data* deserialAddress = Serializer::deserialize(serialAddress);

		std::cout << "Decimal Notation:" << std::endl;
		std::cout << "Serialization Address:   " << serialAddress << std::endl;
		std::cout << "Deserialization Address: " << reinterpret_cast<uintptr_t>(deserialAddress) << std::endl;
		std::cout << std::endl;
		std::cout << "Hexadecimal Notation:" << std::endl;
		std::cout << std::hex << "Serialization Address:   0x" << serialAddress << std::endl;
		std::cout << "Deserialization Address: " << deserialAddress << std::endl;
	}
	*/
	return (0);
}
