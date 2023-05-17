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

Point Character::getLocation() const{
    return Point(0,0);
}

string Character::print(){
    return "blabla";
}

bool Character::isHasTeam(){
    return false;
}

void Character::setHasTeam(bool flag){

}

// To pass tidy methods:
// Copy constuctor.
Character :: Character(const Character& other) : name(other.name), location(other.location), hps(other.hps), team_flag(other.team_flag){}
    // name = other.name;
    // location = Point(other.getLocation().getX(), other.getLocation().getY());
    // hps= other.hps;
    // team_flag = other.team_flag;
// }

// Copy assigment operator (=).
Character& Character::operator=(const Character& other){
    if(this == &other){
        return *this;
    }
    name = other.name;
    location = Point(other.getLocation().getX(), other.getLocation().getY());
    hps= other.hps;
    team_flag = other.team_flag;

    return *this;
}

//Move assigment operator (=).
Character& Character :: operator=(Character&& other) noexcept{
    name = other.name;
    other.name = nullptr;
    location = Point(other.getLocation().getX(), other.getLocation().getY());
    hps = other.hps;
    team_flag = other.team_flag;

    return *this;
}

// Move
Character:: Character(Character&& other) noexcept : location(other.location){
    name=other.name;
    other.name = nullptr;
    // location = Point(other.getLocation().getX(), other.getLocation().getY());
    hps = other.hps;
    team_flag = other.team_flag;
}


