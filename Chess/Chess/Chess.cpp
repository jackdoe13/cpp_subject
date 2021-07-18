// 참여 개발자 : 최주홍, 한세진
// 주제 : 펜팔 체스
// 개발언어 cpp
// 개발착수일자 : 2021.07.16

#include <iostream>
#include <string.h>
#include "Chess_Piece.cpp"
#include "Chess_Board.cpp"

#ifndef MAX_X
#define MAX_X 8
#endif

using namespace std;

int main() {
    bool** board;
    struct piece_list list_b, list_w;

    board = new bool* [MAX_X];
    for (int i = 0; i < MAX_X; i++) {
        board[i] = new bool[MAX_X];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = false;
        }
    }

    // white 폰 8개
    moveSet mv = { 2, 0, 1, 0 };
    Phone phones_w[8];
    for (int i = 0; i < 8; i++) {
        phones_w[i] = Phone(65 + i, i + 1, mv, 'b');
        board[i][1] = true; // 
    }

    // black 폰 8개
    Phone phones_b[8];
    for (int i = 0; i < 8; i++) {
        phones_b[i] = Phone(65 + i, i + 1, mv, 'b');
        board[i][2] = true; // 
    }

    list_b.phones = phones_b;
    list_w.phones = phones_w;

    Board gameBoard = Board(board, list_b, list_w);

    gameBoard.config();

    return 0;
}
/*
Board initialize() {

    return gameBoard;
}
*/