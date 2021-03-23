//
// Created by ibrah on 2/28/2021.
//


#include "chess.h"

bool isKingPos (piece board[8][8],int horizontal,int vertical,int newHorizontal,int newVertical) {
    int control1,control2;
    if(board[horizontal][vertical] >=1 && board[horizontal][vertical] <= 6) {
        control1 = 1;
        control2 = 6;
    } else {
        if(board[horizontal][vertical] >= 7 && board[horizontal][vertical] <= 12) {
            control1 = 7;
            control2 = 12;
        }
    }
    if(abs(horizontal - newHorizontal) <=1 && abs(vertical-newVertical) <= 1) {
        if(board[newHorizontal][newVertical]>=control1 && board[newHorizontal][newVertical] <= control2) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}