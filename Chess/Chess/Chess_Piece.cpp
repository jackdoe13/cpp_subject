#pragma once

#define MAX_X 8			// x좌표 최대치
#define MAX_Y 8			// y좌표 최대치

struct moveSet {
	int mv_forward;
	int mv_backward;
	int mv_side_for;
	int mv_side_back;
	int mv_flag;		// 이동 관련 플래그 값. 1 : 대각선 이동 제한조건, 2 : 유닛 무시 조건, ...
};

class Piece {
protected:
	int PieceID = -1;					// 기물 ID (0 : 킹, 1 : 퀸, 2 : 폰, 3 : 비숍, 4 : 룩, 5 : 나이트)
	bool isAlive = false;				// 말의 생존여부
	moveSet mset = { 0, 0, 0, 0, 0 };	// 이동가능한 칸 수
	char clan = -1;						// 소속팀

	// 위치값
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
	King(int x, char y, char clan = 'b', moveSet mv = { 0, 0, 0, 0, 0 }) { // 이슈 : 좌표 형을 변환했는데 계속 기존 변환형이 나옴.
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

	virtual bool getAlive() {		// C2247 방지를 위한 getter setter 재정의
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

	void Change_line(int& x, char& y) {				// 줄의 끝에 도달하면 줄 변경

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