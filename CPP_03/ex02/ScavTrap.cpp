/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:58:20 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/27 13:40:29 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Deault ScavTrap Constructor called" << std::endl;
    setHitPoints(100);
    setEnergy(50);
    setAtk(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Name Constructor called" << std::endl;
    setName(name);
    setHitPoints(100);
    setEnergy(50);
    setAtk(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Desconstructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergy(other.getEnergyPoints());
	setAtk(other.getAtkPoints());
}

ScavTrap& ScavTrap::operator=(const ScavTrap& fixed)
{
	std::cout << "ScavTrap override= called" << std::endl;
	if (this != &fixed)
	{
		ClapTrap::operator=(fixed);
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << " target " << target;
		std::cout << " causing " << getAtkPoints() << " points of damage!" << std::endl;
	}
	else if (getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is defeated and cannot attack." << std::endl;
		return ;
	}
	else if (getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << "has not enough energy to make an action." << std::endl;
		return ;
	}
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->getName() << " is now on GATE KEEPER mode." << std::endl;
}

void ScavTrap::setValue(int& class_att, int value)
{
    class_att = value;
}

void ScavTrap::showStatus(void) const
{
    std::cout << "Current status:" << std::endl;
    std::cout << "HP: " << this->getHitPoints() << std::endl;
    std::cout << "Atk: " << this->getAtkPoints() << std::endl;
    std::cout << "Energy: " << this->getEnergyPoints() << std::endl;
}
