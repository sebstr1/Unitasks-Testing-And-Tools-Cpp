# Projektets namn
project(HelloCMake)
# Minsta tillåtna CMake version
cmake_minimum_required(VERSION 3.2)
# Kompilera med stöd för C++ 11
set (CMAKE_CXX_STANDARD 11)
# Lägg till katalogen med våra bibliotek till INCLUDE path
# (i dessa kataloger kommer kompilatorn att leta efter de
# header-filer som inkluderas i koden)
include_directories($ENV{TOOLS_INCLUDE})
# Ta med alla källkodsfiler i den aktuella katalogen och
# lägg dem i listan SRC_LIST
aux_source_directory(. SRC_LIST)
# Om Debug mode
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
# skriv ut meddelandet Debug mode samt sätt kompilatordirektivet
# DEBUG
message("Debug mode")
add_definitions(-DDEBUG)
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
# skriv ut meddelandet Release mode
message("Release mode")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")
# Skapa en exekverbar fil med källkodsfilerna från
# SRC_LIST. Första parametern är namnet på målet (Target)
add_executable(${PROJECT_NAME} ${SRC_LIST})

