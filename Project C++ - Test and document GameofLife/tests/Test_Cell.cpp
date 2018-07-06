#include "catch.hpp"
#include "../include/Cell_Culture/Cell.h"

TEST_CASE("Check that a default cell uses default values") {
    Cell cell;

    SECTION("Check that cell is not a rim cell") {
        REQUIRE_FALSE(cell.isRimCell());
    }
    SECTION("Check that cells next action is DO_NOTHING") {
        REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
    }
    SECTION("Check that cells state color is DEAD") {
        REQUIRE(cell.getColor()==STATE_COLORS.DEAD);
    }
    SECTION("Check that cells age is 0") {
        REQUIRE(cell.getAge()==0);
    }
    SECTION("Check that cells value is #") {
        REQUIRE(cell.getCellValue()=='#');
    }
}

TEST_CASE("Check that a cell uses correct values") {
    Cell cell(false, GIVE_CELL_LIFE);

    SECTION("Check that cell is not a rim cell") {
        REQUIRE_FALSE(cell.isRimCell());
    }
    SECTION("Check that cells next action is DO_NOTHING") {
        REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
    }
    SECTION("Check that cells state color is LIVING") {
        REQUIRE(cell.getColor()==STATE_COLORS.LIVING);
    }
    SECTION("Check that cells age is 1") {
        REQUIRE(cell.getAge()==1);
    }
    SECTION("Check that cells value is #") {
        REQUIRE(cell.getCellValue()=='#');
    }
    SECTION("Check that cell is alive") {
        REQUIRE(cell.isAlive());
    }
}

TEST_CASE("Check that a cell uses correct values based on a few different constructors") {
    Cell cell(false, GIVE_CELL_LIFE);

    SECTION("Check that cell is not a rim cell") {
        REQUIRE_FALSE(cell.isRimCell());
    }
    SECTION("Check that cell is alive") {
        REQUIRE(cell.isAlive());
    }

    cell = new Cell(true);
    SECTION("Check that cell is a rim cell") {
        REQUIRE(cell.isRimCell());
    }
    SECTION("Check that cell is not alive") {
        REQUIRE_FALSE(cell.isAlive());
    }
    SECTION("Check that cells age is 0") {
        REQUIRE(cell.getAge()==0);
    }
}


TEST_CASE("Check that a cells get and set functions and such work") {
    Cell cell;

    SECTION("Check setNextGenerationAction") {
        REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
        cell.setNextGenerationAction(GIVE_CELL_LIFE);
        REQUIRE(cell.getNextGenerationAction()==GIVE_CELL_LIFE);
    }
    SECTION("Check setIsAliveNext") {
        cell.setIsAliveNext(true);
        REQUIRE(cell.isAliveNext());
        cell.setIsAliveNext(false);
        REQUIRE_FALSE(cell.isAliveNext());
    }
}


TEST_CASE("Check cell cells get and set functions and such work with update state") {

    Cell cell;

    SECTION("Check setNextGenerationAction with updatestate") {

        SECTION("Check GIVE_CELL_LIFE") {
            cell.setNextGenerationAction(GIVE_CELL_LIFE);
            cell.updateState();
            REQUIRE(cell.getAge() == 1);
            REQUIRE(cell.isAlive());
            REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
        }

        SECTION("Check IGNORE_CELL from dead cell") {
            cell.setNextGenerationAction(IGNORE_CELL);
            cell.updateState();
            REQUIRE(cell.getAge() == 0);
            REQUIRE_FALSE(cell.isAlive());
            REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
        }

        SECTION("Check IGNORE_CELL from alive cell") {
            cell.setNextGenerationAction(GIVE_CELL_LIFE);
            cell.updateState();
            cell.setNextGenerationAction(IGNORE_CELL);
            cell.updateState();
            REQUIRE(cell.getAge() == 2);
            REQUIRE(cell.isAlive());
            REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
        }

        SECTION("Check KILL_CELL") {
            cell.setNextGenerationAction(KILL_CELL);
            cell.updateState();
            REQUIRE(cell.getAge() == 0);
            REQUIRE_FALSE(cell.isAlive());
            REQUIRE(cell.getNextGenerationAction()==DO_NOTHING);
        }
    }

    SECTION("Check setNextCellValue") {
        REQUIRE(cell.getCellValue()=='#');
        cell.setNextCellValue('A');
        cell.updateState();
        REQUIRE(cell.getCellValue()=='A');
    }
    SECTION("Check setNextColor") {
        REQUIRE(cell.getColor()==STATE_COLORS.DEAD);
        cell.setNextColor(STATE_COLORS.ELDER);
        cell.updateState();
        REQUIRE(cell.getColor()==STATE_COLORS.ELDER);
    }
}