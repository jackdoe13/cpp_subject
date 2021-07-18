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
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
};
