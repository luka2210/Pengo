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
	vector<Block> blocks = vector<Block>();

	Board(short blokcCoords[15][13]);
	void draw();
};

