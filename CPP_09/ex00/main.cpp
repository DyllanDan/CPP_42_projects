/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:59:44 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/14 21:02:06 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

bool isValidline(const std::string& line);
bool isValidDate(const std::string& line);
bool isValidRate(const std::string& line);
bool isValidInput(char* input_file);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Not enough arguments - ./btc argument" << std::endl;
        return 0;
    }
    if (!isValidInput(argv[1]))
    {
        std::cout << "Incorrect document informations" << std::endl;
    }
    return 1;
}

bool isValidline(const std::string& line)
{
    if (line[4] != '-' || line[7] != '-' || line[11] != '|')
        return false;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (!((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == ',' || line[i] == '.'))
            return false;
    }
    return true;
}

bool isValidDate(const std::string& line)
{
    std::size_t year_pos = line.find('-');
    std::string year = line.substr(0, year_pos);
    std::size_t month_pos = line.find('-', year_pos + 1);
    std::string month = line.substr(year_pos + 1, month_pos);
    std::size_t day_pos = line.size();
    std::string day = line.substr(month_pos + 1, day_pos);
    std::string exchange_rate = line.substr(day_pos + 1, line.size());
    
    if(std::atoi(year).c_str() < 2009)
        return false;
    if (std::atoi(month).c_str() < 1 || std::atoi(month).c_str() > 12)
        return false;
    if (std::atoi(day).c_str() < 1 || std::atoi(day).c_str() > 31)
        return false;
    return true;
}

bool isValidRate(const std::string& line)
{   
    if(std::stod(line) < 0 || std::stod(line) > 1000)
        return false;
    return true;
}

bool isValidInput(char* input_file)
{
    std::ifstream file(input_file);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error at open databank" << std::endl;
        return false;
    }
    std::getline(file, line); 
    while (std::getline(file, line))
    {
        if (!isValidline(line))
            return false;
        std::stringstream ss(line);
        
        std::string date;
        std::string value;
        std::getline(ss, date, '|');
        std::getline(ss, value, '|');
        if (!isValidDate(line))
            return false;
        if (!isValidDate(line))
            return false;
    }
    file.close();
    return true;
}