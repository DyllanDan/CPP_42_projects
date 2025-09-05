/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:54:23 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:54:24 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* zombone;

    zombone = newZombie("Zumzum");

    (*zombone).announce();
    randomChump("Biebie");

    zombieDecay(zombone);
}
