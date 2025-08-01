/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:25:22 by fatkeski          #+#    #+#             */
/*   Updated: 2025/04/07 20:38:42 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	size_t size;

	std::string stringARR[3] = {"FATMA", "BETUL",  "KESKIN"};
	const char* charARR = "BEATRICE";
	int intARR[3] = {34, -77, 25};
	float floatARR[3] = {3.4f, -7.7f, 2.5f};
	double doubleARR[3] = {34.34, -77.77, 25.25};

	size = sizeof(stringARR) / sizeof(stringARR[0]);
	::iter(stringARR, size, printArray<std::string>);
	std::cout << std::endl;

	size = std::strlen(charARR);
	::iter(charARR, size, printArray<char>);
	std::cout << std::endl;

	size = sizeof(intARR) / sizeof(intARR[0]);
	::iter(intARR, size, printArray<int>);
	std::cout << std::endl;

	size = sizeof(floatARR) / sizeof(floatARR[0]);
	::iter(floatARR, size, printArray<float>);
	std::cout << std::endl;

	size = sizeof(doubleARR) / sizeof(doubleARR[0]);
	::iter(doubleARR, size, printArray<double>);
	std::cout << std::endl;

	return (0);
}
