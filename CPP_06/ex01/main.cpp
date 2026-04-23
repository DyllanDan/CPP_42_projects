/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:58:33 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/23 20:27:31 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void printValues(Data data, int i)
{
    std::cout << i << "_name: " << data.name <<std::endl;
    std::cout << i << "_int: " << data.i_value <<std::endl;
    std::cout << i << "_char: " << data.c_value <<std::endl;
    std::cout << i << "_float: " << data.f_value <<std::endl;
    std::cout << i << "_double: " << data.d_value <<std::endl;
}


int main(void)
{
    Data origin;
    Data other;
    uintptr_t medium;
    
    origin.name = "Alpha";
    origin.i_value = 1;
    origin.c_value = 'a';
    origin.d_value = 1;
    origin.f_value = 1.f;
    
    medium = Serializer::serialize(&origin);
    other = Serializer::deserialize(medium);

    printValues(origin, 1);
    printValues(other, 2);

    std::cout << "origin& :" << &origin << std::endl;
    std::cout << "other& :" << &other << std::endl;
    return 0;
}