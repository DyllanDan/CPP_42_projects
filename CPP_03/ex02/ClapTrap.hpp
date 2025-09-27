/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:11:16 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/27 11:09:49 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int atkDamage;
    
    public:
    //Canonical
        ClapTrap(); // Constructor
        ~ClapTrap(); // Destructor
        ClapTrap(const ClapTrap& other); //Copy
		ClapTrap& operator=(const ClapTrap& fixed); //Overcharge =
        ClapTrap(std::string name); // Constructor with name
    //methods
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getHitPoints(void) const;
        int getAtkPoints(void) const;
        int getEnergyPoints(void) const;
        virtual void showStatus(void) const;
        void setName(std::string name);
        void setHitPoints(int num);
        void setAtk(int num);
        void setEnergy(int num);
        virtual std::string getName(void) const;
};

#endif