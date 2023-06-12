#include "Zombie.hpp"

Zombie* newZombie(std::string const &zname){

	Zombie *z;

	z = new Zombie;
	z->setName(zname);
	return(z);
}