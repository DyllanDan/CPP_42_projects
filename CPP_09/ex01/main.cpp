/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 10:29:04 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 12:33:19 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isValidInput(char *input)
{
    int len = std::strlen(input);
    for(int i = 0; i < len; i++)
    {
        if (std::isdigit((unsigned char)input[i]) || input[i] == '+' || input[i] == '-' || \
            input[i] == '/' || input[i] == '*'|| input[i] == ' ')
        continue ;
        else
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }
    if(!isValidInput(argv[1]))
    {
        std::cout << "Only numerical or operators \'+-*/\' arguments" << std::endl;
            return 1;
    }
    try
    {
        RPN rpn;
        std::cout << rpn.calculator(argv[1]) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}