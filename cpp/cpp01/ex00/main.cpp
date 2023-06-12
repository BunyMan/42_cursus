#include "Zombie.hpp"

Zombie *newZombie(std::string const &zombieName);

void    randomChump(std::string const &zombieName);

int main(void) {
    Zombie *nZombie;

    nZombie = newZombie("Hernesto");
    nZombie->announce();

    std::cout << "\n\n" ;

    randomChump("Another Zombie");

    delete nZombie;
}