cmake_minimum_required(VERSION 3.17)
project(simpleChess C)

set(CMAKE_C_STANDARD 99)

add_executable(simpleChess main.c chess.h chess.c pawnMoveIsPos.c bishopMoveIsPos.c rookMoveIsPos.c knightMoveIsPos.c kingMoveIsPos.c queenMoveIsPos.c)