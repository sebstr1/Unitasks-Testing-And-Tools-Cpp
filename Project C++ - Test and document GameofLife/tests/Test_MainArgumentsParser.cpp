#include "catch.hpp"
#include "../include/Support/MainArgumentsParser.h"
#include <iostream>
TEST_CASE("Test the arguments parser generation argument and check standard rules") {

    ApplicationValues appv;
    MainArgumentsParser parser;

    unsigned int SIZE = 2;
    char ** argValues = new char *[SIZE];

    std::string str = "-g";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0


    argValues[0] = value;

    str = "500";

    char * value2 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value2);
    value2[str.size()] = '\0'; // don't forget the terminating 0
    argValues[1] = value2;

    appv=parser.runParser(argValues, SIZE);

    SECTION("Max gen changed") {
        REQUIRE(appv.maxGenerations == 500);
    }
    SECTION("Default evenRule") {
        REQUIRE(appv.evenRuleName == "conway");
    }
    SECTION("Default oddRule") {
        REQUIRE(appv.oddRuleName == "conway");
    }

    delete[] argValues;
    delete[] value;
    delete[] value2;
}

TEST_CASE("Test even rulename and default odd") {

    ApplicationValues appv;
    MainArgumentsParser parser;

    unsigned int SIZE = 2;
    char ** argValues = new char *[SIZE];

    std::string str = "-er";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0


    argValues[0] = value;

    str = "erik";

    char * value2 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value2);
    value2[str.size()] = '\0'; // don't forget the terminating 0
    argValues[1] = value2;


    appv=parser.runParser(argValues, SIZE);

    SECTION("Default evenRule") {
        REQUIRE(appv.evenRuleName == "erik");
    }
    SECTION("Default oddRule") {
        REQUIRE(appv.oddRuleName == "erik");
    }

    delete[] argValues;
    delete[] value;
    delete[] value2;
}

TEST_CASE("Test odd rulename and default even") {

    ApplicationValues appv;
    MainArgumentsParser parser;

    unsigned int SIZE = 2;
    char ** argValues = new char *[SIZE];

    std::string str = "-or";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0


    argValues[0] = value;

    str = "erik";

    char * value2 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value2);
    value2[str.size()] = '\0'; // don't forget the terminating 0
    argValues[1] = value2;

    appv=parser.runParser(argValues, SIZE);

    SECTION("Default evenRule") {
        REQUIRE(appv.evenRuleName == "conway");
    }
    SECTION("oddRule") {
        REQUIRE(appv.oddRuleName == "erik");
    }

    delete[] argValues;
    delete[] value;
    delete[] value2;
}

TEST_CASE("Test world dimension") {

    ApplicationValues appv;
    MainArgumentsParser parser;

    unsigned int SIZE = 2;
    char ** argValues = new char *[SIZE];

    std::string str = "-s";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0


    argValues[0] = value;

    str = "40x12";

    char * value2 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value2);
    value2[str.size()] = '\0'; // don't forget the terminating 0
    argValues[1] = value2;

    appv=parser.runParser(argValues, SIZE);

    SECTION("Dimensions correct") {
        REQUIRE(WORLD_DIMENSIONS.WIDTH==40);
        REQUIRE(WORLD_DIMENSIONS.HEIGHT==12);
    }

    delete[] argValues;
    delete[] value;
    delete[] value2;
}

TEST_CASE("Test Filename") {

    ApplicationValues appv;
    MainArgumentsParser parser;

    unsigned int SIZE = 2;
    char ** argValues = new char *[SIZE];

    std::string str = "-f";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0


    argValues[0] = value;

    str = "Population_Seed.txt";

    char * value2 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value2);
    value2[str.size()] = '\0'; // don't forget the terminating 0
    argValues[1] = value2;

    appv=parser.runParser(argValues, SIZE);

    SECTION("Filename correct") {
        REQUIRE(fileName == "Population_Seed.txt");
    }

    delete[] argValues;
    delete[] value;
    delete[] value2;
}

TEST_CASE("Test multiple input") {

    ApplicationValues appv;
    MainArgumentsParser parser;

    unsigned int SIZE = 4;
    char ** argValues = new char *[SIZE];

    std::string str = "-or";
    char * value = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value);
    value[str.size()] = '\0'; // don't forget the terminating 0

    argValues[0] = value;

    str = "erik";

    char * value2 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value2);
    value2[str.size()] = '\0'; // don't forget the terminating 0

    argValues[1] = value2;

    str = "-f";

    char * value3 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value3);
    value3[str.size()] = '\0'; // don't forget the terminating 0

    argValues[2] = value3;

    str = "Population_Seed.txt";

    char * value4 = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), value4);
    value4[str.size()] = '\0'; // don't forget the terminating 0

    argValues[3] = value4;

    appv=parser.runParser(argValues, SIZE);

    SECTION("Odd rulename correct") {
        REQUIRE(appv.oddRuleName == "erik");
    }
    SECTION("Filename correct") {
        REQUIRE(fileName == "Population_Seed.txt");
    }

    delete[] argValues;
    delete[] value;
    delete[] value2;
    delete[] value3;
    delete[] value4;
}