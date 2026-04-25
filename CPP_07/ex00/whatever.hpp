/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:48:39 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 12:12:54 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}

template<typename T>
T min(const T &first, const T &second)
{
    if (second > first)
        return first;
    return second;
}

template<typename T>
T max(const T &first, const T &second)
{
    if (second < first)
        return first;
    return second;
}

#endif