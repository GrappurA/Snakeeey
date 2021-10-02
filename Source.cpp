#include<iostream>
#include<conio.h>
#include <windows.h>

using namespace std;
void draw();
void logic();
void input();

bool gameover = false;
const int width = 20, height = 20;
int sx = width / 2, sy = height / 2;
int fx = rand() % width, fy = rand() % height;
int Bfx = rand() % width, Bfy = rand() % height;
int gamemode = 0;
int score = 0;
int tx[100], ty[100];
int t;
int speed;
int applespeed;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
enum direction
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
direction dir;

int main() {

	system("mode con cols=22 lines=24");
	system("color 06");
	logic();

	cout << "Choose gamemode\n 1 - hard ||| 0 - easy\n";
	cin >> gamemode;
	cout << endl;
	cout << "Set speed:\n 1 - FAST\n 2 - MEDIUM\n 3 - SLOW\n ULTRA SPEED - 8\n";
	cin >> speed;


	while (!gameover)
	{

		logic();
		draw();
		input();

		cout << "Score - " << score;
	}


	return 0;
}


void draw() {
	system("cls");
	for (int i = 0; i < width; i++)
	{

		cout << "#";
	}
	cout << endl;
	/////////////////////////////////

	for (int i = 0; i < height + 1; i++)
	{
		for (int j = 0; j < width + 1; j++)
		{
			if (j == 0 || j == width - 1)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "#";
			}

			else if (i == sy && j == sx)
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE);
				cout << "@";
			}
			else if (i == fy && j == fx)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				cout << "F";
			}
			else {
				bool aesthetic = true;
				for (int k = 0; k < t; k++)
				{
					if (tx[k] == j && ty[k] == i)
					{
						SetConsoleTextAttribute(h, FOREGROUND_BLUE);
						cout << "o";
						aesthetic = false;
					}


				}
				if (aesthetic) cout << " ";



			}



		}
		cout << endl;
	}
	/////////////////////////////////
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	/////////////////////////////////
}



void logic() {
	switch (speed)
	{
	case 3:
		Sleep(50);
	case 2:
		Sleep(40);
	case 1:
		Sleep(35);
	default:
		break;
	case 8:
		Sleep(0);
	}

	int px = tx[0], py = ty[0];
	int p2x, p2y;
	tx[0] = sx;
	ty[0] = sy;
	for (int i = 1; i < t; i++)
	{
		p2x = tx[i];
		p2y = ty[i];
		tx[i] = px;
		ty[i] = py;
		px = p2x;
		py = p2y;
	}


	switch (dir)
	{
	case STOP:
		break;
	case LEFT:
		sx--;
		break;
	case RIGHT:
		sx++;
		break;
	case UP:
		sy--;
		break;
	case DOWN:
		sy++;
		break;
	default:
		break;
	}



	switch (gamemode)
	{
	case 1:
		if (sx > width || sx < 0)
		{
			gameover = true;
		}
		else if (sy > height || sy < 0)
		{
			system("cls");
			gameover = true;

		}


		break;
	case 0:

		if (sx >= width)
		{
			sx = 0;
		}
		else if (sx < 0)
		{
			sx = width - 1;
		}
		if (sy >= height)
		{
			sy = 0;
		}
		else if (sy < 0)
		{
			sy = height - 1;
		}






	default:
		break;
	}




	if (sx == fx && sy == fy)
	{
		score++;
		Beep(700, 100);
		fx = rand() % width;
		fy = rand() % height;
		t++;

	}






}





void input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 97: dir = LEFT;
			break;
		case 119: dir = UP;
			break;
		case 115: dir = DOWN;
			break;
		case 100: dir = RIGHT;
			break;
		case 228: dir = LEFT;
			break;
		case 162: dir = RIGHT;
			break;
		case 230: dir = UP;
			break;
		case 63: dir = DOWN;
			break;
		case 235: dir = DOWN;
			break;
		}
	}





}
