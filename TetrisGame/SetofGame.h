#pragma once

int score = 0, level = 1;
char wall = 219, block = 219, background = ' ';
bool exitProgram = false, exitMenu = false, exitGame = false;
bool gameHasStarted = false, blockIsActive = false, failure = false;
int nextBlock = 0, currentBlock = 0, blockPosition = 1;
COORD coord;
int X_coord = 6, Y_coord = 1;

void gameDraw();
void gameInput();
void gameLogic();
void clearStart();
void drawMap();
void setWalls();
bool rotationCheck();
void clearScreen(int);
void resetBlock(int);
void mapBlock();
void incrementY();
bool checkForCollision();
void checkForRow();
void decrement(int);
bool failureCheck();
void loss();
void copyMap();
char getBlockVisual();
bool keyIsDown(char, bool = true, bool = true);

char mapTemp[20][12]
{
	'#','#','#','#','#','#','#','#','#','#','#','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
	'#','#','#','#','#','#','#','#','#','#','#','#'
};

char mapCopy[20][12];
int counter = 0, counterLimit = 60;
bool mayMoveLeft = true, mayMoveRight = true;
int fCount = 0;