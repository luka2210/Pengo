#pragma once
#include "Board.h"

short blockCoords[15][13] = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 0, 1, 1, 2, 0, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
								  {0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
								  {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 ,0},
								  {0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
								  {0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
								  {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
								  {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								  {0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 1, 0},
								  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0} };
Board board = Board(blockCoords, Pengo(8, 6));
Pengo& pengo = board.pengo;