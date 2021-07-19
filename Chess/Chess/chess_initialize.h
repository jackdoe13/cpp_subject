#pragma once
#include <Windows.h>
#include "Chess_Board.cpp"

void gotoxy(int x, int y);
void SelectMenu();
Board* initialize();
bool startGame(Board& board);

bool startGame(Board& board) {
    cout << "머기중..." << endl;
    Sleep(5000);

    cout << "끗." << endl;
    system("pause");

    return true;
}

void SelectMenu() {
    int mode;

    gotoxy(10, 10);
    cout << ".______    _______ .__   __. .______      ___       __           ______  __    __   _______     _______.     _______." << endl;
    gotoxy(10, 11);
    cout << "|   _  \\  |   ____||  \\ |  | |   _  \\    /   \\     |  |         /      ||  |  |  | |   ____|   /       |    /       |" << endl;
    gotoxy(10, 12);
    cout << "|  |_)  | |  |__   |   \\|  | |  |_)  |  /  ^  \\    |  |        |  ,----'|  |__|  | |  |__     |   (----`   |   (----`" << endl;
    gotoxy(10, 13);
    cout << "|   ___/  |   __|  |  . `  | |   ___/  /  /_\\  \\   |  |        |  |     |   __   | |   __|     \\   \\        \\   \\    " << endl;
    gotoxy(10, 14);
    cout << "|  |      |  |____ |  |\\   | |  |     /  _____  \\  |  `----.   |  `----.|  |  |  | |  |____.----)   |   .----)   |   " << endl;
    gotoxy(10, 15);
    cout << "| _|      |_______||__| \\__| | _|    /__/     \\__\\ |_______|    \\______||__|  |__| |_______|_______/    |_______/    " << endl;

    gotoxy(15, 18);
    cout << "1. 게임 시작" << endl;
    gotoxy(15, 19);
    cout << "2. 게임 종료" << endl;

    gotoxy(15, 25);
    cout << "선택 >>" << endl;

    while (1) {
        gotoxy(25, 25);
        cout << " " << endl;
        gotoxy(25, 25);
        cin >> mode;
        if (mode == 1) {
            break;
        }
        else if (mode == 2) {
            exit(0);
        }
        else if (mode == 5882) {
            // debug
        }
        else {
            gotoxy(30, 30);
            cout << "WARNING : 해당하는 메뉴 없음. 다시입력." << endl;
        }
    }
}

Board* initialize() {
    bool** board;
    struct piece_list list_w { NULL };

    board = new bool* [MAX_X];
    for (int i = 0; i < MAX_X; i++) {
        board[i] = new bool[MAX_X] {false};     // 아직 delete 안만듬. 
    }

    // white 폰 8개(수정 예정 : 무작위로 말 배치)
    srand(time(NULL));

    moveSet mv1 = { 2, 0, 1, 0 };
    Phone phones_w[8];
    for (int i = 0; i < 8; i++) {
        phones_w[i] = Phone(64 + (MAX_X - 1), 1 + i, mv1, 'w');
        board[MAX_X - 2][i] = true;
    }

    // black 킹 1개
    King target = King();
    board[0][2] = true;

    list_w.phones = phones_w;

    Board gameBoard(board, list_w, target);

    gameBoard.config();

    return &gameBoard;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
