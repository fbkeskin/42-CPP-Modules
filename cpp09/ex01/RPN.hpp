/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:31:14 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/01 14:17:52 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <stack>

#define OPERATORS "*/+-"
#define OPERANDS "0123456789"

class RPN
{
	private:
		const char*		postfixExp;
		int				result;
		std::stack<int>	stack;
	public:
		RPN();
		RPN(const char* arg);
		RPN(const RPN& source);
		RPN&	operator=(const RPN& source);
		void	controlPostfixFormat();
		int		solvePostfixNotation();
		~RPN();
};
