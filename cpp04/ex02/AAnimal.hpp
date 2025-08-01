/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:14:50 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 17:08:50 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

// base class
class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal& source);
        AAnimal& operator=(const AAnimal& source);
        std::string getType()const;
        void setType(std::string type);
        virtual void makeSound() const = 0;
        virtual ~AAnimal();
};

#endif
