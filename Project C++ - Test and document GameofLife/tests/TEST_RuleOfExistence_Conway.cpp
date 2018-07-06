/**
 * @file test_RuleOfExistence_Conway.cpp
 * @autor Sebastian Strindlund
 * @brief Tests derived class RuleOfExistence_Conway constructor and memberfunction.
*/
#include "catch.hpp"
#include "../include/Support/FileLoader.h"
#include "../include/Cell_Culture/Cell.h"
#include "../include/Support/Globals.h"
#include "../include/Support/SupportStructures.h"
#include "../include/GoL_Rules/RuleOfExistence_Conway.h"
#include "../include/Cell_Culture/Population.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


TEST_CASE("The RuleOfExistence_Conway constructor.") {
    SECTION("Checking for correct values.") {
        std::map<Point, Cell> cells;
        FileLoader loader;
        fileName = "TEST_Population_Seed.txt";
        loader.loadPopulationFromFile(cells);
        RuleOfExistence_Conway conway(cells);

        // Rulename & populationlimits
        REQUIRE(conway.getRuleName() == "conway");
        REQUIRE(conway.getPopulationLimits().UNDERPOPULATION == 2);
        REQUIRE(conway.getPopulationLimits().OVERPOPULATION == 3);
        REQUIRE(conway.getPopulationLimits().RESURRECTION == 3);


        vector<Directions> expected{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 },{ 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } }; //Expected directions
        vector<Directions> actual = conway.getDirections(); // Actual directions


        vector<Directions>::iterator i, j;
        for(i = expected.begin(), j = actual.begin(); i != expected.end(); ++i, ++j) // Loops thru both maps and compares their values
        {
            REQUIRE(i->HORIZONTAL == j->HORIZONTAL);
            REQUIRE(i->VERTICAL == j->VERTICAL);
        }
    }


}


TEST_CASE("Execute conway rule. Next generation should be as expected after cell states are updated") {
    std::map<Point, Cell> cells;
    FileLoader loader;
    fileName = "TEST_Population_Seed.txt";
    loader.loadPopulationFromFile(cells);
    RuleOfExistence_Conway conway(cells); //gen1

    std::map<Point, Cell> cellsgen2;
    fileName = "TEST_Population_Seed_Gen2_Conway.txt";
    loader.loadPopulationFromFile(cellsgen2); // Expected gen2

    conway.executeRule(); // EXECUTES CONWAYS RULE on gen1

    map<Point,Cell>::iterator i, j;
    for(i = cells.begin(), j = cellsgen2.begin(); i != cells.end(); ++i, ++j) // Loops thru both maps and compares their values
    {
        i->second.updateState();
        REQUIRE(i->second.isAlive() == j->second.isAlive());
    }
}
