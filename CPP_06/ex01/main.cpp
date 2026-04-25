/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:58:33 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 10:46:44 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void printValues(Data data, std::string who)
{
    std::cout << who << "_name: " << data.name <<std::endl;
    std::cout << who << "_int: " << data.i_value <<std::endl;
    std::cout << who << "_char: " << data.c_value <<std::endl;
    std::cout << who << "_float: " << data.f_value <<std::endl;
    std::cout << who << "_double: " << data.d_value <<std::endl;
}


int main(void)
{
    Data origin;
    
    origin.name = "Alpha";
    origin.i_value = 1;
    origin.c_value = 'a';
    origin.d_value = 1;
    origin.f_value = 1.f;
    
    uintptr_t  medium = Serializer::serialize(&origin);
    Data *other = Serializer::deserialize(medium);

    printValues(origin, "origin");
    std::cout << "|---------------|" << std::endl;
    printValues(*other, "other");

    std::cout << "origin& :" << &origin << std::endl;
    std::cout << "other& :" << other << std::endl;

    return 0;
}