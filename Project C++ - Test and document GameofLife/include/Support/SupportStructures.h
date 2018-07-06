/*
 * Filename    SupportStructures.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
 *
 * Various supportive structures to be used throughout the application!
*/
/**
 * @file    	SupportStructures.h
 * @brief 		supportive structures to be used throughout the application!
 * @author      Erik Ström
 * @version     0.1
*/

#ifndef GAMEOFLIFE_SUPPORTSTRUCTURES_H
#define GAMEOFLIFE_SUPPORTSTRUCTURES_H

/**
	@struct Point
	@brief Constitues a single Point in the simulated world.

	@details The Point structure handles x and y (column/row) coordinates in the world of Game of life, and is used
	to map Cell objects to their positions.
*/
struct Point {
	
    int x/** @brief X coordinate */
		,y /** @brief Y coordinate */; 

    /** @brief Overloading operator < for comparing Point objects
     *  @test Test that they compare correctly*/
    bool operator < (const Point& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

};

/**
@struct Dimensions
@brief Data structure holding information about world dimensions in pixels.
*/
struct Dimensions {
    int WIDTH, HEIGHT;
};


#endif //GAMEOFLIFE_SUPPORTSTRUCTURES_H
