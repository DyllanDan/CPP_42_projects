/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:51:02 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:51:04 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char** argv)
{
    std::string line;
    std::string text;
    std::string str_find;
    std::string str_replace;
    size_t i;
    int len;

    i = 1;
    text = "";
    if (argc != 4)
    {
        std::cout << "Incorrect number of arguments." << std::endl;
        return (0);
    }
    str_find = std::string(argv[2]);
    str_replace = std::string(argv[3]);
    std::ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        std::cout << "File \"" << argv[1] << "\" cannot be open" << std::endl;
        return (1);
    }
    while (std::getline(infile, line))
    {
        i = line.find(argv[2]);
        while (i != std::string::npos)
        {
            len = line.length();
            text += line.substr(0, i);
            text += str_replace;
            line = line.substr(i + str_find.length());
            i = line.find(argv[2]);
        }
        text += line;
        text += "\n";
    }
    infile.close();
    std::ofstream outfile(argv[1], std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
    {
        std::cout << "File \"" << argv[1] << "\" cannot be writen" << std::endl;
        return (1);
    }
    outfile << text;
    outfile.close();
    return (0);
}
