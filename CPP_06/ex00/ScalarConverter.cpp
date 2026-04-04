/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:03:16 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/04 18:14:42 by dydaniel         ###   ########.fr       */
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

    if (type.length() == 1 && std::isalpha(type[0]))
    {
        std::cout << "Char: " << type[0] << std::endl;
        return ;
    }
    std::stringstream ss(type);
    ss >> value;
    if (ss.fail())
    {
        std::cout << "Char: impossível" << std::endl;
        return;
    }
    if (value < 32 || value > 127)
    {
        std::cout << "Char: sem visualização" << std::endl;
        return;
    }
    c = static_cast<char>(value);
    std::cout << "Char: " << c << std::endl;
}

static void intConverter(std::string type)
{
    long value;

    std::stringstream ss(type);
    ss >> value;
    if (ss.fail())
    {
        std::cout << "Int: impossível" << std::endl;
        return;
    }
    if (value < INT_MIN || value > INT_MAX)
    {
        std::cout << "Int: impossível" << std::endl;
        return;
    }
    std::cout << "Int: " << value << std::endl;
    return ;
}
    
static void floatConverter(std::string type)
{
    float value;

    std::stringstream ss(type);
    ss >> value;
    if (ss.fail())
    {
        std::cout << "Int: impossível" << std::endl;
        return;
    }
    std::cout << "Float: " << value << "f" << std::endl;
    return ;
}

static void doubleConverter(std::string type)
{
    double value;

    std::stringstream ss(type);
    ss >> value;
    if (ss.fail())
    {
        std::cout << "Int: impossível" << std::endl;
        return ;
    }
    std::cout << "Double: " << value << std::endl;
    return ;
}

void ScalarConverter::Converter(std::string type)
{
    charConverter(type);
    intConverter(type);
    floatConverter(type);
    doubleConverter(type);
}