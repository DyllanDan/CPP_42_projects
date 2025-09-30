#include "action.hpp"

inline void actionMessage(std::string name, int flag)
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