#pragma once
#include <vector>
#include "Border.h"
#include "Block.h"
#include "Pengo.h"
#include "Enemy.h"

class Board {
public:
	std::vector<Block> blocks;
	std::vector<Enemy> enemies;
	Border border;
	Pengo pengo;

	Board();
	Board(short blockCoords[15][13], Pengo pengo);
	void draw();
};

