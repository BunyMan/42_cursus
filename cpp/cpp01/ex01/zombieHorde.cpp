#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string zombieName) {
    Zombie *horde;

    horde = new Zombie[N];
    for (int n = 0; n < N; n++)
        horde[n].setName(zombieName);
    return (horde);
}