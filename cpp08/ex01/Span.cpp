/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:36:45 by fatkeski          #+#    #+#             */
/*   Updated: 2025/06/11 19:23:10 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << "empty constructor called" << std::endl;
	this->N = 0;
}

Span::Span(unsigned int N)
{
	std::cout << "parameterized constructor called" << std::endl;
	this->N = N;
}

Span::Span(const Span& source)
{
	std::cout << "copy constructor called" << std::endl;
	*this = source;
}

Span& Span::operator=(const Span& source)
{
	std::cout << "copy assignment overloading called" << std::endl;
	if(this != &source)
	{
		this->N = source.N;
		this->vector = std::vector<int>(source.vector);
	}
	return(*this);
}

void Span::addNumber(int number)
{
	if(N == 0)
		throw("not enough capacity!");
	if(vector.size() == N)
		throw("number capacity full!");
	this->vector.push_back(number);
}

void Span::print()
{
	std::cout << "list size: " << this->vector.size();
	std::cout << ", content: ";
	iterator start = this->vector.begin();
	iterator end = this->vector.end();
	while(start != end)
	{
		std::cout << *start << " ";
		start++;
	}
	std::cout << std::endl;
}

size_t Span::shortestSpan()
{
	size_t size = vector.size();
	if(size <= 1)
		throw("not enough values ​​to apply the algorithm!");
	std::vector<int> sortedVec(this->vector);
	iterator start = sortedVec.begin();
	iterator end = sortedVec.end();
	std::sort(start, end);

	int index1, index2, span;
	int shortestSpan = (*(start + 1)) - (*start);
	for(size_t i = 0; i < (size - 1); i++)
	{
		index1 = *start;
		index2 = *(start + 1);
		span = index2 - index1;
		if(span < shortestSpan)
			shortestSpan = span;
		start++;

	}
	return(shortestSpan);
}

size_t Span::longestSpan()
{
	if(vector.size() <= 1)
		throw("not enough values ​​to apply the algorithm!");
	iterator start = this->vector.begin();
	iterator end = this->vector.end();
	int min = *(std::min_element(start, end));
	int max = *(std::max_element(start, end));
	return(max - min);
}

Span::~Span()
{
	std::cout << "destructor called" << std::endl;
}
