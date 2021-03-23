//
// Created by ibrah on 2/28/2021.
//

#include "chess.h"

bool isRookPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    int i,j,control,control1,control2;

    if (horizontal == newHorizontal) {
        i = vertical;
        control = newVertical;
        j = horizontal;
    } else if (vertical == newVertical) {
        i = horizontal;
        control = newHorizontal;
        j = vertical;
    } else {
        return false;
    }

    if (board[horizontal][vertical] >=1 && board[horizontal][vertical] <=6) {
        control1 = 1;
        control2 = 6;
    } else {
        if (board[horizontal][vertical] >=7 && board[horizontal][vertical] <=12) {
            control1 = 7;
            control2 = 12;
        }
    }

    while (i != control) {

        if(i < control) {
            i++;
        } else if(i > control) {
            i--;
        }
        if (i != control) {
            if (j == horizontal) {
                if (board[horizontal][i] != empty) {
                    return false;
                }
            } else if (j == vertical) {
                if (board[i][vertical] != empty) {
                    return false;
                }
            }
        } else {
            if (j == horizontal) {
                if (board[horizontal][i] >= control1 && board[horizontal][i] <= control2) {
                    return false;
                }
            }
            if (j == vertical) {
                if (board[i][vertical] >= control1 && board[i][vertical] <= control2) {
                    return false;
                }
            }
        }
    }

    return true;
}