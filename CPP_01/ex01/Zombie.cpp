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