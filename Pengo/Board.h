#pragma once
#include <vector>
#include "Border.h"
#include "Block.h"
#include "Pengo.h"
#include "Glut.h"

class Board {
public:
	std::vector<Block> blocks;
	Border border;
	Pengo pengo;

	Board(short blokcCoords[15][13], Pengo pengo);
	void draw();
};

