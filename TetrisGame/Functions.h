#pragma once

void clearStart()
{
	for (int i = 1; i <= 10; i++)
		mapTemp[9][i] = ' ';
}

void drawMap()
{
	if (!failure)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (!gameHasStarted)
					if (i == 9 && j >= 2 && j <= 7)
						cout << mapTemp[i][j];
				if (mapTemp[i][j] == '#')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << wall;
				}
				if (mapTemp[i][j] == '@')
				{
					switch (currentBlock)
					{
					case 1:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					case 2:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					case 3:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					case 4:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					case 5:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					case 6:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					case 7:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						break;
					}
					cout << block;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				}
				if (mapTemp[i][j] == '$')
					cout << block;
				if (mapTemp[i][j] == ' ')
					cout << background;
				if (i == 0 && j == 11)
					cout << wall << wall << wall << wall << wall << wall;
				if (i == 1 && j == 11)
					cout << "Next " << wall;
				if (i == 2 && j == 11)
					cout << "  " << getBlockVisual() << "  " << wall;
				if (i == 3 && j == 11)
					cout << wall << wall << wall << wall << wall << wall;
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (mapCopy[i][j] == '#')
					cout << wall;
				if (mapCopy[i][j] == '@')
					cout << block;
				if (mapCopy[i][j] == '$')
					cout << block;
				if (mapCopy[i][j] == ' ')
					cout << background;
			}
			cout << endl;
		}
		cout << "<<< GAME OVER >>>";
	}
}
char getBlockVisual()
{
	switch (nextBlock)
	{
	case 1:
		return 'O';
		break;
	case 2:
		return 'T';
		break;
	case 3:
		return 'Z';
		break;
	case 4:
		return 'S';
		break;
	case 5:
		return 'I';
		break;
	case 6:
		return 'J';
		break;
	case 7:
		return 'L';
		break;
	default:
		return ' ';
		break;
	}
}

void clearScreen(int clear)
{
	coord.X = 0;
	coord.Y = 0;
	switch (clear)
	{
	case 1:
		system("cls");
	case 2:
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}
void setWalls()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if ((i == 0 || i == 19) || (j == 0 || j == 11))
				mapTemp[i][j] = '#';
		}
	}
}
void resetBlock(int a)
{
	srand(time(0));
	bool blockHasFallenOnce = false;

	if (failureCheck())
	{
		failure = true;
		copyMap();
	}
	X_coord = 6;
	Y_coord = 1;

	if (a == 0)
	{
		if (nextBlock == 0)
		{
			blockHasFallenOnce = true;
			currentBlock = rand() % 7 + 1;

		}
		else
			currentBlock = nextBlock;
		nextBlock = rand() % 7 + 1;
	}
	else
	{
		currentBlock = a;
		nextBlock = a;
	}
}
void mapBlock()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (mapTemp[i][j] == '@')
				mapTemp[i][j] = ' ';
		}
	}
	switch (currentBlock)
	{
	case 1: // O block
		switch (blockPosition)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord + 1] = '@';
		}
		break;
	case 2: // T block
		switch (blockPosition)
		{
		case 1:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			break;
		case 2:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			break;
		case 3:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			break;
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			break;
		}
		break;
	case 3: // Z block
		switch (blockPosition)
		{
		case 1:
		case 3:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord + 1][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			break;
		case 2:
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord - 1][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			break;
		}
		break;
	case 4: // S block
		switch (blockPosition)
		{
		case 1:
		case 3:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord - 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			break;
		case 2:
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord + 1][X_coord + 1] = '@';
			break;
		}
		break;
	case 5: // I block
		switch (blockPosition)
		{
		case 1:
		case 3:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord + 2][X_coord] = '@';
			break;
		case 2:
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord][X_coord - 2] = '@';
			break;
		}
		break;
	case 6: // L block
		switch (blockPosition)
		{
		case 1:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord + 1] = '@';
			break;
		case 2:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord + 1][X_coord + 1] = '@';
			break;
		case 3:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord - 1] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			break;
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			mapTemp[Y_coord - 1][X_coord - 1] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			break;
		}
		break;
	case 7: // J block
		switch (blockPosition)
		{
		case 1:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			mapTemp[Y_coord + 1][X_coord + 1] = '@';
			break;
		case 2:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord + 1][X_coord - 1] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			break;
		case 3:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord - 1] = '@';
			mapTemp[Y_coord + 1][X_coord] = '@';
			break;
		case 4:
			mapTemp[Y_coord][X_coord] = '@';
			mapTemp[Y_coord - 1][X_coord + 1] = '@';
			mapTemp[Y_coord][X_coord - 1] = '@';
			mapTemp[Y_coord][X_coord + 1] = '@';
			break;
		}
		break;
	}
}

void incrementY()
{
	Y_coord++;
}
bool checkForCollision()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (mapTemp[i][j] == '@')
			{
				if (mapTemp[i + 1][j] == '#' || mapTemp[i + 1][j] == '$')
				{
					for (int k = 0; k < 20; k++)
					{
						for (int g = 0; g < 12; g++)
						{
							if (mapTemp[k][g] == '@')
								mapTemp[k][g] = '$';
						}
					}
					blockIsActive = false;
					return true;
				}
				if (mapTemp[i][j - 1] == '#' || mapTemp[i][j - 1] == '$')
					mayMoveLeft = false;
				if (mapTemp[i][j + 1] == '#' || mapTemp[i][j + 1] == '$')
					mayMoveRight = false;
			}
		}
	}
	return false;
}
void checkForRow()
{
	int row_counter = 0;
	int column_counter = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (mapTemp[i][j] == '$')
				row_counter++;
		}
		if (row_counter == 10)
		{
			Sleep(300);
			clearScreen(2);
			drawMap();
			column_counter++;
			for (int s = 1; s < 11; s++)
			{
				mapTemp[i][s] = ' ';
			}
			decrement(i);
		}
		row_counter = 0;
	}
	if (column_counter != 0)
		score += static_cast<int>((column_counter, 1) * 100);
	column_counter = 0;
}

void decrement(int r)
{
	for (int i = r - 1; i > 1; i--)
	{
		for (int j = 0; j < 12; j++)
		{
			if (mapTemp[i][j] == '$')
			{
				mapTemp[i + 1][j] = '$';
				mapTemp[i][j] = ' ';
			}
		}
	}
}

bool rotationCheck()
{
	switch (currentBlock)
	{
	case 1:
		// No rotation on O block
		return true;
		break;
	case 2: // T
		switch (blockPosition)
		{
		case 1:
			if (mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$')
				return false;
		case 2:
			if (mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$')
				return false;
		case 3:
			if (mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$')
				return false;
		case 4:
			if (mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$')
				return false;
		default:
			return true;
		}
	case 3: // Z
		switch (blockPosition)
		{
		case 1:
		case 3:
			if ((mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$') || (mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$'))
				return false;
		case 2:
		case 4:
			if ((mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$') || (mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$'))
				return false;
		default:
			return true;
		}
	case 4: // S
		switch (blockPosition)
		{
		case 1:
		case 3:
			if (mapTemp[Y_coord + 1][X_coord - 1] == '#' || mapTemp[Y_coord + 1][X_coord - 1] == '$')
				return false;
		case 2:
		case 4:
			if (mapTemp[Y_coord - 1][X_coord + 1] == '#' || mapTemp[Y_coord - 1][X_coord + 1] == '$')
				return false;
		default:
			return true;
		}
	case 5: // I
		switch (blockPosition)
		{
		case 1:
		case 3:
			if ((mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$') || (mapTemp[Y_coord][X_coord - 2] == '#' || mapTemp[Y_coord][X_coord - 2] == '$') || (mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$'))
				return false;
		case 2:
		case 4:
			if ((mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$') || (mapTemp[Y_coord + 2][X_coord] == '#' || mapTemp[Y_coord + 2][X_coord] == '$') || (mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$'))
				return false;
		default:
			return true;
		}
		break;
	case 6: // L
		switch (blockPosition)
		{
		case 1:
			if ((mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$') || (mapTemp[Y_coord + 1][X_coord + 1] == '#' || mapTemp[Y_coord + 1][X_coord + 1] == '$') || (mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$'))
				return false;
		case 2:
			if ((mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$') || (mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$') || (mapTemp[Y_coord + 1][X_coord - 1] == '#' || mapTemp[Y_coord + 1][X_coord - 1] == '$'))
				return false;
		case 3:
			if ((mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$') || (mapTemp[Y_coord - 1][X_coord - 1] == '#' || mapTemp[Y_coord - 1][X_coord - 1] == '$') || (mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$'))
				return false;
		case 4:
			if ((mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$') || (mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$') || (mapTemp[Y_coord - 1][X_coord + 1] == '#' || mapTemp[Y_coord - 1][X_coord + 1] == '$'))
				return false;
		default:
			return true;
		}
	case 7: // J
		switch (blockPosition)
		{
		case 1:
			if ((mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$') || (mapTemp[Y_coord - 1][X_coord - 1] == '#' || mapTemp[Y_coord - 1][X_coord - 1] == '$') || (mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$'))
				return false;
		case 2:
			if ((mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$') || (mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$') || (mapTemp[Y_coord - 1][X_coord - 1] == '#' || mapTemp[Y_coord - 1][X_coord - 1] == '$'))
				return false;
		case 3:
			if ((mapTemp[Y_coord][X_coord + 1] == '#' || mapTemp[Y_coord][X_coord + 1] == '$') || (mapTemp[Y_coord - 1][X_coord + 1] == '#' || mapTemp[Y_coord - 1][X_coord + 1] == '$') || (mapTemp[Y_coord][X_coord - 1] == '#' || mapTemp[Y_coord][X_coord - 1] == '$'))
				return false;
		case 4:
			if ((mapTemp[Y_coord - 1][X_coord] == '#' || mapTemp[Y_coord - 1][X_coord] == '$') || (mapTemp[Y_coord + 1][X_coord] == '#' || mapTemp[Y_coord + 1][X_coord] == '$') || (mapTemp[Y_coord + 1][X_coord + 1] == '#' || mapTemp[Y_coord + 1][X_coord + 1] == '$'))
				return false;
		default:
			return true;
		}
	default:
		return true;
	}
}
bool failureCheck()
{
	for (int i = 0; i < 12; i++)
	{
		if (mapTemp[2][i] == '$')
		{
			fCount++;
			break;
		}
	}
	if (fCount == 2)
		return true;
	else
		return false;
}

void copyMap()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			mapCopy[i][j] = mapTemp[i][j];
		}
	}
}

void loss()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	gameHasStarted = false;
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			clearScreen(2);
			Sleep(3);
			mapCopy[i][j] = '#';
			drawMap();
		}
	}
	Sleep(2000);
	exitProgram = true;
	exitGame = true;
}

void gameDraw()
{
	drawMap();
	cout << endl << "   Score: " << score << endl;
	cout << "   Level: " << level << endl;
}

void gameInput()
{
	checkForCollision();
	char gmA = 13;

	if (keyIsDown(gmA))
	{
		if (!gameHasStarted)
		{
			gameHasStarted = true;
			clearStart();
		}
	}
	if (keyIsDown('A', true, false) && !keyIsDown('D', true, false))
	{
		if (mayMoveLeft)
		{
			X_coord--;
		}
		counterLimit = 60;
	}
	else if (keyIsDown('D', true, false) && !keyIsDown('A', true, false))
	{
		if (mayMoveRight)
		{
			X_coord++;
		}
		counterLimit = 60;
	}
	else if (keyIsDown('S'))
	{
		if (counter != 0)
		{
			if (counter > 4)
			{
				counter = 3;
			}
			counterLimit = 4;
		}
	}
	else if (keyIsDown('Q', true, false))
	{
		if (rotationCheck())
		{
			blockPosition++;
		}
	}
	else
	{
		counterLimit = 60;
	}
	mayMoveRight = true;
	mayMoveLeft = true;
}

void gameLogic()
{
	checkForCollision();
	if (blockPosition == 5)
	{
		blockPosition = 1;
	}
	if (gameHasStarted)
	{
		counter++;
		if (blockIsActive)
		{
			mapBlock();
			if (counter == counterLimit)
			{
				if (!checkForCollision())
				{
					incrementY();
				}
				counter = 0;
			}
			mapBlock();
		}
		else
		{
			resetBlock(0);
			mapBlock();
			blockIsActive = true;
			blockPosition = 1;
		}
	}

	checkForCollision();
	checkForRow();
	setWalls();
	if (score > 1000)
	{
		level = (score / 1000) + 1;
	}
	if (failure)
	{
		loss();
	}
}

bool keyIsDown(char key, bool pressed, bool held)
{
	int keyState = GetAsyncKeyState(key);
	return (pressed && (keyState & 1)) || (held && keyState);
}