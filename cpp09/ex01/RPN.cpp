/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:24:33 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/22 14:33:17 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "empty constructor() called" << std::endl;
	this->postfixExp = "";
	this->result = INT_MIN;
}

RPN::RPN(const char* arg)
{
	std::cout << "paramaterized constructor() called" << std::endl;
	this->postfixExp = arg;
	this->result = 0;
}

RPN::RPN(const RPN& source)
{
	std::cout << "RPN copy constructor()" << std::endl;
	*this = source;
}

RPN& RPN::operator=(const RPN& source)
{
	std::cout << "RPN copy assignment overloading" << std::endl;
	this->postfixExp = source.postfixExp;
	this->stack = source.stack;
	this->result = source.result;
	return(*this);
}

bool	isOperator(char& c)
{
	bool flag = false;
	for(int i = 0; i < 4; i++)
	{
		if(c == OPERATORS[i])
			flag = true;
	}
	return(flag);
}

int applyOperator(int num1, int num2, char op)
{
	if(op == '*')
		return(num1 * num2);
	else if(op == '/')
		return(num1 / num2);
	else if(op == '+')
		return(num1 + num2);
	else if(op == '-')
		return(num1 - num2);
	return(-777);
}

void RPN::controlPostfixFormat()
{
	std::string str = this->postfixExp;

	if(str.length() < 5)
		throw("Error: Missing RPN Notation!");
	size_t	pos1 = 0, pos2 = 0;
	while(true)
	{
		pos2 = str.find(' ', pos1);
		if(pos2 == std::string::npos)
			break;
		if((pos2 - pos1) > 1)
			throw("Error: Numbers passed as arguments must always be less than 10!");
		pos1 = pos2 + 1;
	}
}

int	RPN::solvePostfixNotation()
{
	std::string str = this->postfixExp;
	size_t i;
	size_t len = str.length();

	controlPostfixFormat();
	for(i = 0; i < len; i++)
	{
		if(str[i] == ' ')
			continue;
		else if(std::isdigit(str[i]))
		{
			this->stack.push(str[i] - '0');
		}
		else if(isOperator(str[i]))
		{
			if(this->stack.size() > 1)
			{
				int top1 = this->stack.top();
				this->stack.pop();
				int top2 =  this->stack.top();
				this->stack.pop();
				this->stack.push(applyOperator(top2, top1, str[i]));
			}
			else
				throw("Error: not correct RPN form!");
		}
		else
			throw("Error: different value!");
	}
	if(this->stack.size() != 1)
		throw("Error: Bad Format RPN Notation!");
	this->result = stack.top();
	this->stack.pop();
	return(this->result);
}

RPN::~RPN()
{
	std::cout << "destructor() called" << std::endl;
}
