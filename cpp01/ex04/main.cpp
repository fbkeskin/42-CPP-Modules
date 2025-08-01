/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:21:04 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 13:57:31 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int main(int argc, char* argv[])
{
    int ret;
    
    if(argc != 4)
    {
        std::cout << "Argument count must be 4: ./program file_path string1 string2" << std::endl;
        return (1);
    }
    if(argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cout << "Empty Argument!" << std::endl;
        return (1);
    }
    File file(argv[1], argv[2], argv[3]);
    ret = file.replaceFile();
    if(ret == -1)
    {
        std::cerr <<  "File cannot open!" << std::endl;
        return (1);
    }
    if(ret == 0)
        std::cerr <<  "No change!" << std::endl;
    else if(ret == 2)
        std::cerr << "The file is empty!" << std::endl;
    return(0);
}
