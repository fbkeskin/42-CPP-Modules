/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:12:56 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/18 17:33:01 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

// derived class
class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& source);
        Cat& operator=(const Cat& source);
        void    makeSound() const;
        ~Cat();
};

#endif
