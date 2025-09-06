/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:18:29 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/06 13:18:31 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "[ Harl is complaining about not having anything to complain ]" << std::endl;
        return (0);
    }
    else
    {
        harl.complain(argv[1]);
    }
    return (0);
}
