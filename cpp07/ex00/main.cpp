/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:27:14 by fatkeski          #+#    #+#             */
/*   Updated: 2025/04/07 17:36:50 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

typedef struct MyData
{
	int num;

	MyData& operator=(const MyData& source) {
		if(this == &source)
			return (*this);
		num = source.num;
		return(*this);
	}
	bool operator<(const MyData& other) const {
		return (num < other.num);
	}
	bool operator>(const MyData& other) const {
		return (num > other.num);
	}
} TData;

std::ostream&  operator<<(std::ostream& output, const TData& dataStruct)
{
    output << dataStruct.num;
    return (output);
}

int main( void )
{
	int intNum1 = 2;
	int intNum2 = 3;
	::swap(intNum1, intNum2);
	std::cout << "a = " << intNum1 << ", b = " << intNum2 << std::endl;
	std::cout << "min( a, b ) = " << ::min(intNum1, intNum2) << std::endl;
	std::cout << "max( a, b ) = " << ::max(intNum1, intNum2) << std::endl;

	// float floatNum1 = 7.7f;
	// float floatNum2 = 1.9f;
	// ::swap(floatNum1, floatNum2);
	// std::cout << "f_a = " << floatNum1 << ", f_b = " << floatNum2 << std::endl;
	// std::cout << "min( f_a, f_b ) = " << ::min(floatNum1, floatNum2) << std::endl;
	// std::cout << "max( f_a, f_b ) = " << ::max(floatNum1, floatNum2) << std::endl;

	// std::cout << "min( a, b ) = " << ::min(5.5, 10.2) << std::endl;
	// std::cout << "max( a, b ) = " << ::max(5.5, 10.2) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// different structure example
	TData data1; 
	TData data2;
	
	data1.num = 25;
	data2.num = 34;
	::swap(data1, data2);
	std::cout << "data1->num = " << data1 << ", data2->num = " << data2 << std::endl;
	std::cout << "min( data1, data2 ) = " << ::min(data1, data2) << std::endl;
	std::cout << "max( data1, data2 ) = " << ::max(data1, data2) << std::endl;

	return (0);
}
