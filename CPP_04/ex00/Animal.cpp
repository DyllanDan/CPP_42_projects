#include "Animal.hpp"

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

void Animal::makeSound() const
{
    std::cout << name << ": " << "a sound yet unknown." << std::endl;
}

std::string Animal::getType() const
{
    return (name);
}

void actionMessage(std::string name, int flag)
{
    if (flag == 0)
        std::cout << name << " Default Constructor called";
    else if (flag == 1)
        std::cout << name << " Own constructor called";
    else if (flag == 2)
        std::cout << name << " Copy constructor called";
    else if (flag == 3)
        std::cout << name << " Overcharge assign  called";
    else if (flag == 4)
        std::cout << name << " Destructor called";
    std::cout << std::endl;
}