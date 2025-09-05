/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:53:16 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:53:17 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string quote;
    std::string* stringPTR;
    std::string& stringREF = quote;

    quote = "HI THIS IS BRAIN";
    stringPTR = &quote;

    std::cout<< "Memory address of the string variable: " << (&quote) << std::endl;
    std::cout<< "Memory address held by stringPTR: " << (&stringPTR) << std::endl;
    std::cout<< "Memory address memory address held by stringREF: " << (&stringREF) << std::endl;

    std::cout<< "The value of the string variable: " << quote << std::endl;
    std::cout<< "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout<< "The value pointed to by stringREF: " << stringREF << std::endl;
}
