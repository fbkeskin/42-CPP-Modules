/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:34:13 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/22 14:56:48 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

template <typename C>
class PmergeMe
{
	private:
		C		container;
		size_t	order;

		void	swapPairs(int index1, int index2)
		{
			typename C::iterator start1 = this->container.begin() + index1;
			typename C::iterator start2 = this->container.begin() + index2;

			std::swap_ranges(start1, start1 + order, start2);
		}

		void	sortByPairs() {
			int element1;
			int element2;
			size_t order = this->order;
			size_t size = this->container.size() - order;

			for(size_t i = order - 1; i < size; i += (order * 2))
			{
				element1 = this->container[i];
				element2 = this->container[i + order];
				if(element1 > element2)
					swapPairs(i - order + 1, i + 1);
			}
		}

		C createTemp(C main, size_t order) {
			size_t	index = order - 1;

			size_t pairCount = main.size() / order;
			C temp;
			int i = index;
			while(pairCount > 0)
			{
				temp.push_back(main[i]);
				i += order;
				pairCount--;
			}
			return(temp);
		}

		C generateJacobsthal(size_t pairs) {
			std::vector<size_t> temp;
			temp.push_back(0);
			temp.push_back(1);
			while (temp.back() <= pairs)
			{
				temp.push_back(temp.back() + (2 * temp[temp.size() - 2]));
			}
			C jacobsthal(temp.begin() + 2, temp.end());
			return (jacobsthal);
		}

		C generateInsertionOrder(C& pend, size_t order) {
			size_t pairs = pend.size() / order;
			if(pairs < 2)
				return(pend);
			C jacobsthal = generateJacobsthal(pairs);
			C temp;
			int count = 0;
			size_t len = jacobsthal.size();
			size_t i = 0;

			while(i < len - 1)
			{
				int elements = jacobsthal[i + 1] - jacobsthal[i];
				int index = jacobsthal[i + 1] - 2;
				size_t start = order * index;
				if(start > pend.size())
					break;
				while(elements > 0)
				{
					int end = start + order;
					temp.insert(temp.end(), pend.begin() + start, pend.begin() + end);
					count++;
					elements--;
					start = start - order;
				}
				i++;
			}
			len = pend.size();
			if(temp.size() != len)
			{
				size_t start = temp.size();
				while(len > start)
				{
					temp.insert(temp.end(), pend.begin() + len - order, pend.begin() + len);
					len = len - order;
				}
			}
			return(temp);
		}

		void	insertToMain(C& main, C& sourcePend, size_t order) {
			if(sourcePend.empty())
				return;

			size_t pairCount = sourcePend.size() / order;
			int j = 0;
			size_t	index = order - 1;
			C pend = generateInsertionOrder(sourcePend, order);
			while(pairCount > 0)
			{
				C temp = createTemp(main, order);
				typename C::iterator it = std::lower_bound(temp.begin(), temp.end(), pend[index]);
				size_t loc = std::distance(temp.begin(), it) * order;
				main.insert(main.begin() + loc, pend.begin() + j, pend.begin() + j + order);
				j += order;
				index += order;
				pairCount--;
			}
		}

		void	createMainAndPend() {
			C	main;
			C	pend;
			C	odd;

			C& vec = this->container;
			size_t order = this->order;
			typename C::iterator start = vec.begin();
			size_t count = ((vec.size()) / (order * 2));
			main.insert(main.end(), start, (start + (order * 2))); // a1 ve b1 eklendi main'e
			start = start + 2*order;
			while(count > 1)
			{
				pend.insert(pend.end(), start, (start + order));
				start = start + order;
				main.insert(main.end(), start, (start + order));
				start = start + order;
				count--;
			}
			size_t dist = std::distance(start, vec.end());
			if(start != vec.end())
			{
				if(dist >= order)
				{
					pend.insert(pend.end(), start, (start + order));
					start = start + order;
				}
				if(start < vec.end())
					odd.insert(odd.end(), start, vec.end());
			}
			insertToMain(main, pend, order);
			main.insert(main.end(), odd.begin(), odd.end());
			container = main;
		}

	public:
		PmergeMe() {
			this->order = 1;
			std::cout << "empty constructor called" << std::endl;
		}

		void	loadInputArguments(char** argv) {
			int i = 1;
			while(argv[i])
			{
				this->container.push_back(std::atoi(argv[i]));
				i++;
			}
		}

		void	sort() {
			if(order > this->container.size() / 2)
			{
				this->order = (this->order) / 2;
				return;
			}
			sortByPairs();
			this->order = (this->order) * 2;
			sort();
			createMainAndPend();
			this->order = (this->order) / 2;
		}

		void	print() {
			typename C::iterator begin = this->container.begin();
			typename C::iterator end = this->container.end();
			while (begin != end)
			{
				std::cout << *begin << " ";
				begin++;
			}
			std::cout << std::endl;
		}

		bool	isSorted() {
			for (size_t i = 0; i < this->container.size() - 1; ++i)
			{
				if (this->container[i] > this->container[i + 1])
					return false;
			}
			return (true);
		}

		~PmergeMe() {
			std::cout << "destructor called" << std::endl;
		}
};
