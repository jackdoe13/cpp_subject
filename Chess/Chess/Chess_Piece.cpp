#pragma once

#include <random>
#include <time.h>

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
	int PieceID;		// 기물 ID (0 : 킹, 1 : 퀸, 2 : 폰, 3 : 비숍, 4 : 룩, 5 : 나이트)
	bool isAlive;		// 말의 생존여부
	moveSet mset;		// 이동가능한 칸 수
	char clan;			// 소속팀

	// 위치값
	char posX;
	int posY;

public:
	virtual bool MovePos(char nx, int ny) = 0;

	virtual bool SetPos(char x, int y) = 0;

	// getter & setter
	virtual bool getAlive() {
		return isAlive;
	}
	virtual moveSet getMoveset() {
		return mset;
	}
	virtual char getPosX() {
		return posX;
	}
	virtual int getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class King : Piece {
private:
	int check;

	bool isCheck(char &kx, int &ky, int &x, int &y, Piece &obj) {
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
	King() {
		PieceID = 0;
		isAlive = true;
		check = 0;
		SetPos('a', 0);
		mset = { 0, 0, 0, 0, 0 };
		clan = 'b';
	}

	bool SetPos(char x, int y) {
		posX = x;
		posY = y;

		return true;
	}

	bool MovePos(char nx, int ny) {

	}

	virtual bool getAlive() {
		return isAlive;
	}
	virtual moveSet getMoveset() {
		return mset;
	}
	virtual char getPosX() {
		return posX;
	}
	virtual int getPosY() {
		return posY;
	}
	virtual char getClan() {
		return clan;
	}
};

class Phone : public Piece {
private:
	bool isRush;

	void Change_line(int &x, int &y) {				// 줄의 끝에 도달하면 줄 변경

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
		clan = 'w';
		mset = { 0, 0, 0, 0, 0 };
	}

	bool SetPos(char x, int y) {
		posX = x;
		posY = y;

		return true;
	}

	bool MovePos(char nx, int ny) {
		posX = nx;
		posY = ny;

		return true;
	}
};

class Knight : public Piece {
public:
	Knight(char x, int y, moveSet mv, char clan) {
		isAlive = true;
		mset = mv;
		this->clan = clan;
		SetPos(x, y);
	}

	Knight() {
		isAlive = true;
		mset = { 0, 0, 0, 0, 0 };
		clan = 'w';
		SetPos('a', 0);
	}

};
/*
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
