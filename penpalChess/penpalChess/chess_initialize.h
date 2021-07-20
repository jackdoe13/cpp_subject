#pragma once

#include <Windows.h>
#include <stdlib.h>
#include "Chess_Board.cpp"

void gotoxy(int x, int y);
void SelectMenu();
Board& initialize();
void printRule();
bool startGame(Board& board);

bool startGame(Board& board) {
    printRule();
    board.config();

    system("pause");
    system("cls");

    while (true) {
        struct piece_list list = board.getList();

        cout << "어떤 말을 움직이겠습니까? >>" << endl;

        for (int i = 0; i < sizeof(list.phones); i++) {
            cout << i + 1 << ") ";
            cout << list.phones[i].getPosX() << list.phones[i].getPosY() << endl;
        }
        system("pause");
        system("cls");
    }



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

Board& initialize() {
    bool** board;
    struct piece_list list_w { NULL };

    board = new bool* [MAX_X];
    for (int i = 0; i < MAX_X; i++) {
        board[i] = new bool[MAX_X] {false};     // 아직 delete 안만듬. 
    }

    // white 기물 n개 (수정 예정 : 무작위로 말 배치)
    srand(time(NULL));

    int x, y;
    Phone* ps = NULL;
    /*
    Bishop& bs = NULL;
    Rook* rs = NULL;
    Knight* ks = NULL;
    Queen* qs = NULL;
    */
    ps = new Phone[6];

    for (int i = 0; i < 6; i++) {
        x = rand() / 5000;
        y = rand() / 5000;

        if ((x <= 0 || x >= 8) || (y <= 0 || y >= 8)) {
            i--;
            continue;
        }
        else if (board[y - 1][x - 1] == true) {
            i--;
            continue;
        }

        ps[i] = Phone(x, 64 + y);
        board[y - 1][x - 1] = true;
    }

    // black 킹 1개 설정 초기화
    int kx, ky;
    while (true) {
        kx = rand() / 5000;
        ky = rand() / 5000;

        if ((kx <= 0 || kx >= 8) || (ky <= 0 || ky >= 8)) {
            continue;
        }
        else if (board[ky - 1][kx - 1] == true) {
            continue;
        }
        else {
            break;
        }
    }
    
    King target = King(kx, 64 + ky);
    board[ky - 1][kx - 1] = true;

    list_w.phones = ps;

    Board gameBoard(board, list_w, target);

    return gameBoard;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { (short)x, (short)y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printRule() {
    system("cls");
    gotoxy(10, 15);
    cout << "1. 판 위에 말이 주어집니다. 각각의 말은 현재 위치한 값이 표시됩니다." << endl;
    gotoxy(10, 16);
    cout << "2. 플레이어는 주어진 말을 움직여서 상대 킹을 잡아야 합니다. " << endl;
    gotoxy(10, 17);
    cout << "3. 플레이어 말은 폰, 룩, 나이트, 비숍, 나이트, 퀸 중 무작위로 지급됩니다." << endl;
    gotoxy(10, 18);
    cout << "4. 상대 왕은 움직이지 않지만 위치가 알려지지 않습니다. 열심히 찾아보세요." << endl;
    gotoxy(10, 19);
    cout << "5. 말을 움직였을 때 공격범위 내에 킹이 존재하면 체크 상태가 됩니다." << endl;
    gotoxy(10, 20);
    cout << "6. 체크가 3개 모여서 체크메이트가 되거나 왕을 처치하면 게임에서 승리합니다." << endl;
    gotoxy(25, 25);
    system("pause");
    system("cls");
}