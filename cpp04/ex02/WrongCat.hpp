/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:39:40 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/18 17:40:23 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

// derived class
class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& source);
        WrongCat& operator=(const WrongCat& source);
        void    makeSound() const;
        ~WrongCat();
};

#endif
