#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(void);
        ~Zombie(void);
        void    setName(std::string const &zombieName);
        void    announce(void);
};

#endif