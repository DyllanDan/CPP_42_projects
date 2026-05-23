/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:39:53 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 09:49:56 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        BitcoinExchange(const std::string& DBFile);

        void addDB(const std::string& file);

        float getRate(const std::string& date) const;
        void processInput(const std::string& file) const;
};

bool isValidline(const std::string& line);
bool isValidDate(const std::string& line);
bool isValidRate(const std::string& line);
bool isValidInput(char* input_file);

#endif