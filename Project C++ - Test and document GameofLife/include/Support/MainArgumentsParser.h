/*
 * Filename    MainArgumentsParser.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
* @file		MainArgumentsParser.h
* @brief    Provides functions that parses the starting arguments for the application.
* @author	Erik Ström
* @version	0.1
*/

#ifndef mainArgumentsParserH
#define mainArgumentsParserH

#include "MainArguments.h"
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

/**
	@class MainArgumentsParser
	@brief Provides functions that parses the starting arguments for the application.
*/
class MainArgumentsParser {
public:
	/**
		@brief Checks/parses arguments provided by the user
		@details Creates an vector with all implementations of BaseArgument and runs through them all checking if
		the values of the BaseArgument implementations correspond to any of the given
		arguments provided to the function. Unless the help option "-h" was used
		the argument will be executed and values will be stored in appValues or a global variable.
		This function also sets default values to evenRuleName and oddRuleName if they were not provided.
		@see BaseArgument
		@param argv[] char-pointer array containing the arguments provided by the user
		@param length an Integer containing length of char array
		@return A reference to ApplicationValues
	    @test That arguments will be parsed correctly and correct values are returned via ApplicationValues.
	        Check that mutiple arguments can be parsed together.
	*/
    ApplicationValues& runParser(char* argv[], int length);

private:

	/**
		@brief Holds values that will be used to determine how the application will run.
	*/
    ApplicationValues appValues;


	/**
		@brief Checks if a given option exists
		@param begin char pointer to pointer. Where to start searching in the pointer array
		@param end char pointer to pointer. Where to stop searching in the pointer array
		@param option A const reference to string containing the option that will be checked for exsistance
		@return True if option exists withing interval
	*/
    bool optionExists(char** begin, char** end, const std::string& option);


	/**
		@brief Gets the given option value
		@param begin char pointer to pointer. Where to start searching in the pointer array
		@param end char pointer to pointer. Where to stop searching in the pointer array
		@param option A const reference to string containing the option that will be óbtained
		@return A char pointer contatining a given option value
	*/
    char* getOption(char** begin, char** end, const std::string& option);
};

#endif
