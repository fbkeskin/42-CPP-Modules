/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:39:16 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:11:30 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Argument count must be 2: ./harlFilter \"message\"" << std::endl;
        return (1);
    }
    void (Harl::*ptrToMemberFunc)(std::string) = &Harl::complain;
    
    Harl harl;
    (harl.*ptrToMemberFunc)(argv[1]);

    return (0);
}