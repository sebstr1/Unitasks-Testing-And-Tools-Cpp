/*
 * Filename    RuleOfExistence_VonNeumann.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file       RuleOfExistence_VonNeumann.h
 * @brief 	   Concrete RuleOfExistence, implementing VonNeumann's rule.
 * @author     Erik Ström
 * @version    0.1
*/

#ifndef GAMEOFLIFE_RULEOFEXISTENCE_VONNEUMANN_H
#define GAMEOFLIFE_RULEOFEXISTENCE_VONNEUMANN_H

#include "RuleOfExistence.h"

/**
 * @class RuleOfExistence_VonNeumann
 * @brief Concrete Rule of existence, implementing Von Neumann's rule.
 * @details Von Neumann's RuleOfExistence, differs from Conway in that only 4 neighbours are accounted for.
 * The only difference from Conway is that neighbours are determined using only cardinal directions (N, E, S, W).
 * @see RuleOfExistence_Conway
 */
class RuleOfExistence_VonNeumann : public RuleOfExistence
{
private:

public:

    /**
     * @brief Initializes RuleOfExistence for cell population with VonNeumann's rule
     * @param cells Reference to the population of cells.
     * @test Checks that
     * - Constructor values are correct.
    */
    RuleOfExistence_VonNeumann(map<Point, Cell>& cells)
            : RuleOfExistence({ 2,3,3 }, cells, CARDINAL, "von_neumann") {}

    /** @brief deallocates memory.  */
    ~RuleOfExistence_VonNeumann() {}

    /**
     * @brief Executes rule which is specific for VonNeumann.
     * @test Checks that
     * - After the rule is executed, generation is as expected
    */
    void executeRule();
};

#endif //GAMEOFLIFE_RULEOFEXISTENCE_VONNEUMANN_H
