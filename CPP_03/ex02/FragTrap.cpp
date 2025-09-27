/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 11:37:42 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/27 13:39:26 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Deault ScavTrap Constructor called" << std::endl;
    setHitPoints(100);
    setEnergy(100);
    setAtk(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name Constructor called" << std::endl;
    setName(name);
    setHitPoints(100);
    setEnergy(100);
    setAtk(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Desconstructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	setName(other.getName());
	setHitPoints(other.getHitPoints());
	setEnergy(other.getEnergyPoints());
	setAtk(other.getAtkPoints());
}

FragTrap& FragTrap::operator=(const FragTrap& fixed)
{
	std::cout << "FragTrap override= called" << std::endl;
	if (this != &fixed)
	{
		ClapTrap::operator=(fixed);
	}
	return (*this);
}

void FragTrap::setValue(int& class_att, int value)
{
    class_att = value;
}

void FragTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "FragTrap " << getName() << " attacks " << " target " << target;
		std::cout << " causing " << getAtkPoints() << " points of damage!" << std::endl;
	}
	else if (getHitPoints() == 0)
	{
		std::cout << "FragTrap " << getName() << "is defeated and cannot attack." << std::endl;
		return ;
	}
	else if (getEnergyPoints() == 0)
	{
		std::cout << "FragTrap " << getName() << "has not enough energy to make an action." << std::endl;
		return ;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "HighFive ma'friend" << std::endl;
	std::cout << "    .-." << std::endl;
	std::cout << "  .-| |-." << std::endl;
	std::cout << "  | | | |" << std::endl;
	std::cout << "  | | | |-." << std::endl;
	std::cout << "  | | | | |" << std::endl;
	std::cout << "  |_|_|_| |" << std::endl;
	std::cout << " / )    `-|" << std::endl;
	std::cout << "| | `--   |" << std::endl;
	std::cout << "|     ||  |" << std::endl;
	std::cout << "\\    '   /" << std::endl;
	std::cout << " |       |" << std::endl;
	std::cout << " |       |" << std::endl;
}