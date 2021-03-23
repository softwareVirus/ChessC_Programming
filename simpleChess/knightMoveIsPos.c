//
// Created by ibrah on 2/28/2021.
//

#include "chess.h"

bool isKnightPos(piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    if(abs(horizontal-newHorizontal) == 2) {
        if(abs(vertical-newVertical) == 1) {
            return true;
        }
    }
    if(abs(horizontal-newHorizontal) == 1) {
        if(abs(vertical-newVertical) == 2) {
            return true;
        }
    }
    return false;
}