/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:15:47 by dydaniel          #+#    #+#             */
/*   Updated: 2026/04/25 11:22:07 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Esab.hpp"

int main(void)
{
    std::srand(std::time(NULL));
    
    for (i = 0; i < 10; i++)
    {
        Base* ptr = generate();
        std::cout << "Ptr: " << ptr << std::endl;
        identify(ptr);
        identify(*ptr);
        delete ptr;
        std::cout << "|------|" << std::endl;
    }
    Esab *rtp = new Esab();
    identify(rtp);
    identify(*rtp);
    delete rtp;
    return (0);
}