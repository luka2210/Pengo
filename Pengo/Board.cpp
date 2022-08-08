#include "Board.h"
#include "LoadTexture.h"

Board::Board(short blockCoords[15][13], Pengo pengo) {
	this->pengo = pengo;
	this->border = Border();
	this->blocks = std::vector<Block>();

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 13; j++)
			if (blockCoords[i][j] == 1)
				blocks.push_back(Block(14 - i, j, false));
			else if (blockCoords[i][j] == 2)
				blocks.push_back(Block(14 - i, j, true));
}

void Board::draw() {
	border.draw();
	pengo.draw();	
	for (Block &block : blocks)
		block.draw();
}


