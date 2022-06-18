#include "Board.h"

Board::Board(short blockCoords[15][13], int numEnemy1, int numEnemy2) {
	double offsetX = border.getBorderX() + border.getBorderThickness();
	double offsetY = border.getBorderY() + border.getBorderThickness();
	this->numEnemy1 = numEnemy1;
	this->numEnemy2 = numEnemy2;
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 13; j++)
			if (blockCoords[i][j] == 1)
				blocks.push_back(Block(i, j, offsetX, offsetY));
}

void Board::draw() {
	border.draw();
	for (Block block : blocks)
		block.draw();
}
