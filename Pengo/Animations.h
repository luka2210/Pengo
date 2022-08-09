#pragma once

void drawBoard();
void loadTextures();
void turnPengo(int direction);
void movePengo(int direction);
void pushPengo();
void pengoPushingAnimation(int stopFlag);
void blockPush(int direction);
void blockDestroyedAnimation(int state);
void checkIfBlockShouldBeDestroyed();