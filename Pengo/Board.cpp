#include "Board.h"
#include "LoadTexture.h"

Board::Board(short blockCoords[15][13]) {
	double offsetX = 0.5;
	double offsetY = 1.25;
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 13; j++)
			if (blockCoords[i][j] == 1)
				blocks.push_back(Block(14 - i, j));
}

void Board::draw() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	LoadTexture::image(Block::getImage());
	for (Block &block : blocks)
		block.draw();
	glDisable(GL_TEXTURE_2D);
}


