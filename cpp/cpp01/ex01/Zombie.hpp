#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie(void);
        ~Zombie(void);
        void    setName(std::string const &zombieName);
        void    announce(void);
    
    private:
        std::string name;
};

#endif
