/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:21:14 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 14:30:13 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


void print(const int& x)
{
    std::cout << x << " ";
}

void increment(int& x)
{
    x++;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;

    std::cout << "Original: ";
    iter(arr, len, print);
    std::cout << std::endl;

    std::cout << "Incrementing...\n";
    iter(arr, len, increment);

    std::cout << "After increment: ";
    iter(arr, len, print);
    std::cout << std::endl;

    return 0;
}