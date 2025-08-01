/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:26:01 by fatkeski          #+#    #+#             */
/*   Updated: 2025/06/11 19:23:02 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <queue>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> vector;
	public:
		typedef std::vector<int>::iterator iterator;
		Span();
		Span(unsigned int N);
		Span(const Span& source);
		Span& operator=(const Span& source);
		void addNumber(int number);
		template<typename T>
		void addNumbers(T start, T end)
		{
			size_t size = std::distance(start, end);
			if(size == 0)
				throw("no elements to add!");
			if(vector.size() == N)
				throw("number capacity full!");
			if((N == 0) || (N - vector.size() < size))
				throw("not enough capacity!");
			vector.insert(this->vector.end(), start, end);
		}
		void print();
		size_t shortestSpan();
		size_t longestSpan();
		~Span();
};

#endif
