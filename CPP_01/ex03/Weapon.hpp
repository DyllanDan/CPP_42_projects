/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:52:45 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:52:47 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP
#include <iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string type);
        std::string getType(void) const;
        void setType(std::string);
};
#endif
