/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:41:25 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/23 20:25:18 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t address;

    address = reinterpret_cast<uintptr_t>(ptr);
    return (address);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* address;

    address = reinterpret_cast<Data*>(raw);
    return (address);
}