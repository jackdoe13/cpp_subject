// 참여 개발자 : 최주홍, 한세진
// 주제 : 펜팔 체스
// 개발언어 cpp
// 개발착수일자 : 2021.07.16

#include <iostream>
#include <string.h>
#include "Chess_Piece.cpp"
#include "Chess_board.cpp"
#include "chess_initialize.h"

#ifndef MAX_X
#define MAX_X 8
#endif

using namespace std;

int main() {
    while (true) {
        SelectMenu();
        system("cls");

        // 게임 보드 생성
        Board board = initialize();

        startGame(board);
        system("cls");
    }

    return 0;
}