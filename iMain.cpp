#include<iostream>
using namespace std;
#include "iGraphics.h"


#define screenWidth 1920
#define screenHeight 1080
#define SPEED 3


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
char gameOverImage[30] = "Background\\gameover.png";
char khelaparena[30] = "Background\\tanjiroded.png";
//power limit
int hk = 0;
int wb11 = 0;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
bool musicon = true;
int attack, autoindex;
int gameState = -1;

//tanjiro
char tanjiro[6][25] = { "Tanjiro\\dour1.png", "Tanjiro\\dour2.png", "Tanjiro\\dour3.png", "Tanjiro\\dour4.png", "Tanjiro\\dour5.png", "Tanjiro\\dour6.png" };
char rtanjiro[6][25] = { "Tanjiro\\r.dour1.png", "Tanjiro\\r.dour2.png", "Tanjiro\\r.dour3.png", "Tanjiro\\r.dour4.png", "Tanjiro\\r.dour5.png", "Tanjiro\\r.dour6.png" };
char tanjirostand[25] = "Tanjiro\\kharayase.png";
char tanjirowaterbreathing1[10][25] = { "water1\\wb1.png", "water1\\wb2.png", "water1\\wb3.png", "water1\\wb4.png", "water1\\wb5.png", "water1\\wb6.png", "water1\\wb7.png", "water1\\wb8.png", "water1\\wb9.png", "water1\\wb10.png" };
char tanjirobasicattack[11][25] = { "battack\\ba0.png", "battack\\ba0.png", "battack\\ba1.png", "battack\\ba2.png", "battack\\ba3.png", "battack\\ba4.png", "battack\\ba5.png", "battack\\ba6.png", "battack\\ba7.png", "battack\\ba8.png", "battack\\ba9.png" };
char tanjirowaterbreathing11[9][25] = { "water11\\wbd1.png", "water11\\wbd2.png", "water11\\wbd3.png", "water11\\wbd4.png", "water11\\wbd5.png", "water11\\wbd6.png", "water11\\wbd7.png", "water11\\wbd8.png", "water11\\wbd9.png" };
char hinogamikagura[11][25] = { "hinogamikagura\\thk1.png", "hinogamikagura\\thk2.png", "hinogamikagura\\thk3.png", "hinogamikagura\\thk4.png", "hinogamikagura\\thk5.png", "hinogamikagura\\thk6.png", "hinogamikagura\\thk7.png", "hinogamikagura\\thk8.png", "hinogamikagura\\thk9.png", "hinogamikagura\\thk10.png", "hinogamikagura\\thk11.png" };
int tanjiroCordinateX = 450;
int tanjiroCordinateY = 100;
int tanjiroIndex = 0;
int rtanjiroIndex = 0;
int tanjirowb1Index = 0;
int tanjirobaIndex = 0;
int tanjirowb11Index = 0;
int tanjirohkIndex = 0;
int storeCoins = 0;
//muzan
char muzan[9][25] = { "Muzan douraitase\\MD1.png", "Muzan douraitase\\MD2.png", "Muzan douraitase\\MD3.png", "Muzan douraitase\\MD4.png", "Muzan douraitase\\MD5.png", "Muzan douraitase\\MD6.png", "Muzan douraitase\\MD7.png", "Muzan douraitase\\MD8.png", "Muzan douraitase\\MD9.png" };
char muzanstand[25] = "Muzan kharay ase\\MK0.png";
char muzanatk[17][50] = { "Muzan hat martase\\msa1.png", "Muzan hat martase\\msa2.png", "Muzan hat martase\\msa3.png", "Muzan hat martase\\msa4.png", "Muzan hat martase\\msa5.png", "Muzan hat martase\\msa6.png", "Muzan hat martase\\msa7.png", "Muzan hat martase\\msa8.png", "Muzan hat martase\\msa9.png", "Muzan hat martase\\msa10.png", "Muzan hat martase\\msa11.png", "Muzan hat martase\\msa12.png", "Muzan hat martase\\msa13.png", "Muzan hat martase\\msa14.png", "Muzan hat martase\\msa15.png", "Muzan hat martase\\msa16.png", "Muzan hat martase\\msa17.png" };
char muzandatk[18][50] = { "MA1\\ma1.png", "MA1\\ma2.png", "MA1\\ma3.png", "MA1\\ma4.png", "MA1\\ma5.png", "MA1\\ma6.png", "MA1\\ma7.png", "MA1\\ma8.png", "MA1\\ma9.png", "MA1\\ma10.png", "MA1\\ma11.png", "MA1\\ma12.png", "MA1\\ma13.png", "MA1\\ma14.png", "MA1\\ma15.png", "MA1\\ma16.png", "MA1\\ma17.png", "MA1\\ma18.png" };
//struct Muzan
int muzanCordinateX = 1350;
int muzanCordinateY = 100;
int muzanIndex = 0;
int muzanatkIndex = 0;
int muzanatk2Index = 0;
int muzanatk3Index = 0;
int muzanAnimationtimer;

bool muzand = false;
bool muzans = false;
bool muzanatk1 = true;
bool muzanatk2 = false;
bool muzanatk3 = false;
bool muzandefeated = false;
bool tanjirodefeated = false;
//stance
bool standPosition = true;
bool fight1 = false;
bool fight2 = false;
bool fight3 = false;
bool fight4 = false;
bool running = false;
bool frunning = false;
bool brunning = false;
int standcount = 0;
int rstandcount = 0;


//health
int health = 292;
int muzanhealth = 292;
int healthbarImage;
int muzanhealthbarImage;
char healthbar[25] = "Background\\Healthbar.png";
char muzanhealthBar[30] = "Background\\muzanhealthbar.png";

//score
int totalCoins;
int countTimer;
int randatk;
char scoreStr[100000];
//healthbar
void Healthbar()
{

	healthbarImage = iLoadImage(healthbar);
	iShowImage(50, 900, 400, 100, healthbarImage);

	iSetColor(160, 160, 160);
	iFilledRectangle(150, 925, 292, 37);
	if (health > 180)
		iSetColor(0, 204, 0);
	else if (health > 60)
		iSetColor(220, 220, 0);
	else
		iSetColor(204, 0, 0);

	iFilledRectangle(150, 925, health, 37);
	if (health <= 5)
	{
		tanjirodefeated = true;
	}
}
void muzanHealthBar()
{
	muzanhealthbarImage = iLoadImage(muzanhealthBar);
	iShowImage(1400, 900, 400, 100, muzanhealthbarImage);

	iSetColor(160, 160, 160);
	iFilledRectangle(1408, 930, 292, 34);
	if (muzanhealth > 180)
		iSetColor(0, 204, 0);
	else if (muzanhealth > 60)
		iSetColor(220, 220, 0);
	else
		iSetColor(204, 0, 0);

	iFilledRectangle(1408, 930, muzanhealth, 34);
	if (muzanhealth == 0)
	{
		muzandefeated = true;
	}
}
void muzankibutsuji()
{
	if (muzand)
	{
		int muzandour = iLoadImage(muzan[muzanIndex]);
		iShowImage(muzanCordinateX, muzanCordinateY, 250, 216, muzandour);
	}
	if (muzanatk1)
	{
		int muzanattack1 = iLoadImage(muzanatk[muzanatkIndex]);
		iShowImage(muzanCordinateX, muzanCordinateY, 350, 316, muzanattack1);
	}
	if (muzanatk2)
	{
		int muzanattack2 = iLoadImage(muzandatk[muzanatk2Index]);
		iShowImage(muzanCordinateX, 65, 350, 316, muzanattack2);
	}
	if (muzanatk3)
	{
		int muzanattack3 = iLoadImage(muzandatk[muzanatk3Index]);
		iShowImage(muzanCordinateX, muzanCordinateY, 350, 316, muzanattack3);
	}

	/*else
	{
		int muzanstanding = iLoadImage(muzanstand);
		iShowImage(muzanCordinateX, muzanCordinateY, 350, 316, muzanstanding);
	}*/
}
void muzananimation()
{
	/*if (muzand)
	{
	if (muzanIndex < 7)
	{
	muzanIndex++;
	}
	else
	{
	muzanIndex = 0;
	}
	}*/
	if (muzanatk1)
	{	
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			health -= 2;

		}
		muzanCordinateX -= 40;
		if (muzanatkIndex < 15)
		{
			muzanatkIndex++;

			if (muzanCordinateX <= 450)
			{
				muzanCordinateX = 1350;
			}
		}
		else
		{
			muzanatkIndex = 0;
		}
		
	}

	if (muzanatk2)
		{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			health -= 3;

		}
			muzanCordinateX -= 40;
			if (muzanatk2Index < 16)
			{
				muzanatk2Index++;

				if (muzanCordinateX <= 450)
				{
					muzanCordinateX = 1350;
				}
			}
			else
			{
				muzanatk2Index = 0;
			}
		}
		
	}

void playermovement()
{	//tanjiro stand and run
	if (running)
	{
		if (frunning)
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
		if (brunning)
		{
			int rtandour = iLoadImage(rtanjiro[rtanjiroIndex]);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, rtandour);
			rstandcount++;
			if (rstandcount >= 20)
			{
				rstandcount = 0;
				rtanjiroIndex = 0;
				standPosition = true;
			}

		}
		else if (standPosition)
		{
			frunning = false;
			brunning = false;
			int tanstand = iLoadImage(tanjirostand);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tanstand);
		}

	}

	//waterbreathing1 ATTACK 1

	else if (fight1)
	{
		int sword = iLoadImage(tanjirobasicattack[tanjirobaIndex]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, sword);
	}
	// basic attacck!
	else if (fight2)
	{
		int waterbreathing1 = iLoadImage(tanjirowaterbreathing1[tanjirowb1Index]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, waterbreathing1);
	}

	//waterbreathing11 ATTACK 2

	else if (fight3)
	{
		int waterbreathing11 = iLoadImage(tanjirowaterbreathing11[tanjirowb11Index]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, waterbreathing11);
	}

	//Hinogami kagura Attack 3

	else if (fight4)
	{
		int hinogami = iLoadImage(hinogamikagura[tanjirohkIndex]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, hinogami);
	}

	else if (standPosition)
	{
		int tanstand = iLoadImage(tanjirostand);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tanstand);
	}

}
/*
void getTotalCoin()
{
	FILE *fp = fopen("TotalCoin.txt", "r");
	if (fp == NULL)
	{
		printf("file not opened");
	}
	else
	{
		while (fscanf(fp, "%d",storeCoins) != EOF)
		{
			totalCoins++;
		}

		fclose(fp);
	}
}*/
/*
void showTotalCoin()
{
	if (totalCoins == 0)
	{
		//iShowImage(0, 0, 860, 600, noHighScores);
	}
	if (totalCoins >= 1)
	{
		sprintf(scoreStr, "%d", storeCoins);
		iText(760, 390, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (totalCoins >= 2)
	{
		sprintf(scoreStr, "%d", storeCoins);
		iText(760, 340, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (totalCoins >= 3)
	{
		sprintf(scoreStr, "%d", storeCoins);
		iText(760, 290, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (totalCoins >= 4)
	{
		sprintf(scoreStr, "%d", storeCoins);
		iText(760, 240, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (totalCoins == 5)
	{
		sprintf(scoreStr, "%d", storeCoins);
		iText(760, 190, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}*/

void CollisionCheck()
{
	if (fight1)
	{
		if ((tanjiroCordinateX + 250 >= muzanCordinateX) && (tanjiroCordinateX <= muzanCordinateX + 350))
		{
			muzanhealth -= 15;
			storeCoins += 20;
			//health -= 5;
		}
	}
	else if (fight2)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			muzanhealth -= 30;
			storeCoins += 60;
			//health -= 5;
		}
	}

	else if (fight4)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			muzanhealth -= 60;
			storeCoins += 200;
			//			health -= 5;
		}
	}
	/*
	if (muzanatk1)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			health -= 15;

		}
	}
	
	if (muzanatk2)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			health -= 30;

		}
	}
	*/
	
}
void ShowGameOver()
{
	if (muzandefeated)
	{
		int goim = iLoadImage(gameOverImage);
		iShowImage(0, 0, 1920, 1080, goim);
	}
	if (tanjirodefeated)
	{
		int td = iLoadImage(khelaparena);
		iShowImage(0, 0, 1920, 1080, td);
	}
}
void gameOver()
{
	muzanatk1 = false;
	muzanatk2 = false;
	iPauseTimer(randatk);
	iPauseTimer(muzanAnimationtimer);
}
void randAttack()
{
	if (muzanatk1)
	{
		if (muzanatkIndex >= 15)
		{
			muzanatk1 = false;
			muzanatk2 = true;
			muzanatkIndex = 0;
		}
	}
	if (muzanatk2)
	{
		if (muzanatk2Index >= 16)
		{	
			muzanatk2 = false;
			muzanatk1 = true;
			muzanatk2Index = 0;
		}
	}
}

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
	//PLAY WINDOW
	else if (gameState == 0)
	{
		int img3 = iLoadImage(play);
		iShowImage(0, 0, 1920, 1080, img3);
		Healthbar();
		muzanHealthBar();
		playermovement();
		muzankibutsuji();
		if (muzanhealth <= 1)
		{
			muzandefeated = true;
		}
		if (muzandefeated)
		{
			ShowGameOver();
			gameOver();
			sprintf_s(scoreStr, "%d", storeCoins);
			iSetColor(255, 255, 255);
			iText(970, 430, scoreStr,GLUT_BITMAP_TIMES_ROMAN_24);
			tanjirodefeated = false;
			
		}
		if (tanjirodefeated)
		{	
			gameOver();
			ShowGameOver();
			
		}
	}
	//Store
	else if (gameState == 1)
	{
		int img4 = iLoadImage(store);
		iShowImage(0, 0, 1920, 1080, img4);
	}
	else if (gameState == 5)
	{
		exit(0);
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
	cout << mx << " " << my << endl;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameState == -1)
		{
			for (int i = 0; i < 6; i++)
			{
				if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 309 && my >= bCordinate[i].y && my <= bCordinate[i].y + 112)
				{
					gameState = i;
				}
			}
		}
		if (muzandefeated)
		{
			if (mx >= 261 && mx <= 650 && my >= 114 && my <= 253)
			{
				gameState = -1;
			}
			if (mx >= 786 && mx <= 1176 && my >= 114 && my <= 253)
			{
				gameState = 0;
			}
			if (mx >= 1300 && mx <= 1700 && my >= 114 && my <= 253)
			{
				exit(0);
			}
		}
		if (tanjirodefeated)
		{
			if (mx >= 253 && mx <= 650 && my >= 215 && my <= 351)
			{
				gameState = -1;
			}
			if (mx >= 786 && mx <= 1176 && my >= 215 && my <= 351)
			{
				gameState = 0;
			}
			if (mx >= 1300 && mx <= 1700 && my >= 215 && my <= 351)
			{
				exit(0);
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

	if (key == '\q')
	{
		
		wb11++;
		if (wb11 <= 3)
		{
			fight2 = true;
			tanjirowb1Index = 0;
			iResumeTimer(countTimer);
			CollisionCheck();
			if (tanjirowb1Index >= 9 && tanjiroCordinateX < 1300)
			{
				fight2 = false;
				standPosition = true;
				iPauseTimer(countTimer);
				tanjirowb1Index = 0;
			}

			if (tanjirowb1Index <= 9 && tanjiroCordinateX < 1300){

				running = false;
				fight2 = true;
				standPosition = false;
			}
		}
		
	}

	if (key == '\e')
	{
		fight1 = true;
		iResumeTimer(countTimer);
		tanjirobaIndex = 0;
		CollisionCheck();
		if (tanjirobaIndex <= 10){

			running = false;
			fight1 = true;
			standPosition = false;
		}
		if (tanjirobaIndex >= 10)
		{
			fight1 = false;
			standPosition = true;
			iPauseTimer(countTimer);
			tanjirobaIndex = 0;
		}

		

	}
	/*if (key == '\c')
	{
		tanjirowb11Index = 0;
		iResumeTimer(countTimer);
		CollisionCheck();
		

		if (tanjirowb11Index <= 8 && tanjiroCordinateX < 1300){

			running = false;
			fight3 = true;
			standPosition = false;
		}
		if (tanjirowb11Index >= 8 && tanjiroCordinateX < 1300)
		{
			fight3 = false;
			standPosition = true;
			iPauseTimer(countTimer);
			tanjirowb11Index = 0;
		}



	}*/

	if (key == '\z')
	{
		
		hk++;
		

		if (hk <= 2)
		{
			fight4 = true;
			tanjirohkIndex = 0;
			iResumeTimer(countTimer);
			CollisionCheck();
			if (tanjirohkIndex <= 10 && tanjiroCordinateX < 1300){

				running = false;
				fight4 = true;
				standPosition = false;
			}

			if (tanjirohkIndex >= 10 && tanjiroCordinateX < 1300)
			{
				fight4 = false;
				standPosition = true;
				iPauseTimer(countTimer);
				tanjirohkIndex = 0;
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


	if (key == GLUT_KEY_RIGHT || tanjiroCordinateX <350)
	{
		tanjiroCordinateX += 45;
		tanjiroIndex++;

		if (tanjiroIndex >= 6)
		{
			tanjiroIndex = 0;
		}
		running = true;
		brunning = false;
		frunning = true;
		fight1 = false;
		standPosition = false;

	}
	if (key == GLUT_KEY_LEFT || tanjiroCordinateX >1400)
	{
		tanjiroCordinateX -= 45;

		rtanjiroIndex++;

		if (rtanjiroIndex >= 6)
		{
			rtanjiroIndex = 0;
		}
		running = true;
		frunning = false;
		brunning = true;
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
void changeindex()
{
	if ((tanjirobaIndex >= 0 && tanjirobaIndex <= 9) && fight1)
	{
		tanjirobaIndex++;
	}
	else if ((tanjirowb1Index >= 0 && tanjirowb1Index <= 8) && (tanjiroCordinateX >= 400 && tanjiroCordinateX <= 1400) && fight2)
	{
		tanjirowb1Index++;
		//tanjiroCordinateX += 90;

	}
	/*else if ((tanjirowb11Index >= 0 && tanjirowb11Index <= 7) && (tanjiroCordinateX >= 400 && tanjiroCordinateX <= 1400) && fight3)
	{
		tanjirowb11Index++;
		//tanjiroCordinateX += 90;

	}*/
	else if ((tanjirohkIndex >= 0 && tanjirohkIndex <= 9) && (tanjiroCordinateX >= 400 && tanjiroCordinateX <= 1400) && fight4)
	{
		tanjirohkIndex++;
		//tanjiroCordinateX += 85;

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

	countTimer = iSetTimer(150, changeindex);
	iPauseTimer(countTimer);
	muzanAnimationtimer = iSetTimer(140, muzananimation);
	randatk = iSetTimer(150, randAttack);
	//iPauseTimer(muzanAnimationtimer);
	iStart();
	return 0;
}