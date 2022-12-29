#define CATCH_CONFIG_MAIN

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "catch.hpp"
#include <stdlib.h>
#include "C:/Technion/Semester3/DataStructuresWet2/worldcup23a2.h"

using namespace std;

static const char *StatusTypeStr[] =
        {
                "SUCCESS",
                "ALLOCATION_ERROR",
                "INVALID_INPUT",
                "FAILURE"};


TEST_CASE("Insert player")
{
    SECTION("simple add player")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("simple add goal keeper player")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("add player with negative id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(-1, 2, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative team id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, -2, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with invalid spirit")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::invalid(), 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative games")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), -3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 2, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with 0 team id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 0, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative cards")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), 3, 3, -3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with negative ability")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), 0, -5, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("add player with 0 ability")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), 0, 0, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        delete obj;
    }

    SECTION("add player with 0 id and 0 team id")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 0, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with many zeroes")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 2, permutation_t::neutral(), 0, 0, 0, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player with zero all")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(0, 0, permutation_t::neutral(), 0, 0, 0, true);
        REQUIRE(res == StatusType::INVALID_INPUT);
        delete obj;
    }

    SECTION("add player that exists")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add player with team that doesn't exist")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(4, 4, permutation_t::neutral(), 4, 4, 4, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add player to two different teams")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add existing player that has no team")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 2, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add player to removed team")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1, 1, permutation_t::neutral(), 3, 3, 3, true);
        REQUIRE(res == StatusType::FAILURE);
        delete obj;
    }

    SECTION("add teams and players - segel test from wet1")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(3);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(4);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1001, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1003, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1004, 1, permutation_t::neutral(), 10, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1005, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1006, 1, permutation_t::neutral(), 10, 4, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1007, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1008, 1, permutation_t::neutral(), 10, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1009, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1010, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1011, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1012, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(2001, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2003, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2004, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2005, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2006, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2007, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2008, 2, permutation_t::neutral(), 20, 6, 4, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2009, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2010, 2, permutation_t::neutral(), 0, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2011, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(3001, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3002, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3003, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3004, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3005, 3, permutation_t::neutral(), 30, 2, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3006, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3007, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3008, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3009, 3, permutation_t::neutral(), 30, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3010, 3, permutation_t::neutral(), 30, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3011, 3, permutation_t::neutral(), 30, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(4001, 4, permutation_t::neutral(), 2, 1, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(4002, 4, permutation_t::neutral(), 2, 2, 2, false);
        REQUIRE(res == StatusType::SUCCESS);

        delete obj;
    }

    SECTION("add teams and players with random team remove")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(3);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(4);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1001, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1003, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1004, 1, permutation_t::neutral(), 10, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1005, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1006, 1, permutation_t::neutral(), 10, 4, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1007, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1008, 1, permutation_t::neutral(), 10, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1009, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1010, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1011, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1012, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(2001, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2003, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2004, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2005, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2006, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2007, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2008, 2, permutation_t::neutral(), 20, 6, 4, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2009, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_team(3);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2010, 2, permutation_t::neutral(), 0, 0, 0, false);
        REQUIRE(res == StatusType::FAILURE);
        res = obj->add_player(2011, 2, permutation_t::neutral(), 20, 0, 0, false);
        REQUIRE(res == StatusType::FAILURE);

        res = obj->add_player(3001, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3002, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3003, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3004, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3005, 3, permutation_t::neutral(), 30, 2, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3006, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3007, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3008, 3, permutation_t::neutral(), 30, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3009, 3, permutation_t::neutral(), 30, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3010, 3, permutation_t::neutral(), 30, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(3011, 3, permutation_t::neutral(), 30, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_team(3);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(4001, 4, permutation_t::neutral(), 2, 1, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(4002, 4, permutation_t::neutral(), 2, 2, 2, false);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->remove_team(4);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(4001, 4, permutation_t::neutral(), 2, 1, 2, false);
        REQUIRE(res == StatusType::FAILURE);


        delete obj;
    }

    SECTION("add teams and players with random team remove")
    {
        world_cup_t *obj = new world_cup_t();
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1001, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1003, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1004, 1, permutation_t::neutral(), 10, 0, 2, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1005, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1006, 1, permutation_t::neutral(), 10, 4, 3, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->remove_team(1);
        REQUIRE(res == StatusType::FAILURE);
        res = obj->add_player(1007, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::FAILURE);
        res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1008, 1, permutation_t::neutral(), 10, 0, 0, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1009, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1010, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1011, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1012, 1, permutation_t::neutral(), 10, 0, 0, false);
        REQUIRE(res == StatusType::SUCCESS);

        delete obj;
    }
}

TEST_CASE("play_match")
{
    SECTION("simple play_match")
    {
        world_cup_t *obj = new world_cup_t();

        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);

        // first team players
        res = obj->add_player(1001, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, permutation_t::neutral(), 1, 50000, 1, true);
        REQUIRE(res == StatusType::SUCCESS);


        // second team players
        res = obj->add_player(2001, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2005, 2, permutation_t::neutral(), 1, 1, 1, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2011, 2, permutation_t::neutral(), 1, 1, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res1 = obj->play_match(1, 2);
        REQUIRE(res1.status() == StatusType::SUCCESS);
        REQUIRE(res1.ans() == 1);

        delete obj;
    }

    SECTION("play_match invalid input")
    {
        world_cup_t *obj = new world_cup_t();

        output_t<int> res1 = obj->play_match(0, 1);
        REQUIRE(res1.status() == StatusType::INVALID_INPUT);
        output_t<int> res2 = obj->play_match(1, 0);
        REQUIRE(res2.status() == StatusType::INVALID_INPUT);
        output_t<int> res3 = obj->play_match(0, 0);
        REQUIRE(res3.status() == StatusType::INVALID_INPUT);
        output_t<int> res4 = obj->play_match(3, 3);
        REQUIRE(res4.status() == StatusType::INVALID_INPUT);
        output_t<int> res5 = obj->play_match(-1, 1);
        REQUIRE(res5.status() == StatusType::INVALID_INPUT);
        output_t<int> res6 = obj->play_match(1, -1);
        REQUIRE(res6.status() == StatusType::INVALID_INPUT);
        output_t<int> res7 = obj->play_match(-1, -1);
        REQUIRE(res7.status() == StatusType::INVALID_INPUT);

        delete obj;
    }

    SECTION("play_match no goal keepers")
    {
        world_cup_t *obj = new world_cup_t();

        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);

        // first team players
        res = obj->add_player(1001, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);

        //second team players
        res = obj->add_player(2001, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2003, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);


        output_t<int> res1 = obj->play_match(1, 2);
        REQUIRE(res1.status() == StatusType::FAILURE);

        delete obj;
    }

    SECTION("play_match goal keepers only on one")
    {
        world_cup_t *obj = new world_cup_t();

        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);

        // first team players
        res = obj->add_player(1005, 1, permutation_t::neutral(), 1, 1, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        // second team players
        res = obj->add_player(2001, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);


        output_t<int> res1 = obj->play_match(1, 2);
        REQUIRE(res1.status() == StatusType::FAILURE);

        delete obj;
    }


    SECTION("play_match extra failure")
    {
        world_cup_t *obj = new world_cup_t();

        output_t<int> res1 = obj->play_match(1, 2);
        REQUIRE(res1.status() == StatusType::FAILURE);
        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res2 = obj->play_match(2, 1);
        REQUIRE(res2.status() == StatusType::FAILURE);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res3 = obj->play_match(1, 2);
        REQUIRE(res3.status() == StatusType::FAILURE);
        res = obj->add_player(1001, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1002, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2001, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2002, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res4 = obj->play_match(1, 2);
        REQUIRE(res4.status() == StatusType::FAILURE);
        res = obj->add_player(1003, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2003, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res5 = obj->play_match(1, 2);
        REQUIRE(res5.status() == StatusType::FAILURE);
        res = obj->add_player(1004, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1005, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1006, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2004, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2005, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2006, 2, permutation_t::neutral(), 1, 1, 1, true);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res6 = obj->play_match(1, 2);
        REQUIRE(res6.status() == StatusType::FAILURE);
        res = obj->add_player(1007, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1008, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1009, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1010, 1, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(1011, 1, permutation_t::neutral(), 1, 1, 1, true);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res7 = obj->play_match(1, 2);
        REQUIRE(res7.status() == StatusType::SUCCESS);
        res = obj->remove_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res8 = obj->play_match(1, 2);
        REQUIRE(res8.status() == StatusType::FAILURE);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);
        output_t<int> res9 = obj->play_match(1, 2);
        REQUIRE(res9.status() == StatusType::FAILURE);
        res = obj->add_player(2007, 2, permutation_t::neutral(), 1, 1, 1, false);
        REQUIRE(res == StatusType::FAILURE);

        delete obj;
    }

    SECTION("play_match success returns")
    {
        world_cup_t *obj = new world_cup_t();

        StatusType res = obj->add_team(1);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_team(2);
        REQUIRE(res == StatusType::SUCCESS);

        res = obj->add_player(1001, 1, permutation_t::neutral(), 1, 5, 1, true);
        REQUIRE(res == StatusType::SUCCESS);
        res = obj->add_player(2001, 2, permutation_t::neutral(), 1, 1, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res1 = obj->play_match(1, 2);
        REQUIRE(res1.status() == StatusType::SUCCESS);
        REQUIRE(res1.ans() == 1); // 5|1

        res = obj->add_player(2002, 2, permutation_t::neutral(), 1, 10, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res2 = obj->play_match(1, 2);
        REQUIRE(res2.status() == StatusType::SUCCESS);
        REQUIRE(res2.ans() == 3); // 8|11

        res = obj->add_player(1002, 1, permutation_t::neutral(), 1, 6, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res3 = obj->play_match(1, 2);
        REQUIRE(res3.status() == StatusType::SUCCESS);
        REQUIRE(res3.ans() == 0);// 11|11

        res = obj->add_player(1003, 1, permutation_t::neutral(), 1, 5, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res4 = obj->play_match(2, 1);
        REQUIRE(res4.status() == StatusType::SUCCESS);
        REQUIRE(res4.ans() == 3);// 12|17

        res = obj->add_player(2003, 2, permutation_t::neutral(), 1, 10, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res5 = obj->play_match(2, 1);
        REQUIRE(res5.status() == StatusType::SUCCESS);
        REQUIRE(res5.ans() == 1);// 22|20

        res = obj->add_player(1004, 1, permutation_t::neutral(), 1, 5, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res6 = obj->play_match(2, 1);
        REQUIRE(res6.status() == StatusType::SUCCESS);
        REQUIRE(res6.ans() == 0);// 25|25

        res = obj->add_player(1005, 1, permutation_t::read("2,3,4,5,1"), 1, 0, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res7 = obj->play_match(1, 2);
        REQUIRE(res7.status() == StatusType::SUCCESS);
        REQUIRE(res7.ans() == 4);// 26|26 -> str[45|55]


        res = obj->add_player(2004, 2, permutation_t::read("4,3,5,2,1"), 1, 3, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res8 = obj->play_match(1, 2);
        REQUIRE(res8.status() == StatusType::SUCCESS);
        REQUIRE(res8.ans() == 2);// 29|29 -> str[45|38]

        res = obj->add_player(1006, 1, permutation_t::read("4,3,5,2,1"), 1, 3, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res9 = obj->play_match(2, 1);
        REQUIRE(res9.status() == StatusType::SUCCESS);
        REQUIRE(res9.ans() == 0);// 32|32 -> str[38|38]

        res = obj->add_player(2005, 2, permutation_t::read("2,3,4,5,1"), 1, 0, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res10 = obj->play_match(2, 1);
        REQUIRE(res10.status() == StatusType::SUCCESS);
        REQUIRE(res10.ans() == 2);// 33|33 -> str[43|38]

        res = obj->add_player(1007, 1, permutation_t::read("5,4,1,3,2").inv(), 1, 3, 1, true);
        REQUIRE(res == StatusType::SUCCESS);

        output_t<int> res11 = obj->play_match(2, 1);
        REQUIRE(res11.status() == StatusType::SUCCESS);
        REQUIRE(res11.ans() == 4);// 36|36 -> str[43|55]


        delete obj;
    }
}