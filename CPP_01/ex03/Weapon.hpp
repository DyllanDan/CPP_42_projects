#ifndef WEAPON_HPP

#define WAEPON_HPP
#include <iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string type);
        std::string getType(void) const;
        void setType(std::string);
};
#endif
