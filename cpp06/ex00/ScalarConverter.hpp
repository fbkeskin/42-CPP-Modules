/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:20:35 by fbetul            #+#    #+#             */
/*   Updated: 2025/03/24 12:37:18 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utilities.hpp"

// utility class, not be instantiable
class ScalarConverter
{
  private:
	ScalarConverter();
	~ScalarConverter();
  public:
	ScalarConverter(const ScalarConverter& source);
	ScalarConverter& operator=(const ScalarConverter& source);
	static void convert(const std::string str);
};
