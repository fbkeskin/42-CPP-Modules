/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:32:15 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 14:13:53 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& source);
        Brain& operator=(const Brain& source);
        void    setIdea(int index, std::string newIdea);
        std::string getIdea(int index);
        void    printBrainIdeas();
        ~Brain();
};

#endif