/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 10:07:06 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/23 11:28:13 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <stack>
# include <string>
# include <cstring>
# include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> _stack;
    
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        
        int calculator(const std::string& input);
};
#endif