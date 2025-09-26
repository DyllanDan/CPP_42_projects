/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:48:13 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/25 21:35:10 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    //Canonical
        ScavTrap(); // Constructor
        ~ScavTrap(); // Destructor
        ScavTrap(const ScavTrap& other); //Copy
		ScavTrap& operator=(const ScavTrap& fixed); //Overcharge =
        ScavTrap(std::string name); // Constructor with name
    //methods
        void guardGate();
        void setValue(int& class_att, int value);
        void showStatus(void) const;
};

#endif