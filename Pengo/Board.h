#pragma once
#include <vector>
#include <algorithm>
#include "Border.h"
#include "Block.h"
#include "Pengo.h"
#include "Glut.h"

using namespace std;

class Board {
public:
	int numEnemy1 = 0, numEnemy2 = 0;
	Border border = Border();
	vector<Block> blocks = vector<Block>();

	Board(short blokcCoords[15][13], int numEnemy1, int numEnemy2);
	void draw();
};

