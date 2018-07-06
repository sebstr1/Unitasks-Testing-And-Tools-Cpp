/*
 * Filename    RuleOfExistence_Conway.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file       RuleOfExistence_Conway.h
 * @brief 	   Concrete RuleOfExistence, implementing Conway's rule.
 * @author     Erik Ström
 * @version    0.1
*/

#ifndef GAMEOFLIFE_RULEOFEXISTENCE_CONWAY_H
#define GAMEOFLIFE_RULEOFEXISTENCE_CONWAY_H

#include "RuleOfExistence.h"

/**
 * @class RuleOfExistence_Conway
 * @brief Conway's RuleOfExistence, applying actions based on PopulationLimits on all 8 surrounding neighbours.
 * @details Concrete RuleOfExistence, implementing Conway's rule of determining alive neighbours surrounding the cell
 * by checking all 8 directions, 4 x Cardinal + 4 x Diagonal. PopulationLimits are set as;
 *
 * *UNDERPOPULATION	    < 2*	**Cell dies of loneliness**
 *
 * *OVERPOPULATION		> 3*	**Cell dies of overcrowding**
 *
 * *RESURRECTION		= 3*	**Cell is infused with life**
 */
class RuleOfExistence_Conway : public RuleOfExistence
{
private:

public:

     /**
     * @brief Initializes RuleOfExistence for cell population with the Conway rule
     * @param cells Reference to the population of cells.
     * * @test Checks that
     * - Constructor values are correct.
    */
    RuleOfExistence_Conway(map<Point, Cell>& cells)
            : RuleOfExistence({ 2,3,3 }, cells, ALL_DIRECTIONS, "conway") {}

    /** @brief deallocates memory.  */
    ~RuleOfExistence_Conway() {}

    /**
     * @brief Executes rule which is specific for conway.
     * * @test Checks that
     * - After the rule is executed, generation is as expected
    */
    void executeRule();
};

#endif //GAMEOFLIFE_RULEOFEXISTENCE_CONWAY_H
