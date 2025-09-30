#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void)
{
    Animal *a = new Dog();
    Animal *b;
    const Animal* pets[20];
    const WrongAnimal* wrongPets[20];

    a->makeSound();
    b = a;
    b->makeSound();
    for(int i = 0; i < 20; i++)
    {
        std::cout << "\033[33m" <<"Creating ANIMAL number: " << i << std::endl;
        std::cout << "\033[33m" <<"-------------------------" << std::endl;
        if (i % 2 == 0)
        {
            pets[i] = new Dog();
            pets[i]->makeSound();
        }
        else
        {
            pets[i] = new Cat();
            pets[i]->makeSound();
        }
    }
    std::cout << "End of Creation of Animals" << std::endl;
    for(int i = 0; i < 20; i++)
    {
        std::cout << "Creating WRONGANIMAL number: " << i << std::endl;
        std::cout << "-------------------------" << std::endl;
        if (i % 2 == 1)
        {
            wrongPets[i] = new WrongDog();
            wrongPets[i]->makeSound();
        }
        else
        {
            wrongPets[i] = new WrongCat();
            wrongPets[i]->makeSound();
        }
        std::cout << "Creation Completed"<< std::endl;
        std::cout << "-------------------------" << std::endl;
    }
    std::cout << "End of Creation of WrongAnimals" << std::endl;

    for (int i = 0; i < 20; i++)
    {
        std::cout << "Deleting ANIMAL number: " << i << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Bye bye" << std::endl;
        pets[i]->makeSound();
        delete pets[i];
    }

    for (int i = 0; i < 20; i++)
    {
        std::cout << "Deleting WRONGANIMAL number: " << i << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Bye bye" << std::endl;
        wrongPets[i]->makeSound();
        delete wrongPets[i];
        std::cout << "End of deletion"<< std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}