#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    actionMessage("WrongAnimal", 0);
    name = "Plant";
}

WrongAnimal::~WrongAnimal()
{
    actionMessage("WrongAnimal", 4);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    actionMessage("WrongAnimal", 2);
    name = other.name;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    actionMessage("WrongAnimal", 3);
    if (this != &other)
    {
        name = other.name;
    }
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (name);
}
