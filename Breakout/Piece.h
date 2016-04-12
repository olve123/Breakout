#ifndef PIECE_H
#define PIECE_H
/*
* Intented to be inherited from by Brick, Ball and Paddle classes
*/
#include <string>
#include "SDL.h"
using namespace std;

class Piece {
public:
	Piece();
	Piece(int xPos, int yPos, Uint32 color);
	Piece(int xPos, int yPos ,int height, int length, Uint32 color);
	~Piece();

	int getX_Pos();
	int getY_Pos();
	int getHeight();
	int getLength();
	Uint32 getColor();

	void setX_Pos(int pos);
	void setY_Pos(int pos);
	void setHeight(int height);
	void setLength(int length);
	void setColor(Uint32 color);

	void PrintStats() const;
	void initPos(int m_xPos, int m_yPos);
	void initSize(int m_height, int m_length);

protected:
	int m_xPos;
	int m_yPos;
	int m_height;
	int m_length;
	Uint32 m_color;
};

#endif // !PIECE_H
