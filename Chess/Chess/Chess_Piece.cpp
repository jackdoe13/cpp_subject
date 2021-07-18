#pragma once

#define MAX_X 8			// x��ǥ �ִ�ġ
#define MAX_Y 8			// y��ǥ �ִ�ġ

struct moveSet {
	int mv_forward;
	int mv_backward;
	int mv_side_for;
	int mv_side_back;
	int mv_flag;		// �̵� ���� �÷��� ��. 1 : �밢�� �̵� ��������, 2 : ���� ���� ����, ...
};

class Piece {
protected:
	int code;			// �⹰ �ڵ� (1:ŷ, 2:��, ...)
	bool isAlive;		// ���� ��������
	moveSet mset;		// �̵������� ĭ ��
	char clan;			// �Ҽ���

	// ��ġ��
	char posX;
	int posY;

public:
	Piece(char x, int y, moveSet mv, char clan) {
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}

	Piece() {
		isAlive = true;
		mset.mv_forward = 1;
		mset.mv_backward = 1;
		mset.mv_side_for = 1;
		mset.mv_side_back = 1;
		SetPos('a', 0);
	}

	bool MovePos(char nx, int ny) {
		// �ش� ��ġ�� �̵�. ���� �̵��ϴ� ĭ�� �� ���� ������ óġ.
		if (true) {


		}

		return true;
	}

	bool SetPos(char x, int y) {
		posX = x;
		posY = y;

		return true;
	}

	// getter & setter
	bool getAlive() {
		return isAlive;
	}
	moveSet getMoveset() {
		return mset;
	}
	char getPosX() {
		return posX;
	}
	int getPosY() {
		return posY;
	}
	char getClan() {
		return clan;
	}
};

class King : public Piece {
private:
	bool isCheck() {
		return true;
	}
	bool isCheckMate() {
		return true;
	}


public:
	King(char x, int y, moveSet mv, char clan) {
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}
};

class Phone : public Piece {
private:
	bool isRush;

	void Change_Piece(Piece& dead_piece) {

	}
	void Change_moveset() {

	}

public:
	Phone(char x, int y, moveSet mv, char clan) {
		isAlive = true;
		mset = mv;
		this->clan = clan;
		isRush = false;
		SetPos(x, y);
	}

	Phone() {
		isAlive = true;
		isRush = true;
		mset.mv_forward = 1;
		mset.mv_backward = 1;
		mset.mv_side_for = 1;
		mset.mv_side_back = 1;
		SetPos('a', 0);
	}
};

/*
class Knight : public Piece {
protected:
	bool isAlive;
	int moveset;

	char posX;
	int posY;

public:
	Knight();

};

class Bishop : public Piece {
protected:
	bool isAlive;
	int moveset;

	char posX;
	int posY;

public:
	Bishop();



};

class Rook : public Piece {
protected:
	bool isAlive;
	int moveset;

	char posX;
	int posY;

public:
	Bishop();



};

class Queen : public Piece {
protected:
	bool isAlive;
	int moveset;

	char posX;
	int posY;

public:
	Bishop();



};

class King : public Piece{
protected:
	bool isAlive;
	int moveset;

	char posX;
	int posY;

public:
	Bishop();


};
*/
