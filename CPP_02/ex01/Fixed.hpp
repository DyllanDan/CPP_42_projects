/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:13:26 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/06 16:43:03 by dydaniel         ###   ########.fr       */
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
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;	
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif
