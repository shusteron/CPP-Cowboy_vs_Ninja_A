#ifndef TEAM_HPP
#define TEAM_HPP
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>


namespace ariel{}

class Team{
    private:
        vector<Character*> team;
        Character* leader;

    public:
        Team(Character* leader);
        void add(Character* character);
        void attack(Team* enemy_team);
        int stillAlive();
        void print();   
        // To pass tidy:

        // Destructor.
        virtual ~Team();
        // Copy constuctor.
        Team(Team& other);
        // Copy assigment opertor ( = ).
        Team& operator=(const Team& other);
        // Move operator.
        Team& operator=(Team&& other) noexcept;
        // Move
        Team(Team&& other) noexcept;
};
#endif