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

        cout << "� ���� �����̰ڽ��ϱ�? >>" << endl;

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

Board& initialize() {
    bool** board;
    struct piece_list list_w { NULL };

    board = new bool* [MAX_X];
    for (int i = 0; i < MAX_X; i++) {
        board[i] = new bool[MAX_X] {false};     // ���� delete �ȸ���. 
    }

    // white �⹰ n�� (���� ���� : �������� �� ��ġ)
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

    // black ŷ 1�� ���� �ʱ�ȭ
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
    //x, y ��ǥ ����
    COORD pos = { (short)x, (short)y };
    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printRule() {
    system("cls");
    gotoxy(10, 15);
    cout << "1. �� ���� ���� �־����ϴ�. ������ ���� ���� ��ġ�� ���� ǥ�õ˴ϴ�." << endl;
    gotoxy(10, 16);
    cout << "2. �÷��̾�� �־��� ���� �������� ��� ŷ�� ��ƾ� �մϴ�. " << endl;
    gotoxy(10, 17);
    cout << "3. �÷��̾� ���� ��, ��, ����Ʈ, ���, ����Ʈ, �� �� �������� ���޵˴ϴ�." << endl;
    gotoxy(10, 18);
    cout << "4. ��� ���� �������� ������ ��ġ�� �˷����� �ʽ��ϴ�. ������ ã�ƺ�����." << endl;
    gotoxy(10, 19);
    cout << "5. ���� �������� �� ���ݹ��� ���� ŷ�� �����ϸ� üũ ���°� �˴ϴ�." << endl;
    gotoxy(10, 20);
    cout << "6. üũ�� 3�� �𿩼� üũ����Ʈ�� �ǰų� ���� óġ�ϸ� ���ӿ��� �¸��մϴ�." << endl;
    gotoxy(25, 25);
    system("pause");
    system("cls");
}