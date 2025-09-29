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

void WrongAnimal::makeSound() const
{
    std::cout << name << ": " << "*whooosh!!!!, as the wind blows*" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (name);
}

static void actionMessage(std::string name, int flag)
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
