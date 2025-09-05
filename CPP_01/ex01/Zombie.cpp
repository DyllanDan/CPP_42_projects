/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:53:37 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:53:38 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    this->name = "";
}

Zombie::~Zombie(void)
{
    std::cout << name << ": IiiiirghH..." << std::endl;
    name = "";
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

void zombieDecay(Zombie* zombie)
{
    //(*zombie).~Zombie();
    delete zombie;
}
