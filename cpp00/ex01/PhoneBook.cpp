/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:59:31 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/11 13:02:49 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* CONSTRUCTORS */
PhoneBook::PhoneBook()
{
    //std::cout << "empty constructor" << std::endl;
    currentIndex = 0;
    contactCount = 0;

}

/* OTHER FUNCTIONS */
std::string    PhoneBook::getContactData(std::string request, std::string response)
{
    
    std::cout << request << std::endl;
    while(std::getline(std::cin, response))
    {
        if (!response.empty())
            break;
        std::cout << "Not a valid data. " << request;
    }
    return(response);
}

void    PhoneBook::addContact()
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    firstName = getContactData("Enter first name: ", firstName);
    lastName = getContactData("Enter last name: ", lastName);
    nickName = getContactData("Enter nickname: ", nickName);
    phoneNumber = getContactData("Enter phone number: ", phoneNumber);
    darkestSecret = getContactData("Enter darkest secret: ", darkestSecret);

    contacts[currentIndex].setFirstName(firstName);
    contacts[currentIndex].setLastName(lastName);
    contacts[currentIndex].setNickName(nickName);
    contacts[currentIndex].setPhoneNumber(phoneNumber);
    contacts[currentIndex].setDarkestSecret(darkestSecret);

	currentIndex = (currentIndex + 1) % 8;
    if(contactCount < 8)
        contactCount++;
}

std::string formatColumn(std::string column)
{
    if(column.length() > 10)
        return(column.substr(0, 9) + ".");
    return(column);
}

int isValidInput(int max, std::string input)
{
    size_t i;
    int num;

    if(input.empty())
        return (0);
    for(i = 0; i < input.length(); i++)
    {
        if(!(std::isdigit(input[i])))
            return (0);
    }
    std::stringstream convertion(input);
    convertion >> num;
    if (convertion.fail() || (num < 1 || num > max))
        return (0);
    return(1);
}

void        PhoneBook::searchContact()
{
    int         i;
    int         index;
    std::string userInput;

    if(contactCount > 0)
    {
        std::cout << std::endl;
        std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << std::endl;
        for(i = 0; i < contactCount; i++)
        {
            std::cout << std::string(43, '=') << std::endl;
            std::cout << std::setw(10) << (i + 1);
            std::cout << "|";
            std::cout << std::setw(10) << formatColumn(contacts[i].getFirstName());
            std::cout << "|";
            std::cout << std::setw(10) << formatColumn(contacts[i].getLastName());
            std::cout << "|";
            std::cout << std::setw(10) << formatColumn(contacts[i].getNickName());
            std::cout << std::endl;
        }
        std::cout << "Select the index you want to view: ";
        if(!(std::getline(std::cin, userInput)))
            return ;
        while(!(isValidInput(contactCount, userInput)))
        {
            std::cout << "Not a valid data. " <<  "Try again: ";
	        if(!(std::getline(std::cin, userInput)))
                return ;
        }
        std::stringstream convertion(userInput);
        convertion >> index;
        index = index - 1;
        std::cout << std::endl;
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
        std::cout << std::endl;
    }
    else
        std::cout << "Empyt Phonebook!" << std::endl;
}

/* DESTRUCTORS */
PhoneBook::~PhoneBook()
{
    //std::cout << "destructor worked" << std::endl;
}
