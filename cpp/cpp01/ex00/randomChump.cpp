#include "Zombie.hpp"

void randomChump(std::string const &zname) {

	Zombie z;

	z.setName(zname);
	z.announce();
}