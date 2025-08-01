/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:56:31 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/11 12:56:34 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* CONSTRUCTORS */
Contact::Contact()
{
    // std::cout << "empty constructor" << std::endl;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

/* SETTER FUNCTIONS */
void    Contact::setFirstName(std::string firstName)
{
    if(!firstName.empty())
        this->firstName = firstName;
}

void    Contact::setLastName(std::string lastName)
{
    if(!lastName.empty())
        this->lastName = lastName;
}

void    Contact::setNickName(std::string nickName)
{
    if(!nickName.empty())
        this->nickName = nickName;
}

void    Contact::setPhoneNumber(std::string phoneNumber)
{
    if(!phoneNumber.empty())
        this->phoneNumber = phoneNumber;
}

void    Contact::setDarkestSecret(std::string darkestSecret)
{
    if(!darkestSecret.empty())
        this->darkestSecret = darkestSecret;
}

/* GETTER FUNCTIONS */
std::string Contact::getFirstName()
{
    return(firstName);
}

std::string Contact::getLastName()
{
    return(lastName);
}

std::string Contact::getNickName()
{
    return(nickName);
}      

std::string Contact::getPhoneNumber()
{
    return(phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return(darkestSecret);
}

/* DESTRUCTORS */
Contact::~Contact()
{
    // std::cout << "destructor worked" << std::endl;
}
