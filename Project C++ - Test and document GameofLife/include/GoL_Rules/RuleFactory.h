/*
 * Filename    RuleFactory.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file    RuleFactory.h
 * @brief Singleton class to handle creation of RulesOfExistence objects.
 * @author  Erik Ström
 * @version 0.1
*/

#ifndef RULEFACTORY_H
#define RULEFACTORY_H

#include "GoL_Rules/RuleOfExistence.h"

/**
	@class RuleFactory
	@brief Singleton class to handle creation of RulesOfExistence objects.

*/
class RuleFactory
{
private:
	/**
		@brief Default private constructor
	*/
    RuleFactory() {}

public:
	/**
		@brief Singleton factory receiver, returns a reference to the instance.
		@return A static reference to the RuleFactory
        @test Should return the same instance since its a Singleton
	*/
    static RuleFactory& getInstance();


	/**
		@brief Creates and returns specified RuleOfExistence.
		@details If the ruleName parameter is "von_neumann" a RuleOfExistence_VonNeumann will be created and returned.
		If the ruleName parameter is "erik" a RuleOfExistence_Erik will be created and returned.
		Defaults to conway rule which returns RuleOfExistence_Conway
		@param cells A map that maps cells to coordinates/points
		@param ruleName Specifies what rule to be used. Defaults to "conway"
		@see RuleOfExistence_Erik
		@see RuleOfExistence_Conway
		@see RuleOfExistence_VonNeumann
		@return A pointer to a new instance of some RuleOfExistance created with cells as argument
        @test That createAndReturnRule returns correct rule
	*/
    RuleOfExistence* createAndReturnRule(map<Point, Cell>& cells, string ruleName = "conway");
};

#endif
