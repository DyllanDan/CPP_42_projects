#include "Zombie.hpp"

void Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << name << ": IiiiirghH..." << std::endl;
    name = "";
}

void zombieDecay(Zombie* zombie)
{
    delete zombie;
}