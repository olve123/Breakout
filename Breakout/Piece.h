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
	Piece(int height, int length);
	~Piece();

	int getX_Pos();
	int getY_Pos();
	int getHeight();
	int getLength();
	String getColor();

	void setX_Pos(int pos);
	void setY_Pos(int pos);
	void setHeight(int height);
	void setLength(int length);
	void setColor(String color);

	void PrintStats() const;
	void initiatePos(int xPos, int yPos);
	void initiateSize(int height, int length);

private:
	int xPos;
	int yPos;
	int height;
	int length;
	String Color;
};

#endif // !PIECE_H
