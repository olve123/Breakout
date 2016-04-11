#ifndef PIECE_H
#define PIECE_H
/*
* Intented to be inherited from by Brick, Ball and Paddle classes
* Should be made abstract
*/
#include <string>
using namespace std;

class Piece {
public:
	Piece();
	Piece(int xPos, int yPos, uint32_t color);
	Piece(int xPos, int yPos ,int height, int length, uint32_t color);
	~Piece();

	int getX_Pos();
	int getY_Pos();
	int getHeight();
	int getLength();
	uint32_t getColor();

	void setX_Pos(int pos);
	void setY_Pos(int pos);
	void setHeight(int height);
	void setLength(int length);
	void setColor(uint32_t color);

	void PrintStats() const;
	void initPos(int m_xPos, int m_yPos);
	void initSize(int m_height, int m_length);

protected:
	int m_xPos;
	int m_yPos;
	int m_height;
	int m_length;
	uint32_t m_color;
};

#endif // !PIECE_H
