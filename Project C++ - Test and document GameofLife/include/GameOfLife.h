/*
 * Filename    GameOfLife.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/

/**
* @file		GameOfLife.h
* @brief The heart of the simulation, interconnects the main execution with the graphical presentation.
* @author	Erik Ström
* @version	0.1
*/


/**
* @mainpage DT042G Game of Life Mainpage
* ## Task
* - Work in teams of two
* - Fork Game of life repo
* - Study the code
* - Document it with Doxygen
* - Write Unit tests
* - Agile workflow with administration of Trello Kanban board
* - Git Feature Branch Workflow
*
*
* This project's Trello Kanban board: https://trello.com/b/dX14jTAU/game-of-life-kanban
*
* @ref about_the_authors
*
* @page about_the_authors This Page presents the project’s team members.
*
*
* @section Author1 Alice Hedmark
*
* username: alhe1501
*
* email: alhe1501@student.miun.se
*
 @section Author2 Sebastian Strindlund
*
* username: sest1601
*
* email: sest1601@student.miun.se
*
*
*/

#ifndef GameOfLifeH
#define GameOfLifeH

#include "Cell_Culture/Population.h"
#include "ScreenPrinter.h"
#include <string>

/**
	@class GameOfLife
	@brief The heart of the simulation, interconnects the main execution with the graphical presentation.

	@details Creates and manages Population and the ScreenPrinter instances. Will instruct the Population of cells to keep
	updating as long as the specified number of generations is not reached, and for each iteration instruct
	ScreenPrinter to write the information on screen.
*/
class GameOfLife {

private:
	/** @brief An instance of the Population class*/
    Population population;

	/** @brief  A Reference to a ScreenPrinter*/
    ScreenPrinter& screenPrinter;

	/** @brief An integer of the number of generations that will be simulated*/
    int nrOfGenerations;

public:
	/**
		@brief Constructor that initializes the simulation values such as population
		@param nrOfGenerations An integer of the number of generations that will be simulated
		@param evenRuleName The name of the rule that should be applied on even generations
		@param oddRuleName The name of the rule that should be applied on odd generations
	*/
    GameOfLife(int nrOfGenerations, string evenRuleName, string oddRuleName);


	/**
		@brief Function that runs the simulation
		@details  Run the simulation for as many generations as been set by the user (default = 100).
		For each iteration; calculate population changes and print the information on screen.
	*/
    void runSimulation();

};

#endif
