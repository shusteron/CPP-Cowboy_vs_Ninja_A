#include "Cowboy.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

Cowboy::Cowboy(){}

Cowboy::Cowboy(Point location, int hp, string name, int bullets): Character(location, hp, name), bullets(6){
    
}

void Cowboy::shoot(Character* enemy){

}

bool Cowboy::hasBoolets(){

}

void Cowboy::reload(){

}