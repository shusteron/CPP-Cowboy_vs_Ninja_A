#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdio.h>
#include <iostream>
#include "Point.hpp"

namespace ariel{}
using namespace std;

class Character{
    private:
        Point location;
        int hps; 
        string name;

    public:
        Character(string name, Point location);
        bool isAlive();
        double distance(Character* other_character);
        void hit(int dmg);
        string getName();
        Point getLocation();
        string print();   

};
#endif