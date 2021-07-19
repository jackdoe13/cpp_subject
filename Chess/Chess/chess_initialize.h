#pragma once
#include <Windows.h>
#include "Chess_Board.cpp"

void gotoxy(int x, int y);
void SelectMenu();
Board initialize();

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
    cout << "1. ���� ����" << endl;
    gotoxy(15, 19);
    cout << "2. ���� ����" << endl;

    gotoxy(15, 25);
    cout << "���� >>" << endl;

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
            cout << "WARNING : �ش��ϴ� �޴� ����. �ٽ��Է�." << endl;
        }
    }
}

Board initialize() {
    bool** board;
    struct piece_list list_b, list_w;

    board = new bool* [MAX_X];
    for (int i = 0; i < MAX_X; i++) {
        board[i] = new bool[MAX_X];     // ���� delete �ȸ���. 
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = false;
        }
    }

    // white �� 8��
    moveSet mv1 = { 2, 0, 1, 0 };
    Phone phones_w[8];
    for (int i = 0; i < 8; i++) {
        phones_w[i] = Phone(64 + (MAX_X - 1), 1 + i, mv1, 'w');
        board[1][i] = true;             // ���� ȿ������ ����� ������?
    }

    // black �� 8��
    moveSet mv2 = { 2, 0, 1, 0 };
    Phone phones_b[8];
    for (int i = 0; i < 8; i++) {
        phones_b[i] = Phone(66, 1 + i, mv2, 'b');
        board[MAX_X - 2][i] = true;
    }

    list_b.phones = phones_b;
    list_w.phones = phones_w;

    Board gameBoard = Board(board, list_b, list_w);

    gameBoard.config();

    return gameBoard;
}

void gotoxy(int x, int y) {
    //x, y ��ǥ ����
    COORD pos = { x,y };
    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}