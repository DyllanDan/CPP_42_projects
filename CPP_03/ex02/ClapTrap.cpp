/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:15:52 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/27 13:39:58 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Deault ClapTrap Constructor called" << std::endl;
    name = "";
	hitPoints = 10;
    energyPoints = 10;
    atkDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name ClapTrap Constructor called" << std::endl;
    this->name = name;
	hitPoints = 10;
    energyPoints = 10;
    atkDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Desconstructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
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
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << " target " << target;
		std::cout << " causing " << atkDamage << " points of damage!" << std::endl;
	}
	else if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is defeated and cannot attack." << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << "has not enough energy to make an action." << std::endl;
		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already defeated." << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	if (hitPoints <= 0)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " was defeated." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " receives " << amount << " of damage. Remaining health: ";
	std::cout << hitPoints << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		this->hitPoints += amount;
		std::cout << "ClapTrap " << name << " was healed by " << amount << std::endl;
	}
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
}

int ClapTrap::getHitPoints(void) const
{
	return(hitPoints);
}

int ClapTrap::getAtkPoints(void) const
{
	return(atkDamage);
}

int ClapTrap::getEnergyPoints(void) const
{
	return(energyPoints);
}

std::string ClapTrap::getName(void) const
{
	return (name);
}

void ClapTrap::showStatus(void) const
{
	std::cout << "Current status:" << std::endl;
    std::cout << "HP: " << this->hitPoints << std::endl;
    std::cout << "Atk: " << this->atkDamage << std::endl;
    std::cout << "Energy: " << this->energyPoints << std::endl;
}

void ClapTrap::setAtk(int num)
{
	this->atkDamage = num;	
}

void ClapTrap::setHitPoints(int num)
{
	this->hitPoints = num;	
}

void ClapTrap::setEnergy(int num)
{
	this->energyPoints = num;	
}

void ClapTrap::setName(std::string name)
{
	this->name = name;	
}