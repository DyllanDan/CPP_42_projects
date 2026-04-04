/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:12:27 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/04 17:45:05 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::string type;
    
    if (argc != 2)
    {
        std::cout << "Insert one argument" << std::endl;
        return (1);
    }
    type = static_cast<std::string>(argv[1]);
    ScalarConverter::Converter(type);
    return (0);    
}