#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
    public:
        Weapon(std::string const &n);
        ~Weapon(void);
        void    setType(std::string const &newType);
        std::string const &getType(void);
    private:
        std::string type;
};

#endif