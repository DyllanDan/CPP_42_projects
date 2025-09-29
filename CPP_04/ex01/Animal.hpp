#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string name;

    public:
        Animal();
        ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual void makeSound(void) const;
        std::string getType() const;
};

void actionMessage(std::string name, int flag);
#endif