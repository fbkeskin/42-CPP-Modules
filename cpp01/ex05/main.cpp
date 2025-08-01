/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:39:16 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 17:24:01 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;

    void (Harl::*ptrToMemberFunc)(std::string) = &Harl::complain;
    (harl.*ptrToMemberFunc)("INFO");

    return (0);
}
