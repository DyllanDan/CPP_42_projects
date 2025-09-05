/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:53:44 by dydaniel          #+#    #+#             */
/*   Updated: 2025/09/04 20:53:46 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie();
        ~Zombie(void);
        void set_name(std::string name);
        void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);
void hordeDecay(Zombie* horde);

#endif
