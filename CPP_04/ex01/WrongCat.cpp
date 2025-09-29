#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    actionMessage("WrongCat", 0);
    name = "WrongCat";
    brain = new Brain();
}

WrongCat::~WrongCat()
{
    actionMessage("WrongCat", 4);
    delete brain;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    actionMessage("WrongCat", 2);
    name = other.name;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    actionMessage("WrongCat", 3);
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << name << ": " << "Côcóóó" << std::endl;
}
