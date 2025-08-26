#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie* bited;

    bited = newZombie(name);
    (*bited).announce();
    zombieDecay(bited);
}