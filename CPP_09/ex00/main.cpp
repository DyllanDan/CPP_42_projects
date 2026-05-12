/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:59:44 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/12 19:20:51 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Not enough arguments - ./btc argument" << std::endl;
        return ;
    }
    
    if (!isValidInput(argv[1]))
    {
        std::cout << "Incorrect document informations" << std::endl;
    }
    
}

bool isValidline(line)
{
    
    for (size_t = 0; i < line.size(); i++)
    {
        if (!((line[i] >= '0' && line[i] <= '9') || line[i] == '-' || line[i] == ','))
            return false;
    }
    std::string day;
    std::string month;
    std::string year;
    

}

bool isValidInput(char* file)
{
    std::ifstream file(file);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error at open databank" << std::endl;
        return ;
    }
    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        
        if (!isValidline(line))
            return false;
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