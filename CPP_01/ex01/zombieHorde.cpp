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