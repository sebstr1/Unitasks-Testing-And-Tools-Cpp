/*
 * Filename    RuleOfExistence.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/





/**
 * @file       RuleOfExistence.h
 * @brief 	   Data that will be used by rules and Abstract base class RuleOfExistence
 * @author     Erik Ström
 * @version    0.1
 * @see Classes derived from RuleOfExistence :
 * @see RuleOfExistence_Conway
 * @see RuleOfExistence_Erik
 * @see RuleOfExistence_VonNeumann
*/
#ifndef RULEOFEXISTENCE_H
#define RULEOFEXISTENCE_H

#include<string>
#include<map>
#include<vector>
#include "Cell_Culture/Cell.h"
#include "Support/Globals.h"
using namespace std;

/*
These rules lies at the heart
of the simulation, and determines the fate of each cell in the world population.
*/

/**
 * @struct PopulationLimits
 * @brief Data structure holding population limits which will be used by rules to determine what ACTION to make.
*/
struct PopulationLimits {
    int UNDERPOPULATION, /**< @brief cell dies of loneliness. */
            OVERPOPULATION, /**< @brief cell dies of over crowding. */
            RESURRECTION; /**< @brief cell lives on / is resurrected. */
};


/**
 * @struct Directions
 * @brief Data structure holding directional values. Used by rules to determine neighbouring cells.
*/
struct Directions {
    int HORIZONTAL,
        VERTICAL;
};



/** @brief Vector holding all directions; N, E, S, W, NE, SE, SW, NW */
const vector<Directions> ALL_DIRECTIONS{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 },{ 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };

/** @brief Vector holding cardinal directions; N, E, S, W */
const vector<Directions> CARDINAL{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 } };

/** @brief Vector holding diagonal directions; NE, SE, SW, NW */
const vector<Directions> DIAGONAL{ { 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };


/**
 * @class RuleOfExistence
 * @brief Abstract base class, upon which concrete rules will derive.
 * @details The derivations of RuleOfExistence is what determines the culture of Cell Population. Each rule implements
 * specific behaviours and so may execute some parts in different orders. In order to accommodate this
 * requirement RuleOfExistence will utilize a **Template Method** desing pattern, where all derived rules
 * implements their logic based on the virtual method executeRule().
 * @see Classes derived from RuleOfExistence :
 * @see RuleOfExistence_Conway
 * @see RuleOfExistence_Erik
 * @see RuleOfExistence_VonNeumann
*/
class RuleOfExistence {
protected:
    string ruleName;

    /** @brief Reference to the population of cells. */
    map<Point, Cell>& cells;

    /** @brief Amounts of alive neighbouring cells, with specified limits. */
    const PopulationLimits POPULATION_LIMITS;

    /** @brief The directions, by which neighbouring cells are identified. */
    const vector<Directions>& DIRECTIONS;

    /**
     * @brief Determines the amount of alive neighbouring cells to current cell, using directions specified by the rule.
     * @param currentPoint Struct that holds current cell position.
     * @return Number of neighbours alive.
    */
    int countAliveNeighbours(Point currentPoint);

    /**
     * @brief Determines what action should be taken regarding the current cell, based on alive neighbouring cells.
     * @param aliveNeighbours Number of neighbours alive for current Cell.
     * @param isAlive Bool that is true or false depending on if alive or not.
     * @return KILL_CELL
     * @return IGNORE_CELL
     * @return GIVE_CELL_LIFE
     * @return DO_NOTHING
    */
    ACTION getAction(int aliveNeighbours, bool isAlive);

public:

    /**
     * @brief Constructor
     * @param limits Struct with number of neighbouring cells and specified limits.
     * @param cells Reference to the population of cells.
     * @param DIRECTIONS Vector with directions for neighbouring cells.
     * @param ruleName string with rulename
    */
    RuleOfExistence(PopulationLimits limits, map<Point, Cell>& cells, const vector<Directions>& DIRECTIONS, string ruleName)
            : POPULATION_LIMITS(limits), cells(cells), DIRECTIONS(DIRECTIONS), ruleName(ruleName) {}

    /** @brief deallocates memory  */
    virtual ~RuleOfExistence() {}


    /** @brief Execute rule, in order specific to the concrete rule, by utilizing template method DP. */
    virtual void executeRule() = 0;

    /**
     * @brief Getter for ruleName.
     * @return string ruleName
    */
    string getRuleName() { return ruleName; }


    /**
     * @brief Getter for PopulationLimits
     * @return struct POPULATION_LIMITS
     * @addtogroup EXTRA_FUNCTIONS
    */
     const PopulationLimits  getPopulationLimits() { return POPULATION_LIMITS; }

     /**
      * @brief Getter for neighbours directions
      * @return vector<Directions>% DIRECTIONS
      * @addtogroup EXTRA_FUNCTIONS
     */
     const vector<Directions>& getDirections() { return DIRECTIONS; }


     bool operator==(const Directions &lhs);

};

#endif
