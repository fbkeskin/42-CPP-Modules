/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:58:58 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/12 13:32:47 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
* ✅ difference between pointer and reference
* ✅ how they are stored in memory?
* ✅ when should you use a pointer and when should you use a reference?
*/
int main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string*    strPTR = &str;
    std::string&    strREF = str;

    std::cout << "Your program has to print:" << std::endl;
    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << strPTR << std::endl;
    std::cout << "The memory address of the string variable: " << &strREF << std::endl;
    std::cout << "And then:" << std::endl;
    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The memory address held by stringPTR: " << *strPTR << std::endl;
    std::cout << "The memory address of the string variable: " << strREF << std::endl;
    return (0);
}

/**
 * std::string     str2 = "Z";
 * std::cout << "The memory address of the str2 variable: " << &str2 << std::endl;
 * strREF = str2;
 */
