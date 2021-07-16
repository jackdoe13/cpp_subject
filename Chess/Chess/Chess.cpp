// 참여 개발자 : 최주홍, 한세진
// 주제 : 펜팔 체스
// 개발언어 cpp
// 개발착수일자 : 2021.07.16

#include <iostream>
#include <string.h>
#include "Chess_Piece.cpp"

using namespace std;

int main() {
    Piece piece = Piece();
    
    cout << piece.getAlive() << endl;
    cout << piece.getMoveset() << endl;
    cout << piece.getPosX() << endl;
    cout << piece.getPosY() << endl;

    return 0;
}
