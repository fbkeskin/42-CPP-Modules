/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:56:05 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/11 12:56:20 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

        void    setFirstName(std::string firstName);
        std::string getFirstName();
        
        void    setLastName(std::string lastName);
        std::string getLastName();

        void    setNickName(std::string nickName);
        std::string getNickName();     
        
        void    setPhoneNumber(std::string phoneNumber);
        std::string getPhoneNumber();

        void    setDarkestSecret(std::string darkestSecret);
        std::string getDarkestSecret();
        
        ~Contact();
};

#endif
