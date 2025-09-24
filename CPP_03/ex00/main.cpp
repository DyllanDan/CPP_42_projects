/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:40:58 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/23 20:45:15 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap vivified("Jorgin");
    ClapTrap shattered;
    ClapTrap ghost;
    
    shattered = ClapTrap(vivified);
    ghost = ClapTrap("Pedrin");
    
    std::cout << ""
    
    return (0);
}