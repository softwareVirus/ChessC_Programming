//
// Created by ibrah on 2/11/2021.
//

#include <stdio.h>
#include "chess.h"

int main() {
    piece board[8][8] = {{Brook,Bknight,Bbishop,Bqueen,Bking,Bbishop,Bknight,Brook},
                         {Bpawn,Bpawn,Bpawn,Bpawn,Bpawn,Bpawn,Bpawn,Bpawn},
                         {empty,empty,empty,empty,empty,empty,empty,empty},
                         {empty,empty,empty,empty,empty,empty,empty,empty},
                         {empty,empty,empty,empty,empty,empty,empty,empty},
                         {empty,empty,empty,empty,empty,empty,empty,empty},
                         {Wpawn,Wpawn,Wpawn,Wpawn,Wpawn,Wpawn,Wpawn,Wpawn},
                         {Wrook,Wknight,Wbishop,Wqueen,Wking,Wbishop,Wknight,Wrook}};
    game situation = continueGame;
    char *pieces[14] = {"  ","WP","WB","WN","WQ","WR","WK","BP","BB","BN","BQ","BR","BK"};
    int square = 0;
    int playerNumber = 0;
    int rookBoard[8][8];
    int pawnBoard[200][8][8];
    piece gameBoard[200][8][8];
    int newX,newY,oldX,oldY;
    int round = 1;
    int gameNumber = 0;
    for(int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            rookBoard[i][j] = 0;
        }
    }

    while (situation == continueGame) {
        system("CLS");
        system("color F0");

        printBoard(board,pieces);
        printf("\n\n");
        if(round > 0) {
            situation = drawBoard(board,gameBoard,gameNumber,playerNumber,pawnBoard);
            gameNumber++;
        }

        if(situation != continueGame) {
            printBoard(board,pieces);
            if(situation == draw) {
                printf("DRAW!!");
            }
            if(situation == patDraw) {
                printf("PAT!!");
            }
            break;
        }

        round = 0;
        char *oldSquare = playerInput(square);
        oldX = oldSquare[1]-49;
        oldY = oldSquare[0]-97;


        if (board[oldX][oldY] != 0) {
            if((playerNumber == 0 && board[oldX][oldY] < 7) || (playerNumber == 1 && board[oldX][oldY] >= 7)) {
                square++;
                char *newSquare = playerInput(square);
                newX = newSquare[1]-49;
                newY = newSquare[0]-97;
                if((board[oldX][oldY] == Wking && board[newX][newY] == Wrook) || (board[oldX][oldY] == Bking && board[newX][newY] == Brook)) {
                    if(isCastlingPos(board,playerNumber,newX,newY,rookBoard) && check(board,playerNumber) == true) {
                        if(newY>oldY) {
                            board[oldX][oldY+2] = board[oldX][oldY];
                            board[newX][newY-2] = board[newX][newY];
                            board[oldX][oldY] = empty;
                            board[newX][newY] = empty;
                        } else {
                            board[oldX][oldY-2] = board[oldX][oldY];
                            board[newX][newY+3] = board[newX][newY];
                            board[oldX][oldY] = empty;
                            board[newX][newY] = empty;
                        }
                        rookBoard[oldX][oldY] = 1;
                        rookBoard[newX][newY] = 1;
                        round++;
                    } else {
                        printf("You can't play this move\n");
                    }
                } else {
                    if (controlMove(board,oldX,oldY,newX,newY) == true && check(board,playerNumber) == true) {
                        if(board[oldX][oldY] == Wking || board[oldX][oldY] == Wrook || board[oldX][oldY] == Bking || board[oldX][oldY] == Brook) {
                            rookBoard[oldX][oldY] = 1;
                        }
                        board[newX][newY] = board[oldX][oldY];
                        board[oldX][oldY] = empty;
                        round++;
                    } else {
                        printf("You can't play this move\n");
                    }
                }
            } else {
                printf("You entered enemy piece's square! \n");
            }
        } else {
            printf("You entered invalid value! \n");
        }

        if ((board[newX][newY] == Wpawn && newX == 0) || (board[newX][newY] == Bpawn && newX == 7)) {
            board[newX][newY] = pawnChange(newX);
        }
        if(round > 0) {
            playerNumber = (playerNumber+1)%2;
        }


        if(check(board,playerNumber) == false) {
            system("CLS");
            printBoard(board,pieces);
            printf("\n\n                                            ");
            if(checkMate(board,playerNumber) == true) {
                printf("CHECKMATE !!!");

                if(playerNumber == 1) {
                    printf("WHITE WIN \n");
                    
                } else {
                    printf("BLACK WIN \n");
                    
                }
                Sleep(3000);
				return 0;
            }

            if (playerNumber == 1) {
                printf("CHECK TO BLACK\n");
            } else {
                printf("CHECK TO WHITE\n");
            }
            Sleep(3000);
        }
        Sleep(1000);
        square = 0;
    }
}
