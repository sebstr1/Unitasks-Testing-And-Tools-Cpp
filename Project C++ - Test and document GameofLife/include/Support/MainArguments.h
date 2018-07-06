/*
 * Filename    MainArguments.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/
/**
 * @file	    MainArguments.h
 * @brief       An abstract class that handles arguments
 * @author      Erik Ström
 * @version     0.1
*/

#ifndef GAMEOFLIFE_MAINARGUMENTS_H
#define GAMEOFLIFE_MAINARGUMENTS_H

#include "Globals.h"
#include "ScreenPrinter.h"
#include <sstream>
#include <string>

using namespace std;

/**
	@struct ApplicationValues
	@brief Holds values that will be used to determine how the application will run
*/
struct ApplicationValues {
	/** @brief true if simulation should run */
    bool runSimulation = true;

	/** @brief Name of the rule that should be applied on even generations */
    string evenRuleName,
		/** @brief Name of the rule that should be applied on odd generations */
			oddRuleName;

	/** @brief Default number of generations to simulate */
    int maxGenerations = 100;

};

/**
	@class BaseArgument
	@brief An abstract class that handles arguments
*/
class BaseArgument {
protected:
	/** @brief Value of argument */
    const string argValue;

    /** @brief Inform the user that no value was provided for the argument */
    void printNoValue();

public:
	/**
		@brief Constructor that initializes the value of the argument
		@param argValue The argument value
	*/
    BaseArgument(string argValue) : argValue(argValue) {}

	/**
		@brief Virtual destructor
	*/
    virtual ~BaseArgument() {}

	/**
		@brief A pure virtual function that will be defined in subclasses
		@see HelpArgument::execute()
		@see GenerationsArgument::execute()
		@see WorldsizeArgument::execute()
		@see FileArgument::execute()
		@see EvenRuleArgument::execute()
		@see OddRuleArgument::execute()
		@param appValues A reference to some application values
		@param value A char-pointer to some value, defaults to nullptr
	*/
    virtual void execute(ApplicationValues& appValues, char* value = nullptr) = 0;


	/**
		@brief Gets the value of the argument
		@return argValue The value of the argument
	*/
    const string& getValue() { return argValue; }
};


/**
	@class HelpArgument
	@brief Provides functions for the helpscreen.
*/
class HelpArgument : public BaseArgument {
public:
	/**
		@brief Constructor that sends a predefined value/argument to the base class
	*/
    HelpArgument() : BaseArgument("-h") {}
	/**
		@brief Default destructor
	*/
    ~HelpArgument() {}


	/**
		@brief Prints a help screen
		@details Prints a help screen with the help of ScreenPrinter. Also sets the appValues.runSimulation to false
		@see ScreenPrinter::printHelpScreen()
		@param appValues A reference to some application values
		@param value A char-pointer to some value.
	    @test Check that the ApplicationValues was changed accordingly to input.
	*/
    void execute(ApplicationValues& appValues, char* value);
};


/**
	@class GenerationsArgument
	@brief Amount of generations to simulate
*/
class GenerationsArgument : public BaseArgument {
public:
	/**
		@brief Constructor that sends a predefined value/argument to the base class
	*/
    GenerationsArgument() : BaseArgument("-g") {}
	/**
		@brief Default destructor
	*/
    ~GenerationsArgument() {}

	/**
		@brief Sets maximum number of generations to be simulated
		@details Sets maximum number of generations to be simulated if generations parameter is set to something.
		Otherwise sets appValues.runSimulation to false and tells the user that no value for the argument was provided
		@see ApplicationValues::maxGenerations
		@see BaseArgument::printNoValue()
		@param appValues A reference to some application values
		@param generations A char-pointer to some value.
	    @test Check that the ApplicationValues was changed accordingly to input.
	*/
    void execute(ApplicationValues& appValues, char* generations);
};


/**
	@class WorldsizeArgument
	@brief Custom population size
*/
class WorldsizeArgument : public BaseArgument {
public:
	/**
		@brief Constructor that sends a predefined value/argument to the base class
	*/
    WorldsizeArgument() : BaseArgument("-s") {}
	/**
		@brief Default destructor
	*/
    ~WorldsizeArgument() {}



	/**
		@brief Sets the world size
		@details If dimensions contains something dimensions will be extracted from it and applied to WORLD_DIMENSIONS.
		Otherwise sets appValues.runSimulation to false and tells the user that no value for the argument was provided
		@see WORLD_DIMENSIONS
		@see BaseArgument::printNoValue()
		@param appValues A reference to some application values
		@param dimensions A char-pointer to some value.
	    @test Check that the ApplicationValues was changed accordingly to input.
	*/
    void execute(ApplicationValues& appValues, char* dimensions);
};


/**
	@class FileArgument
	@brief Initiate population from file
*/
class FileArgument : public BaseArgument {
public:
	/**
		@brief Constructor that sends a predefined value/argument to the base class
	*/
    FileArgument() : BaseArgument("-f") {}
	/**
		@brief Default destructor
	*/
    ~FileArgument() {}


	/**
		@brief Specifies what file should be used
		@details If fileNameArg contains something a filename will be extracted from it and applied to fileName.
		Otherwise sets appValues.runSimulation to false and tells the user that no value for the argument was provided
		@see fileName
		@see BaseArgument::printNoValue()
		@param appValues A reference to some application values
		@param fileNameArg A char-pointer to some value.
	    @test Check that the ApplicationValues was changed accordingly to input.
	*/
    void execute(ApplicationValues& appValues, char* fileNameArg);
};


/**
	@class EvenRuleArgument
	@brief Rule used for even generations
*/
class EvenRuleArgument : public BaseArgument {
public:
	/**
		@brief Constructor that sends a predefined value/argument to the base class
	*/
    EvenRuleArgument() : BaseArgument("-er") {}
	/**
		@brief Default destructor
	*/
    ~EvenRuleArgument() {}


	/**
		@brief Specifies rule should be applied to even generations
		@details If evenRule contains something a rule will be extracted from it and applied to appValues.
		Otherwise sets appValues.runSimulation to false and tells the user that no value for the argument was provided
		@see ApplicationValues::evenRuleName
		@see BaseArgument::printNoValue()
		@param appValues A reference to some application values
		@param evenRule A char-pointer to some value.
	    @test Check that the ApplicationValues was changed accordingly to input.
	*/
    void execute(ApplicationValues& appValues, char* evenRule);
};


/**
	@class OddRuleArgument
	@brief Rule used for odd generations
*/
class OddRuleArgument : public BaseArgument {
public:
	/**
		@brief Constructor that sends a predefined value/argument to the base class
	*/
    OddRuleArgument() : BaseArgument("-or") {}
	/**
		@brief Default destructor
	*/
    ~OddRuleArgument() {}


	/**
		@brief Specifies rule should be applied to odd generations
		@details If oddRule contains something a rule will be extracted from it and applied to appValues.
		Otherwise sets appValues.runSimulation to false and tells the user that no value for the argument was provided
		@see ApplicationValues::oddRuleName
		@see BaseArgument::printNoValue()
		@param appValues A reference to some application values
		@param oddRule A char-pointer to some value.
	    @test Check that the ApplicationValues was changed accordingly to input.
	*/
    void execute(ApplicationValues& appValues, char* oddRule);
};

#endif //GAMEOFLIFE_MAINARGUMENTS_H
