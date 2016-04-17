#include "Bricks.h"

void Bricks::createBricks()
{
	Uint32 colors[] = { 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00800080 };
	
	brickAr.reserve(32);
	int brickWidth = 97;
	int brickHeight = 25;
	int brickSpace = 3;
	int y = 1;
	for (int row = 0; row < 4; row++) {
		int x = 1;

		for (int col = 0; col < 8; col++) {
			Brick b = { static_cast<double>(x),static_cast<double>(y), brickHeight, brickWidth, colors[row], 1 };
			brickAr.push_back(b);
			x += (brickWidth + brickSpace);

		}
		y += (brickHeight + brickSpace);
	}
}

void Bricks::drawBricks(SDL_Surface* dest)
{
	std::vector<Brick>::iterator it;
	for (it = brickAr.begin(); it != brickAr.end(); ++it) {
		it->draw(dest);
	}
}

void Bricks::checkBricks(Ball& ball)
{
	std::vector<Brick>::iterator it;
	int hitCount = 0;
	int ix = 0;
	int deleteIx = -1;
	for (it = brickAr.begin(); (it != brickAr.end()) && (hitCount == 0); ++it) {
		if (TrigonometryFunctions::overlap(ball, it->getRect())) {
			hitCount++;
			deleteIx = ix;
			ball.setY(it->getY() + it->getHeight() + ball.getRadius());
			ball.setYDiff(-ball.getYDiff());

		}
		ix++;
	}
	if (deleteIx > 0) {
		brickAr.erase(brickAr.begin() + deleteIx);
	}
}
