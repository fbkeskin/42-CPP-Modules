/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:06:45 by fatkeski          #+#    #+#             */
/*   Updated: 2025/05/16 18:36:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	// vector test
	std::cout << "-----------------VECTOR TEST-----------------" << std::endl;
	try
	{
		std::vector<int> vec(3, -7);
		vec.push_back(42);
		vec.insert(vec.begin()+1, 4, 25);
		vec[3] = 1453;
		std::cout << "container content: ";
		printContainer(vec.begin(), vec.end());
		std::cout << "easyfind result  : "; printContainer(::easyfind(vec, 1453), vec.end());
	}
	catch(const char* message)
	{
		std::cerr << "Error: " << message << std::endl;
	}

	// list test
	std::cout << "-----------------LIST TEST-----------------" << std::endl;
	try
	{
		std::list<int> list(3, -7);
		list.push_front(571);
		std::list<int>::iterator start = list.begin();
		std::advance(start, 3);
		list.insert(start, 2, 11);
		list.push_back(632);
		list.insert(list.end(), 3, 3); list.remove(3);
		std::cout << "container content: ";
		printContainer(list.begin(), list.end());
		std::cout << "easyfind result  : "; printContainer(::easyfind(list, 11), list.end());
	}
	catch(const char* message)
	{
		std::cerr << "Error: " << message << std::endl;
	}

	// deque(Double-Ended Queue) test
	std::cout << "-----------------DEQUE TEST-----------------" << std::endl;
	try
	{
		std::deque<int> deque(5, 1907);
		std::cout << "is empty: " << deque.empty() << ", size: " << deque.size() << std::endl;
		std::cout << "container content: ";
		printContainer(deque.begin(), deque.end());
		deque.push_front(-7);
		deque.insert(deque.begin()+1, 3, -1);
		deque.push_back(-999);
		std::cout << "container content: ";
		printContainer(deque.begin(), deque.end());
		// SİL
		// deque[-10] = 3; // büyük sayı, bellek adreslemesinde "wrap-around" etkisi yaparak, programınızın bellek alanı içinde bir yere denk gelir.
		// deque[129] = 5; // DİREKT SEG
		// printContainer(deque.begin(), deque.end());
		std::cout << "easyfind result: "; printContainer(::easyfind(deque, 1907), deque.end());
		std::cout << "easyfind result: "; printContainer(::easyfind(deque, 1903), deque.end());

	}
	catch(const char* message)
	{
		std::cerr << "Error: " << message << std::endl;
	}

	// forward list test -> c++11 ve sonrasında var ÇALIŞMIYOR.
	// #include <forward_list>
	// std::cout << "-----------------FORWARD LIST TEST-----------------" << std::endl;
	// try
	// {
	// 	std::forward_list<int> forwardList(5, -1);
	// 	forwardList.push_front(13);
	// 	printContainer(forwardList.begin(), forwardList.end());
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	return (0);
}
