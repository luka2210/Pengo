#include "Board.h"
#include "Glut.h"

Board::Board() {
	this->pengo = Pengo();
	this->border = Border();
	this->blocks = std::vector<Block>();
	this->enemies = std::vector<Enemy>();
}

Board::Board(short blockCoords[15][13], Pengo pengo) {
	this->pengo = pengo;
	this->border = Border();
	this->blocks = std::vector<Block>();
	this->enemies = std::vector<Enemy>();

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 13; j++)
			if (blockCoords[i][j] == 1)
				blocks.push_back(Block(14 - i, j, false));
			else if (blockCoords[i][j] == 2) 
				blocks.push_back(Block(14 - i, j, true));
			else if (blockCoords[i][j] == 3)
				enemies.push_back(Enemy(14 - i, j, false));
			else if (blockCoords[i][j] == 4)
				enemies.push_back(Enemy(14 - i, j, true));
}

void Board::draw() {
	pengo.draw();
	for (Enemy& enemy : enemies)
		enemy.draw();
	border.draw();
	for (Block& block : blocks)
		block.draw();
}


