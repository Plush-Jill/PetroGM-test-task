cmake_minimum_required(VERSION 3.27)
project(PetroGM_test_task)

set(CMAKE_CXX_STANDARD 20)

add_executable(PetroGM_test_task src/main.cpp
        include/pieces/abstract-piece.hpp
        src/pieces/king.cpp
        include/pieces/king.hpp
        src/chess-board.cpp
        include/chess-board.hpp
        src/pieces/queen.cpp
        include/pieces/queen.hpp
        src/pieces/rook.cpp
        include/pieces/rook.hpp
        src/pieces/bishop.cpp
        include/pieces/bishop.hpp
        src/pieces/knight.cpp
        include/pieces/knight.hpp
        src/pieces/shadow.cpp
        include/pieces/shadow.hpp
        src/attack-direction/abstract-attack-direction.cpp
        include/attack-direction/abstract-attack-direction.hpp
        src/attack-direction/jump-direction.cpp
        include/attack-direction/jump-direction.hpp
        src/attack-direction/linear-direction.cpp
        include/attack-direction/linear-direction.hpp
        src/pieces/shadow-trace.cpp
        include/pieces/shadow-trace.hpp
        src/position.cpp
        include/position.hpp
        src/pieces/abstract-piece.cpp
        src/creating/piece-factory.cpp
        include/creating/piece-factory.hpp
        src/creating/piece-registrar.cpp
        include/creating/piece-registrar.hpp
        src/creating/piece-parser.cpp
        include/creating/piece-parser.hpp
        src/attack-relation.cpp
        include/attack-relation.hpp
        src/board-view.cpp
        include/board-view.hpp
)

#include_directories("include")
target_include_directories(PetroGM_test_task PUBLIC "include")
target_compile_options(PetroGM_test_task PUBLIC -O1 -Wall -Wextra -Wpedantic -Werror)