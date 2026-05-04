#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
COORD c = { 0,0 };
static void Goto_xy(int x, int y)
{
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int score_x = 0, score_o = 0;
char RG[3][3] = { '1','2','3','4','5','6','7','8','9' };
char Game[3][3] = { '1','2','3','4','5','6','7','8','9' };
static void restartGame()
{ 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Game[i][j] = RG[i][j];
}
char player = 'X';
static void printGame()
{
	system("cls");
	Goto_xy(0, 1);
	cout << "Score \"O\" : " << score_o << endl;
	Goto_xy(0, 2);
	cout << "Score \"X\" : " << score_x << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Goto_xy(40 + (i * 5), (j + 1) * 2);
			cout << Game[i][j] << " ";
		}
		cout << endl;
	}
}
static bool checkColumns(char player)
{
	int sum = 0;
	for (int i = 0, j = 0; (i < 3) && (j < 3); i++)
	{
		if (Game[i][j] == player)
		{
			sum++;
		}
		if (i == 2)
		{
			if (sum == 3)
				return true;
			else
			{
				i = 0;
				sum = 0;
				j++;
			}

		}
	}
	return false;
}
static bool checkRows(char player)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Game[i][j] == player)
				sum++;
		}
		if (sum == 3)
			return true;
		else
			sum = 0;
	}
	return false;
}
static bool checkDiagonals(char player)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (Game[i][i] == player)
			sum++;
	}
	if (sum == 3)
		return true;
	if ((Game[2][0] == Game[0][2]) && (Game[0][2] == Game[1][1]))
		return true;
	return false;
}
static bool checkWin(char player)
{
	if (checkColumns(player) || checkDiagonals(player) || checkRows(player))
		return true;
	return false;
}
static bool checkOption(char option)
{
	switch (option)
	{
	case('1'):
	{
		if ((Game[0][0] != 'X') && (Game[0][0] != 'O'))
			return true;
		return false;
	}
	case('2'):
	{
		if (Game[0][1] != 'X' && Game[0][1] != 'O')
			return true;
		return false;

	}
	case('3'):
	{
		if (Game[0][2] != 'X' && Game[0][2] != 'O')
			return true;
		return false;

	}
	case('4'):
	{
		if (Game[1][0] != 'X' && Game[1][0] != 'O')
			return true;
		return false;

	}
	case('5'):
	{
		if (Game[1][1] != 'X' && Game[1][1] != 'O')
			return true;
		return false;

	}
	case('6'):
	{
		if (Game[1][2] != 'X' && Game[1][2] != 'O')
			return true;
		return false;

	}
	case('7'):
	{
		if (Game[2][0] != 'X' && Game[2][0] != 'O')
			return true;
		return false;

	}
	case('8'):
	{
		if (Game[2][1] != 'X' && Game[2][1] != 'O')
			return true;
		return false;

	}
	case('9'):
	{
		if (Game[2][2] != 'X' && Game[2][2] != 'O')
			return true;
		return false;
	}
	default:
		return false;
	}
}
static bool play()
{
	char op = '0';
	do
	{
		Goto_xy(0, 8);
		cout << "CHOOSE YOUR POSITION PLAYER \"" << player << "\" : ";
		op = _getch();
	} while (!checkOption(op));
	switch (op)
	{
	case('1'):
	{
		Game[0][0] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('2'):
	{
		Game[0][1] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('3'):
	{
		Game[0][2] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('4'):
	{
		Game[1][0] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('5'):
	{
		Game[1][1] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('6'):
	{
		Game[1][2] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('7'):
	{
		Game[2][0] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('8'):
	{
		Game[2][1] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	case('9'):
	{
		Game[2][2] = player;
		printGame();
		if (checkWin(player))
		{
			cout << "Player \"" << player << "\" Win" << endl;
			return true;
		}
		else
			player = (player == 'X' ? 'O' : 'X');
		break;
	}
	}
	return false;
}
static void startGame()
{
	int i = 1;
	int rep = 0;
	do
	{
		rep = 0;
		i = 1;
		restartGame();
		system("cls");
		Goto_xy(1, 1);
		cout << "SCORE \"O\" : " << score_o << endl;
		Goto_xy(1, 2);
		cout << "SCORE \"X\" : " << score_x << endl;
		printGame();
		for (; i <= 9; i++)
		{
			if (play())
				break;
		}
		if (i != 9)
		{
			(player == 'X' ? ++score_x : ++score_o);
		}
		cout << "GAME OVER.\nPLAY AGAIN ? (YES Click [1] NO Click [0] : ";
		cin >> rep;
	} while (rep == 1);
}
static void START_GAME()
{
	Goto_xy(40, 1);
	cout << char(201);
	for (int i = 1; i <= 20; i++)
		cout << char(205);
	cout << char(187);
	Goto_xy(40, 2);
	cout << char(186);
	for (int i = 1; i <= 20; i++)
		cout << " ";
	cout << char(186);
	Goto_xy(40, 3);
	cout << char(186);
	for (int i = 1; i <= 20; i++)
		cout << " ";
	cout << char(186);
	Goto_xy(40, 4);
	cout << char(200);
	for (int i = 1; i <= 20; i++)
		cout << char(205);
	cout << char(188);
	HANDLE consol = GetStdHandle(STD_OUTPUT_HANDLE);
	Goto_xy(22, 0);
	cout << "--------------------<<<<<\"XO_GAME\">>>>>--------------------" << endl;
	int pos = 1;
	char ch = '\0';
	do
	{
		SetConsoleTextAttribute(consol, 15);
		Goto_xy(42, 2);
		cout << "[1] START GAME     " << endl;
		Goto_xy(42, 3);
		cout << "[2] END GAME       " << endl;
		switch (pos)
		{
		case(1):
		{
			SetConsoleTextAttribute(consol, 240);
			Goto_xy(42, 2);
			cout << "[1] START GAME     " << endl;
			break;
		}
		case(2):
		{
			SetConsoleTextAttribute(consol, 240);
			Goto_xy(42, 3);
			cout << "[2] END GAME       " << endl;
			break;
		}
		}
		ch = _getch();
		if (ch == -32)
			ch = _getch();
		if (ch == 72)
		{
			pos--;
			if (pos == 0)
				pos = 2;
		}
		if (ch == 80)
		{
			pos++;
			if (pos == 3)
				pos = 1;
		}

	} while (ch != 13);
	SetConsoleTextAttribute(consol, 15);
	if (pos == 1)
	{
		system("cls");
		startGame();
	}
	else
	{
		system("cls");
		return;
	}
}
