#include "GameLogic.h"
#include "Glut.h"
#include "LoadTexture.h"
#include "TicToc.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>

int level = 0;
bool levelInitialized = false;
int score = 0;
int animationId = 0;
int lives = 3;

Board board = Board();
Pengo& pengo = board.pengo;
Block* pushedBlock = nullptr;

void initLevel(int level) {
	switch (level) {
	case 1:
		short blockCoords[15][13] = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
									 {0, 1, 0, 1, 1, 1, 3, 1, 1, 2, 0, 1, 0},
									 {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
									 {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
									 {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
									 {0, 1, 0, 1, 1, 2, 1, 1, 1, 1, 0, 1, 0},
									 {0, 1, 3, 0, 0, 1, 0, 0, 0, 1, 3, 1, 0},
									 {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 ,0},
									 {0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
									 {0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
									 {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
									 {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
									 {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
									 {0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 1, 0},
									 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0} };
		board = Board(blockCoords, Pengo(8, 6));
		pengo = board.pengo;
		break;
	}
}

void drawBoard() {
	if (!levelInitialized) {
		srand(time(NULL));
		levelInitialized = true;
		animationId++;
		initLevel(1);
		turnEnemy(animationId);
		enemyChangeStepPos(animationId);
	}
	glColor3f(1, 0, 1);
	glRasterPos2f(1.0, 1.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
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
	Pengo::pengoDead1 = LoadTexture::file("textures/PengoDead1.bmp");
	Pengo::pengoDead2 = LoadTexture::file("textures/PengoDead2.bmp");
	Pengo::pengoIndestructable = LoadTexture::file("textures/PengoIndestructable.bmp");
	Border::borderHorizontal = LoadTexture::file("textures/BorderHorizontal.bmp");
	Border::borderVertical = LoadTexture::file("textures/BorderVertical.bmp");
	Enemy::enemyDown1 = LoadTexture::file("textures/EnemyDown1.bmp");
	Enemy::enemyDown2 = LoadTexture::file("textures/EnemyDown2.bmp");
	Enemy::enemyUp1 = LoadTexture::file("textures/EnemyUp1.bmp");
	Enemy::enemyUp2 = LoadTexture::file("textures/EnemyUp2.bmp");
	Enemy::enemyLeft1 = LoadTexture::file("textures/EnemyLeft1.bmp");
	Enemy::enemyLeft2 = LoadTexture::file("textures/EnemyLeft2.bmp");
	Enemy::enemyRight1 = LoadTexture::file("textures/EnemyRight1.bmp");
	Enemy::enemyRight2 = LoadTexture::file("textures/EnemyRight2.bmp");
	Enemy::enemySweepDown1 = LoadTexture::file("textures/EnemySweepDown1.bmp");
	Enemy::enemySweepDown2 = LoadTexture::file("textures/EnemySweepDown2.bmp");
	Enemy::enemySweepUp1 = LoadTexture::file("textures/EnemySweepUp1.bmp");
	Enemy::enemySweepUp2 = LoadTexture::file("textures/EnemySweepUp2.bmp");
	Enemy::enemySweepLeft1 = LoadTexture::file("textures/EnemySweepLeft1.bmp");
	Enemy::enemySweepLeft2 = LoadTexture::file("textures/EnemySweepLeft2.bmp");
	Enemy::enemySweepRight1 = LoadTexture::file("textures/EnemySweepRight1.bmp");
	Enemy::enemySweepRight2 = LoadTexture::file("textures/EnemySweepRight2.bmp");
	Enemy::enemyStunned1 = LoadTexture::file("textures/EnemyStunned1.bmp");
	Enemy::enemyStunned2 = LoadTexture::file("textures/EnemyStunned2.bmp");
}

void turnPengo(int direction) {
	if (pengo.moving || pengo.pushing || pengo.dead)
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
	if (pengo.dead)
		return;

	pengo.distance += pengo.speed;
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
		return;
	}
	
	glutTimerFunc(15, movePengo, direction);
}

void pushPengo() {
	if (pengo.moving || pengo.pushing || pengo.dead)
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
				if (!block.destroyed) {
					pengoPushingAnimation(0);
					pushedBlock = &block;
					blockPush(pengo.orientation);
				}
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
				if (!block.destroyed) {
					pengoPushingAnimation(0);
					pushedBlock = &block;
					blockPush(pengo.orientation);
				}
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
				if (!block.destroyed) {
					pengoPushingAnimation(0);
					pushedBlock = &block;
					blockPush(pengo.orientation);
				}
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
				if (!block.destroyed) {
					pengoPushingAnimation(0);
					pushedBlock = &block;
					blockPush(pengo.orientation);
				}
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
	blockKillEnemies();
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
		score += 100;
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

void turnEnemy(int animId) {
	if (animId != animationId)
		return;

	for (Enemy& enemy : board.enemies) {
		pengoEnemyInteraction();

		if (enemy.moving || enemy.stunned)
			continue;

		//odredi novu orijentaciju
		if (enemy.sweeping)
			enemy.orientation = sweepingEnemyNewOrientation(&enemy);
		else
			enemy.orientation = enemyNewOrientation(&enemy);

		enemy.moving = true;

		switch (enemy.orientation) {
		case 1:
			if (enemy.j == 0) {
				enemy.moving = false;
				continue;
			}
			for (Block& block : board.blocks)
				if (block.i == enemy.i && block.j == enemy.j - 1) {
					enemyBlockInteraction(&enemy, block);
					break;
				}
			break;
		case 2:
			if (enemy.i == 0) {
				enemy.moving = false;
				continue;
			}
			for (Block& block : board.blocks)
				if (block.j == enemy.j && block.i == enemy.i - 1) {
					enemyBlockInteraction(&enemy, block);
					break;
				}
			break;
		case 3:
			if (enemy.j == 12) {
				enemy.moving = false;
				continue;
			}
			for (Block& block : board.blocks)
				if (block.i == enemy.i && block.j == enemy.j + 1) {
					enemyBlockInteraction(&enemy, block);
					break;
				}
			break;
		case 4:
			if (enemy.i == 14) {
				enemy.moving = false;
				continue;
			}
			for (Block& block : board.blocks)
				if (block.j == enemy.j && block.i == enemy.i + 1) {
					enemyBlockInteraction(&enemy, block);
					break;
				}
			break;
		}
	}
	moveEnemy();
	glutTimerFunc(30, turnEnemy, animId);
}

int enemyNewOrientation(Enemy* enemy) {

	int newOrientation = rand() % 4 + 1;

	switch (enemy->orientation) {
	case 1:
		if (enemy->j == 0)
			return newOrientation;
		for (Block& block : board.blocks)
			if (block.i == enemy->i && block.j == enemy->j - 1)
				return newOrientation;
		break;
	case 2:
		if (enemy->i == 0)
			return newOrientation;
		for (Block& block : board.blocks)
			if (block.j == enemy->j && block.i == enemy->i - 1)
				return newOrientation;
		break;
	case 3:
		if (enemy->j == 12)
			return newOrientation;
		for (Block& block : board.blocks)
			if (block.i == enemy->i && block.j == enemy->j + 1)
				return newOrientation;
		break;
	case 4:
		if (enemy->i == 14)
			return newOrientation;
		for (Block& block : board.blocks)
			if (block.j == enemy->j && block.i == enemy->i + 1)
				return newOrientation;
		break;
	default:
		return enemy->orientation;
	}
	return enemy->orientation;
	return newOrientation;
}

int sweepingEnemyNewOrientation(Enemy* enemy) {
	if (abs(enemy->i - pengo.i) < abs(enemy->j - pengo.j)) {
		if (pengo.j < enemy->j)
			return 1;
		return 3;
	}
	if (pengo.i < enemy->i)
			return 2;
	return 4;
}

void moveEnemy() {
	for (Enemy &enemy: board.enemies)
		if (enemy.moving && !enemy.stunned) {
			enemy.distance += enemy.speed;
			if (enemy.distance >= 1) {
				switch (enemy.orientation) {
				case 1:
					enemy.j--;
					break;
				case 2:
					enemy.i--;
					break;
				case 3:
					enemy.j++;
					break;
				case 4:
					enemy.i++;
					break;
				}
				enemy.moving = false;
				enemy.distance = 0;
			}
		}
}

void enemyBlockInteraction(Enemy* enemy, Block& block) {
	if (enemy->sweeping && !block.diamond) {
		enemy->speed /= 3;
		block.destroyed = true;
		blockDestroyedAnimation(block.id);
		glutTimerFunc(750, sweepingEnemyRestoreSpeed, enemy->id);
	}
	else if (enemy->sweeping && block.diamond) {
		enemy->stunned = true;
		enemy->moving = false;
		glutTimerFunc(2000, sweepingEnemyUnStun, enemy->id);
	}
	else
		enemy->moving = false;
}

void sweepingEnemyRestoreSpeed(int id) {
	for (Enemy& enemy : board.enemies)
		if (enemy.id == id)
			enemy.speed *= 3;
}

void sweepingEnemyUnStun(int id) {
	for (Enemy& enemy : board.enemies)
		if (enemy.id == id)
			enemy.stunned = false;
}

void enemyChangeStepPos(int animId) {
	if (animId != animationId)
		return;

	for (Enemy& enemy : board.enemies)
		enemy.stepPos = !enemy.stepPos;

	glutTimerFunc(250, enemyChangeStepPos, animId);
}

void blockKillEnemies() {
	for (auto enemyIterator = board.enemies.begin(); enemyIterator < board.enemies.end(); enemyIterator++)
		if (abs((*enemyIterator).getPosX() - pushedBlock->getPosX()) < 0.75 && abs((*enemyIterator).getPosY() - pushedBlock->getPosY()) < 0.75) {
			board.enemies.erase(enemyIterator);
			score += 1000;
			return;
		}
}

void pengoEnemyInteraction() {
	if (pengo.dead)
		return;

	for (auto enemyIterator = board.enemies.begin(); enemyIterator < board.enemies.end(); enemyIterator++)
		if (abs((*enemyIterator).getPosX() - pengo.getPosX()) < 0.75 && abs((*enemyIterator).getPosY() - pengo.getPosY()) < 0.75) {
			if ((*enemyIterator).stunned) {
				board.enemies.erase(enemyIterator);
				score += 500;
			}
			else if (!pengo.indestructable) {
				pengo.dead = true;
				lives--;
				glutTimerFunc(3000, pengoRespawn, 0);
				pengoDeadStepPos(0);
			}
			return;
		}
}

void pengoRespawn(int useless) {
	for (Block& block : board.blocks) 
		if (block.i == 8 && block.j == 6) {
			block.destroyed = true;
			blockDestroyedAnimation(block.id);
		}
	board.pengo = Pengo(8, 6);
	pengo = board.pengo;
	pengo.indestructable = true;
	glutTimerFunc(3000, pengoNoLongerIndestructable, 0);
	pengoIndestructableStepPos(0);
}

void pengoNoLongerIndestructable(int useless) {
	pengo.indestructable = false;
}

void pengoIndestructableStepPos(int useless) {
	if (pengo.indestructable) {
		pengo.stepPosIndestructable = !pengo.stepPosIndestructable;
		glutTimerFunc(30, pengoIndestructableStepPos, 0);
	}
}

void pengoDeadStepPos(int useless) {
	if (pengo.dead) {
		pengo.stepPos = !pengo.stepPos;
		glutTimerFunc(200, pengoDeadStepPos, 0);
	}
}