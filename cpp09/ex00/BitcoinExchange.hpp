/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:10:03 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/22 14:22:02 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <list>
#include <algorithm>

#define CURRENT_YEAR 2025

enum Months {
	JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class BitcoinExchange
{
	private:
		std::map<std::string, double> database;
		std::list<std::pair<std::string, double> > input;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& source);
		BitcoinExchange& operator=(const BitcoinExchange& source);
		/* OTHER MEMBER FUNCS */
		int		loadDatabase();
		int		loadInputData(const char* fileName);
		std::pair<std::string, double>	findPair(std::pair<std::string, double> sourcePair);
		std::pair<std::string, double>	inputControl(std::pair<std::string, double> pair);
		void	applyExchangeRate();
		~BitcoinExchange();
};

bool isValidNumber(const std::string& s);

template<typename T>
void printContainer(T& container, std::string sep = " ")
{
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();
	while (begin != end)
	{
		std::cout << begin->first << ", " << begin->second << sep;
		begin++;
	}
	std::cout << std::endl;
}
