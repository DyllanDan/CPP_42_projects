#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack(void) const
{
    if (weapon)
        std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
    else
        std::cout << name << " doesn't hav a weapon to strike" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}