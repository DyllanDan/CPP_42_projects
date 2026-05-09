/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:49:28 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/09 15:06:19 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
    
    public:
        Span();
        ~Span();
        Span(const Span &other);
        Span& operator=(const Span &other);
        Span(unsigned int N);
        
        void addNumber(int n); //add a sigle number
        void addNumbers(std::vector<int>& numbers); //add a group of numbers
        int shortestSpan() const;
        int longestSpan() const;
        void setSize(unsigned int N);
};

#endif