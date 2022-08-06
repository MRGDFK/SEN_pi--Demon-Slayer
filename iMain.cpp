
#include<iostream>
using namespace std;
#include "iGraphics.h"

#define screenWidth 1920
#define screenHeight 1080


struct buttonCordinate{

	int x;
	int y;
}bCordinate[6];

//int mposx, mposy;
char homemenu[20] = "Background\\menu.png"; 
char button[6][25] = { "Buttons\\play.png", "Buttons\\store.png", "Buttons\\options.png", "Buttons\\help.png", "Buttons\\credit.png", "Buttons\\exit.png" };
//individual page
char play[20] = "Background\\bg3.png";
char store[25] = "Background\\store.png";


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
bool musicon = true;

int gameState = -1;

//tanjiro
char tanjiro[6][25] = { "Tanjiro\\dour1.png", "Tanjiro\\dour2.png", "Tanjiro\\dour3.png", "Tanjiro\\dour4.png", "Tanjiro\\dour5.png", "Tanjiro\\dour6.png" };
char tanjirostand[25] = "Tanjiro\\kharayase.png";
char tanjirowaterbreathing1[10][25] = { "water1\\wb1.png", "water1\\wb2.png", "water1\\wb3.png", "water1\\wb4.png", "water1\\wb5.png", "water1\\wb6.png", "water1\\wb7.png", "water1\\wb8.png", "water1\\wb9.png", "water1\\wb10.png" };
char tanjirowaterbreathing1f[25] = "water1\\wb10.png";
int tanjiroCordinateX = 450;
int tanjiroCordinateY = 100;
int waterattack1=450;
int tanjiroIndex = 0;
int tanjirowb1Index = 0;
bool standPosition = true;
bool fight1 = false;
bool running = false;
int standcount = 0;
int dx=10;

void iDraw()
{
	iClear();

	if (gameState == -1)
	{
		//HomePage(Menu)

		int img = iLoadImage(homemenu);
		iShowImage(0, 0, 1920, 1080, img);

		for (int i = 0; i < 6; i++)
			{
				int img2 = iLoadImage(button[i]);
				iShowImage(bCordinate[i].x, bCordinate[i].y, 309, 112, img2);
			}
	}
	else if (gameState == 0)
	{
		int img3 = iLoadImage(play);
		iShowImage(0, 0, 1920, 1080, img3);
		//tanjiro stand and run
		if (running)
		{
			int tandour = iLoadImage(tanjiro[tanjiroIndex]);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tandour);
			standcount++;
			if (standcount >= 20)
			{
				standcount = 0;
				tanjiroIndex = 0;
				standPosition = true;
			}

		}
		
		//waterbreathing1 ATTACK 1

		else if (fight1)
		{
			if (tanjiroCordinateX < 1470 && tanjiroCordinateX > 450)
			{
				int waterbreathing1 = iLoadImage(tanjirowaterbreathing1[tanjirowb1Index]);
				iShowImage(waterattack1, tanjiroCordinateY, 250, 216, waterbreathing1);
			}

		}
		else
		{
			int tanstand = iLoadImage(tanjirostand);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tanstand);
		}
	

		
		
		
		
		
	}
	//Store
	else if (gameState == 1)
	{
		int img4 = iLoadImage(store);
		iShowImage(0, 0, 1920, 1080, img4);
	}
	else
	{

	}
		
	
	
	return;
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
		for (int i = 0; i < 6; i++)
		{
			if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 309 && my >= bCordinate[i].y && my <= bCordinate[i].y + 112)
			{
				gameState = i;


			}
		}
		
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
	if (key == '\e')
	{
		
		if (waterattack1<1400 || waterattack1>450)
		{
			waterattack1 += 50;
			tanjirowb1Index++;

			if (tanjirowb1Index >= 10)
			{
				tanjirowb1Index = 0;
			}
			running = false;
			fight1 = true;
			standPosition = false;

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

	
	if (key == GLUT_KEY_RIGHT)
	{
		tanjiroCordinateX += 45;
		tanjiroIndex++;

		if (tanjiroIndex >= 6)
		{
			tanjiroIndex = 0;
		}
		running = true;
		fight1 = false;
		standPosition = false;
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		tanjiroCordinateX -= 45;

		tanjiroIndex--;

		if (tanjiroIndex <0)
		{
			tanjiroIndex = 5;
		}
		running = true;
		fight1 = false;
		standPosition = false;
	}
	
	if (key == GLUT_KEY_HOME)
	{
		gameState = -1;
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	
}

void change()
{
	
	waterattack1 += dx;
	if (waterattack1 >= screenWidth || waterattack1 <= 0)
		{
			dx *= (-1);
		}
	

}

int main(void)
{	
	int sum = 100;
	///srand((unsigned)time(NULL));
	iInitialize(screenWidth, screenHeight, "Demon Slayer: Kimetsu No Yaiba");

	///updated see the documentations
	
	if (musicon == true){
		PlaySound("Music\\menusfx.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	for (int i = 5; i >= 0; i--)
	{
		bCordinate[i].x = 800;
		bCordinate[i].y = sum;
		sum += 150;
	}
	//iSetTimer(500, change);

	iStart();
	return 0;
}

