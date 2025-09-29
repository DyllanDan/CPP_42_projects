#include "Cat.hpp"

Cat::Cat()
{
    actionMessage("Cat", 0);
    name = "Cat";
}

Cat::~Cat()
{
    actionMessage("Cat", 4);
}

Cat::Cat(const Cat& other) : Animal(other)
{
    actionMessage("Cat", 2);
    name = other.name;
}

Cat& Cat::operator=(const Cat& other)
{
    actionMessage("Cat", 3);
    if (this != &other)
    {
        Animal::operator=(other);
        name = other.name;
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << name << ": " << "Miau miau..." << std::endl;
}
