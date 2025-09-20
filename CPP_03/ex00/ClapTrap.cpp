/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:15:52 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/20 14:00:13 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "";
	hitPoints = 10;
    energyPoints = 10;
    atkDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
	hitPoints = 10;
    energyPoints = 10;
    atkDamage = 0;
}

ClapTrap::~ClapTrap(){}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	atkDamage = other.atkDamage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& fixed)
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

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0)
	std::cout << "ClapTrap " << name << " attacks " << " target " << target;
	std::cout << " causing " << atkDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
		this->hitPoints -= amount;
	if (hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << name << " receives " << amount << "of damage. Remaining health: ";
	std::cout << hitPoints << std::endl;	
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
		this->hitPoints += amount;
	else if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is defeated and cannot be repaired..." << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to repair itself." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " receives " << amount << "of damage. Remaining health: ";
	std::cout << hitPoints << std::endl;	
}