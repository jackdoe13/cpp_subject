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
	King target;

public:
	Board(bool** init_board, struct piece_list list_w, King target) {
		board = init_board;
		this->list_w = list_w;
		this->target = target;
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

		cout << "3. 왕에 대한 정보 >>" << endl;
		cout << target.getClan() << " ";
		cout << target.getMoveset().mv_backward << target.getMoveset().mv_flag << target.getMoveset().mv_forward << target.getMoveset().mv_side_back << target.getMoveset().mv_side_for << " ";
		cout << target.getPosX() << " ";
		cout << target.getPosY() << " ";
		cout << endl;
	}
};
