/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:40:58 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/27 13:35:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void fight(ScavTrap& fighter1, ScavTrap& fighter2)
{
    FragTrap kikki("Kikki");
    
    for(int i = 0; i < 5; i++)
    {
        std::cout << "_________________Round " << i << std::endl;
        fighter1.attack(fighter2.getName());
        fighter2.takeDamage(fighter1.getAtkPoints());
        fighter2.attack(fighter1.getName());
        fighter1.takeDamage(fighter2.getAtkPoints());
        fighter2.beRepaired(5);
    }
    fighter1.attack(fighter2.getName());
    fighter2.takeDamage(fighter1.getAtkPoints());
    fighter2.attack(fighter1.getName());
    fighter1.takeDamage(fighter2.getAtkPoints());
    fighter2.beRepaired(5);
    std::cout << "_____FragTrap has stepped in_____" << std::endl;
    kikki.highFivesGuys();
    kikki.attack(fighter2.getName());
    fighter2.takeDamage(kikki.getAtkPoints());
}

int main(void)
{
    ClapTrap vivified("Jorgin");
    ScavTrap shattered(vivified.getName());
    ScavTrap ghost;
    
    std::cout << "----Construction Complete----" << std::endl;
    ghost.setName("Mishi");
    ghost.guardGate();
    ghost.showStatus();
    std::cout << "----Fight iniciated----" << std::endl;
    fight(shattered, ghost);
    std::cout << "----Fight ended----" << std::endl;
    std::cout << "----Show status----" << std::endl;
    ghost.showStatus();
    std::cout << "----Second part----" << std::endl;
    shattered.beRepaired(1);
    shattered.attack("Pedrin");
    ghost.takeDamage(1);
    ghost.showStatus();
    shattered.beRepaired(1);
    
    return (0);
}