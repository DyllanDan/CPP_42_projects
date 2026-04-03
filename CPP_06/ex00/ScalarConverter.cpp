/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:03:16 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/03 18:03:17 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

static void charConverter(std::string type)
{
    char c;
    if (type.length() == 1)
        c = type[0];
    else if
    {
        int value = std::stoi(type)
        if (value >= 32 && value <= 255)
        {
            c = static_cast<char>(value);
        }
        else
        {
            
        }
    }
}

static void intConverter(std::string type)
{
    
}

static void floatConverter(std::string type)
{
    
}

static void doubleConverter(std::string type)
{
    
}

void ScalarConverter::Converter(std::string type)
{
    charConverter(type);
    intConverter(type);
    floatConverter(type);
    doubleConverter(type);
}