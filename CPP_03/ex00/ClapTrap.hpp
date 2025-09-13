/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:11:16 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/13 18:18:44 by dydaniel         ###   ########.fr       */
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
        ClapTrap();
        ~ClapTrap();
        ClapTrap( const ClapTrap& other );
		ClapTrap& operator=(const ClapTrap& fixed);
    //methods
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif