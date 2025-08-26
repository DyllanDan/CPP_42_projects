#include "Zombie.hpp"

int main(void)
{
    Zombie* zombone;

    zombone = newZombie("Zumzum");

    (*zombone).announce();
    randomChump("Biebie");

    zombieDecay(zombone);
}