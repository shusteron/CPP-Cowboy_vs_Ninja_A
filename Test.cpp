#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include "Point.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "doctest.h"

TEST_CASE("Basic initialization"){
    Point a(32.3,44),b(1.3,3.5),c(1,1),d(-3.14,-10), f(-1,-1);
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *sasuke = new YoungNinja("sasuke",c);
    TrainedNinja *itachi = new TrainedNinja("itachi",d);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team(sasuke);
    
    //Cowboy
    CHECK(tom->getName()=="Tom");
    CHECK(tom->getLocation().distance(a)==0);
    CHECK(tom->isAlive() == true);
    CHECK(tom->hasBoolets() == true);
    //YoungNinja
    CHECK(sasuke->getName() == "sasuke");
    CHECK(sasuke->getLocation().distance(c)==0);
    CHECK(sasuke->isAlive() == true);
    //TrainedNinja
    CHECK(itachi->getName() == "itachi");
    CHECK(itachi->getLocation().distance(d) == 0);
    CHECK(itachi->isAlive() == true);
    //OldNinja
    CHECK(sushi->getName() == "shusi");
    CHECK(sushi->getLocation().distance(d) == 0);
    CHECK(sushi->isAlive() == true);
    //Team
    CHECK(team.stillAlive() == 1);
}

TEST_CASE("Distance measuring"){
    Point a(32.3,44),b(1.3,3.5),c(1,1),d(-3.14,-10), f(-1,-1);
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *sasuke = new YoungNinja("sasuke",c);
    TrainedNinja *itachi = new TrainedNinja("itachi",d);
    OldNinja *sushi = new OldNinja("sushi", b);

    double dest1 = tom->distance(sasuke);
    double dest2 = sasuke->distance(tom);
    
    CHECK(dest1 == dest2);
    CHECK(itachi->distance(sushi) == 14.21);
    CHECK(a.distance(f) == 55.98);
    CHECK(f.distance(f) == 0);
}

TEST_CASE("Attack"){
    Point a(32.3,44),b(1.3,3.5),c(0,0),d(-3.14,-10);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *tony = new Cowboy("Tony", a);
    Cowboy *bob1 = new Cowboy("Bob1", a);
    Cowboy *bob2 = new Cowboy("Bob2", a);

    YoungNinja *sasuke = new YoungNinja("sasuke",c);
    TrainedNinja *itachi = new TrainedNinja("itachi",c);
    TrainedNinja *jiraya = new TrainedNinja("itachi",c);
    OldNinja *sushi = new OldNinja("sushi", c);

    SUBCASE("Cowboy"){
        // When cowboy has no bullets-> shooting someone shouldn't make any damage.
        for(int i=0; i<6; i++)
            bob1->shoot(bob2);
        CHECK(bob1->hasBoolets() == false);  
        // Bob1 trying to shoot but he has no bullets.
        for(int i=0; i<10; i++)
            bob1->shoot(bob2);
        CHECK(bob2->isAlive());    

        // We already know that cowboy create with 110 hp.
        tom->shoot(tony);
        CHECK(tony->isAlive());

        // Now, "tony" has 100 hps
        for(int i=0; i < 10; i++){
            if(tom->hasBoolets())
                tom->shoot(tony);
            else{
                CHECK(tom->hasBoolets() == false);
                tom->reload();
            }
        }
        // Now "tony" should be dead and "tom" still has bullets.
        CHECK(tony->isAlive() == false);
        CHECK_THROWS(tony->reload());
        CHECK(tom->hasBoolets());
        // Trying to attack dead enemy.
        CHECK_THROWS(tom->shoot(tony));
        // Dead character is trying to attack.
        CHECK_THROWS(tony->shoot(tom));
    }

    SUBCASE("Ninja"){
        // Attempt to attack when distance too long. 
        itachi->slash(tom);
        sushi->slash(tom);
        sasuke->slash(tom);

        CHECK(tom->isAlive());

        // Attempt to attack when distance <= 1
        while(itachi->isAlive())
            sasuke->slash(itachi);

        while(sushi->isAlive())
            jiraya->slash(sushi);

        // Dead characters trying to attack / attempt to attack dead characters.
        CHECK(itachi->isAlive() == false);
        CHECK(sushi->isAlive() == false);

        CHECK_THROWS(itachi->slash(sasuke));
        CHECK_THROWS(sushi->slash(jiraya));

        CHECK_THROWS(sasuke->slash(itachi));
        CHECK_THROWS(jiraya->slash(itachi));
        CHECK_THROWS(jiraya->slash(sushi));
    }
}

TEST_CASE("Team"){
    Point a(32.3,44),b(1.3,3.5),c(0,0),d(-3.14,-10);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *tony = new Cowboy("Tony", a);
    Cowboy *bob1 = new Cowboy("Bob1", a);



    YoungNinja *sasuke = new YoungNinja("sasuke",c);
    YoungNinja *shinobi1 = new YoungNinja("shinobi1",a);
    YoungNinja *shinobi2 = new YoungNinja("shinobi2",a);

    TrainedNinja *itachi = new TrainedNinja("itachi",c);
    TrainedNinja *jiraya = new TrainedNinja("jiraya",c);
    OldNinja *sushi = new OldNinja("sushi", c);

    Team team1(sasuke);
    Team team2(itachi);

    // Same leader to different team.
    CHECK_THROWS(Team(sasuke));

    // Check if stillAlive() updates correctly.
    for(int i = 1 ;i < 10; i++){
        Cowboy *bob = new Cowboy("Bob", a);
        team1.add(bob);
        CHECK(team1.stillAlive() == i+1);
    }

    // Trying to add more than 10 characters to a team.
    CHECK_THROWS(team1.add(jiraya));

    // Same character to different team.
    CHECK_THROWS(team2.add(sasuke));
    CHECK_THROWS(team2.add(bob1));

    SUBCASE("Team Attack"){
        team2.add(shinobi1);
        team2.add(shinobi2);

        // team1 has 10 members while team2 has 3 members
        team1.attack(&team2);
        CHECK(((team1.stillAlive() && !team2.stillAlive()) || (!team1.stillAlive() && team2.stillAlive())));

    }

    SUBCASE("Team2 Attack"){
        // Same as Team but Team2 is according in order of addition.
        Cowboy *shalom = new Cowboy("shalom", a);
        OldNinja *obito = new OldNinja("obito", c);

        Team2 t1(shalom);
        Team2 t2(obito);

        for(int i=0; i<2; i++){
            Cowboy *shalom = new Cowboy("shalom", a);
            YoungNinja *shi = new YoungNinja("shi",a);
            t1.add(shalom);
            t1.add(shi);
        }

        for(int i=0; i<2;i++){
            TrainedNinja *jiraya = new TrainedNinja("jiraya",c);
            OldNinja *sushi = new OldNinja("sushi", c);
            Cowboy *beri = new Cowboy("beri", a);
            t2.add(jiraya);
            t2.add(sushi);
            t2.add(beri);
        }

        t1.attack(&t2);
        CHECK(((t1.stillAlive() && !t2.stillAlive()) || (!t1.stillAlive() && t2.stillAlive())));

    }
}

TEST_CASE("Move() & MoveTowards()"){
    Point a(2,2),b(1.3,3.5),c(1,1),d(-3.14,-10), f(-1,-1);
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *sasuke = new YoungNinja("sasuke",c);
    TrainedNinja *itachi = new TrainedNinja("itachi",c);
    OldNinja *sushi = new OldNinja("sushi", f);

    SUBCASE("Move"){
        sasuke->move(itachi);
        CHECK(sasuke->getLocation().getX() == itachi->getLocation().getX());
        CHECK(sasuke->getLocation().getY() == itachi->getLocation().getY());

        // When the other character is close enough to reach.
        sushi->move(tom); // The distance between them is 4.24, sushi's speed is 8.
        CHECK(sushi->getLocation().getX() == tom->getLocation().getX());
        CHECK(sushi->getLocation().getY() == tom->getLocation().getY());
    }

    SUBCASE("MoveTowards"){
        // If the ditance is greater then the goal, the goal value should return.
        Point result = Point::moveTowards(a,f,5);
        CHECK(result.getX() == f.getX());
        CHECK(result.getY() == f.getY());

        // Distance cannot be negative value.
        CHECK_THROWS(Point::moveTowards(a,f,-1));

        // If te distance is less then the distance between the points, the result should be closer to the goal.
        result = Point::moveTowards(a,f,2);
        CHECK(result.distance(f) < a.distance(f));
    }
}