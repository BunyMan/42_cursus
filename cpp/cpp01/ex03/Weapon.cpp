#include "Weapon.hpp"

Weapon::Weapon(std::string const &n) {
    type = n;
    return ;
}

Weapon::~Weapon(void) {
    return ;
}

void    Weapon::setType(std::string const &newType) {
    type = newType;
    return ;
}

std::string const &Weapon::getType(void) {
    return (type);
}