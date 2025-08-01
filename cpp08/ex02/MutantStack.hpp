/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:41:30 by fatkeski          #+#    #+#             */
/*   Updated: 2025/06/10 14:25:19 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		iterator begin()
		{
			// std::cout << "begin: " << *(this->c.begin()) << std::endl;
			return(this->c.begin());
		}
		iterator end()
		{
			// std::cout << "end: " << *(--(this->c.end())) << std::endl;
			return(this->c.end());
		}
};

template <typename T>
void printStack(std::stack<T> stack)
{
	while(!(stack.empty()))
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << std::endl;
}

#endif
