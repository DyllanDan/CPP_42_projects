#include "Cat.hpp"

Cat::Cat()
{
    actionMessage("Cat", 0);
    name = "Cat";
    brain = new Brain();
}

Cat::~Cat()
{
    actionMessage("Cat", 4);
    delete brain;
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
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << name << ": " << "Miau miau..." << std::endl;
}
