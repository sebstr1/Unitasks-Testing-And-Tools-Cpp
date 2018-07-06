/*
 * Filename    Cell.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
* @file Cell.h
* @brief Cells represents a certain combination of row and column of the simulated world.
* @author Erik Ström
* @version 0.1
*/

#ifndef cellH
#define cellH

#include "../../terminal/terminal.h"

	/**
		@struct StateColors
		@brief Data structure holding colors to visualize the state of cells.
	*/
struct StateColors {
    COLOR LIVING, /** Representing living cell*/
            DEAD, /** Representing dead cell*/
            OLD,  /** Representing old cell*/
            ELDER;/** Representing very old cell*/
}
/** Initiate default values. */
const STATE_COLORS = { COLOR::WHITE, COLOR::BLACK, COLOR::CYAN, COLOR::MAGENTA };

    /** An enum type.
     *  Cell action. Determined by rule, and sent to cell for future change.
     */
enum ACTION {	KILL_CELL,		/**< enum value 0 */
				IGNORE_CELL,	/**< enum value 1 */
				GIVE_CELL_LIFE,	/**< enum value 2 */
				DO_NOTHING		/**< enum value 3 */};


/**
	@class Cell

	@brief Cells represents a certain combination of row and column of the simulated world.

	@details Cells may be of two types; rim cells, those representing the outer limits of the world,
	or non-rim cells. The first cell type are immutable, exempt from the game's rules, and
	thus their values may not be changed. The latter type, however, may be changed and edited
	in ways specified by the rules.
*/

class Cell {

private:
	/**
		@struct CellDetails
		@brief encapsulate cell details
	*/
    struct CellDetails {
        int age;
        COLOR color;
        bool rimCell;
        char value;
    } details;
	/**
		@struct NextUpdate
		@brief encapsulate changes to next state
	*/
    struct NextUpdate {
        ACTION nextGenerationAction;
        COLOR nextColor;
        char nextValue;
        bool willBeAlive;	/** some rules may need to know beforehand whether the cell will be alive*/
    } nextUpdate;


	/**
		@brief Increments the current cells age
	    @test Check that the age actually increments
	*/
    void incrementAge() { details.age++; }



	/**
		@brief Kills the cell by setting its age to zero
	    @test Check that age is 0 after use
	*/
    void killCell() { details.age = 0; }



	/**
		@brief Sets the character value of the cell, which will be printed to screen.
		@param value The caracted that will be printed
	    @test Check that the value changes, like after the use of the constructor
	*/
    void setCellValue(char value) { details.value = value; }



	/**
		@brief Sets the color of a cell
		@param color the color the cell will recieve
	    @test Check that the color changes, like after the use of the constructor
	*/
    void setColor(COLOR color) { this->details.color = color; }

public:

	/**
		@brief Constructor that determines the cell's starting values.
		@param isRimCell determines if the cell is a rim cell
		@param action tells the cell what to do
	    @test Check that next ACTION is action
	    @test Check that it becomes a rim cell if isRimCell is set to True. If it is set to
	    true cell should also be dead
	    @test Check that cell gets correct color based on action.
	*/
    Cell(bool isRimCell = false, ACTION action = DO_NOTHING);



	/**
		@brief Checks if the cell is alive
		@return True if the cell is alive, otherwise false. Also returns false if it is a rim cell
	    @test Check that function returns false if it is a rim cell or if it is dead, otherwise true
	*/
    bool isAlive();



	/**
		@brief Sets the cells next action to take in its coming update.
		@param action What action the cell should do next update/generation
	    @test Check that next generation action becomes action after this function has been used
	*/
    void setNextGenerationAction(ACTION action);



	/**
		@brief Updates the cell to its new state, based on stored update values.
		@details Based on what ACTION the cell have the next generation ot will either be killed or have its
		age incremented (either by being a cell thats already alive, or by creating a new cell)
	    @test Test that a cell with action GIVE_CELL_LIFE becomes alive after this, and that next action is DO_NOTHING
	    @test Test that a cell with action IGNORE_CELL is ignored, id the cell was alive its age should be incremented
	    , and that next action is DO_NOTHING
	    @test Test that a cell with action KILL_CELL gets killed, and that next action is DO_NOTHING
	*/
    void updateState();



	/**
		@brief Returns the cells age
		@return The cells current age
	    @test Test that current age gets returned, 0 if dead
	*/
    int getAge() { return details.age; }



	/**
		@brief Returns the cells color
		@return The cells current color
	    @test Test that current color gets returned
	*/
    COLOR getColor() { return details.color; }




	/**
		@brief Determines whether the cell is a rim cell, and thus should be immutable
		@return True if the cell is a rim cell, otherwise false
	 	@test Test that true is returned if the cell is a rim cell
	*/
    bool isRimCell() { return details.rimCell; }



	/**
		@brief Sets the color the cell will have after its next update.
		@param nextColor the color the cell will have next update
	    @test Test that the next color is the color provided to this function (through updateState())
	*/
    void setNextColor(COLOR nextColor) { this->nextUpdate.nextColor = nextColor; }


	/**
		@brief Returns the cells value
		@return The cells value
	    @test Test that correct value is returned, for example right after constructor was called
	*/
    char getCellValue() { return details.value; }




	/**
		@brief Sets the next character value of the cell, which will be printed to screen.
		@param value The char that will be printed
	    @test Test that the value is the value provided (through updateState())
	*/
    void setNextCellValue(char value) { nextUpdate.nextValue = value; }




	/**
		@brief Sets whether the cell is alive/dead next generation.
		@param isAliveNext
	    @test Test that isAliveNext() returns true if isAliveNext is set to true
	*/
    void setIsAliveNext(bool isAliveNext) { nextUpdate.willBeAlive = isAliveNext; }



	/**
		@brief Checks if the cell be alive next generation
		@return True if the cell will be alive next update, otherwise false
	    @test Test that the function returns true if nextUpdate.willBeAlive is set to true
	*/
    bool isAliveNext() { return nextUpdate.willBeAlive; }


	/**
		@brief Gets the cells next action.
		@return a reference to ACTION
	    @test Test that the function returns the next action of a cell
	*/
    ACTION& getNextGenerationAction() { return nextUpdate.nextGenerationAction; }

};

#endif
