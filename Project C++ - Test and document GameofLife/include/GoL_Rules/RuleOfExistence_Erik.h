/*
 * Filename    RuleOfExistence_Erik.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file       RuleOfExistence_Erik.h
 * @brief 	   Concrete RuleOfExistence, implementing Erik's rule, based on Conway's rule
 * @author     Erik Ström
 * @version    0.1
*/

#ifndef GAMEOFLIFE_RULEOFEXISTENCE_ERIK_H
#define GAMEOFLIFE_RULEOFEXISTENCE_ERIK_H

#include "RuleOfExistence.h"

/**
 * @class RuleOfExistence_Erik
 * @brief Concrete RuleOfExistence, implementing Erik's rule, based on Conway's rule (RuleOfExistence_Conway)
 * @details Sentient lifeforms is rarely created, but once in a while a cell has lived enough generations to become as wise as Erik.
 *
 * - Once a cell has survived a minimum amount of generations it will recieve a color to distinguish itself from younger ones.
 * - If such a cell would then survive another set amount of generations, it will be marked with a value of **E**.
 * - In the extreme case, where the cell has achieved above requirements and is determined to be the oldest living cell, it will
 * become a **prime elder**, and have its color changed once again. A generation may only have one such elder.
 */
class RuleOfExistence_Erik : public RuleOfExistence
{
private:
    char usedCellValue;	/**< @brief Char value to differentiate very old cells. */
    Cell* primeElder; /**< @brief Pointer to the one and only primeElder cell. */

    /**
     * @brief Method to change appearance of Cells that meets specific requirements.
     * @details Cells older than 5 generations recievees an old age color. If the cell is older than 10 generations, it also gets the value 'E' (for Erik).
     * @param cell Reference to specific Cell.
     * @param action Enum type Cell action.
     */
    void erikfyCell(Cell& cell, ACTION action);

    /**
     * @brief Method to set a Cell to be the primeElder.
     * @details Sets the prime elder with a pointer, a very rare occasion of a cell surviving longer than any other. Only one cell
     * can be elder at a time.
     * @param newElder pointer that may be the new primeElder pointer.
     */
    void setPrimeElder(Cell* newElder);

public:

    /**
     * @brief Initializes RuleOfExistence for cell population with Erik's rule
     * @param cells Reference to the population of cells.
     * @test Checks that
     * - Constructor values are correct.
    */
    RuleOfExistence_Erik(map<Point, Cell>& cells)
            : RuleOfExistence({2,3,3}, cells, ALL_DIRECTIONS, "erik"), usedCellValue('E') {
        primeElder = nullptr;
    }

    /** @brief deallocates memory.  */
    ~RuleOfExistence_Erik() {}

    /**
     * @brief Executes rule which is specific for Erik.
     * @test Checks that
     * - After the rule is executed, generation is as expected
     * - Cells update as expected when Erik rule is executed.
     * - If two cells at SAME age ages from 10 to 11, None of them should become primeElder since they are the same AGE.
     * - If older cell dies the other cell that is atleast 11 should become PRIME
     * - Cells below age 6 should behave correctly
     * - Cells ages from 5 to 6 should behave correctly
     * - Cells ages from 6 to 7 should behave correctly
     * - Cells BETWEEN 6-10 should behave correctly
     * - Cells ages from 10 to 11 should behave correctly
     * - Another cell is already over 12 or older and Another cell ages from 10 to 11. Should be 'E' but NOT a primeElder
     * - Prime ages to 12 and should still be primeElder.
     *
     * @bug When two cells with same age ages from 10 to 11 NONE should be prime. However the cell that is first to update becomes PRIME.
     * @bug When prime survies and ages again, it loses its prime Color.
    */
    void executeRule();
};

#endif //GAMEOFLIFE_RULEOFEXISTENCE_ERIK_H
