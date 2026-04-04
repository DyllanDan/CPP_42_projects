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
    int value;

    std::stringstream ss(type);
    ss >> value;

    if (ss.fail() || ss.eof())
    {
        std::cout << "Char: impossível" << std::endl;
        return;
    }
    if (value < 32 || value > 255)
    {
        std::cout << "Char: sem visualização" << std::endl;
        return;
    }
    c = static_cast<char>(value);
    std::cout << "Char: " << c << std::endl;
}

static void intConverter(std::string type)
{
    return ;
}

static void floatConverter(std::string type)
{
    return ;
}

static void doubleConverter(std::string type)
{
    return ;
}

void ScalarConverter::Converter(std::string type)
{
    charConverter(type);
    //intConverter(type);
    //floatConverter(type);
    //doubleConverter(type);
}