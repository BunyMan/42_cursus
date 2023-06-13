#include "Zombie.hpp"

Zombie::Zombie(void) {
    return ;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie destructor called" << std::endl;
    return ;
}

void    Zombie::setName(std::string const &zombieName) {
    name = zombieName;
    return ;
}

void    Zombie::announce(void) {
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}