#include "HumanB.hpp"

HumanB::HumanB(std::string const &n) {
    this->name = n;
    this->weapon = NULL;
    return ;
}

HumanB::~HumanB(void) {
    return ;
}

void    HumanB::setWeapon(Weapon &w) {
    this->weapon = &w;
    return ;
}

void    HumanB::attack(void) {
    if (this->weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " is pretty much fucked " << std::endl ;
    return ; 
}
