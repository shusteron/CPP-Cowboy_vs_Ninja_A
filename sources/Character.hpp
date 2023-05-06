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
        int hp; //Hit points.
        string name;

    public:
        virtual bool isAlive() const=0;
        virtual double distance(Character* other_character)const=0;
        void hit(int dmg);
        string getName();
        virtual Point getLocation()const=0;
        void print();   

};
#endif