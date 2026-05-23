/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:59:44 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 09:46:58 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc("data.csv");
        btc.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

bool isValidline(const std::string& line)
{
    if (line.size() < 14)
        return false;

    if (line[4] != '-' || line[7] != '-')
        return false;

    return true;
}

bool isValidDate(const std::string& line)
{
    size_t year_pos = line.find('-');

    size_t month_pos = line.find('-', year_pos + 1);

    std::string year = line.substr(0, year_pos);

    std::string month = line.substr(
        year_pos + 1,
        month_pos - year_pos - 1
    );

    std::string day = line.substr(month_pos + 1);

    int y = std::atoi(year.c_str());
    int m = std::atoi(month.c_str());
    int d = std::atoi(day.c_str());

    if (y < 2009)
        return false;

    if (m < 1 || m > 12)
        return false;

    if (d < 1 || d > 31)
        return false;

    return true;
}

bool isValidRate(const std::string& line)
{   
    if(std::atof(line.c_str()) < 0 || std::atof(line.c_str()) > 1000)
        return false;
    return true;
}

bool isValidInput(char* input_file)
{
    std::ifstream file(input_file);

    if (!file.is_open())
    {
        std::cerr << "Error opening input file" << std::endl;
        return false;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (!isValidline(line))
        {
            std::cout << "Error: bad input => "
                    << line
                    << std::endl;
            continue;
        }
        std::stringstream ss(line);
        std::string date;
        std::string value;

        std::getline(ss, date, '|');
        std::getline(ss, value);

        if (!isValidDate(date))
            return false;

        if (!isValidRate(value))
            return false;
    }

    file.close();

    return true;
}