/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:31:19 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/14 20:56:28 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange(const BitcoinExchange& other) : database(other.database) {}

BitcoinExchange& operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
       database = other.database; 
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(std::string& DBFile)
{
    addDB(DBFile);
}

void BitcoinExchange::addDB(const std::string& text)
{
    std::ifstream file(text);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error at open databank" << std::endl;
        return ;
    }
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string value;

        std::getline(ss, date, ',');
        std::getline(ss, value, ',');
        double rate = std::stod(value)

        databank[data] = rate;
    }
    file.close();
    return ;
}