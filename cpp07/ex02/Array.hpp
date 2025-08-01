/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:40:56 by fatkeski          #+#    #+#             */
/*   Updated: 2025/04/07 21:35:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template<typename T> class Array
{
 private:
 	T* arr;
	size_t length;
 public:
 	Array(){
 		this->arr = NULL;
		length = 0;
		std::cout << "Default constructor called." << std::endl;
 	}

 	Array(unsigned int n){
 		arr = new T[n];
		length = n;
 	}

 	Array(const Array& source){
		arr = NULL;
		*this = source;
 	}

 	Array& operator=(const Array& source){
 		if(this == &source)
 			return(*this);
 		if(arr)
			delete[] arr;
		length = source.size();
		arr = new T[length];
		for(size_t i = 0; i < length; i++)
			arr[i] = source.arr[i];
		return(*this);
 	}

	T& operator[](unsigned int index) const{
		if(index >= length)
			throw std::exception();
		return(arr[index]);
	}
	
 	size_t size() const {
		return (length);
	}
	
 	~Array(){
		std::cout << "Destructor called" << std::endl;
		delete[] arr;
	}
};

#endif
