/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:02:34 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/22 14:24:32 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "empty constructor() called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	std::cout << "BitcoinExchange copy constructor" << std::endl;
	*this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	std::cout << "BitcoinExchange copy assignment overloading" << std::endl;
	if(this == &source)
		return(*this);
	this->database = source.database;
	this->input = source.input;
	return(*this);
}

int	BitcoinExchange::loadDatabase()
{
	std::ifstream	infile;
	std::string		line;
	size_t 			pos;
	char*			endptr = NULL;

	infile.open("data_subject.csv");
	if(!(infile.is_open()))
		return (-1);
	if(!(std::getline(infile, line)))
		return (-2);
	while(std::getline(infile, line))
	{
		std::pair<std:: string, double> pair("", 0);
		pos = line.find(',');
		if(pos == std::string::npos)
			return (-3);
		pair.first = line.substr(0, pos);
		pair.second = std::strtod((line.substr(pos + 1)).c_str(), &endptr);
		this->database.insert(pair);
	}
	infile.close();
	return(0);
}

int	BitcoinExchange::loadInputData(const char* fileName)
{
	std::ifstream	infile;
	std::string		line;
	size_t 			pos;
	char*			endptr = NULL;

	infile.open(fileName);
	if(!(infile.is_open()))
		return (-1);
	if(!(std::getline(infile, line)))
		return (-2);
	if(line.compare("date | value") != 0)
		return (std::cout << "Data loading failed, bad format! " << "Header must be: \"date | value\"" << std::endl, -3);
	while(std::getline(infile, line))
	{
		std::pair<std::string, double> pair("", 0);
		pos = line.find(' ');
		if(pos == std::string::npos || line.substr(pos).length() < 4)
		{
			pair.first = "M" + line;
			pair.second = -1;
		}
		else
		{
			std::string valuePart = line.substr(pos + 3);
			if((line.substr(pos, 3).compare(" | ") != 0) || !(isValidNumber(valuePart)))
			{
				pair.first = "B" + line;
				pair.second = -1;
			}
			else
			{
				pair.first = line.substr(0, pos);
				pair.second = std::strtod(valuePart.c_str(), &endptr);
			}
		}
		this->input.push_back(pair);
	}
	infile.close();
	return(0);
}

int	validDayInMonth(int year, int month)
{
	switch(month)
	{
		case APRIL:
		case JUNE:
		case SEPTEMBER:
		case NOVEMBER:
			return 30;
		case FEBRUARY:
			if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				return (29);
			else
				return(28);
		default:
			return 31;
	}
}

bool isValidNumber(const std::string& s)
{
	std::stringstream ss(s);
	double num;
	ss >> num;

	return (!ss.fail() && ss.eof());
}

std::pair<std::string, double> BitcoinExchange::findPair(std::pair<std::string, double> sourcePair)
{
	std::map<std::string, double>::iterator it = this->database.find(sourcePair.first);
	if(it != this->database.end())
		return(*it);
	it = this->database.lower_bound(sourcePair.first);
	if(it != this->database.end())
	{
		if(it == this->database.begin())
			return(*it);
		return(*(--it));
	}
	return(*(--it));
}

std::pair<std::string, double> BitcoinExchange::inputControl(std::pair<std::string, double> pair)
{
	// base
	if(pair.first[0] == 'M')
		return(std::make_pair("Error: Data loading failed, missing data entry!", false));
	if(pair.first[0] == 'B')
		return(std::make_pair("Error: Input value is not in true format! Expected format: X.X (double)", false));

	// date
	if(pair.first.length() != 10)
		return(std::make_pair("Error: Input is not in true format!  Expected format: YYYY-MM-DD", false));

	int year = std::atoi((pair.first.substr(0, 4)).c_str());
	int month = std::atoi((pair.first.substr(5, 7)).c_str());
	int day = std::atoi((pair.first.substr(8, pair.first.length())).c_str());
	// std::cout << year << "/" << month << "/" << day << std::endl;

	// date controls
	if((year < 2009) || (year > CURRENT_YEAR))
		return(std::make_pair("Error: No BTC data available for the entered year!", false));
	if((month < 1) || (month > 12))
		return(std::make_pair("Error: No BTC data available for the entered month!", false));
	if((day < 1 )|| (day > validDayInMonth(year, month)))
		return(std::make_pair("Error: No BTC data available for the entered day!", false));

	// value controls
	if(pair.second < 0)
		return(std::make_pair("Error: Not a positive BTC value!", false));
	if(pair.second > 1000)
		return(std::make_pair("Error: Too large a BTC value!", false));
	return(std::make_pair("true", true));
}

void	BitcoinExchange::applyExchangeRate()
{
	double exchangeRate;
	std::list<std::pair<std::string, double> >::iterator begin = this->input.begin();
	std::list<std::pair<std::string, double> >::iterator end = this->input.end();

	while (begin != end)
	{
		exchangeRate = (findPair(*begin)).second;

		std::pair<std::string, bool> input = inputControl(*begin);

		if(input.second)
			std::cout << begin->first << " => " << begin->second << " = " << (begin->second * exchangeRate) << std::endl;
		else
			std::cout << input.first << std::endl;
		begin++;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "destructor called" << std::endl;
}
