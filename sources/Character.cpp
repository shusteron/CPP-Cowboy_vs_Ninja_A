#include "Character.hpp"
#include "Point.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

Character::Character(string name, Point location): location(location), name(name){

}

bool Character::isAlive(){
    return false;
}

double Character::distance(Character* other_character){
    return 0.0;
}

void Character::hit(int dmg){
    
}

string Character::getName(){
    return this->name;
}

Point Character::getLocation(){
    return Point(0,0);
}

string Character::print(){
    return "";
}

