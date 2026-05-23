/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 10:25:58 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 12:27:23 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN(){}

RPN::RPN(const RPN& other) : _stack(other._stack) {};

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

int RPN::calculator(const std::string& input)
{
    while (!_stack.empty())
        _stack.pop();
    std::stringstream ss(input);
    std::string token;
    while(ss >> token)
    {
        if (token.size() == 1 && (token[0] >= '0' && token[0] <= '9'))
                _stack.push(token[0] - '0');
        else if(token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '/' || \
        token[0] == '*'))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int num2 = _stack.top();
            _stack.pop();
            int num1 = _stack.top();
            _stack.pop();
            if (token[0] == '+')
                _stack.push(num1 + num2);
            if (token[0] == '-')
                _stack.push(num1 - num2);
            if (token[0] == '*')
                _stack.push(num1 * num2);
            if (token[0] == '/')
            {
                if (num2 == 0)
                    throw std::runtime_error("Error: division by zero.");
                _stack.push(num1 / num2);
            }
        }
        else
            throw std::runtime_error("Error");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return _stack.top();
}

