/**
 * @file test_RuleOfExistence_Conway.cpp
 * @autor Sebastian Strindlund
 * @brief Tests derived class RuleOfExistence_Erik constructor and memberfunction.
*/
#include "catch.hpp"
#include "../include/Support/FileLoader.h"
#include "../include/Cell_Culture/Cell.h"
#include "../include/Support/Globals.h"
#include "../include/Support/SupportStructures.h"
#include "../include/GoL_Rules/RuleOfExistence_Erik.h"
#include "../include/Cell_Culture/Population.h"
#include "../Terminal/Terminal.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


TEST_CASE("The RuleOfExistence_Erik constructor.") {
    SECTION("Checking for correct values.") {
        std::map<Point, Cell> cells;
        FileLoader loader;
        fileName = "TEST_Population_Seed.txt";
        loader.loadPopulationFromFile(cells);
        RuleOfExistence_Erik erik(cells);

        // Rulename & populationlimits
        REQUIRE(erik.getRuleName() == "erik");
        REQUIRE(erik.getPopulationLimits().UNDERPOPULATION == 2);
        REQUIRE(erik.getPopulationLimits().OVERPOPULATION == 3);
        REQUIRE(erik.getPopulationLimits().RESURRECTION == 3);


        vector<Directions> vec_expected{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 },{ 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } }; //Expected directions
        vector<Directions> vec_actual = erik.getDirections(); // Actual directions


        vector<Directions>::iterator i, j;
        for(auto expected = vec_expected.begin(), actual = vec_actual.begin(); expected != vec_expected.end(); ++actual, ++expected) // Loops thru both maps and compares their values
        {
            REQUIRE(expected->HORIZONTAL == actual->HORIZONTAL);
            REQUIRE(expected->VERTICAL == actual->VERTICAL);
        }
    }


}


TEST_CASE("Execute Erik rule. Next generation should be as expected after cell states are updated") {
    std::map<Point, Cell> cells;
    FileLoader loader;
    fileName = "TEST_Population_Seed.txt";
    loader.loadPopulationFromFile(cells);
    RuleOfExistence_Erik erik(cells); //gen1

    std::map<Point, Cell> cellsgen2;
    fileName = "TEST_Population_Seed_Gen2Erik.txt";
    loader.loadPopulationFromFile(cellsgen2); // Expected gen2

    erik.executeRule(); // EXECUTES Erik RULE on gen1

    for(auto actual = cells.begin(), expected = cellsgen2.begin(); actual != cells.end(); ++actual, ++expected) // Loops thru both maps and compares their values
    {
        actual->second.updateState();
        REQUIRE(actual->second.isAlive() == expected->second.isAlive());
    }


}

TEST_CASE("Does cells update as expected when rule is executed?") {
    std::map<Point, Cell> cells;
    FileLoader loader;
    fileName = "TEST_Population_Seed_2x2map.txt";
    loader.loadPopulationFromFile(cells);
    RuleOfExistence_Erik erik(cells); //gen1

    //0,0,0,0
    //0,1,1,0  (1,1) (1,2)
    //0,1,1,0  (2,2) (2,3)
    //0,0,0,0
    SECTION("Two cells at same AGE goes from 10 to 11. Since they are the same age NONE of them should be primeElder.") {
      // Sets two cells to be 10.
      for(int i = 0; i < 9; i++) {
         erik.executeRule();
         cells[Point{2,2}].updateState();
         cells[Point{2,1}].updateState();
       }

       erik.executeRule();

       cells[Point{2,1}].updateState();
       cells[Point{2,2}].updateState();


       // Both should be 11, just 'E' and not primeElder.
       REQUIRE((cells[Point{2,1}].getAge()) == 11);
       REQUIRE((cells[Point{2,2}].getAge()) == 11);

       REQUIRE((cells[Point{2,1}].getCellValue()) == 'E');
       REQUIRE((cells[Point{2,2}].getCellValue()) == 'E');


      REQUIRE((cells[Point{2,2}].getColor()) == COLOR::CYAN);
      REQUIRE((cells[Point{2,1}].getColor()) == COLOR::CYAN);
    }

    SECTION("If older cell dies the other cell that is atleast 11 should become PRIME") {
      // Sets one cell to 11 and other to 10
      for(int i = 0; i < 10; i++) {
         erik.executeRule();
         cells[Point{1,1}].updateState();

         if (cells[Point{1,2}].getAge() < 10) {
           cells[Point{1,2}].updateState();
        }
      }

       // Older Cell should now Be a primeElder
       REQUIRE((cells[Point{1,1}].getColor()) == COLOR::MAGENTA);
       REQUIRE((cells[Point{1,2}].getColor()) == COLOR::CYAN);

       // Older Cell dies
       cells[Point{1,1}].setNextGenerationAction(KILL_CELL);
       cells[Point{1,1}].updateState();
       REQUIRE((cells[Point{1,1}].getAge()) == 0);


       erik.executeRule();
       cells[Point{1,2}].updateState();

       // Since Older Cell died this cell should now be primeElder
       REQUIRE((cells[Point{1,2}].getAge()) == 11);
       REQUIRE((cells[Point{1,2}].getColor()) == COLOR::MAGENTA);

    }

    SECTION("Age behaviour") {

      // Sets the 3 of cells to desired ages for testing rule.
       for(int i = 0; i < 9; i++) {
          erik.executeRule();
          cells[Point{2,2}].updateState();

          if (cells[Point{1,1}].getAge() < 5) {
              cells[Point{1,1}].updateState();
          }
          if (cells[Point{2,1}].getAge() < 9) {
              cells[Point{2,1}].updateState();
          }

      }

      SECTION(" Cells below age 6 should behave correctly") {
        // Should be white and '#' Since its less than 6
        REQUIRE((cells[Point{1,1}].isAlive()));                           // Must be alive
        REQUIRE((cells[Point{1,1}].getAge()) == 5);                      // Must be 5 years old
        REQUIRE((cells[Point{1,1}].getCellValue()) == '#');              // Must be '#' (not very old)
        REQUIRE_FALSE((cells[Point{1,1}].getColor()) == COLOR::CYAN);    // Must not be cyan since its not 6 yet.


      }

      SECTION(" Cells ages from 5 to 6 should behave correctly") {
        erik.executeRule();
        cells[Point{1,1}].updateState();
        // Should now be six and have a new color
        REQUIRE((cells[Point{1,1}].isAlive()));                    // Must be alive
        REQUIRE((cells[Point{1,1}].getAge()) == 6);                // Must be 6 years old
        REQUIRE((cells[Point{1,1}].getCellValue()) == '#');        // Must be '#' (not very old)
        REQUIRE((cells[Point{1,1}].getColor()) == COLOR::CYAN);    // Must be cyan for somewhat old

        SECTION(" Cells ages from 6 to 7 should behave correctly") {

          erik.executeRule();
          cells[Point{1,1}].updateState();
          // Should now be 7 and still have same color
          REQUIRE((cells[Point{1,1}].isAlive()));                    // Must be alive
          REQUIRE((cells[Point{1,1}].getAge()) == 7);                // Must be 7 years old
          REQUIRE((cells[Point{1,1}].getCellValue()) == '#');        // Must be '#' (not very old)
          REQUIRE((cells[Point{1,1}].getColor()) == COLOR::CYAN);    // Must be cyan for somewhat old

        }

      }

      SECTION(" Cells BETWEEN 6-10 should behave correctly") {
        erik.executeRule();
        cells[Point{2,1}].updateState();
        // Should now be 10 years old and not 'E'
        REQUIRE((cells[Point{2,1}].isAlive()));                    // Must be alive
        REQUIRE((cells[Point{2,1}].getAge()) == 10);               // Must be 10 years old
        REQUIRE_FALSE((cells[Point{2,1}].getCellValue()) == 'E');  // Must NOT have 'E' (very old)
        REQUIRE((cells[Point{2,1}].getColor()) == COLOR::CYAN);    // Must be cyan for somewhat old
      }

    SECTION(" Cells ages from 10 to 11 should behave correctly") {
      erik.executeRule();
      cells[Point{2,2}].updateState();
      //Should now be 11 hence char 'E' and prime color.
      REQUIRE((cells[Point{2,2}].isAlive()));                    // Must be alive
      REQUIRE((cells[Point{2,2}].getAge()) == 11);               // Must be 11 years old
      REQUIRE((cells[Point{2,2}].getCellValue()) == 'E');        // Must be 'E' (very old)
      REQUIRE((cells[Point{2,2}].getColor()) == COLOR::MAGENTA); // Must be MAGENTA (PRIME ELDER)

      SECTION("  Prime ages to 12 and should still be prime & Another cell ages from 10 to 11 and should be 'E' but NOT a primeElder") {
        erik.executeRule();
        cells[Point{2,2}].updateState(); // Prime ages to 12
        cells[Point{2,1}].updateState(); // Cell goes from 9 to 10

        erik.executeRule();
        cells[Point{2,1}].updateState(); // Cell goes from 10 to 11


        //Should now be 11 years old and Aquire 'E'
        REQUIRE((cells[Point{2,1}].isAlive()));                    // Must be alive
        REQUIRE((cells[Point{2,1}].getAge()) == 11);               // Must be 11 years old
        REQUIRE((cells[Point{2,1}].getCellValue()) == 'E');        // Must be 'E' (very old)
        REQUIRE_FALSE((cells[Point{2,1}].getColor()) == COLOR::MAGENTA); // Must NOT BE PRIME ELDER (MAGENTA)

        REQUIRE((cells[Point{2,2}].isAlive()));                    // Must be alive
        REQUIRE((cells[Point{2,2}].getAge()) == 12);               // Must be 12 years old
        REQUIRE((cells[Point{2,2}].getCellValue()) == 'E');        // Must be 'E' (very old)
        REQUIRE((cells[Point{2,2}].getColor()) == COLOR::MAGENTA); // Must still be MAGENTA (PRIME ELDER)
      }
    }
  }
}
