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
	int PieceID = -1;					// �⹰ ID (0 : ŷ, 1 : ��, 2 : ��, 3 : ���, 4 : ��, 5 : ����Ʈ)
	bool isAlive = false;				// ���� ��������
	moveSet mset = { 0, 0, 0, 0, 0 };	// �̵������� ĭ ��
	char clan = -1;						// �Ҽ���

	// ��ġ��
	int posX = -1;
	char posY = -1;

public:
	virtual bool MovePos(int nx, char ny) = 0;

	virtual bool SetPos(int x, char y) = 0;

	// getter & setter
	virtual bool getAlive() {
		return isAlive;
	}
	virtual moveSet getMoveset() {
		return mset;
	}
	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class King : Piece {
private:
	int check;

	bool isCheck(int& kx, char& ky, int& x, char& y, Piece& obj) {
		if (true) {
			return true;
		}
		else {
			return false;
		}

	}

	bool isCheckMate() {
		return true;
	}


public:
	King(int x, char y, char clan = 'b', moveSet mv = { 0, 0, 0, 0, 0 }) { // �̽� : ��ǥ ���� ��ȯ�ߴµ� ��� ���� ��ȯ���� ����.
		PieceID = 0;
		isAlive = true;
		check = 0;
		this->clan = clan;
		SetPos(x, y);
		mset = mv;
	}

	King() {
		PieceID = 0;
		isAlive = true;
		check = 0;
		SetPos('a', 0);
		mset = { 0, 0, 0, 0, 0 };
		clan = 'b';
	}

	virtual bool SetPos(int x, char y) {
		posX = x;
		posY = y;

		return true;
	}

	virtual bool MovePos(int nx, char ny) {
		return true;
	}

	virtual bool getAlive() {		// C2247 ������ ���� getter setter ������
		return isAlive;
	}
	virtual moveSet getMoveset() {
		return mset;
	}
	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class Phone : public Piece {
private:
	bool isRush;

	void Change_line(int& x, char& y) {				// ���� ���� �����ϸ� �� ����

	}

public:
	Phone(int x, char y, char clan = 'w', moveSet mv = { 2, 0, 1, 0, 1 }) {
		PieceID = 2;
		isAlive = true;
		mset = mv;
		this->clan = clan;
		isRush = false;
		SetPos(x, y);
	}

	Phone() {
		PieceID = 2;
		isAlive = true;
		isRush = true;
		clan = 'w';
		mset = { 0, 0, 0, 0, 0 };
	}

	bool SetPos(int x, char y) {
		posX = x;
		posY = y;

		return true;
	}

	bool MovePos(int nx, char ny) {
		posX = nx;
		posY = ny;

		return true;
	}

	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class Knight : public Piece {
public:
	Knight(int x, char y, char clan = 'w', moveSet mv = { 1, 1, 1, 1, 2 }) {
		PieceID = 5;
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}
	/*
	Knight() {
		PieceID = 5;
		isAlive = true;
		mset = { 0, 0, 0, 0, 0 };
		clan = 'w';
		SetPos('a', 0);
	}
	*/
	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class Bishop : public Piece {
public:
	Bishop(int x, char y, char clan = 'w', moveSet mv = { 0, 0, 8, 8, 0 }) {
		PieceID = 3;
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}
	/*
	Bishop() {
		PieceID = 3;
		isAlive = true;
		mset = { 0, 0, 0, 0, 0 };
		clan = 'w';
		SetPos('a', 0);
	}
	*/
	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class Rook : public Piece {
public:
	Rook(int x, char y, char clan = 'w', moveSet mv = { 8, 8, 0, 0, 0 }) {
		PieceID = 3;
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}
	/*
	Rook() {
		PieceID = 3;
		isAlive = true;
		mset = { 0, 0, 0, 0, 0 };
		clan = 'w';
		SetPos('a', 0);
	}
	*/
	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class Queen : public Piece {
public:
	Queen(int x, char y, char clan = 'w', moveSet mv = { 8, 8, 8, 8, 0 }) {
		PieceID = 1;
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}
	/*
	Queen() {
		PieceID = 1;
		isAlive = true;
		mset = { 0, 0, 0, 0, 0 };
		clan = 'w';
		SetPos('a', 0);
	}
	*/
	virtual int getPosX() {
		return posX;
	}
	virtual char getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};