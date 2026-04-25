/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:12:30 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 15:13:46 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array();
Array::~Array();
Array::Array(const Array& other);
Array& Array::operator=(const Array& other);

Array::Array(unsigned int i);
T& operator[](unsigned int i);
T const & operator[](unsigned int i) const;
unsigned int size() const;
        
