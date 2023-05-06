#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}


class Cowboy:  public Character{
    private:
        int bullets;

    public:
        Cowboy();
        Cowboy(Point location, int hp, string name, int bullets);
        void shoot(Character* enemy);
        bool hasBoolets();
        void reload();


};
#endif