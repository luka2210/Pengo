#pragma once
#include "Enemy.h"
#include "Block.h"

void drawBoard();
void loadTextures();
void turnPengo(int direction);
void movePengo(int direction);
void pushPengo();
void pengoPushingAnimation(int stopFlag);
void blockPush(int direction);
void blockDestroyedAnimation(int state);
void checkIfBlockShouldBeDestroyed();
void turnEnemy(int useless);
int sweepingEnemyNewOrientation(Enemy* enemy);
int enemyNewOrientation(Enemy* enemy);
void moveEnemy();
void enemyBlockInteraction(Enemy* enemy, Block& block);
void sweepingEnemyRestoreSpeed(int id);
void sweepingEnemyUnStun(int id);
void sweepingEnemyStunnedChangeStepPos(int id);