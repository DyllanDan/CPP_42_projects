/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:51:49 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:51:50 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string &name, Weapon& weapon)
    : name(name), weapon(&weapon) {}

void HumanA::attack(void) const
{
    std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}
