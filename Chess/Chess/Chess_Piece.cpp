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
	int code;			// 기물 코드 (1:킹, 2:폰, ...)
	bool isAlive;		// 말의 생존여부
	moveSet mset;		// 이동가능한 칸 수
	char clan;			// 소속팀

	// 위치값
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
		// 해당 위치로 이동. 만약 이동하는 칸에 적 말이 있으면 처치.
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
