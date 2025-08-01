/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:52:39 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/13 13:55:20 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class File
{
    private:
        const char* fileName;
        std::string str1;
        std::string str2;
        std::string* arr;
    public:
        File(const char* fileName, std::string str1, std::string str2);
        void    setFileAttributes(std::string str1, std::string str2);
        std::string*    getFileAttributes();
        int     replaceFile();
        ~File();
};

#endif