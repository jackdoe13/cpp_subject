#pragma once

#include <iostream>
#include "Chess_Piece.cpp"

using namespace std;

#ifndef MAX_X
#define MAX_X 8
#endif

inline void whatType(struct piece_list list, int index) {
	switch (list.phones[index].getID())
	{
	case 1:
		cout << "��" << endl;
		break;
	case 2:
		cout << "��" << endl;
		break;
	case 3:
		cout << "���" << endl;
		break;
	case 4:
		cout << "��" << endl;
		break;
	case 5:
		cout << "����Ʈ" << endl;
		break;
	default:
		// ����
		break;
	}
}

struct piece_list {
	Phone* phones;
	Rook* rooks;
};

class Board {
private:
	bool** board;
	struct piece_list list_w;
	King target;

public:
	Board(bool** init_board, struct piece_list& list_w, King& target) {
		board = init_board;
		this->list_w = list_w;
		this->target = target;
	}

	void config() {
		/*
		cout << "�� ���� ������ ��ġ >>" << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		*/

		cout << endl;
		cout << "�� ���۰����� ���� ��� >>" << endl;
		for (int i = 0; i < 6; i++) {
			cout << "<" << i + 1 << "��° ��>" << endl;
			cout << "Ÿ�� >> ";
			whatType(list_w, i);
			cout << "��ġ >> ";
			cout << list_w.phones[i].getPosX() << list_w.phones[i].getPosY() << endl;
			cout << endl;
		}

		/*
		cout << "3. �տ� ���� ���� >>" << endl;
		cout << target.getClan() << " ";
		cout << target.getMoveset().mv_backward << target.getMoveset().mv_flag << target.getMoveset().mv_forward << target.getMoveset().mv_side_back << target.getMoveset().mv_side_for << " ";
		cout << (int)target.getPosX() << " ";
		cout << (char)target.getPosY() << " ";
		cout << endl;
		*/
	}

	struct piece_list getList() {
		return list_w;
	};

	King getTarget() {
		return target;
	}
};