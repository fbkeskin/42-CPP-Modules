/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:43:50 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/18 17:44:34 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include "WrongAnimal.hpp"

// derived class
class WrongDog : public WrongAnimal
{
    public:
        WrongDog();
        WrongDog(const WrongDog& source);
        WrongDog& operator=(const WrongDog& source);
        void    makeSound() const;
        ~WrongDog();
};

#endif
