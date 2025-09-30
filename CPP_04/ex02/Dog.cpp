#include "Dog.hpp"

Dog::Dog() 
{
    actionMessage("Dog", 0);
    name = "Dog";
    brain = new Brain();
}


Dog::~Dog()
{
    actionMessage("Dog", 4);
    delete brain;
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
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << name << ": " << "Au au!" << std::endl;
}
