/*
 * Filename    Globals.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file    	  Globals.h
 * @brief 		  Global variables defined elsewhere (with extern) to be used throughout the application!
 * @author      Erik Ström
 * @version     0.1
*/

#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include "SupportStructures.h"

using namespace std;

/** @brief Global variable defined elsewhere with actual width and height of used world */
extern Dimensions WORLD_DIMENSIONS;

/** @brief Global variable defined elsewhere with name of file to read */
extern string fileName;


#endif
