#include "WrongDog.hpp"

WrongDog::WrongDog() 
{
    actionMessage("WrongDog", 0);
    name = "WrongDog";
    brain = new Brain();
}

WrongDog::~WrongDog()
{
    actionMessage("WrongDog", 4);
    delete brain;
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
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void WrongDog::makeSound() const
{
    std::cout << name << ": " << "Khiiiw Khiwww!" << std::endl;
}
