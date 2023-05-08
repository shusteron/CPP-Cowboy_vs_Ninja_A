#include "Cowboy.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;


Cowboy::Cowboy(string name, Point location): Character(name,location), bullets(6){
    
}

void Cowboy::shoot(Character* enemy){

}

bool Cowboy::hasBoolets(){
    return false;
}

void Cowboy::reload(){

}