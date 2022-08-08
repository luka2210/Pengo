#include "Animations.h"
#include "GlobalVariables.h"
#include "Glut.h"

void turnPengo(int direction) {
	if (pengo.moving || pengo.pushing)
		return;
	pengo.orientation = direction;

	switch (direction) {
	case 1:
		if (pengo.j == 0)
			return;
		for (Block& block : board.blocks)
			if (block.i == pengo.i && block.j == pengo.j - 1)
				return;
		break;
	case 2:
		if (pengo.i == 0)
			return;
		for (Block& block : board.blocks)
			if (block.j == pengo.j && block.i == pengo.i - 1)
				return;
		break;
	case 3:
		if (pengo.j == 12)
			return;
		for (Block& block : board.blocks)
			if (block.i == pengo.i && block.j == pengo.j + 1)
				return;
		break;
	case 4:
		if (pengo.i == 14)
			return;
		for (Block& block : board.blocks)
			if (block.j == pengo.j && block.i == pengo.i + 1)
				return;
		break;
	default:
		return;
	}

	pengo.moving = true;
	pengo.stepPos = !pengo.stepPos;
	movePengo(direction);
}

void movePengo(int direction) {
	pengo.distance += pengo.speed;
	//pengo.stepPos = !pengo.stepPos;
	if (pengo.distance >= 1) {
		switch (direction) {
		case 1:
			pengo.j--;
			break;
		case 2:
			pengo.i--;
			break;
		case 3:
			pengo.j++;
			break;
		case 4:
			pengo.i++;
			break;
		}
		pengo.moving = false;
		pengo.distance = 0;
		printf("///\n");
		return;
	}
	printf("pengo moved\n");
	glutTimerFunc(10, movePengo, direction);
}