/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:53:55 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:53:57 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i;
    Zombie* horde;

    horde = new Zombie[N];

    i = 0;
    while (i < N)
    {
        horde[i].set_name(name);
        horde[i].announce();
        i++;
    }
    return (horde);
}

void hordeDecay(Zombie* horde)
{
        delete [] horde;
}
