#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string const &n, Weapon &w);
        ~HumanA(void);
        void    attack(void);

    private:
        std::string name;
        Weapon *weapon;
};

#endif