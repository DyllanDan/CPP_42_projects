/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:01:25 by dydaniel          #+#    #+#             */
/*   Updated: 2026/05/05 21:02:03 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span();
~Span();
Span& Span(const Span &other);
Span& operator=(const Span &other);

void addNumber(int n);
void addNumbers(std::vector<int>& numbers);
int shortestSpan() const;
int longestSpan() const;