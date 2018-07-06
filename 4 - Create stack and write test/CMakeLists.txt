# Projektets namn
project(lab4del1)

# Minsta tillåtna cmake version
cmake_minimum_required(VERSION 3.2)

# Kompilera med c++ 11 stöd
set (CMAKE_CXX_STANDARD 11)

# Lägg till katalogen med våra bibliotek till INCLUDE path
# (i dessa kataloger kommer kompilatorn att leta efter de
# header filer som inkluderas i koden)
INCLUDE_DIRECTORIES($ENV{TOOLS_INCLUDE} ${CMAKE_SOURCE_DIR}/test ${CMAKE_SOURCE_DIR}/include)


# Ta med alla källkodsfiler i den aktuella katalogen och
# lägger dem i listan SRC_LIST.
set (SRC_LIST
        ./test/test-main.cpp
        ./test/test-stack.cpp
        ./include/stack.h
        ./include/catch.hpp
)




# Om Debug mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Debug mode samt sätt kompilator
    # direktivet DEBUG
    message("Debug mode")
    add_definitions(-DDEBUG)
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Skriv ut meddelandet Release mode.
    message("Release mode")
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

# Skapa en exekverbar fil med källkodsfilerna i från
# SRC_LIST. Första parametern är namnet på målet (Target)
add_executable(${PROJECT_NAME} ${SRC_LIST})