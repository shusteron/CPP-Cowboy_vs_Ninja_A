#include "Ninja.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;

Ninja Ninja::Ninja(){}

Ninja Ninja::Ninja(Point location, int hp, string name, int speed):Character(location,hp,name), speed(0){

}

void Ninja::move(Character* enemy){

}

void Ninja::slash(Character* enemy){
    
}
