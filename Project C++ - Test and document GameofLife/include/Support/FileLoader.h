/*
 * Filename    FileLoader.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file    FileLoader.h
 * @brief Responsible determination of simulation starting values, based on contents of specified file.
 * @author  Erik Ström
 * @version 0.1
*/

#ifndef FileLoaderH
#define FileLoaderH

#include <map>
#include "Cell_Culture/Cell.h"
#include "Globals.h"

using namespace std;

/**
* @brief Responsible determination of simulation starting values, based on contents of specified file.
* @details Reads startup values from spcified file, containing values for WORLD_DIMENSIONS and cell Population.
* Will also create the corresponding cells.
*/
class FileLoader {

public:
    /**
    * @brief Default constructor
    */
    FileLoader() {}


    /**
    * @brief Method to load disposed map with cells that are loaded from file pointed to by global variable "filename".
    * @details Opens file pointed to by global variable "filename", with try catch
    *
    * Loads world dimension by reading file.
    *
    * Create cells accordingly to map
    * @param cells is a reference to a map that contains Point structs and Cell objects
    *
    * @throw ios_base::failure
    *
    * @copydetails returns back to main (application closes) if file could not be found.
    * @test Checks that
    * - Exception is thrown if file to load does not exist.
    * - Correct type if exception is thrown.
    * - Exception is thrown if file loads but file contains bad data.
    * - Exception is NOT thrown if file exists and data is good.
    * - When data is loaded to map it should be as expected.
    *
    * @bug Program accepts files with Bogus data (Waka waka, eh eh)
    */
    void loadPopulationFromFile(map<Point, Cell>& cells);

};

#endif
