#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongDog : public WrongAnimal
{
    private:
        Brain* brain;
    public:
        WrongDog();
        ~WrongDog();
        WrongDog(const WrongDog& other);
        WrongDog& operator=(const WrongDog& other);
        void makeSound() const;
};
#endif
