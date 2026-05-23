/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:31:19 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 10:03:57 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database(other.database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        database = other.database;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string& DBFile)
{
    addDB(DBFile);
}

void BitcoinExchange::addDB(const std::string& file_name)
{
    std::ifstream file(file_name.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error opening database");

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string value;

        std::getline(ss, date, ',');
        std::getline(ss, value);

        float rate = std::atof(value.c_str());

        database[date] = rate;
    }

    file.close();
}

float BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it;

    it = database.lower_bound(date);

    if (it == database.end())
    {
        --it;
        return it->second;
    }

    if (it->first == date)
        return it->second;

    if (it == database.begin())
        return -1;

    --it;
    return it->second;
}

void BitcoinExchange::processInput(const std::string& file_name) const
{
    std::ifstream file(file_name.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error opening input file" << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string value;

        std::getline(ss, date, '|');
        std::getline(ss, value);

        if (date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);
        if (value[0] == ' ')
            value.erase(0, 1);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        double amount;
        std::stringstream s2(value);
        s2 >> amount;
        if (s2.fail())
        {
            std::cout << "Error: bad input" << amount << std::endl;
            continue;
        }
        if (amount < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (amount > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getRate(date);
        if (rate < 0)
        {
            std::cout << "Error: bad input => "
                      << date
                      << std::endl;
            continue;
        }
        std::cout << date << " => " << amount << " = " << amount * rate
                  << std::endl;
    }

    file.close();
}