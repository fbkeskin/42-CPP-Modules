/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:32:53 by fatkeski          #+#    #+#             */
/*   Updated: 2025/08/01 21:27:56 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <sys/time.h>
#include <iomanip>


bool	isValidInput(char**& argv)
{
	int i = 1;
	while(argv[i])
	{
		int j = 0;
		if(argv[i][j] == '\0')
			return (false);
		while(argv[i][j] != '\0')
		{
			char c = argv[i][j];
			if(!(std::isdigit(c)) && !(c == ' '))
				return(false);
			j++;
		}
		i++;
	}
	return(true);
}

int main(int argc, char* argv[])
{
	if(argc < 2)
		return(std::cout << "you must enter a list of numbers as arguments!" << std::endl, 1);
	if(!isValidInput(argv))
		return(std::cout << "arguments can only be positive integers!" << std::endl, 1);

	struct timeval start, end;
	std::cout << "**********VECTOR TEST**********" << std::endl;
	{
		PmergeMe<std::vector<int> > container;
		container.loadInputArguments(argv);
		// std::cout << "is sorted: " << container.isSorted() << std::endl;
		std::cout << "Before: "; container.print();
		gettimeofday(&start, NULL);
		container.sort();
		gettimeofday(&end, NULL);
		double duration = ((end.tv_sec - start.tv_sec)*1000000) + (end.tv_usec - start.tv_usec);
		std::cout << "After:  "; container.print();
		// std::cout << "is sorted: " << container.isSorted() << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector -> " << std::fixed << std::setprecision(2) << duration << " us" << std::endl;
	}

	std::cout << "**********DEQUE TEST**********" << std::endl;
	{
		PmergeMe<std::deque<int> > container;
		container.loadInputArguments(argv);
		// std::cout << "is sorted: " << container.isSorted() << std::endl;
		std::cout << "Before: "; container.print();
		gettimeofday(&start, NULL);
		container.sort();
		gettimeofday(&end, NULL);
		double duration = ((end.tv_sec - start.tv_sec)*1000000) + (end.tv_usec - start.tv_usec);
		std::cout << "After:  "; container.print();
		// std::cout << "is sorted: " << container.isSorted() << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque -> " << std::fixed << std::setprecision(2) << duration << " us" << std::endl;
	}
	return (0);
}
