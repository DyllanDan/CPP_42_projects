#include "Animal.hpp"
#include "action.hpp"

Animal::Animal()
{
    actionMessage("Animal", 0);
    name = "A creature you don't know yet";
}

Animal::~Animal()
{
    actionMessage("Animal", 4);
}

Animal::Animal(const Animal& other)
{
    actionMessage("Animal", 2);
    name = other.name;
}

Animal& Animal::operator=(const Animal& other)
{
    actionMessage("Animal", 3);
    if (this != &other)
    {
        name = other.name;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (name);
}
