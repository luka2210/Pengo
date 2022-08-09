#include "Animations.h"
#include "GlobalVariables.h"
#include "Glut.h"
#include "LoadTexture.h"
#include "TicToc.h"

void drawBoard() {
	board.draw();
}

void loadTextures() {
	Block::texture = LoadTexture::file("textures/Block.bmp");
	Block::textureDiamond = LoadTexture::file("textures/BlockDiamond.bmp");
	Block::textureDestroyed[0] = LoadTexture::file("textures/BlockDestroyed0.bmp");
	Block::textureDestroyed[1] = LoadTexture::file("textures/BlockDestroyed1.bmp");
	Block::textureDestroyed[2] = LoadTexture::file("textures/BlockDestroyed2.bmp");
	Block::textureDestroyed[3] = LoadTexture::file("textures/BlockDestroyed3.bmp");
	Block::textureDestroyed[4] = LoadTexture::file("textures/BlockDestroyed4.bmp");
	Block::textureDestroyed[5] = LoadTexture::file("textures/BlockDestroyed5.bmp");
	Block::textureDestroyed[6] = LoadTexture::file("textures/BlockDestroyed6.bmp");
	Block::textureDestroyed[7] = LoadTexture::file("textures/BlockDestroyed7.bmp");
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
	tic();
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
		toc();
		return;
	}
	
	glutTimerFunc(15, movePengo, direction);
}

void pushPengo() {
	if (pengo.moving || pengo.pushing)
		return;

	switch (pengo.orientation) {
	case 1:
		if (pengo.j == 0) {
			pengoPushingAnimation(0);
			return;
		}
		for (Block& block : board.blocks)
			if (block.i == pengo.i && block.j == pengo.j - 1) {
				if (block.destroyed)
					return;
				pengoPushingAnimation(0);
				pushedBlock = &block;
				blockPush(pengo.orientation);
				return;
			}
		return;
	case 2:
		if (pengo.i == 0) {
			pengoPushingAnimation(0);
			return;
		}
		for (Block& block : board.blocks)
			if (block.j == pengo.j && block.i == pengo.i - 1) {
				if (block.destroyed)
					return;
				pengoPushingAnimation(0);
				pushedBlock = &block;
				blockPush(pengo.orientation);
				return;
			}
		return;
	case 3:
		if (pengo.j == 12) {
			pengoPushingAnimation(0);
			return;
		}
		for (Block& block : board.blocks)
			if (block.i == pengo.i && block.j == pengo.j + 1) {
				if (block.destroyed)
					return;
				pengoPushingAnimation(0);
				pushedBlock = &block;
				blockPush(pengo.orientation);
				return;
			}
		return;
	case 4:
		if (pengo.i == 14) {
			pengoPushingAnimation(0);
			return;
		}
		for (Block& block : board.blocks)
			if (block.j == pengo.j && block.i == pengo.i + 1) {
				if (block.destroyed)
					return;
				pengoPushingAnimation(0);
				pushedBlock = &block;
				blockPush(pengo.orientation);
				return;
			}
		return;
	default:
		return;
	}
}

void pengoPushingAnimation(int stopFlag) {
	if (stopFlag == 0) {
		pengo.pushing = true;
		glutTimerFunc(500, pengoPushingAnimation, 1);
	}
	else
		pengo.pushing = false;
}

void blockPush(int direction) {
	//ako je blok gurnut u smeru do susednog bloka i ako nije dijamant blok onda ga unisti
	pushedBlock->orientation = direction;
	printf("(%d, %d) %d\n", pushedBlock->i, pushedBlock->j, pushedBlock->orientation);
	switch (pushedBlock->orientation) {
	case 1:
		if (pushedBlock->j == 0) {
			checkIfBlockShouldBeDestroyed();
			return;
		}
		for (Block& block : board.blocks)
			if (block.i == pushedBlock->i && block.j == pushedBlock->j - 1) {
				checkIfBlockShouldBeDestroyed();
				return;
			}
		break;
	case 2:
		if (pushedBlock->i == 0) {
			checkIfBlockShouldBeDestroyed();
			return;
		}
		for (Block& block : board.blocks)
			if (block.j == pushedBlock->j && block.i == pushedBlock->i - 1) {
				checkIfBlockShouldBeDestroyed();
				return;
			}
		break;
	case 3:
		if (pushedBlock->j == 12) {
			checkIfBlockShouldBeDestroyed();
			return;
		}
		for (Block& block : board.blocks)
			if (block.i == pushedBlock->i && block.j == pushedBlock->j + 1) {
				checkIfBlockShouldBeDestroyed();
				return;
			}
		break;
	case 4:
		if (pushedBlock->i == 14) {
			checkIfBlockShouldBeDestroyed();
			return;
		}
		for (Block& block : board.blocks)
			if (block.j == pushedBlock->j && block.i == pushedBlock->i + 1) {
				checkIfBlockShouldBeDestroyed();
				return;
			}
		break;
	default:
			break;
	}

	pushedBlock->moving = true;
	pushedBlock->distance += pushedBlock->speed;
	if (pushedBlock->distance >= 1) {
		switch (pushedBlock->orientation) {
		case 1:
			pushedBlock->j--;
			break;
		case 2:
			pushedBlock->i--;
			break;
		case 3:
			pushedBlock->j++;
			break;
		case 4:
			pushedBlock->i++;
			break;
		}
		//pushedBlock->moving = false;
		pushedBlock->distance = 0;
	}
	glutTimerFunc(15, blockPush, direction);
}

void checkIfBlockShouldBeDestroyed() {
	if (!pushedBlock->moving && !pushedBlock->diamond) {
		pushedBlock->destroyed = true;
		blockDestroyedAnimation(pushedBlock->id);
	}
	else 
		pushedBlock->moving = false;
}

void blockDestroyedAnimation(int id) {
	for (std::vector<Block>::iterator blockIterator = board.blocks.begin(); blockIterator != board.blocks.end(); blockIterator++)
		if ((*blockIterator).id == id) {
			if ((*blockIterator).destroyedState < 7) {
				(*blockIterator).destroyedState++;
				glutTimerFunc(50, blockDestroyedAnimation, id);
			}
			else
				board.blocks.erase(blockIterator);
			return;
		}
}

