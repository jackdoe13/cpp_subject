#pragma once

#define MAX_X f
#define MAX_Y 8

class Piece {
protected:
	bool isAlive;
	int moveSet;
	// 팀원 구ㅗ분을 위한 변수 ㅍ추가할 것.

	char posX;
	int posY;

public:
	Piece();
	Piece(char x, int y, int moveset);
	bool MovePos(char nx, int ny);
	bool SetPos(char x, int y);

	// getter & setter
	bool getAlive();
	int getMoveset();
	char getPosX();
	int getPosY();
};

Piece::Piece(char x, int y, int moveset) {
	isAlive = true;
	moveset = moveset;
	SetPos(x, y);
}

Piece::Piece() {
	isAlive = true;
	moveSet = 0;
	SetPos(0, 0);
}

bool Piece::MovePos(char nx, int ny) {

	return true;
}

bool Piece::SetPos(char x, int y) {
	posX = x;
	posY = y;

	return true;
}

bool Piece::getAlive() {
	return isAlive;
}
int Piece::getMoveset() {
	return moveSet;
}
char Piece::getPosX() {
	return posX;
}
int Piece::getPosY() {
	return posY;
}

/*
class Phone : public Piece {
protected:
	bool isAlive;
	int moveset;
	
	char posX;
	int posY;

public:
	Phone();
	void Change_moveset();
	void Change_Piece();

};


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