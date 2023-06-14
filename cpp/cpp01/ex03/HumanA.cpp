#include "HumanA.hpp"

HumanA::HumanA(std::string const &n, Weapon &w) {
    name = n;
    weapon = &w;
    return ;
}

HumanA::~HumanA(void) {
    return ;
}

void    HumanA::attack(void) {
    std::cout << name << " atacked with " << weapon->getType() << std::endl;
}