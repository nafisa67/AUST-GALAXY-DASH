#include "iGraphics.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <deque>
#include <utility>
#include <fstream>
#include <set>

using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

char BG1[50] = {"Space Time Continuum.bmp"};
char BG2[50] = { "Red Space.bmp" };
char BG3[50] = { "Burning Planet.bmp" };
char BG4[50] = { "Saving Earth.bmp" };
char apollo11[50] = { "Spaceship.bmp" };
char apollo12[50] = { "Spaceship 2.bmp" };
char apollo13[50] = { "Spaceship 3.bmp" };
char apollo14[50] = { "Spaceship 4.bmp" };
char enemy1[50] = { "Enemy1.bmp" };
char enemy2[50] = { "Enemy1.bmp" };
char enemy3[50] = { "Enemy1.bmp" };
char enemy4[50] = { "Enemy2.bmp" };
char enemy5[50] = { "Enemy2.bmp" };
char enemy6[50] = { "Enemy2.bmp" };
char enemy7[50] = { "Enemy3.bmp" };
char enemy8[50] = { "Enemy3.bmp" };
char enemy9[50] = { "Enemy3.bmp" };
char enemy10[50] = { "Enemy4.bmp" };
char enemy11[50] = { "Enemy4.bmp" };
char enemy12[50] = { "Enemy4.bmp" };
char laser[50] = { "Laser.bmp" };
char enterName[50] = { "Enter Name.bmp" };
char stat[10] = { "Score: " };
char health[10] = { "Life: " };
char name[50];
char gameBG[50] = { "Menu BG.bmp" };
char option1[50] = { "Menu option 1.bmp" };
char option2[50] = { "Menu option 2.bmp" };
char option3[50] = { "Menu option 3.bmp" };
char option4[50] = { "Menu option 4.bmp" };
char levels1[50] = { "Levels 1.bmp" };
char levels2[50] = { "Levels 2.bmp" };
char levels3[50] = { "Levels 3.bmp" };
char levels4[50] = { "Levels 4.bmp" };
char creds[50] = { "Credits.bmp" };
char pause1[50] = { "Pause Menu 1.bmp" };
char pause2[50] = { "Pause Menu 2.bmp" };
char highscores[50] = { "Highscores.bmp" };

char scorestr[1000];
char lifestr[10];

int indexNumber = 0;
int apollox = 100;
int apolloy = 400;
int enemy1x = 1700;
int enemy1y = 700;
int enemy2x = 2100;
int enemy2y = 200;
int enemy3x = 2500;
int enemy3y = 500;
int score = 0;
int life = 5;
int x = 6;
int y = 6;
int z = 6;
int key1 = 1;
int key2 = 1;
int key3 = 1;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;

int gamestate = 0;
int is_game_on = 0;
int level = 0;

set<pair<int, string>>scoreboard;


typedef struct 
{
	int bulletx, bullety;
}bullet;

deque < bullet > bullet_arr;

void iDraw()
{
	iClear();
	if (gamestate == 0)
	{
		iShowBMP(0, 0, gameBG);
	}
	else if (gamestate == 1)
	{
		iShowBMP(0, 0, option1);
	}
	else if (gamestate == 2)
	{
		iShowBMP(0, 0, option2);
	}
	else if (gamestate == 3)
	{
		iShowBMP(0, 0, option3);
	}
	else if (gamestate == 4)
	{
		iShowBMP(0, 0, option4);
	}
	else if (gamestate == 5)
	{
		iShowBMP(0, 0, creds);
	}
	else if (gamestate == 6)
	{
		iShowBMP(0, 0, highscores);
		set<pair<int, string> >::reverse_iterator rit;
		pair<int, string>temp;
		int y = 705;
		int count = 0;
		char score[50];
		char name[50];
		string line;
		int i, x;
		for (rit = scoreboard.rbegin(); rit != scoreboard.rend(); rit++)
		{

			temp = *rit;
			line = temp.second;
			for (i = 0; i < line.size(); i++)
			{
				name[i] = line[i];
			}
			name[i] = '\0';

			_itoa_s(temp.first, score, 10);
			iText(500, y, score, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, y, name, GLUT_BITMAP_TIMES_ROMAN_24);
			y -= 150;
		}
		
	}
	else if (gamestate == 7)
	{
		iShowBMP(0, 0, pause1);
	}
	else if (gamestate == 8)
	{
		iShowBMP(0, 0, pause2);
	}
	else if (gamestate == 10)
	{
		iShowBMP(0, 0, enterName);
		iText(770, 700, name, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gamestate == 11)
	{
		iShowBMP(0, 0, levels1);
	}
	else if (gamestate == 12)
	{
		iShowBMP(0, 0, levels2);
	}
	else if (gamestate == 13)
	{
		iShowBMP(0, 0, levels3);
	}
	else if (gamestate == 14)
	{
		iShowBMP(0, 0, levels4);
	}
	if (is_game_on == 1)
	{
		if (level == 1)
		{
			iShowBMP(0, 0, BG1);
			iShowBMP2(apollox, apolloy, apollo11, 0);
			iShowBMP2(enemy1x, enemy1y, enemy1, 0);
			iShowBMP2(enemy2x, enemy2y, enemy2, 0);
			iShowBMP2(enemy3x, enemy3y, enemy3, 0);
			for (int i = 0; i < bullet_arr.size(); i++)
			{
				iShowBMP2(bullet_arr[i].bulletx, bullet_arr[i].bullety, laser, 0);
			}
			iSetColor(255, 255, 255);


			_itoa_s(score, scorestr, 10);
			_itoa_s(life, lifestr, 10);
			iText(0, 870, stat, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(65, 870, scorestr, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1520, 870, health, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1570, 870, lifestr, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (level == 2)
		{
			iShowBMP(0, 0, BG2);
			iShowBMP2(apollox, apolloy, apollo12, 0);
			iShowBMP2(enemy1x, enemy1y, enemy4, 0);
			iShowBMP2(enemy2x, enemy2y, enemy5, 0);
			iShowBMP2(enemy3x, enemy3y, enemy6, 0);
			for (int i = 0; i < bullet_arr.size(); i++)
			{
				iShowBMP2(bullet_arr[i].bulletx, bullet_arr[i].bullety, laser, 0);
			}
			iSetColor(255, 255, 255);


			_itoa_s(score, scorestr, 10);
			_itoa_s(life, lifestr, 10);
			iText(0, 870, stat, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(65, 870, scorestr, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1520, 870, health, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1570, 870, lifestr, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (level == 3)
		{
			iShowBMP(0, 0, BG3);
			iShowBMP2(apollox, apolloy, apollo13, 0);
			iShowBMP2(enemy1x, enemy1y, enemy7, 0);
			iShowBMP2(enemy2x, enemy2y, enemy8, 0);
			iShowBMP2(enemy3x, enemy3y, enemy9, 0);
			for (int i = 0; i < bullet_arr.size(); i++)
			{
				iShowBMP2(bullet_arr[i].bulletx, bullet_arr[i].bullety, laser, 0);
			}
			iSetColor(255, 255, 255);


			_itoa_s(score, scorestr, 10);
			_itoa_s(life, lifestr, 10);
			iText(0, 870, stat, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(65, 870, scorestr, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1520, 870, health, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1570, 870, lifestr, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (level == 4)
		{
			iShowBMP(0, 0, BG4);
			iShowBMP2(apollox, apolloy, apollo14, 0);
			iShowBMP2(enemy1x, enemy1y, enemy10, 0);
			iShowBMP2(enemy2x, enemy2y, enemy11, 0);
			iShowBMP2(enemy3x, enemy3y, enemy12, 0);
			for (int i = 0; i < bullet_arr.size(); i++)
			{
				iShowBMP2(bullet_arr[i].bulletx, bullet_arr[i].bullety, laser, 0);
			}
			iSetColor(255, 255, 255);


			_itoa_s(score, scorestr, 10);
			_itoa_s(life, lifestr, 10);
			iText(0, 870, stat, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(65, 870, scorestr, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1520, 870, health, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1570, 870, lifestr, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}

void make_bullet(int apollox, int apolloy)
{
	bullet p;
	p.bulletx = apollox + 135;
	p.bullety = apolloy;
	int i;
	for (i = 0; i < bullet_arr.size(); i++)
	{
	}
	i--;
	if (bullet_arr.size()==0)
		bullet_arr.push_back(p);
	else if (bullet_arr[i].bulletx - apollox>350)
		bullet_arr.push_back(p);
}

void store()
{
	ofstream myfile;
	myfile.open("High Scores.txt", ios::app);

	set<pair<int, string> >::iterator it;
	pair<int, string>temp;
	for (it = scoreboard.begin(); it != scoreboard.end(); it++)
	{
		temp = *it;
		myfile << temp.first << temp.second << endl;
	}
}

void load()
{
	scoreboard.clear();
	ifstream myfile;
	myfile.open("High Scores.txt");
	string word;
	int num;
	myfile >> num;
	getline(myfile, word);
	while (myfile.good())
	{
		//cout<<num<<' '<<word<<endl;
		scoreboard.insert(make_pair(num, word));
		myfile >> num;
		getline(myfile, word);

	}
	
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (is_game_on==1)
	{
		if (key == ' ' && bullet_arr.size() < 8)
		{
			make_bullet(apollox, apolloy);
			//PlaySound("Sound Effects//Laser.wav", NULL, SND_ASYNC);
		}
	}

	//if (gamestate == 0 || gamestate == 1 || gamestate == 2 || gamestate == 3 || gamestate == 4 || gamestate == 5 || gamestate == 6 || gamestate == 7 || gamestate == 8 || gamestate == 10 || gamestate == 11 || gamestate == 12 || gamestate == 13 || gamestate == 14)
		//PlaySound("Sound Effects//StarWars.wav", NULL, SND_LOOP | SND_ASYNC);
	//if (is_game_on==0)
		//PlaySound("Sound Effects//StarWars.wav", NULL, SND_LOOP | SND_ASYNC);
	//else if (is_game_on == 1)
		//PlaySound(0, 0, 0);

	if (key == '\r')
	{
		if (gamestate == 0)//game start
		{
			gamestate = 1;
		}
		else if (gamestate == 1)//menu (play)
		{
			gamestate = 11;
		}
		else if (gamestate == 2)//menu (high scores)
		{
			gamestate = 6;
			load();
		}
		else if (gamestate == 3)//menu (credits)
		{
			gamestate = 5;
		}
		else if (gamestate == 4)//menu (exit)
		{
			exit(1);
		}
		else if (gamestate == 7)//pause (resume)
		{
			
			is_game_on = 1;
			if (level == 1)
				gamestate = 69;
			else if (level == 2)
				gamestate = 69;
			else if (level == 3)
				gamestate = 69;
			else if (level == 4)
				gamestate = 69;
		}
		else if (gamestate == 8)//pause (quit)
		{
			gamestate = 1;
			is_game_on = 0;
			level = 0;

			indexNumber = 0;
			apollox = 100;
			apolloy = 400;
			enemy1x = 1700;
			enemy1y = 700;
			enemy2x = 2100;
			enemy2y = 200;
			enemy3x = 2500;
			enemy3y = 500;
			score = 0;
			life = 5;
			x = 6;
			y = 6;
			z = 6;
			key1 = 1;
			key2 = 1;
			key3 = 1;
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
			bullet_arr.clear();
		}
		else if (gamestate == 10)//enter name
		{
			scoreboard.clear();
			scoreboard.insert(make_pair(score, name));
			store();
			name[0] = '\0';
			gamestate = 1;
			is_game_on = 0;
			level = 0;

			indexNumber = 0;
			apollox = 100;
			apolloy = 400;
			enemy1x = 1700;
			enemy1y = 700;
			enemy2x = 2100;
			enemy2y = 200;
			enemy3x = 2500;
			enemy3y = 500;
			score = 0;
			life = 5;
			x = 6;
			y = 6;
			z = 6;
			key1 = 1;
			key2 = 1;
			key3 = 1;
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
			bullet_arr.clear();
		}
		else if (gamestate == 11)//level select(option 1)
		{
			is_game_on = 1;
			level = 1;
			gamestate = 69;
		}
		else if (gamestate == 12)//level select(option 2)
		{
			is_game_on = 1;
			level = 2;
			gamestate = 69;
		}
		else if (gamestate == 13)//level select(option 3)
		{
			is_game_on = 1;
			level = 3;
			gamestate = 69;
		}
		else if (gamestate == 14)//level select(option 4)
		{
			is_game_on = 1;
			level = 4;
			gamestate = 69;
		}

	}

	if (key == 27) //Esc button 
	{
		if (gamestate == 1)
			gamestate = 0;
		else if (is_game_on == 1)
		{
			gamestate = 7;
			is_game_on = 0;
		}
		else if (gamestate == 5)
			gamestate = 1;
		else if (gamestate == 6)
			gamestate = 1;
		else if (gamestate == 11 || gamestate == 12 || gamestate == 13 || gamestate == 14)//Level Select
			gamestate = 1;
	}
	
	if (gamestate == 10)//Enter name
	{
		if (key != '\b')
		{
			name[indexNumber] = key;
			indexNumber++;
			name[indexNumber] = '\0';
		}
		else
		{
			if (indexNumber <= 0)
				indexNumber = 0;
			else
			{
				indexNumber--;
				name[indexNumber] = '\0';
			}
		}
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (is_game_on == 0)
	{
		if (gamestate == 1 || gamestate == 2 || gamestate == 3 || gamestate == 4) //menu button 
		{
			if (key == GLUT_KEY_DOWN)
			{
				gamestate++;
			}
			if (key == GLUT_KEY_UP)
			{
				gamestate--;
			}
			if (gamestate > 4)
				gamestate = 1;
			if (gamestate < 1)
				gamestate = 4;
		}
		if (gamestate == 11 || gamestate == 12 || gamestate == 13 || gamestate == 14) // level selection 
		{
			if (key == GLUT_KEY_DOWN)
				gamestate++;
			if (key == GLUT_KEY_UP)
				gamestate--;
			if (gamestate>14)
				gamestate = 11;
			if (gamestate < 11)
				gamestate = 14;
		}
	}
	
	if (is_game_on == 1)
	{
		if (key == GLUT_KEY_UP&&apolloy <= 760) // apollo movement 
		{
			apolloy += 40;
		}
		if (key == GLUT_KEY_DOWN&&apolloy > 0)
		{
			apolloy -= 40;
		}

		if (key == GLUT_KEY_RIGHT&&apollox <= 1430)
		{
			apollox += 40;
		}

		if (key == GLUT_KEY_LEFT&&apollox > 20)
		{
			apollox -= 40;
		}
	}
	if (gamestate == 7 || gamestate == 8)
	{
		if (key == GLUT_KEY_DOWN)
			gamestate++;
		if (key == GLUT_KEY_UP)
			gamestate--;
		if (gamestate > 8)
			gamestate = 7;
		if (gamestate < 7)
			gamestate = 8;
	}
}

void MEcollision_detect(int a, int b, int c, int d, int e, int f, int g, int h) // Apollo colllided 
{
	if ((apollox + 100 >= enemy1x && apollox + 100 <= enemy1x + 100) && (apolloy >= enemy1y && apolloy <= enemy1y + 100))
	{
		apollox = 100;
		apolloy = 400;
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x+=2;
		}
		key1++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox + 100 >= enemy1x && apollox + 100 <= enemy1x + 100) && (apolloy + 100 <= enemy1y + 100 && apolloy+100>=enemy1y))
	{
		apollox = 100;
		apolloy = 400;
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x+=2;
		}
		key1++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox >= enemy1x && apollox <= enemy1x + 100) && (apolloy + 100 <= enemy1y + 100 && apolloy + 100 >= enemy1y))
	{
		apollox = 100;
		apolloy = 400;
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x += 2;
		}
		key1++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox >= enemy1x&&apollox <= enemy1x + 100) && (apolloy >= enemy1y&&apolloy <= enemy1y + 100))
	{
		apollox = 100;
		apolloy = 400;
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x += 2;
		}
		key1++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}

	if ((apollox + 100 >= enemy2x && apollox + 100 <= enemy2x + 100) && (apolloy >= enemy2y && apolloy <= enemy2y + 100))
	{
		apollox = 100;
		apolloy = 400;
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox + 100 >= enemy2x && apollox + 100 <= enemy2x + 100) && (apolloy + 100 <= enemy2y + 100 && apolloy + 100 >= enemy2y))
	{
		apollox = 100;
		apolloy = 400;
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox >= enemy2x && apollox <= enemy2x + 100) && (apolloy + 100 <= enemy2y + 100 && apolloy + 100 >= enemy2y))
	{
		apollox = 100;
		apolloy = 400;
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox >= enemy2x && apollox <= enemy2x + 100) && (apolloy >= enemy2y && apolloy <= enemy2y + 100))
	{
		apollox = 100;
		apolloy = 400;
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}

	if ((apollox + 100 >= enemy3x && apollox + 100 <= enemy3x + 100) && (apolloy >= enemy3y && apolloy <= enemy3y + 100))
	{
		apollox = 100;
		apolloy = 400;
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z+=2;
		}
		key3++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox + 100 >= enemy3x && apollox + 100 <= enemy3x + 100) && (apolloy + 100 <= enemy3y + 100 && apolloy + 100 >= enemy3y))
	{
		apollox = 100;
		apolloy = 400;
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox >= enemy3x && apollox <= enemy3x + 100) && (apolloy + 100 <= enemy3y + 100 && apolloy + 100 >= enemy3y))
	{
		apollox = 100;
		apolloy = 400;
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
	else if ((apollox >= enemy3x && apollox <= enemy3x + 100) && (apolloy >= enemy3y && apolloy <= enemy3y + 100))
	{
		apollox = 100;
		apolloy = 400;
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		life--;
		if (life <= 0)
		{
			gamestate = 10;
			is_game_on = 0;
		}
	}
}

void LEcollision_detect(int i, int b, int c, int d, int e,int f, int g, int h, int j)
{
	if ((bullet_arr[i].bulletx + 100 >= enemy1x && bullet_arr[i].bulletx + 100 <= enemy1x + 100) && (bullet_arr[i].bullety + 50 >= enemy1y && bullet_arr[i].bullety + 50 <= enemy1y + 80))
	{
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x += 2;
		}
		key1++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin()+i);
	}
	else if ((bullet_arr[i].bulletx + 100 >= enemy1x && bullet_arr[i].bulletx + 100 <= enemy1x + 100) && (bullet_arr[i].bullety + 50 <= enemy1y + 80 && bullet_arr[i].bullety + 50 >= enemy1y))
	{
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x += 2;
		}
		key1++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx >= enemy1x && bullet_arr[i].bulletx <= enemy1x + 100) && (bullet_arr[i].bullety + 50 <= enemy1y + 80 && bullet_arr[i].bullety + 50 >= enemy1y) && bullet_arr.size()>0)
	{
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x += 2;
		}
		key1++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx >= enemy1x && bullet_arr[i].bulletx <= enemy1x + 100) && (bullet_arr[i].bullety >= enemy1y&&bullet_arr[i].bullety <= enemy1y + 80) && bullet_arr.size()>0)
	{
		enemy1x = 1700;
		enemy1y = 700;
		if (x<48 && key1 % 5 == 0)
		{
			x += 2;
		}
		key1++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}

	else if ((bullet_arr[i].bulletx + 100 >= enemy2x && bullet_arr[i].bulletx + 100 <= enemy2x + 100) && (bullet_arr[i].bullety + 50 >= enemy2y && bullet_arr[i].bullety + 50 <= enemy2y + 80))
	{
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y+=2;
		}
		key2++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx + 100 >= enemy2x && bullet_arr[i].bulletx + 100 <= enemy2x + 100) && (bullet_arr[i].bullety + 50 <= enemy2y + 80 && bullet_arr[i].bullety + 50 >= enemy2y))
	{
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx >= enemy2x && bullet_arr[i].bulletx <= enemy2x + 100) && (bullet_arr[i].bullety + 50 <= enemy2y + 80 && bullet_arr[i].bullety + 50 >= enemy2y) && bullet_arr.size()>0)
	{
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx >= enemy2x && bullet_arr[i].bulletx <= enemy2x + 100) && (bullet_arr[i].bullety >= enemy2y && bullet_arr[i].bullety <= enemy2y + 80) && bullet_arr.size()>0)
	{
		enemy2x = 2100;
		enemy2y = 200;
		if (y<48 && key2 % 5 == 0)
		{
			y += 2;
		}
		key2++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}

	else if ((bullet_arr[i].bulletx + 100 >= enemy3x && bullet_arr[i].bulletx + 100 <= enemy3x + 100) && (bullet_arr[i].bullety + 50 >= enemy3y && bullet_arr[i].bullety + 50 <= enemy3y + 80))
	{
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx + 100 >= enemy3x && bullet_arr[i].bulletx + 100 <= enemy3x + 100) && (bullet_arr[i].bullety + 50 <= enemy3y + 80 && bullet_arr[i].bullety + 50 >= enemy3y))
	{
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx >= enemy3x && bullet_arr[i].bulletx <= enemy3x + 100) && (bullet_arr[i].bullety + 50 <= enemy3y + 80 && bullet_arr[i].bullety + 50 >= enemy3y) && bullet_arr.size()>0)
	{
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}
	else if ((bullet_arr[i].bulletx >= enemy3x && bullet_arr[i].bulletx <= enemy3x + 100) && (bullet_arr[i].bullety >= enemy3y && bullet_arr[i].bullety <= enemy3y + 80) && bullet_arr.size()>0)
	{
		enemy3x = 2500;
		enemy3y = 500;
		if (z<48 && key3 % 5 == 0)
		{
			z += 2;
		}
		key3++;
		score += 5;
		bullet_arr.erase(bullet_arr.begin() + i);
	}

}



void game()
{
	if (is_game_on == 1)
	{
		enemy1x -= x;
		if (enemy1x < 0)
			enemy1x = iScreenWidth + 100;
		if (flag1 == 0)
		{
			if (enemy1x % 20 == 0)
				enemy1y += 15; // distance 
			if (enemy1y >= 800)
				flag1 = 1;
			if (enemy1x % 25 == 0)
				enemy1y -= 15;
		}
		else
		{
			if (enemy1x % 20 == 0)
				enemy1y -= 15;
			if (enemy1y <= 0)
				flag1 = 0;
			if (enemy1x % 25 == 0)
				enemy1y += 15;
		}
		enemy2x -= y;
		if (enemy2x < 0)
			enemy2x = iScreenWidth + 300;
		if (flag2 == 0)
		{
			if (enemy2x % 20 == 0)
				enemy2y += 15;
			if (enemy2y >= 800)
				flag2 = 1;
			if (enemy2x % 25 == 0)
				enemy2y -= 15;
		}
		else
		{
			if (enemy2x % 20 == 0)
				enemy2y -= 15;
			if (enemy2y <= 0)
				flag2 = 0;
			if (enemy2x % 25 == 0)
				enemy2y += 15;
		}
		enemy3x -= z;
		if (enemy3x < 0)
			enemy3x = iScreenWidth + 400;
		if (flag3 == 0)
		{
			if (enemy3x % 20 == 0)
				enemy3y += 15;
			if (enemy3y >= 800)
				flag3 = 1;
			if (enemy3x % 25 == 0)
				enemy3y -= 15;
		}
		else
		{
			if (enemy3x % 20 == 0)
				enemy3y -= 15;
			if (enemy3y <= 0)
				flag3 = 0;
			if (enemy3x % 25 == 0)
				enemy3y += 15;                                         
		}
		if (bullet_arr.size() > 0 && bullet_arr[0].bulletx > 1600)
			bullet_arr.pop_front();
		for (int i = 0; i < bullet_arr.size(); i++)
		{
			bullet_arr[i].bulletx += 30;
			LEcollision_detect(i, bullet_arr[i].bulletx, bullet_arr[i].bullety, enemy1x, enemy1y, enemy2x, enemy2y, enemy3x, enemy3y); 
		}
		MEcollision_detect(apollox, apolloy, enemy1x, enemy1y, enemy2x, enemy2y, enemy3x, enemy3y);
	}
}




int main()
{
	PlaySound("Sound Effects//StarWars.wav", NULL, SND_LOOP | SND_ASYNC);
	iSetTimer(.5, game);
	///srand((unsigned)time(NULL));
	iInitialize(1600, 900, "AUST GALAXY DASH");
	///updated see the documentations
	iStart();
	return 0;
}