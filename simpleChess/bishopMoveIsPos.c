//
// Created by ibrah on 2/28/2021.
//

#include "chess.h"

bool isBishopPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    int control1, control2;

    if(board[horizontal][vertical] >= 7) {
        control1 = 1;
        control2 = 6;
    } else if (board[horizontal][vertical] < 7 && board[horizontal][vertical] > 0) {
        control1 = 7;
        control2 = 12;
    }
    if (abs(newHorizontal - horizontal) != abs(newVertical - vertical)) {
        return false;
    }
    while (horizontal != newHorizontal && vertical != newVertical) {
        if (horizontal < newHorizontal) {
            horizontal++;
        }
        if (horizontal > newHorizontal) {
            horizontal--;
        }
        if(vertical < newVertical) {
            vertical++;
        }
        if (vertical > newVertical) {
            vertical--;
        }
        if(horizontal != newHorizontal && vertical != newVertical) {
            if (board[horizontal][vertical] != empty) {
                return false;
            }
        }
        if (horizontal == newHorizontal && vertical == newVertical) {
            if ((board[horizontal][vertical] >= control1 && board[horizontal][vertical] <= control2) || (board[horizontal][vertical] == empty)) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}
