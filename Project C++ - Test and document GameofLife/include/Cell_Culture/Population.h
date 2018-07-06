/*
 * Filename    Population.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/

/**
 * @file    Population.h
 * @brief Representation of the complete society of cell existance and interactions.
 * @author  Erik Ström
 * @version 0.1
*/

#ifndef POPULATION_H
#define POPULATION_H

#include<map>
#include<string>
#include "Cell.h"
#include "Support/Globals.h"
#include "GoL_Rules/RuleOfExistence.h"
#include "GoL_Rules/RuleFactory.h"

using namespace std;

/**
	@class Population
	@brief Representation of the complete society of cell existance and interactions.

	@details The Population constitutes of all current, previous and future generations of cells, both living and dead
	as well as those not yet born. By mapping all cells to their respective positions in the simulation world,
	Population has the complete knowledge of each cell's whereabouts. Furthermore, the class is responsible for
	determining which rules should be required from the RuleFactory, and store the pointer to these as members.

	Population's main responsibility during execution is determining which rule to apply for each new generation
	and updating the cells to their new states.
*/
class Population
{
private:
	/** @brief Current generation number */
    int generation;

	/** @brief A map with cells placed at certain rows and columns*/
    map<Point, Cell> cells;

	/** @brief Pointer to the rule that applies on even generations*/
    RuleOfExistence* evenRuleOfExistence;

	/** @brief Pointer to the rule that applies to odd generations*/
    RuleOfExistence* oddRuleOfExistence;

	/**
		@brief Build cell culture based on randomized starting values.
		@details Allocates and maps cells based on worldSize, selects rim cells and
		randomly chooses whether other cells should be alive or not
	    @test Tests that dimensions corresponds default dimensions
	*/
    void randomizeCellCulture();


	/**
		@brief Send cells map to FileLoader, which will populate its culture based on file values.
	    @test Tests that dimensions corresponds to file dimensions
	*/
    void buildCellCultureFromFile();

public:
	/**
		@brief Initializes values on creation
		@details evenRuleOfExistence is set to nullptr, oddRuleOfExistence is set to nullptr and generation is set to 0
	*/
    Population() : generation(0), evenRuleOfExistence(nullptr), oddRuleOfExistence(nullptr) {}

	/**
		@brief Frees allocated memory on destruction.
	*/
    ~Population();


	/**
		@brief Initializing cell culture and the concrete rules to be used in simulation.
		@details Determines whether the cell culture should be randomized or built from file based on if a file exists or not.
		This function also creates the rules that will be used, based on specified rule names. If oddRuleName is left empty, the same rule
		as evenRuleName will be used.
		@param evenRuleName Name of rule to be applied on even generations
		@param oddRuleName Name of rule to be applied on odd generations
	*/
    void initiatePopulation(string evenRuleName, string oddRuleName = "");


	/**
		@brief Update the cell population and determine next generational changes based on rules.
		@details Updates the states of the cells and executes given rules.
		@see RuleOfExistence_Erik::executeRule()
		@see RuleOfExistence_Conway::executeRule()
		@see RuleOfExistence_VonNeumann::executeRule()
		@return The generation number incremented by one
        @test
        - Check that generations properly increases
        - Check that odd rule is applied on odd generation
        - Check that even rule is applied on even generation
        @bug Population demands that initiatePopulation is run before calculateNewGeneration, otherwise it crashes. Both are public functions.


	*/
    int calculateNewGeneration();



	/**
		@brief Returns cell by specified key value.
		@return A reference to a cell
	    @test Tests that cells are alive according to position
	*/
    Cell& getCellAtPosition(Point position) { return cells.at(position); }



	/**
		@brief Gets the total amount of cells in the population, regardless of state.
		@return Number of cells in population
	*/
    int getTotalCellPopulation() { return cells.size(); }


    /**
        @brief Gets the current generation number.
        @return Generation number.
    */
    int getGeneration() { return generation; }

};

#endif
