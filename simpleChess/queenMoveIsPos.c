//
// Created by ibrah on 2/28/2021.
//

#include "chess.h"

bool isQueenPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    if(horizontal == newHorizontal || vertical == newVertical) {
        if(isRookPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    } else {
        if(isBishopPos(board,horizontal,vertical,newHorizontal,newVertical) == true) return true;
        return false;
    }
}