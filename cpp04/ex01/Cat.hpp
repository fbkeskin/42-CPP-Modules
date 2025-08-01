/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:12:56 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/23 16:26:05 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

// derived class
class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& source);
        Cat& operator=(const Cat& source);
        void    makeSound() const;
        void    setCatIdea(int index, std::string newIdea);
        std::string getCatIdea(int index) const;
        void    printCatIdeas();
        ~Cat();
};

#endif
