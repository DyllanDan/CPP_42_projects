#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "action.hpp"

class Animal
{
    protected:
        std::string name;
        Animal();

    public:
        virtual ~Animal() = 0;
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual void makeSound(void) const = 0;
        std::string getType() const;
};

#endif