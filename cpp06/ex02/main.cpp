/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:42:20 by fatkeski          #+#    #+#             */
/*   Updated: 2025/03/24 15:21:23 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void printType(std::string str)
{
	std::cout << "class " << str << std::endl;
}

Base* generate(void)
{
	Base* objPtr = NULL;

	std::srand(std::time(NULL));
	int	type = rand() % 3;
	// std::cout << type << std::endl;
	if(type == 0)
		objPtr = new A();
	else if(type == 1)
		objPtr = new B();
	else if(type == 2)
		objPtr = new C();
	return(objPtr);
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		printType("A");
	}
	catch(std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			printType("B");
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				printType("C");
			}
			catch(const std::exception& e)
			{
				std::cerr << "casting did not occur: " << e.what() << std::endl;
			}
		}
	}

}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if(a)
	{
		(void)a;
		printType("A");
	}
	else
	{
		B* b = dynamic_cast<B*>(p);
		if(b)
		{
			(void)b;
			printType("B");
		}
		else
		{
			C* c = dynamic_cast<C*>(p);
			if(c)
			{
				(void)c;
				printType("C");
			}
			else
				std::cerr << "casting did not occur!" << std::endl;
		}
	}
}

// Amaç, bir nesnenin gerçek türünü (runtime'da) belirlemek.
int main(void)
{
	Base* obj = generate();

	std::cout << "dynamic refrence cast example: ";
	identify(*obj);

	std::cout << "dynamic pointer cast example: ";
	identify(obj);
	delete obj;
	return (0);
}