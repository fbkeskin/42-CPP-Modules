/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:06:45 by fatkeski          #+#    #+#             */
/*   Updated: 2025/06/11 19:23:21 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

/*
// SUBJECT MAIN
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
*/

int main(void)
{
	{
		std::cout << "########## EXAMPLE 1 ##########" << std::endl;

		// Boş Span ile span hesaplama
		Span emptySpan;
		try
		{
			std::cout << "Empty span shortest: " << emptySpan.shortestSpan() << std::endl;
		}
		catch(const char* message)
		{
			std::cerr << "Error: " << message << std::endl;
		}

		// 2. Tek elemanlı Span ile span hesaplama
		Span singleSpan(5);
		try
		{
			singleSpan.addNumber(42);
			std::cout << "Single element span shortest: " << singleSpan.shortestSpan() << std::endl;
		}
		catch(const char* message)
		{
			std::cerr << "Error: " << message << std::endl;
		}
	}

	{
		std::cout << std::endl << "########## EXAMPLE 2 ##########" << std::endl;
		Span span(10);
		try
		{
			span.addNumber(-10);
			int nums[8] = {5, 2, 8, 99, 3, 10, 1, -2};
			span.addNumbers(&nums[0], &nums[8]);
			span.addNumber(7);
			span.print();
			std::cout << "1. shortestSpan(): " << span.shortestSpan() << std::endl;
			std::cout << "1. longestSpan(): " << span.longestSpan() << std::endl;
		}
		catch(const char* message)
		{
			std::cerr << "Error: " << message << std::endl;
		}

		std::cout << std::endl << "########## EXAMPLE 3 ##########" << std::endl;
		Span span2(span);
		span2.print();
		std::cout << "2. shortestSpan(): " << span2.shortestSpan() << std::endl;
		std::cout << "2. longestSpan(): " << span2.longestSpan() << std::endl;

		Span span3(20);
		int nums[17] = {1, 38923, -329, 32, 321, 5, 2, 8, 99, 3, 10, 1, -2, 10 , 23, 3291, 9};
		span3.addNumbers(&nums[0], &nums[17]);
		span3.addNumber(10);
		span3.addNumber(11);
		span3.addNumber(12);
		span3.print();
		std::cout << "3. shortestSpan(): " << span3.shortestSpan() << std::endl;
		std::cout << "3. longestSpan(): " << span3.longestSpan() << std::endl;

		span2 = span3;
		span2.print();
		std::cout << "4. shortestSpan(): " << span2.shortestSpan() << std::endl;
		std::cout << "4. longestSpan(): " << span2.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "########## EXAMPLE 4 ##########" << std::endl;
		// Büyük veri testi (10.000+ eleman)
		try
		{
			std::srand(std::time(0));
			const unsigned int count = 15000;
			Span largeSpan(count);

			std::vector<int> largeNumbers;
			for (unsigned int i = 0; i < count; ++i) {
				largeNumbers.push_back(std::rand());
			}

			largeSpan.addNumbers(largeNumbers.begin(), largeNumbers.end());
			// largeSpan.print();
			std::cout << "shortestSpan(): " << largeSpan.shortestSpan() << std::endl;
			std::cout << "longestSpan(): " << largeSpan.longestSpan() << std::endl;
		}
		catch (const char* message)
		{
			std::cerr << "Error: " << message << std::endl;
		}
	}
	return (0);
}
