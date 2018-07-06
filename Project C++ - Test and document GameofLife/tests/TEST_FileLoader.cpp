/**
 * @file test_RuleOfExistence_Conway.cpp
 * @autor Sebastian Strindlund
 * @brief Tests alot of stuff.
*/
#include "catch.hpp"
#include "../include/Support/FileLoader.h"
#include "../include/Cell_Culture/Cell.h"
#include "../include/Support/Globals.h"
#include "../include/Support/SupportStructures.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>




using namespace std;

// If file does not exist
TEST_CASE( "Tries to load file that dont exist. Must throw ios_base::failure " ) {

    std::map<Point, Cell> cells;
    FileLoader loader;
    fileName = "notexisting.txt"; //Filename that does not exist

    REQUIRE_THROWS(loader.loadPopulationFromFile(cells));
    CHECK_THROWS_AS(loader.loadPopulationFromFile(cells), std::ios_base::failure);
}




// File exists and is corret
TEST_CASE( "Loads file with correct data and compares created map to expected result"){

    std::map<Point, Cell> cells;
    FileLoader loader;
    fileName = "TEST_Population_Seed.txt"; //Filename exists

    REQUIRE_NOTHROW(loader.loadPopulationFromFile(cells));

    SECTION("Map should be as expected") {
        // Expected map of cells that was read from file. Accounts for rim-cells
        int cordinates[12][22] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1,1,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0},
            {0,0,1,1,1,0,0,0,1,0,1,0,0,1,1,0,0,1,1,0,0,0},
            {0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0},
            {0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0},
            {0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,0},
            {0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0},
            {0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,1,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        };

        string actual;
        string expected;

        for (auto t : cells) {
            actual += t.second.isAlive() ? "1" : "0"; // Ads 1 or 0 to string acording to file
            expected += to_string(cordinates[t.first.y][t.first.x]); // Ads 1 or 0 to string from array

        }

        REQUIRE(expected == actual); // Expected string should match the predefined.

    }
}


TEST_CASE("File with bad data should not be accepted, Exception should be thrown") {


    std::map<Point, Cell> cells;
    FileLoader bad_data_loader;
    fileName = "bad_data.txt"; //Filename with bad data

    REQUIRE_THROWS(bad_data_loader.loadPopulationFromFile(cells));




}
