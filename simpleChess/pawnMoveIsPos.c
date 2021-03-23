//
// Created by ibrah on 2/26/2021.
//

#include "chess.h"

bool isPawnPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    int number;

    if (board[horizontal][vertical] < 7) {
        if(horizontal == 6) {
            number = 3;
        }
        if (horizontal <6) {
            number = 2;
        }
        if (horizontal-newHorizontal<number && horizontal-newHorizontal>0) {
            for (int i = horizontal-1; i>=newHorizontal; i--) {
                if(i == newHorizontal) {
                    if(abs(newVertical-vertical) == 1) {
                        if(board[i][newVertical] >= 7) {
                            return true;
                        } else {
                            return false;
                        }
                    } else if (abs(newVertical-vertical) == 0) {
                        if(board[i][newVertical] == 0) {
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                if(board[i][vertical] != empty) {
                    return false;
                }
            }
        } else {
            return false;
        }
    } else {
        if(horizontal == 1) {
            number = 3;
        }
        if (horizontal > 1) {
            number = 2;
        }

        if (newHorizontal-horizontal<number && newHorizontal-horizontal>0) {
            for (int i = horizontal+1; i<=newHorizontal; i++) {
                if(i == newHorizontal) {
                    if(abs(newVertical-vertical) == 1) {
                        if(board[i][newVertical] < 7 && board[i][newVertical] > 0) {
                            return true;
                        } else {
                            return false;
                        }
                    } else if (abs(newVertical-vertical) == 0) {
                        if(board[i][newVertical] == 0) {
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                if(board[i][vertical]  != 0) {
                    return false;
                }
            }
        } else {
            return false;
        }
    }
}