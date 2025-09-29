#include "Dog.hpp"

Dog::Dog() 
{
    actionMessage("Dog", 0);
    name = "Dog";
}


Dog::~Dog()
{
    actionMessage("Dog", 4);
}

Dog::Dog(const Dog& other) : Animal(other)
{
    actionMessage("Dog", 2);
    name = other.name;
}

Dog& Dog::operator=(const Dog& other)
{
    actionMessage("Dog", 3);
    if (this != &other)
    {
        Animal::operator=(other);
        name = other.name;
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << name << ": " << "Au au!" << std::endl;
}
