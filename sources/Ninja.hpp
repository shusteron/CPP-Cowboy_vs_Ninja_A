#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel{}

class Ninja: public Character{
    private:
        int speed;

    public:
        Ninja();
        Ninja(Point location, int hp, string name, int speed);
        void move(Character* enemy);     
        void slash(Character* enemy);
};
#endif
