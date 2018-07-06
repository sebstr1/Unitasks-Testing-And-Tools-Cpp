#include "catch.hpp"
#include "../include/Support/MainArguments.h"
#include <string>

TEST_CASE("Test the HelpArgument implementations execute") {

    HelpArgument help;
    ApplicationValues appv;

    std::string str = "value";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0



    SECTION("Check that correct values are achieved after execute") {
        REQUIRE(appv.runSimulation);
        help.execute(appv, value);
        REQUIRE_FALSE(appv.runSimulation);
    }

    delete[] value;
}
TEST_CASE("Test the GenerationsArgument implementations execute") {

    GenerationsArgument gen;
    ApplicationValues appv;

    std::string str = "200";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0



    SECTION("Check that correct values are achieved after execute") {
        REQUIRE(appv.runSimulation);
        REQUIRE(appv.maxGenerations==100);
        gen.execute(appv, value);
        REQUIRE(appv.maxGenerations==200);
        REQUIRE(appv.runSimulation);
    }

    delete[] value;
    value=nullptr;

    SECTION("Check that correct values are achieved after execute with value nullptr") {
        REQUIRE(appv.runSimulation);
        REQUIRE(appv.maxGenerations==100);
        gen.execute(appv,value);
        REQUIRE_FALSE(appv.runSimulation);
    }

}

TEST_CASE("Test the WorldsizeArgument implementations execute") {

    WorldsizeArgument worldSize;
    ApplicationValues appv;

    std::string str = "200 100";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0



    SECTION("Check that correct values are achieved after execute") {
        REQUIRE(appv.runSimulation);
        worldSize.execute(appv, value);
        REQUIRE(WORLD_DIMENSIONS.WIDTH==200);
        REQUIRE(WORLD_DIMENSIONS.HEIGHT==100);
        REQUIRE(appv.runSimulation);
    }
    delete[] value;
    value=nullptr;

    SECTION("Check that correct values are achieved after execute with value nullptr") {
        REQUIRE(appv.runSimulation);
        worldSize.execute(appv, value);
        REQUIRE_FALSE(appv.runSimulation);
    }
}

TEST_CASE("Test the FileArgument implementations execute") {

    FileArgument fileArg;
    ApplicationValues appv;

    std::string str = "testName";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0



    SECTION("Check that correct values are achieved after execute") {
        REQUIRE(appv.runSimulation);
        fileArg.execute(appv, value);
        REQUIRE(fileName==str);
        REQUIRE(appv.runSimulation);
    }
    delete[] value;
    value=nullptr;

    SECTION("Check that correct values are achieved after execute with value nullptr") {
        REQUIRE(appv.runSimulation);
        fileArg.execute(appv, value);
        REQUIRE_FALSE(appv.runSimulation);
    }
}
TEST_CASE("Test the EvenRuleArgument implementations execute") {

    EvenRuleArgument even;
    ApplicationValues appv;

    std::string str = "rule";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0



    SECTION("Check that correct values are achieved after execute") {
        REQUIRE(appv.runSimulation);
        even.execute(appv, value);
        REQUIRE(appv.evenRuleName==str);
        REQUIRE(appv.runSimulation);
    }
    delete[] value;
    value=nullptr;

    SECTION("Check that correct values are achieved after execute with value nullptr") {
        REQUIRE(appv.runSimulation);
        even.execute(appv, value);
        REQUIRE_FALSE(appv.runSimulation);
    }
}
TEST_CASE("Test the OddRuleArgument implementations execute") {

    OddRuleArgument odd;
    ApplicationValues appv;

    std::string str = "rule";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0



    SECTION("Check that correct values are achieved after execute") {
        REQUIRE(appv.runSimulation);
        odd.execute(appv, value);
        REQUIRE(appv.oddRuleName==str);
        REQUIRE(appv.runSimulation);
    }
    delete[] value;
    value=nullptr;

    SECTION("Check that correct values are achieved after execute with value nullptr") {
        REQUIRE(appv.runSimulation);
        odd.execute(appv, value);
        REQUIRE_FALSE(appv.runSimulation);
    }
}