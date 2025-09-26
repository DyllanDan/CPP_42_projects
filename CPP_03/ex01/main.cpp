/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:40:58 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/25 21:27:18 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap vivified("Jorgin");
    ClapTrap shattered;
    ScavTrap ghost;
    
    // shattered = ClapTrap(vivified);
    // ghost = ClapTrap("Pedrin");
    ghost.guardGate();
    ghost.showStatus();
    ghost.takeDamage(10);
    ghost.showStatus();
    // std::cout << ghost.getName() << " HP: " << ghost.getHitPoints() << std::endl;
    // shattered.attack("Pedrin");
    // ghost.takeDamage(1);
    // std::cout << ghost.getName() << " HP: " << ghost.getHitPoints() << std::endl;
    // ghost.beRepaired(1);
    // std::cout << ghost.getName() << " HP: " << ghost.getHitPoints() << std::endl;
    
    
    return (0);
}