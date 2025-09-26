/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:58:20 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/25 21:36:48 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Deault ScavTrap Constructor called" << std::endl;
    this->name = "";
    hitPoints = 100;
    energyPoints = 50;
    atkDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Name Constructor called" << std::endl;
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    atkDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Desconstructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	atkDamage = other.atkDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& fixed)
{
	if (this != &fixed)
	{
		this->name = fixed.name;
		this->hitPoints = fixed.hitPoints;
		this->energyPoints = fixed.energyPoints;
		this->atkDamage = fixed.atkDamage;
	}
	return (*this);
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now on GATE KEEPER mode." << std::endl;
}

void ScavTrap::setValue(int& class_att, int value)
{
    class_att = value;
}

void ScavTrap::showStatus(void) const
{
    std::cout << "Current status:" << std::endl;
    std::cout << "HP: " << this->hitPoints << std::endl;
    std::cout << "Atk: " << this->atkDamage << std::endl;
    std::cout << "Energy: " << this->energyPoints << std::endl;
}