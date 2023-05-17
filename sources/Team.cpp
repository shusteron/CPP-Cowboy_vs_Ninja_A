#include "Team.hpp"
#include <stdio.h>
#include <iostream>

namespace ariel{}
using namespace std;


Team::Team(Character* leader): leader(leader){
    this->team.push_back(leader);
}

void Team::add(Character* character){

}

void Team::attack(Team* enemy_team){

}

int Team::stillAlive(){
    return 0;
}

void Team::print(){

}

Team::~Team(){
    for (Character* character : team) {
        delete character;
    }
    // Clear the team vector
    team.clear();
}

// To pass tidy methods:

// Copy constuctor.
Team::Team(Team& other){
    team = other.team;
    leader = other.leader;
}

// Copy assigment operator (=).
Team& Team::operator=(const Team& other){
    if(this == &other){
        return *this;
    }
    team = other.team;
    leader = other.leader;

    return *this;
}

//Move assigment operator (=).
Team& Team::operator=(Team&& other) noexcept{
    team = other.team;
    leader = other.leader;

    return *this;
}

// Move
Team::Team(Team&& other) noexcept{
    team = other.team;
    leader = other.leader;
}
