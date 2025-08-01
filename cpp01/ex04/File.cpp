/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:01:31 by fatkeski          #+#    #+#             */
/*   Updated: 2025/02/15 13:28:17 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(const char* fileName, std::string str1, std::string str2)
{
    this->arr = new std::string[3];
    this->fileName = fileName;
    this->str1 = str1;
    this->str2 = str2;
    this->arr[0] = this->fileName;
    this->arr[1] = this->str1;
    this->arr[2] = this->str2;
}

void    File::setFileAttributes(std::string str1, std::string str2)
{
    this->str1 = str1;
    this->str2 = str2;
}

std::string*    File::getFileAttributes()
{
    return(arr);
}

int     File::replaceFile()
{
    std::ifstream    infile;
    std::ofstream    outfile;
    std::string      content;
    std::string      result;
    size_t           start = 0;
    size_t           end;
    bool             flag;

    infile.open(this->fileName);
    if(!(infile.is_open()))
        return (-1);
    std::stringstream buffer;
    buffer << infile.rdbuf();
    content = buffer.str();
    infile.close();
    if (content.empty())
        return (2);
    // std::cout << content << std::endl;
    end = content.find(this->str1, start);
    flag = false;
    while(end != std::string::npos) // npos: 2³² - 1 veya 2⁶⁴ - 1
    {
        flag = true;
        result += content.substr(start, end - start); 
        result += this->str2;
        start = end + (this->str1).length(); 
        end = content.find(this->str1, start);
    }
    if(flag)
    {
        result += content.substr(start);
        outfile.open((this->fileName + std::string(".replace")).c_str());
        if (!outfile.is_open())
            return (-1);
        outfile << result;
        outfile.close();
    }
    else
        return (0);
   return(1); 
}


File::~File()
{
    delete[] arr;
}