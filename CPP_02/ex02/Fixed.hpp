/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:13:26 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/13 16:09:19 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractional = 8;
	
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float floating);
		~Fixed();
		Fixed( const Fixed& other );
		Fixed& operator=(const Fixed& fixed);
		bool operator>(const Fixed& other ) const;
		bool operator<(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;
		Fixed operator+( const Fixed& other ) const;
		Fixed operator-( const Fixed& other ) const;
		Fixed operator*( const Fixed& other ) const;
		Fixed operator/( const Fixed& other ) const;
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed& min(Fixed& fixed_1, Fixed& fixed_2);
		static const Fixed& min(const Fixed& fixed_1, const Fixed& fixed_2);
		static Fixed& max(Fixed& fixed_1, Fixed& fixed_2);
		static const Fixed& max(const Fixed& fixed_1, const Fixed& fixed_2);
		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif
