#include "Zombie.hpp"

int main(void)
{
    Zombie* horde;
    int N;

    N = 10;
    horde = zombieHorde(N, "Biezum");
    hordeDecay(horde);
}