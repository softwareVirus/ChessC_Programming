//
// Created by ibrah on 2/11/2021.
//

#ifndef SIMPLECHESS_CHESS_H
#define SIMPLECHESS_CHESS_H
#include <windows.h>
#include <time.h>
#include <stdbool.h>

enum Pieces {
    empty,Wpawn,Wbishop,Wknight,Wqueen,Wrook,Wking,Bpawn,Bbishop,Bknight,Bqueen,Brook,Bking
};

typedef enum Pieces piece;

enum GameSituation {
    patDraw,draw,continueGame
};

typedef enum GameSituation game;

void printBoard(piece board[8][8],char *pieces[14]);
bool checkMate (piece board[8][8],int king);
bool isCastlingPos (piece board[8][8],int king,int rookX,int rookY,int rookBoard[8][8]);
game drawBoard(piece board[8][8], piece gameBoard[200][8][8], int gameNumber,int king, int pawnBoard[200][8][8]);
piece pawnChange(int horizontal);
char* playerInput(int square);
bool check(piece board[8][8],int king);
bool controlMove(piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);
bool isPawnPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);
bool isBishopPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);
bool isRookPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);
bool isKnightPos(piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);
bool isKingPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);
bool isQueenPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical);

#endif //SIMPLECHESS_CHESS_H
