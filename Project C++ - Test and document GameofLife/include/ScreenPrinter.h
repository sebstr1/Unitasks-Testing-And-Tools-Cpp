/*
 * Filename    ScreenPrinter.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
* @file		ScreenPrinter.h
* @brief Responsible for all the visual output to the screen.
* @author	Erik Ström
* @version	0.1
*/


#ifndef screenPrinterH
#define screenPrinterH


#include "../terminal/terminal.h"
#include "Cell_Culture/Population.h"


/**
* @brief Responsible for all the visual output to the screen.
* @details Visually represents the simulation world on screen, prints out helpscreen and error messages to the screen
* and also capable of clearing the screen.
*/
class ScreenPrinter {

private:
    Terminal terminal;

    /**
    * @brief Constructor initializes ScreenPrinter.
    * @details Private constructor to ensure that no other class makes another instance.
    */
    ScreenPrinter() {}

public:

    /**
    * @brief Method for fetching an instance of ScreenPrinter
    * @details Singleton design pattern to make sure there is zero or one instances.
    * @return Reference to instance of ScreenPrinter.
    */
    static ScreenPrinter& getInstance() {
        static ScreenPrinter instance;
        return instance;
    }

    /**
    * @brief Method for printing the population to screen.
    * @details Loops through each row and column of terminal window, gets the cell at current [column, row],
    * checks that cell is not a rim cell. If its not a rim cell then get the cell color, change terminal color
    * and finally print the cell to screen followed by a terminal color reset  by calling terminal.popColor();
    * @param population is a reference to the current Population object which contains all cells that will be printed to screen.
    */
    void printBoard(Population& population);

    /**
    * @brief Method for printing out help screen.
    * @details Prints out relevant information as a help screen which should guide the user
    * if he or she would need help understanding how the program can be used.
    */
    void printHelpScreen();


    /**
    * @brief Method to print information to the user.
    * @details Prints the input parameter to the screen for the user (i.e error messages)
    * @param message The content of this string will be printed on the screen for the user to read.
    */
    void printMessage(string message);


    /**
    * @brief Method for clearing the terminal window
    * @details Utilizes the member function clear() of the private object terminal.
    * This will clear the terminal window so we have nice and clean terminal window to work with.
    */
    void clearScreen();
};

#endif
