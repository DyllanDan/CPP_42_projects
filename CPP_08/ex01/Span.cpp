/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:01:25 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/09 15:10:00 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::~Span() {}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
         numbers = other.numbers;
         N = other.N;
    }
    return *this;
}
Span::Span(unsigned int N) : N(N) {}

void Span::addNumber(int n)
{
    if (numbers.size() >= N)
        throw std::runtime_error("Span: already full, cannot add more numbers");
    numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>& other)
{
    if (numbers.size() + other.size() > N)
        throw std::runtime_error("Span: not enough espace to add all numbers");
    numbers.insert(numbers.end(), other.begin(), other.end());
    
}

int Span::shortestSpan() const
{
    if (numbers.size() <= 1)
    {
        throw std::runtime_error("Span: not enough numbers to compare");
    }
    
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin() ,sorted.end());
    int min_diff = sorted[1] - sorted[0];
    for (std::size_t i = 1; i < sorted.size(); i++)
    {
        if (min_diff > sorted[i] - sorted[i - 1])
            min_diff = sorted[i] - sorted[i - 1];
    }
    return (min_diff);
}

int Span::longestSpan() const
{
    if (numbers.size() <= 1)
    {
        throw std::runtime_error("Span: not enough numbers to compare");
    }
    int min_num = *std::min_element(numbers.begin(), numbers.end());
    int max_num = *std::max_element(numbers.begin(), numbers.end());
    
    return (max_num - min_num);
}