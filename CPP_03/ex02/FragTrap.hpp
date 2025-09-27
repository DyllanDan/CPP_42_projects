/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 11:30:59 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/27 13:34:08 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
        public:
    //Canonical
        FragTrap(); // Constructor
        ~FragTrap(); // Destructor
        FragTrap(const FragTrap& other); //Copy
		FragTrap& operator=(const FragTrap& fixed); //Overcharge =
        FragTrap(std::string name); // Constructor with name
    //methods
        void highFivesGuys(void);
        void attack(const std::string& target);
        void setValue(int& class_att, int value);
};

#endif