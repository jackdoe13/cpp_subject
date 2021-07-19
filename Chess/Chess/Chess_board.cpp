#pragma once

#include <iostream>
#include "Chess_Piece.cpp"

using namespace std;

#ifndef MAX_X
#define MAX_X 8
#endif

struct piece_list {
	Phone *phones;
};

class Board {
private:
	bool** board;
	struct piece_list list_w;
	struct piece_list list_b;

public:
	Board(bool** init_board, struct piece_list list_b, struct piece_list list_w) {
		board = init_board;
		this->list_w = list_w;
		this->list_b = list_b;
	}

	void config() {
		cout << "1. 현재 말들의 위치 >>" << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		cout << "2. 생존중인 말들 목록 >>" << endl;
		for (int i = 0; i < 8; i++) {
			cout << list_w.phones[i].getClan() << " ";
			cout << list_w.phones[i].getMoveset().mv_backward << list_w.phones[i].getMoveset().mv_flag << list_w.phones[i].getMoveset().mv_forward << list_w.phones[i].getMoveset().mv_side_back << list_w.phones[i].getMoveset().mv_side_for << " ";
			cout << list_w.phones[i].getPosX() << " ";
			cout << list_w.phones[i].getPosY() << " ";
			cout << endl;
		}

		for (int i = 0; i < 8; i++) {
			cout << list_b.phones[i].getClan() << " ";
			cout << list_b.phones[i].getMoveset().mv_backward << list_b.phones[i].getMoveset().mv_flag << list_b.phones[i].getMoveset().mv_forward << list_b.phones[i].getMoveset().mv_side_back << list_b.phones[i].getMoveset().mv_side_for << " ";
			cout << list_b.phones[i].getPosX() << " ";
			cout << list_b.phones[i].getPosY() << " ";
			cout << endl;
		}
	}
};
