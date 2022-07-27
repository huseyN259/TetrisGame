#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

#include "SetofGame.h"
#include "allFunctions.h"

int main()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << setw(80) << "Loading ";

	const int size = 35;
	char loading = 219;

	for (int i = 0; i < size; i++)
	{
		cout << loading;

		if (i < 10)
		{
			Sleep(300);
		}

		if (i >= 10 && i < 20)
		{
			Sleep(150);
		}

		if (i >= 10)
		{
			Sleep(25);
		}
	}
	system("cls");


	char select;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\nSTART GAME -> PRESS < S >\n";
	cout << "\nGAME RULES -> PRESS < R >\n";
	cout << "\nEXIT -> PRESS < ANY KEY >\n";
	cout << "\n=== Please, enter your selection === -> ";

	cin >> select;

	system("cls");

	if (select == 'S' || select == 's')
	{
		do {
			do
			{
				exitMenu = true;
			} while (!exitMenu);
			while (!exitGame)
			{
				clearScreen(2);
				gameDraw();
				gameInput();
				gameLogic();
			}
		} while (!exitProgram);
		return EXIT_SUCCESS;
	}


	else if (select == 'R' || select == 'r')
	{
		cout << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << setw(80) << " ___________________________________________.___  _________" << endl;
		cout << setw(80) << " \\\\__    ___/\\_   _____/\\__    ___/\\______   \\   |/   _____/" << endl;
		cout << setw(80) << "      |    |     |    __)_   |    |    |       _/   |\\_____  \\" << endl;
		cout << setw(80) << "      |    |     |       \\  |    |    |    |   \\   |/        \\" << endl;
		cout << setw(82) << "      |____|    /_______ /   |____|    |____|_   /___/_______  /" << endl;
		cout << setw(80) << "                    \\/                    \\/            \\/" << endl;

		cout << "\nTetris has very simple rules:\n";
		cout << "You can only move the pieces in specific ways\n";
		cout << "Your game is over if your pieces reach the top of the screen\n";
		cout << "And you can only remove pieces from the screen by filling all the blank space in a line.\n";
		cout << "Rules give much needed structure to our play\n";

		cout << "\nA -> LEFT\n";
		cout << "D -> RIGHT\n";
		cout << "S -> DOWN\n";
		cout << "Q -> ROTATE STONES\n";
		cout << endl;
	}

	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << setw(80) << "<<< GOOD-BYE >>>" << endl;
	}
}