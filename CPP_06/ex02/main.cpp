/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:15:47 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 11:32:56 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    std::srand(std::time(NULL));
    
    for (int i = 0; i < 10; i++)
    {
        Base* ptr = generate();
        std::cout << "Ptr: " << ptr << std::endl;
        identify(ptr);
        identify(*ptr);
        delete ptr;
        std::cout << "|------|" << std::endl;
    }
    D* d = new D;
    std::cout << "Ptr_D: " << d << std::endl;
    identify(d);
    identify(*d);
    delete d;
    return (0);
}