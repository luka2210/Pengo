#pragma once
#include "Board.h"
#include <string>

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
void enemyChangeStepPos(int useless);
void blockKillEnemies();
void pengoEnemyInteraction();
void pengoRespawn(int useless);
void pengoNoLongerIndestructable(int useless);
void pengoIndestructableStepPos(int useless);
void pengoDeadStepPos(int useless);
void timerTick(int animId);
void diamondBlocksTogether(int animId);
void destroyEverything();
void restartGame(unsigned char key);