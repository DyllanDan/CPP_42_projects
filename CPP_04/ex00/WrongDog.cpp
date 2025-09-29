#include "WrongDog.hpp"

WrongDog::WrongDog() 
{
    actionMessage("WrongDog", 0);
    name = "WrongDog";
}


WrongDog::~WrongDog()
{
    actionMessage("WrongDog", 4);
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
    actionMessage("WrongDog", 2);
    name = other.name;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
    actionMessage("WrongDog", 3);
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        name = other.name;
    }
    return (*this);
}

void WrongDog::makeSound() const
{
    std::cout << name << ": " << "Khiiiw Khiwww!" << std::endl;
}
