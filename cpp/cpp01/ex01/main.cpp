#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string zombieName);

int main(void) {

    int n = 10;
    Zombie *horde = ZombieHorde(n, "ZzZz");

    for (int i = 0; i < n; i++)
        horde[i].announce();
    delete[] horde;
}