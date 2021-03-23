//
// Created by ibrah on 2/11/2021.
//

#include "chess.h"
#include <stdio.h>
#include <stdlib.h>


int abs(number) {
    if(number<0) return -number;
    return number;
}

void printBoard(piece board[8][8],char *pieces[14]) {
    printf("\n                                                 CHESS GAME!!\n\n\n\n\n\n");
    printf("                                   |");
    for (int i = 0; i<8; i++) {
        printf("  %c |",97+i);
    }
    printf("\n");
    printf("                                    _______________________________________");
    printf("\n");
    for (int i = 0; i<8; i++) {
        printf("                                 %d |",i+1);
        for (int j = 0; j<8; j++) {
            printf(" %s |",pieces[board[i][j]]);
        }
        printf("\n");
    }

}

char* playerInput(int square) {
    char *cell = malloc(2*sizeof(char));
    if(square == 0) {
        printf("           old square : ");
    } else {
        printf("           new square : ");
    }

    gets(cell);

    return cell;
}

bool controlMove(piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    if (board[horizontal][vertical] == Wpawn || board[horizontal][vertical] == Bpawn) {
        if(isPawnPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
    if (board[horizontal][vertical] == Wbishop || board[horizontal][vertical] == Bbishop) {
        if(isBishopPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
    if (board[horizontal][vertical] == Wknight || board[horizontal][vertical] == Bknight) {
        if(isKnightPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
    if (board[horizontal][vertical] == Wqueen || board[horizontal][vertical] == Bqueen) {
        if(isQueenPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
    if (board[horizontal][vertical] == Wrook || board[horizontal][vertical] == Brook) {
        if(isRookPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
    if (board[horizontal][vertical] == Wking || board[horizontal][vertical] == Bking) {
        if(isKingPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
}

bool check(piece board[8][8],int king) {

    int horizontal,vertical,control1,control2;

    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] == Wking && king == 0) {
                horizontal = i;
                vertical = j;
                control1 = 7;
                control2 = 12;
            }
            if (board[i][j] == Bking && king == 1) {
                horizontal = i;
                vertical = j;
                control1 = 1;
                control2 = 6;
            }
        }
    }

    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] >= control1 && board[i][j] <= control2) {
                if(controlMove(board,i,j,horizontal,vertical) == true) return false;
            }
        }
    }

    return true;
}

bool checkMate (piece board[8][8],int king) {
    piece copyBoard[8][8];
    int horizontal,vertical,control1,control2;

    for (int i = 0; i<8; i++) {
        for(int j = 0; j<8; j++) {
            copyBoard[i][j] = board[i][j];
        }
    }
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] == Wking && king == 0) {
                horizontal = i;
                vertical = j;
                control1 = 1;
                control2 = 6;
            }
            if (board[i][j] == Bking && king == 1) {
                horizontal = i;
                vertical = j;
                control1 = 7;
                control2 = 12;
            }
        }
    }
    int number = 0;
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if(board[i][j] >= control1 && board[i][j] <= control2) {
                number++;
            }
        }
    }
    number = number-1;

    while (number != 0) {
        for (int i = 0; i<8; i++) {
            for (int j = 0; j<8; j++) {
                if (board[i][j] >= control1 && board[i][j] <= control2) {
                    for (int k = 0; k<8; k++) {
                        for (int m = 0; m<8; m++) {
                            if((k != i) && (m != j)) {
                                if (controlMove(copyBoard,i,j,k,m) == true) {
                                    copyBoard[k][m] = copyBoard[i][j];
                                    copyBoard[i][j] = empty;
                                    if (check(copyBoard, king) == true) {
                                        return false;
                                    } else {
                                        copyBoard[i][j] = copyBoard[k][m];
                                        copyBoard[k][m] = empty;
                                        number--;
                                        if(number == 0) {
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool isCastlingPos (piece board[8][8],int king,int rookX,int rookY,int rookBoard[8][8]) {
    int horizontal,vertical,control1,control2;
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] == Wking && king == 0) {
                horizontal = i;
                vertical = j;
                control1 = 1;
                control2 = 6;
            }
            if (board[i][j] == Bking && king == 1) {
                horizontal = i;
                vertical = j;
                control1 = 7;
                control2 = 12;
            }
        }
    }


    if(rookBoard[rookX][rookY] == 0 && rookBoard[horizontal][vertical] == 0 && (abs(rookX-rookY) == 8 || abs(rookX-rookY) == 0)) {
        if(rookY<vertical) {
            for(int i = rookY+1; i<vertical; i++) {
                if(board[horizontal][i] >= control1 && board[horizontal][i] <= control2) {
                    return false;
                }
            }
            for (int k = 0; k<8; k++) {
                for (int m =0; m<8; m++) {
                    if(board[k][m] >=(control1+6)%12 && board[k][m] <= (control2+6)%12) {
                        if(controlMove(board,k,m,horizontal,vertical-1) == true || (controlMove(board,k,m,horizontal,vertical-2) == true)) return false;
                    }
                }
            }

        } else {
            for(int i = rookY-1; i>vertical; i--) {
                if(board[horizontal][i] >= control1 && board[horizontal][i] <= control2) {
                    return false;
                }
            }
            for (int k = 0; k<8; k++) {
                for (int m =0; m<8; m++) {
                    if(board[k][m] >=(control1+6)%12 && board[k][m] <= (control2+6)%12) {
                        if(controlMove(board,k,m,horizontal,vertical+1) == true || (controlMove(board,k,m,horizontal,vertical+2) == true)) return false;
                    }
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

game drawBoard(piece board[8][8], piece gameBoard[200][8][8], int gameNumber,int king, int pawnBoard[200][8][8]) {
    int copy = 0,number = 0,numberPiece = 0;
    int control1,control2;

    if (king == 0) {
        control1 = 1;
        control2 = 6;
    }
    if (king == 1) {
        control1 = 7;
        control2 = 12;
    }

    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            gameBoard[gameNumber][i][j] = board[i][j];
            if(board[i][j] == Wpawn || board[i][j] == Bpawn) {
                pawnBoard[gameNumber][i][j] = 1;
            } else {
                pawnBoard[gameNumber][i][j] = 0;
            }
        }
    }

    int p,r,s;
    for(p = 0; p<=gameNumber; p++) {
        for(r = 0; r<8; r++) {
            for (s = 0; s<8; s++) {
                if (gameBoard[p][r][s] != board[r][s]) {
                    break;
                }
            }
            if (gameBoard[p][r][s] != board[r][s]) {
                break;
            }
        }
        if(s == 8 && r == 7) {
            copy++;
        }
        if(copy == 3) {
            return draw;
        }
    }

    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (board[i][j] == Wking || board[i][j] == Bking || board[i][j] == Wbishop || board[i][j] == Bbishop || board[i][j] == Wknight || board[i][j] == Bknight) {
                numberPiece++;
            }
            if (board[i][j] != empty) {
                number++;
            }
        }
    }
    if(numberPiece == 3 && number == 3) {
        return draw;
    }
    int n,o;
    for (n = 0; n<8; n++) {
        for (o = 0; o<8; o++) {
            if (board[n][o] >= control1 && board[n][o] <= control2) {
                for (int k = 0; k<8; k++) {
                    for (int m = 0; m<8; m++) {
                        if(controlMove(board,n,o,k,m) == true && check(board,king) == true && n != k && o != m) {
                            return continueGame;
                        }
                    }
                }
            }
        }
        if(n == 7 && o == 8) {
            return draw;
        }
    }


    if (gameNumber-99 > 0 && gameNumber%2 == 0) {
        int first = 0;

        for (int i = 0; i<8; i++) {
            for (int j = 0; j<8; j++) {
                if (gameBoard[gameNumber-99][i][j] != empty) {
                    first++;
                }
            }
        }

        int number1 = 0;

        for (int i = gameNumber-98; i<=gameNumber; i++) {
            for (int j = 0; j<8; j++) {
                for (int k = 0; k<8; k++) {
                    if(gameBoard[i][j][k] != empty) {
                        number1++;
                    }
                    if (gameBoard[i-1][j][k] != gameBoard[i][j][k]) {
                        return continueGame;
                    }
                }
            }
            if(number1 != first) {
                return continueGame;
            } else {
                number1 = 0;
            }
            if (i == gameNumber) {
                return draw;
            }
        }
    }

    return continueGame;
}

piece pawnChange(int horizontal) {
    piece number;
    if (horizontal == 0) {
        printf("1-Wbishop\n2-Wknight\n3-Wqueen\n4-Wrook\nSelect your new piece : ");
        scanf("%d",&number);
        number = number+1;
    } else {
        printf("1-Bbishop\n2-Bknight\n3-Bqueen\n4-Brook\nSelect your new piece : ");
        scanf("%d",&number);
        number = number+7;
    }
    return number;
}
