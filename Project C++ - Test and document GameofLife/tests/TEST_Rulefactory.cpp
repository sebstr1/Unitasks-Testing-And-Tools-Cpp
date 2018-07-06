/**
 * @file test_RuleOfExistence_Conway.cpp
 * @autor Sebastian Strindlund
 * @brief Tests derived class RuleOfExistence_Conway constructor and memberfunction.
*/

#include "catch.hpp"
#include "../include/GoL_Rules/RuleFactory.h"
#include "../include/GoL_Rules/RuleOfExistence.h"
#include "../include/GoL_Rules/RuleOfExistence_Conway.h"
#include "../include/GoL_Rules/RuleOfExistence_Erik.h"
#include "../include/GoL_Rules/RuleOfExistence_VonNeumann.h"

TEST_CASE("Returns the same instance.") {

    RuleFactory &instance1 = RuleFactory::getInstance();
    RuleFactory &instance2 = RuleFactory::getInstance();

    REQUIRE(&instance1 == &instance2);
}

TEST_CASE("Check that createAndReturnRule returns correct rule") {

        std::map<Point, Cell> cells;
        auto rulefactory = RuleFactory::getInstance();

        RuleOfExistence* conway = rulefactory.createAndReturnRule(cells);
        RuleOfExistence* conway2 = dynamic_cast<RuleOfExistence_Conway*>(conway);
        REQUIRE(conway2 != nullptr);

        conway = rulefactory.createAndReturnRule(cells, "conway");
        conway2 = dynamic_cast<RuleOfExistence_Conway*>(conway);
        REQUIRE(conway2 != nullptr);


        RuleOfExistence* erik = rulefactory.createAndReturnRule(cells, "erik");
        RuleOfExistence* erik2 = dynamic_cast<RuleOfExistence_Erik*>(erik);
        REQUIRE(erik2 != nullptr);


        RuleOfExistence* vonneumann = rulefactory.createAndReturnRule(cells, "von_neumann");
        RuleOfExistence* vonneumann2 = dynamic_cast<RuleOfExistence_VonNeumann*>(vonneumann);
        REQUIRE(vonneumann2 != nullptr);


}
