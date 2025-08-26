#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* bited;

    bited = new Zombie(name);
    return (bited);
}