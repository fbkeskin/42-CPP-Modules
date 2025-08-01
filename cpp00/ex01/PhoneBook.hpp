/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:59:38 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/11 12:59:41 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     currentIndex;
        int     contactCount;
    public:
        PhoneBook();

        std::string getContactData(std::string request, std::string response);
        void        addContact();
        void        searchContact();

        ~PhoneBook();
};

#endif
