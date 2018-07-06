cmake_minimum_required(VERSION 3.2)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

include_directories($ENV{TOOLS_INCLUDE} ${CMAKE_SOURCE_DIR}/include)

# Add terminal sub directory
add_subdirectory(terminal)

# Om Debug mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Debug mode
    message("Debug mode")
    add_definitions(-DDEBUG)
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Release mode.
    message("Release mode")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

set(SRC_LIST
        # src/main.cpp
        include/Cell_Culture/Cell.h include/Support/FileLoader.h include/GameOfLife.h include/Support/Globals.h include/Support/MainArgumentsParser.h include/Cell_Culture/Population.h include/GoL_Rules/RuleFactory.h include/GoL_Rules/RuleOfExistence.h include/ScreenPrinter.h src/Cell_Culture/Cell.cpp src/Support/FileLoader.cpp src/GameOfLife.cpp src/Support/Globals.cpp src/Cell_Culture/Population.cpp src/GoL_Rules/RuleFactory.cpp src/GoL_Rules/RuleOfExistence.cpp src/ScreenPrinter.cpp include/GoL_Rules/RuleOfExistence_Conway.h src/GoL_Rules/RuleOfExistence_Conway.cpp include/GoL_Rules/RuleOfExistence_VonNeumann.h src/GoL_Rules/RulesOfExistence_VonNeumann.cpp include/GoL_Rules/RuleOfExistence_Erik.h src/GoL_Rules/RuleOfExistence_Erik.cpp include/Support/SupportStructures.h src/Support/MainArgumentsParser.cpp include/Support/MainArguments.h src/Support/MainArguments.cpp)



# Sets for all tests

set(TEST_CELL
        include/Cell_Culture/Cell.h
        src/Cell_Culture/Cell.cpp
        tests/CatchMain.cpp
        tests/Test_Cell.cpp
        )

set(TEST_POPULATION
        include/Cell_Culture/Cell.h
        src/Cell_Culture/Cell.cpp
        include/Cell_Culture/Population.h
        src/Cell_Culture/Population.cpp
        tests/CatchMain.cpp
        tests/Test_Population.cpp
        include/GoL_Rules/RuleFactory.h
        src/GoL_Rules/RuleFactory.cpp
        include/GoL_Rules/RuleOfExistence.h
        src/GoL_Rules/RuleOfExistence.cpp
        include/GoL_Rules/RuleOfExistence_Conway.h
        src/GoL_Rules/RuleOfExistence_Conway.cpp
        include/GoL_Rules/RuleOfExistence_Erik.h
        src/GoL_Rules/RuleOfExistence_Erik.cpp
        include/GoL_Rules/RuleOfExistence_VonNeumann.h
        src/GoL_Rules/RulesOfExistence_VonNeumann.cpp
        include/Support/FileLoader.h
        src/Support/FileLoader.cpp
        include/Support/Globals.h
        src/Support/Globals.cpp
        )

set(TEST_MAINARGUMENTS
        include/Support/MainArguments.h
        src/Support/MainArguments.cpp
        include/Support/Globals.h
        src/Support/Globals.cpp
        include/ScreenPrinter.h
        src/ScreenPrinter.cpp
        terminal/terminal.h
        terminal/terminal.cpp
        tests/CatchMain.cpp
        tests/Test_MainArguments.cpp
        )

set(TEST_MAINARGUMENTSPARSER
        include/Support/MainArguments.h
        src/Support/MainArguments.cpp
        include/Support/MainArgumentsParser.h
        src/Support/MainArgumentsParser.cpp
        include/Support/Globals.h
        src/Support/Globals.cpp
        include/ScreenPrinter.h
        src/ScreenPrinter.cpp
        terminal/terminal.h
        terminal/terminal.cpp
        tests/CatchMain.cpp
        tests/Test_MainArgumentsParser.cpp
        )

set(TEST_FILES
        tests/CatchMain.cpp
        tests/TEST_FileLoader.cpp
        tests/TEST_RuleOfExistence_Conway.cpp
        tests/test_RuleOfExistence_VonNeumann.cpp
        tests/TEST_RuleOfExistence_Erik.cpp
        tests/Test_MainArgumentsParser.cpp
        tests/Test_MainArguments.cpp
        tests/Test_Population.cpp
        tests/Test_Cell.cpp
        tests/TEST_Rulefactory.cpp
        tests/Test_SupportStructures.cpp
        )


# add_executable(${PROJECT_NAME} ${SRC_LIST})
# add_executable(${PROJECT_NAME}_Test_Cell ${TEST_CELL})

# add_executable(${PROJECT_NAME}_Test_Population ${TEST_POPULATION})

# add_executable(${PROJECT_NAME}_Test_MainArguments ${TEST_MAINARGUMENTS})

# add_executable(${PROJECT_NAME}_Test_MainArgumentsParser ${TEST_MAINARGUMENTSPARSER})


add_executable(${PROJECT_NAME}-TEST ${TEST_FILES} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME}-TEST Terminal)

# target_link_libraries(${PROJECT_NAME} Terminal)

# target_link_libraries(${PROJECT_NAME} Terminal)
