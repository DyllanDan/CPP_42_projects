#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include "action.hpp"

class WrongAnimal
{
    protected:
        std::string name;
        WrongAnimal();

    public:
        virtual ~WrongAnimal() = 0;
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual void makeSound(void) const = 0;
        std::string getType() const;
};

#endif
