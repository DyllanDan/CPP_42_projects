/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:13:20 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/13 16:07:12 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const int number)
{
	this->fixedPoint = number << fractional;
}

Fixed::Fixed(const float floating)
{
	this->fixedPoint = roundf(floating * (1 << fractional));
}

Fixed::Fixed(const Fixed& fixed)
{
	fixedPoint = fixed.fixedPoint;
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
	{
		this->fixedPoint = fixed.getRawBits();
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

int Fixed::toInt(void) const
{
	return (fixedPoint >> fractional);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPoint) / (1 << fractional));
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->fixedPoint > fixed.fixedPoint);
}


bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->fixedPoint < fixed.fixedPoint);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed aux;
	
	aux.fixedPoint = this->fixedPoint + fixed.fixedPoint;
	return (aux);	
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed aux;
	
	aux.fixedPoint = this->fixedPoint - fixed.fixedPoint;
	return (aux);	
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed aux;
	
	aux.fixedPoint = this->fixedPoint * fixed.fixedPoint;
	return (aux);	
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed aux;
	
    aux.fixedPoint = (this->fixedPoint << fractional) / fixed.fixedPoint;
    return aux;
}

Fixed& Fixed::operator++()
{
	this->fixedPoint += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->fixedPoint -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed aux(*this);
	
	this->fixedPoint += 1;
	return (aux);
}

Fixed Fixed::operator--(int)
{
	Fixed aux(*this);
	
	this->fixedPoint -= 1;
	return (aux);
}

Fixed& Fixed::min( Fixed& a, Fixed& b )
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b )
{
    return (a < b ? a : b);
}

Fixed& Fixed::max( Fixed& a, Fixed& b )
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b )
{
    return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}