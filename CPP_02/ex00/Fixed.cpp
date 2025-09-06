/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:13:20 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/06 16:41:59 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	this->fixedPoint = fixed.fixedPoint;
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
	{
		this->fixedPoint = fixed.fixedPoint;
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}
