/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:55:08 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/11 12:55:16 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phoneBook;
    std::string userInput;

    std::cout << "Please, select command (ADD, SEARCH, EXIT): ";
    while(std::getline(std::cin, userInput))
    {
        if(userInput == "EXIT")
            break;
        else if(userInput == "ADD")
            phoneBook.addContact();
        else if(userInput == "SEARCH")
            phoneBook.searchContact();
        else
            std::cout << "Invalid command!" << std::endl;
        std::cout << "Please, select command (ADD, SEARCH, EXIT): ";
    }
}
