#include "catch.hpp"
#include "../include/Cell_Culture/Population.h"
#include <iostream>


using namespace std;

TEST_CASE("Check that the populations generations counter works") {

    Population population;
    population.initiatePopulation("conway");

    SECTION("Check that generation starts at 0") {

        REQUIRE(population.getGeneration()==0);

    }
    SECTION("Check that generation increments when calling calculateNewGeneration") {

        REQUIRE(population.calculateNewGeneration()==1);
        REQUIRE(population.getGeneration()==1);
    }

}
TEST_CASE("Check that the correct amount of cells are returned from getTotalCellPopulation") {

    fileName="TEST_Population_Seed.txt";
    Population population;
    population.initiatePopulation("conway");

    SECTION("Check that nr of cells returned equals to 200") {

        REQUIRE(population.getTotalCellPopulation()==264);

    }

    fileName.clear();
    WORLD_DIMENSIONS.HEIGHT=30;
    WORLD_DIMENSIONS.WIDTH=30;
    Population population2;
    population2.initiatePopulation("conway");
    SECTION("Check that nr of cells returned equals to 900") {

        REQUIRE(population2.getTotalCellPopulation()==1024);
    }

}

TEST_CASE("Check that getCellAtPosition returns a cell when map/population has been initialised") {

    fileName="TEST_Population_Seed.txt";
    Population population;
    population.initiatePopulation("conway");


    SECTION("Check that it returns a cell") {

        REQUIRE(population.getCellAtPosition(Point{0,0}).getAge()==0);

    }
    SECTION("Check that it returns the right cell compared to file") {

        SECTION("Check that it returns an alive cell") {

            REQUIRE(population.getCellAtPosition(Point{3,3}).isAlive());

        }
        SECTION("Check that it returns a dead cell") {

            REQUIRE_FALSE(population.getCellAtPosition(Point{1,2}).isAlive());

        }

    }


}

TEST_CASE("Check odd and even rule") {

    fileName="TEST_Population_Seed_2x2map.txt";
    Population population;
    population.initiatePopulation("conway", "von_neumann");
    population.calculateNewGeneration();

    population.getCellAtPosition(Point{1,1}).setNextGenerationAction(KILL_CELL);
    population.getCellAtPosition(Point{1,1}).updateState();
    REQUIRE(population.getGeneration()==1);


    //now our map looks like:
    //R = 0 (rimcell)

    //R,R,R,R
    //R,0,1,R // that cell has 3 alive neighbours and should be ressurected.
    //R,1,1,R
    //R,R,R,R



    SECTION("Check that odd rule is executed") {
        REQUIRE(population.getGeneration()==1);
        population.calculateNewGeneration();  // Here odd rule should be used which is set to von_neumann and since it only counts cardinal neighbours the {1,1} cell will just have 2 neighbours and not ressurect.
        REQUIRE(population.getGeneration()==2);
        population.getCellAtPosition(Point{1,1}).updateState(); // Updates state since its not updated until calculateNewGeneration() is run.
        REQUIRE_FALSE(population.getCellAtPosition(Point{1,1}).isAlive());

    }

    SECTION("Check that even rule is executed") {
        population.calculateNewGeneration();

        // Updates cells to clear weird rule shit to set up for what we want to test.
        population.getCellAtPosition(Point{1,2}).updateState();
        population.getCellAtPosition(Point{2,1}).updateState();
        population.getCellAtPosition(Point{2,2}).updateState();

        population.getCellAtPosition(Point{1,2}).setNextGenerationAction(GIVE_CELL_LIFE);
        population.getCellAtPosition(Point{2,1}).setNextGenerationAction(GIVE_CELL_LIFE);
        population.getCellAtPosition(Point{2,2}).setNextGenerationAction(GIVE_CELL_LIFE);

        // Now still setting up the map as we want for our test.
        population.getCellAtPosition(Point{1,2}).updateState();
        population.getCellAtPosition(Point{2,1}).updateState();
        population.getCellAtPosition(Point{2,2}).updateState();


        REQUIRE(population.getGeneration()==2);
        REQUIRE_FALSE(population.getCellAtPosition(Point{1,1}).isAlive());

        population.calculateNewGeneration(); // here even rule should be applied which is conway. Since conway counts neighbours in all directions it will have == 3 neighbours and ressurect
        population.getCellAtPosition(Point{1,1}).updateState();
        REQUIRE(population.getCellAtPosition(Point{1,1}).isAlive());


    }


}

TEST_CASE("If filename is supplied buildCellCultureFromFile() should be called and correct dimensions should be applied.") {

    fileName="TEST_Population_Seed_2x2map.txt";
    Population population;
    population.initiatePopulation("conway");

    REQUIRE(WORLD_DIMENSIONS.HEIGHT ==2);
    REQUIRE(WORLD_DIMENSIONS.WIDTH ==2);


}


TEST_CASE("If filename is not supplied randomizeCellCulture() should be called and correct dimensions should be applied.") {
    fileName.clear();
    Dimensions WORLD_DIMENSIONS = { 80, 24 }; // SETS IT BACK TO INItIAL VALUE
    Population population;
    population.initiatePopulation("conway");

    REQUIRE(WORLD_DIMENSIONS.HEIGHT == 24);
    REQUIRE(WORLD_DIMENSIONS.WIDTH == 80);


}


