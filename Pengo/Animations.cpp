#include "Animations.h"
#include "GlobalVariables.h"
#include "Glut.h"
#include "LoadTexture.h"
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;

Clock::time_point t0, t1;

void drawBoard() {
	board.draw();
}

void loadTextures() {
	Block::texture = LoadTexture::file("textures/Block.bmp");
	Block::textureDiamond = LoadTexture::file("textures/BlockDiamond.bmp");
	Pengo::pengoDown1 = LoadTexture::file("textures/PengoDown1.bmp");
	Pengo::pengoDown2 = LoadTexture::file("textures/PengoDown2.bmp");
	Pengo::pengoUp1 = LoadTexture::file("textures/PengoUp1.bmp");
	Pengo::pengoUp2 = LoadTexture::file("textures/PengoUp2.bmp");
	Pengo::pengoLeft1 = LoadTexture::file("textures/PengoLeft1.bmp");
	Pengo::pengoLeft2 = LoadTexture::file("textures/PengoLeft2.bmp");
	Pengo::pengoRight1 = LoadTexture::file("textures/PengoRight1.bmp");
	Pengo::pengoRight2 = LoadTexture::file("textures/PengoRight2.bmp");
	Pengo::pengoPushDown = LoadTexture::file("textures/PengoPushDown.bmp");
	Pengo::pengoPushUp = LoadTexture::file("textures/PengoPushUp.bmp");
	Pengo::pengoPushLeft = LoadTexture::file("textures/PengoPushLeft.bmp");
	Pengo::pengoPushRight = LoadTexture::file("textures/PengoPushRight.bmp");
	Border::borderHorizontal = LoadTexture::file("textures/BorderHorizontal.bmp");
	Border::borderVertical = LoadTexture::file("textures/BorderVertical.bmp");
}


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
	t0 = Clock::now();
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
		Clock::time_point t1 = Clock::now();
		milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
		std::cout << "Elapsed time is " << ms.count() << " milliseconds\n";
		return;
	}
	
	glutTimerFunc(10, movePengo, direction);
}