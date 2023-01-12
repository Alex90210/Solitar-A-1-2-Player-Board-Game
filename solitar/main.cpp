#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <cstring>
#include <cmath>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

/*
#include <conio.h > */
#define MAX 20
#define FUNDAL CYAN
#define culoarea_mea BLACK
int culoare_piese = 15,
	culoare_piesa1 = 8,
	culoare_piesa2 = 9,
	culoare_piesa3 = 10,
	culoare_piesa4 = 11,
	culoare_piesa5 = 12,
	culoare_piesa6 = 14;
int culoare_tabla = 3,
	culoare_tabla1 = 1,
	culoare_tabla2 = 2,
	culoare_tabla3 = 4,
	culoare_tabla4 = 5,
	culoare_tabla5 = 6,
	culoare_tabla6 = 7;
using namespace std;
typedef unsigned char byte;
typedef unsigned int word;

char sirScor1[10], sirScor2[10];
int scor, uga = 0, KONTOR = 0, mbape = 0, dambile = 0;
int lat = 50;
int m, n;
int aaa = 2, brrr = 0;
int i, j, tabla[10][10];
int scor1 = 0, scor2 = 0;
int parametruTabla = 1;
void openGraph()
{
	/*int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\bc\\bgi"); */
	initwindow(lat *11, lat *12, "Solitar", 500, 100);
}

void deseneazaMeniul()
{
	setfillstyle(SOLID_FILL, CYAN);

	rectangle(lat *3, lat *3, lat *8, lat *4);
	outtextxy(lat *5.2, lat *3.4, "PLAY");
	floodfill(lat *3 + 1, lat *3 + 1, WHITE);

	rectangle(lat *3, lat *5, lat *8, lat *6);
	outtextxy(lat *5, lat *5.4, "RULES");
	floodfill(lat *3 + 1, lat *5 + 1, WHITE);

	rectangle(lat *3, lat *7, lat *8, lat *8);
	outtextxy(lat *5.2, lat *7.4, "EXIT");
	floodfill(lat *3 + 1, lat *7 + 1, WHITE);
}

void deseneazaModJoc()
{
	rectangle(lat *3, lat *3, lat *8, lat *4);
	outtextxy(lat *4.5, lat *3.4, "SINGLEPLAYER");
	floodfill(lat *3 + 1, lat *3 + 1, WHITE);

	rectangle(lat *3, lat *5, lat *8, lat *6);
	outtextxy(lat *4.3, lat *5.4, "2 PLAYERS MODE");
	floodfill(lat *3 + 1, lat *5 + 1, WHITE);

	rectangle(lat *3, lat *7, lat *8, lat *8);
	outtextxy(lat *4.8, lat *7.4, "AUTOPLAY");
	floodfill(lat *3 + 1, lat *7 + 1, WHITE);
}

/*
void deseneazaMeniuSelectieCuloarePiese {}

void deseneazaMeniuSelectieCuloareTabla {}*/
void afiseazaScorSingleplayer()	// matrice refacuta
{
	char sirScor1[10], sirScor2[10];
	setcolor(culoare_piese);
	itoa(scor1, sirScor1, 10);

	int i, j;
	scor1 = 0, scor2 = 0;
    setcolor(WHITE);
	for (i = 2; i <= 8; i++)
		for (j = 2; j <= 8; j++)
			if (tabla[i][j] == 1)
			{
				scor1 += 1;
				itoa(scor1, sirScor1, 10);
				outtextxy(lat *6.4, lat *9.4, sirScor1);
			}
}

bool este_meci_neterminat()	// matrice refacuta, suma neverificata
{
	int suma = 0;
	for (int i = 2; i < 9; i++)
		for (int j = 2; j < 9; j++)
			suma += tabla[i][j];
	if (suma == 161 && tabla[5][5] == 1)
		return false;
	else
		return true;
}

bool este_meci_neterminat_autoplay()	// matrice refacuta
{
	int suma = 0;
	for (int i = 2; i < 9; i++)
		for (int j = 2; j < 9; j++)
			suma += tabla[i][j];
	if (suma == 161 && tabla[5][5] == 1)
		return false;
	else
		return true;
}

void afiseazaScorAutoplay()	// matrice refacuta ?
{
	char sirScor1[10];
	//settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	//setcolor(LIGHTCYAN);
	itoa(scor1, sirScor1, 10);

	int i, j;
	scor1 = 0;
    setcolor(WHITE);

    for (i = 2; i <= 8; i++)
		for (j = 2; j <= 8; j++)
			if (tabla[i][j] == 1)
				scor1 += 1;

	itoa(scor1, sirScor1, 10);
    outtextxy(lat *6.4, lat *9.4, sirScor1);
}

void initializareMatriceTabla()
{
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 10; j++)
			tabla[i][j] = 1;

	tabla[5][5] = 2;

	for (int i = 1; i <= 9; i++)
	{
		tabla[1][i] = 6;
		tabla[9][i] = 6;
		tabla[i][1] = 6;
		tabla[i][9] = 6;
	}

	for (int i = 2; i <= 3; i++)
	{
		tabla[2][i] = 6;
		tabla[3][i] = 6;
		tabla[7][i] = 6;
		tabla[8][i] = 6;
	}

	for (int i = 7; i <= 8; i++)
	{
		tabla[2][i] = 6;
		tabla[3][i] = 6;
		tabla[7][i] = 6;
		tabla[8][i] = 6;
	}

	for (int i = 0; i <= 10; i++)
	{
		tabla[0][i] = 7;
		tabla[10][i] = 7;
		tabla[i][0] = 7;
		tabla[i][10] = 7;
	}
}

void numarDePiese()	// matrice refacuta, trebuie verificat alg
{
	int kk = 0, numarPIESE = 0;
	char KKK[10];

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
			if (tabla[i][j] == 1)
				kk++;

	itoa(kk, KKK, 10);
	outtextxy(220, 530, KKK);

}

int numarDePieseINT()
{
	int kk = 0;

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
			if (tabla[i][j] == 1)
				kk++;
	return kk;
}

void deseneazaMeniuCuloarePiesa()
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, culoare_piesa1);
	circle(lat *8.5, lat *0.5, lat / 4);
	floodfill(lat *8.5, lat *0.5, CYAN);

	setfillstyle(SOLID_FILL, culoare_piesa2);
	circle(lat *7.5, lat *0.5, lat / 4);
	floodfill(lat *7.5, lat *0.5, CYAN);

	setfillstyle(SOLID_FILL, culoare_piesa3);
	circle(lat *6.5, lat *0.5, lat / 4);
	floodfill(lat *6.5, lat *0.5, CYAN);

	setfillstyle(SOLID_FILL, culoare_piesa4);
	circle(lat *5.5, lat *0.5, lat / 4);
	floodfill(lat *5.5, lat *0.5, CYAN);

	setfillstyle(SOLID_FILL, culoare_piesa5);
	circle(lat *4.5, lat *0.5, lat / 4);
	floodfill(lat *4.5, lat *0.5, CYAN);

	setfillstyle(SOLID_FILL, culoare_piesa6);
	circle(lat *3.5, lat *0.5, lat / 4);
	floodfill(lat *3.5, lat *0.5, CYAN);

	setcolor(WHITE);
	line(lat *3, lat *0.125, lat *9, lat *0.125);
	line(lat *3, lat *0.875, lat *9, lat *0.875);
	for (int i = 3; i <= 9; i++)
		line(lat *i, lat *0.125, lat *i, lat *0.875);

}

void deseneazaMeniuCuloareTabla()
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla1);
	rectangle(lat *10.25, lat *2.25, lat *10.75, lat *2.75);
	floodfill(lat *10.5, lat *2.5, WHITE);

	setfillstyle(SOLID_FILL, culoare_tabla2);
	rectangle(lat *10.25, lat *3.25, lat *10.75, lat *3.75);
	floodfill(lat *10.5, lat *3.5, WHITE);

	setfillstyle(SOLID_FILL, culoare_tabla3);
	rectangle(lat *10.25, lat *4.25, lat *10.75, lat *4.75);
	floodfill(lat *10.5, lat *4.5, WHITE);

	setfillstyle(SOLID_FILL, culoare_tabla4);
	rectangle(lat *10.25, lat *5.25, lat *10.75, lat *5.75);
	floodfill(lat *10.5, lat *5.5, WHITE);

	setfillstyle(SOLID_FILL, culoare_tabla5);
	rectangle(lat *10.25, lat *6.25, lat *10.75, lat *6.75);
	floodfill(lat *10.5, lat *6.5, WHITE);

	setfillstyle(SOLID_FILL, culoare_tabla6);
	rectangle(lat *10.25, lat *7.25, lat *10.75, lat *7.75);
	floodfill(lat *10.5, lat *7.5, WHITE);

	line(lat *10.125, lat *2, lat *10.125, lat *8);
	line(lat *10.875, lat *2, lat *10.875, lat *8);
	for (int i = 2; i <= 8; i++)
		line(lat *10.125, i *lat, lat *10.875, i *lat);
}

void deseneazaPiesa(int linia, int coloana, int culoare)
{
	int x1, y1, x2, y2;
	int xmijloc, ymijloc;
	setcolor(GREEN);	//?
	setfillstyle(SOLID_FILL, RED);

	x1 = lat + lat *(coloana - 1);
	y1 = lat + lat *(linia - 1);
	x2 = x1 + lat;
	y2 = y1 + lat;

	xmijloc = (x1 + x2) / 2;
	ymijloc = (y1 + y2) / 2;

	setcolor(culoare);
	setfillstyle(SOLID_FILL, culoare);
	fillellipse(xmijloc, ymijloc, lat / 4, lat / 4);
}

void deseneazaPiesaMeniu(int linia, int coloana, int culoare)
{
	int x1, y1, x2, y2;
	int xmijloc, ymijloc;
	setcolor(GREEN);	//?
	setfillstyle(SOLID_FILL, RED);

	x1 = lat + lat *(coloana - 1);
	y1 = lat + lat *(linia - 1);
	x2 = x1 + lat;
	y2 = y1 + lat;

	xmijloc = (x1 + x2) / 2;
	ymijloc = (y1 + y2) / 2;

	setcolor(culoare);
	setfillstyle(SOLID_FILL, culoare);
	fillellipse(xmijloc, ymijloc, lat / 6, lat / 6);
}

void DesTabla(int culoare_tabla, int mod)
{
	readimagefile("setari1.jpg", lat *1.25, lat *0.25, lat *1.75, lat *0.75);
	readimagefile("reset.jpg", lat *0.25, lat *0.25, lat *0.75, lat *0.75);
	readimagefile("marimeaconteaza.jpg", lat *0.25, lat *1.25, lat *0.75, lat *1.75);
	readimagefile("tabla1.jpg", lat *2.25, lat *0.25, lat *2.75, lat *0.75);

	for (int i = 4; i < 7; i++)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, culoare_tabla);
		bar(i *lat, lat *2, (i + 1) *lat, 3 *lat);
		bar(i *lat, 3 *lat, (i + 1) *lat, 4 *lat);
		rectangle(i *lat, 2 *lat, (i + 1) *lat, 3 *lat);
		rectangle(i *lat, 3 *lat, (i + 1) *lat, 4 *lat);

		//circle(i *lat + lat / 2, 1.5 *lat, lat / 4);
		//circle(i *lat + lat / 2, 2.5 *lat, lat / 4);
	}

	for (int i = 2; i <= 8; i++)
	{
		setfillstyle(SOLID_FILL, culoare_tabla);
		bar(i *lat, lat *4, (i + 1) *lat, 5 *lat);
		bar(i *lat, 5 *lat, (i + 1) *lat, 6 *lat);
		bar(i *lat, 6 *lat, (i + 1) *lat, 7 *lat);
		rectangle(i *lat, lat *4, (i + 1) *lat, 5 *lat);
		rectangle(i *lat, 5 *lat, (i + 1) *lat, 6 *lat);
		rectangle(i *lat, 6 *lat, (i + 1) *lat, 7 *lat);

		//circle(i *lat + lat / 2, 3.5 *lat, lat / 4);
		//circle(i *lat + lat / 2, 5.5 *lat, lat / 4);
		//if (i == 4)
		//continue;
		//else
		//circle(i *lat + lat / 2, 4.5 *lat, lat / 4);
	}

	for (int i = 4; i < 7; i++)
	{
		setfillstyle(SOLID_FILL, culoare_tabla);
		bar(i *lat, 7 *lat, (i + 1) *lat, 8 *lat);
		bar(i *lat, 8 *lat, (i + 1) *lat, 9 *lat);
		rectangle(i *lat, 7 *lat, (i + 1) *lat, 8 *lat);
		rectangle(i *lat, 8 *lat, (i + 1) *lat, 9 *lat);

		/*circle(i *lat + lat / 2, 6.5 *lat, lat / 4);
		circle(i *lat + lat / 2, 7.5 *lat, lat / 4); */
	}

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);
			else if (tabla[i][j] == 2)
				deseneazaPiesa(j, i, BLACK);
		}

	readimagefile("meniuculoare.jpg", lat *10.125, 0.125 *lat, lat *10.875, lat *0.875);
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, culoare_piese);
	circle(lat *9.5, lat *0.5, lat / 4);
	floodfill(lat *9.5, lat *0.5, CYAN);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla);
	rectangle(lat *10.25, lat *1.25, lat *10.75, lat *1.75);
	floodfill(lat *10.5, lat *1.5, WHITE);
	if (mod == 2)
	{
		readimagefile("setari1.jpg", lat *1.25, lat *0.25, lat *1.75, lat *0.75);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
		//m = 0, n = 0;
		setcolor(LIGHTRED);
		char sir1[10], sir2[10];
		itoa(m, sir1, 10);
		itoa(n, sir2, 10);
		outtextxy(lat *2.5, 11 *lat, sir1);
		outtextxy(lat *8.1, 11 *lat, sir2);
	}
}

void setariTwoP()
{
	readimagefile("setari1.jpg", lat *1.25, lat *0.25, lat *1.75, lat *0.75);
	readimagefile("reset.jpg", lat *0.25, lat *0.25, lat *0.75, lat *0.75);
	readimagefile("marimeaconteaza.jpg", lat *0.25, lat *1.25, lat *0.75, lat *1.75);
	readimagefile("tabla1.jpg", lat *2.25, lat *0.25, lat *2.75, lat *0.75);
	readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
	readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);

	readimagefile("meniuculoare.jpg", lat *10.125, 0.125 *lat, lat *10.875, lat *0.875);
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, culoare_piese);
	circle(lat *9.5, lat *0.5, lat / 4);
	floodfill(lat *9.5, lat *0.5, CYAN);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla);
	rectangle(lat *10.25, lat *1.25, lat *10.75, lat *1.75);
	floodfill(lat *10.5, lat *1.5, WHITE);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	readimagefile("setari1.jpg", lat *1.25, lat *0.25, lat *1.75, lat *0.75);
	//m = 0, n = 0;
	/*setcolor(LIGHTRED);
	char sir1[10], sir2[10];
	itoa(m, sir1, 10);
	itoa(n, sir2, 10);
	outtextxy(lat *2.5, 11 *lat, sir1);
	outtextxy(lat *8.1, 11 *lat, sir2);*/

}

void deseneazaMeniuTable()
{
	readimagefile("ics.jpg", lat *2.25, lat *0.25, lat *2.75, lat *0.75);
	readimagefile("cerc.jpg", lat *3.25, lat *0.25, lat *3.75, lat *0.75);
	readimagefile("patrat.jpg", lat *4.25, lat *0.25, lat *4.75, lat *0.75);
	readimagefile("triunghi.jpg", lat *5.25, lat *0.25, lat *5.75, lat *0.75);
}

void matriceVizualaActualizata()
{
	int x1, y1, x2, y2;
	int xmijloc, ymijloc;

	setcolor(WHITE);
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
		{
			char v[2];
			int b = tabla[i][j];
			v[1] = '\0';
			v[0] = '0' + b;
			x1 = lat + lat *(i - 1);
			y1 = lat + lat *(j - 1);
			x2 = x1 + lat;
			y2 = y1 + lat;
			xmijloc = (x1 + x2) / 2;
			ymijloc = (y1 + y2) / 2;
			outtextxy(xmijloc - 4, ymijloc - 8, v);
		}
}

void initializarePieseTabla(int culoare_piese)	// matrice refacuta
{
	for (int i = 2; i < 9; i++)
		for (int j = 2; j < 9; j++)
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);

	deseneazaPiesa(5, 5, BLACK);
}

void schimbaTabla1(int culoare_tabla)
{
	cleardevice();
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla);
	readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
	readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);
    for (int i = 4; i < 7; i++)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, culoare_tabla);
		bar(i *lat, lat *2, (i + 1) *lat, 3 *lat);
		bar(i *lat, 3 *lat, (i + 1) *lat, 4 *lat);
		rectangle(i *lat, 2 *lat, (i + 1) *lat, 3 *lat);
		rectangle(i *lat, 3 *lat, (i + 1) *lat, 4 *lat);
	}

	for (int i = 2; i <= 8; i++)
	{
		setfillstyle(SOLID_FILL, culoare_tabla);
		bar(i *lat, lat *4, (i + 1) *lat, 5 *lat);
		bar(i *lat, 5 *lat, (i + 1) *lat, 6 *lat);
		bar(i *lat, 6 *lat, (i + 1) *lat, 7 *lat);
		rectangle(i *lat, lat *4, (i + 1) *lat, 5 *lat);
		rectangle(i *lat, 5 *lat, (i + 1) *lat, 6 *lat);
		rectangle(i *lat, 6 *lat, (i + 1) *lat, 7 *lat);
	}

	for (int i = 4; i < 7; i++)
	{
		setfillstyle(SOLID_FILL, culoare_tabla);
		bar(i *lat, 7 *lat, (i + 1) *lat, 8 *lat);
		bar(i *lat, 8 *lat, (i + 1) *lat, 9 *lat);
		rectangle(i *lat, 7 *lat, (i + 1) *lat, 8 *lat);
		rectangle(i *lat, 8 *lat, (i + 1) *lat, 9 *lat);
	}

	bar(3 *lat, lat *3, 4 *lat, 4 *lat);
	rectangle(3 *lat, lat *3, 4 *lat, 4 *lat);
	bar(3 *lat, lat *7, 4 *lat, 8 *lat);
	rectangle(3 *lat, lat *7, 4 *lat, 8 *lat);
	bar(7 *lat, lat *3, 8 *lat, 4 *lat);
	rectangle(7 *lat, lat *3, 8 *lat, 4 *lat);
	bar(7 *lat, lat *7, 8 *lat, 8 *lat);
	rectangle(7 *lat, lat *7, 8 *lat, 8 *lat);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);
			else if (tabla[i][j] == 2)
				deseneazaPiesa(j, i, BLACK);
		}
    setariTwoP();
}

void schimbaTabla2(int culoare_tabla)
{
	cleardevice();
	setariTwoP();
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			bar(i *lat, lat *j, (i + 1) *lat, (j + 1) *lat);
			rectangle(i *lat, lat *j, (i + 1) *lat, (j + 1) *lat);
		}

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);
			else if (tabla[i][j] == 2)
				deseneazaPiesa(j, i, BLACK);
		}
}

void schimbaTabla3(int culoare_tabla)
{
	cleardevice();
	setariTwoP();
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			bar(i *lat, lat *j, (i + 1) *lat, (j + 1) *lat);
			rectangle(i *lat, lat *j, (i + 1) *lat, (j + 1) *lat);
		}

	setfillstyle(SOLID_FILL, BLACK);
	bar(lat *4 + 1, lat *4 + 1, lat *7, lat *5);
	bar(lat *4 + 1, lat *6 + 1, lat *7, lat *7);

	bar(lat *2, lat *2, lat *3, lat *3);
	bar(lat *8 + 1, lat *2, lat *9 + 1, lat *3);
	bar(lat *2, lat *8 + 1, lat *3, lat *9 + 1);
	bar(lat *8 + 1, lat *8 + 1, lat *9 + 1, lat *9 + 1);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);
			else if (tabla[i][j] == 2)
				deseneazaPiesa(j, i, BLACK);
		}
}

void schimbaTabla4(int culoare_tabla)
{
	cleardevice();
	setariTwoP();
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, culoare_tabla);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			bar(i *lat, lat *j, (i + 1) *lat, (j + 1) *lat);
			rectangle(i *lat, lat *j, (i + 1) *lat, (j + 1) *lat);
		}

	setfillstyle(SOLID_FILL, BLACK);

	bar(lat *2, lat *2, lat *5, lat *3);
	bar(lat *2, lat *3, lat *4, lat *4);
	bar(lat *2, lat *4, lat *3, lat *5);

	bar(lat *6 + 1, lat *2, lat *9 + 1, lat *3);
	bar(lat *7 + 1, lat *3, lat *9 + 1, lat *4);
	bar(lat *8 + 1, lat *4, lat *9 + 1, lat *5);

	bar(lat *2, lat *6 + 1, lat *3, lat *7 + 1);
	bar(lat *2, lat *7 + 1, lat *4, lat *8 + 1);
	bar(lat *2, lat *8 + 1, lat *5, lat *9 + 1);

	bar(lat *8 + 1, lat *6 + 1, lat *9 + 1, lat *7 + 1);
	bar(lat *7 + 1, lat *7 + 1, lat *9 + 1, lat *8 + 1);
	bar(lat *6 + 1, lat *8 + 1, lat *9 + 1, lat *9 + 1);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);
			else if (tabla[i][j] == 2)
				deseneazaPiesa(j, i, BLACK);
		}
}

void selectieTablaCuloare(int parametruTabla)
{
	if (parametruTabla == 1)
		DesTabla(culoare_tabla, 1);
	if (parametruTabla == 2)
		schimbaTabla1(culoare_tabla);
	if (parametruTabla == 4)
		schimbaTabla2(culoare_tabla);
	if (parametruTabla == 3)
		schimbaTabla3(culoare_tabla);
	if (parametruTabla == 5)
		schimbaTabla4(culoare_tabla);
}

bool verificareMutarePiesa(int coloana1, int linia1, int coloana2, int linia2)
{
	// verifica daca integritatea este intacta
	int k = 0;
	if ((abs(linia2 - linia1) == 2 || abs(coloana2 - coloana1) == 2) &&
		(linia1 == linia2 || coloana1 == coloana2) &&
		tabla[coloana1][linia1] != 0 && tabla[coloana2][linia2] != 0 &&
		// tabla[linia1][coloana1] != tabla[linia2][coloana2])
		tabla[coloana1][linia1] == 1 && tabla[coloana2][linia2] == 2 &&
		tabla[(coloana1 + coloana2) / 2][linia1] != 2 &&
		tabla[coloana1][(linia1 + linia2) / 2] != 2)
		k++;
	if (k == 0)
		return false;
	else
		return true;
}

int verificarePozitieValidaINT()	// verifica alg
{
	int piesaBlocata = 0, count = 0;
	for (int i = 2; i < 9; i++)
	{
		for (int j = 2; j < 9; j++)
		{
			if (tabla[i][j] == 1)
			{
				int coloana2 = i, linia2 = j;
				count++;

				if ((tabla[coloana2 - 1][linia2] != 1 || tabla[coloana2 - 2][linia2] % 2 != 0 || tabla[coloana2 - 2][linia2] == 6) &&
					(tabla[coloana2 + 1][linia2] != 1 || tabla[coloana2 + 2][linia2] % 2 != 0 || tabla[coloana2 + 2][linia2] == 6) &&
					(tabla[coloana2][linia2 - 1] != 1 || tabla[coloana2][linia2 - 2] % 2 != 0 || tabla[coloana2][linia2 - 2] == 6) &&
					(tabla[coloana2][linia2 + 1] != 1 || tabla[coloana2][linia2 + 2] % 2 != 0 || tabla[coloana2][linia2 + 2] == 6))
					piesaBlocata++;
			}
		}
	}

	return piesaBlocata;

}

void schimbaCuloarePiese(int mod)	// matrice refacuta
{
	int x1, y1;
	int culoare;
	int click = false;
	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			x1 = mousex();
			y1 = mousey();
		}

	while (!click);

	culoare = getpixel(x1, y1);
	if (culoare == 0 || culoare == culoare_tabla)
		culoare = culoare_piese;

	if (culoare == culoare_piesa1)
	{
		int aux = culoare_piese;
		culoare_piese = culoare_piesa1;
		culoare_piesa1 = aux;
	}

	if (culoare == culoare_piesa2)
	{
		int aux = culoare_piese;
		culoare_piese = culoare_piesa2;
		culoare_piesa2 = aux;
	}

	if (culoare == culoare_piesa3)
	{
		int aux = culoare_piese;
		culoare_piese = culoare_piesa3;
		culoare_piesa3 = aux;
	}

	if (culoare == culoare_piesa4)
	{
		int aux = culoare_piese;
		culoare_piese = culoare_piesa4;
		culoare_piesa4 = aux;
	}

	if (culoare == culoare_piesa5)
	{
		int aux = culoare_piese;
		culoare_piese = culoare_piesa5;
		culoare_piesa5 = aux;
	}

	if (culoare == culoare_piesa6)
	{
		int aux = culoare_piese;
		culoare_piese = culoare_piesa6;
		culoare_piesa6 = aux;
	}

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare);

	culoare_piese = culoare;
	if (mod == 1) afiseazaScorSingleplayer();

	setfillstyle(SOLID_FILL, culoare_piese);
	floodfill(lat *9.5, lat *0.5, CYAN);
	setfillstyle(SOLID_FILL, BLACK);
	bar(lat *3, 0, lat *9 + 1, lat);
}

void schimbaCuloareTabla(int mod)
{
	int x1, y1;
	int culoare;
	int click = false;
	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			x1 = mousex();
			y1 = mousey();
		}

	while (!click);

	culoare = getpixel(x1, y1);
	if (culoare == 0 || culoare == culoare_piese)
		culoare = culoare_tabla;

	if (culoare == culoare_tabla1)
	{
		int aux = culoare_tabla;
		culoare_tabla = culoare_tabla1;
		culoare_tabla1 = aux;
	}

	if (culoare == culoare_tabla2)
	{
		int aux = culoare_tabla;
		culoare_tabla = culoare_tabla2;
		culoare_tabla2 = aux;
	}

	if (culoare == culoare_tabla3)
	{
		int aux = culoare_tabla;
		culoare_tabla = culoare_tabla3;
		culoare_tabla3 = aux;
	}

	if (culoare == culoare_tabla4)
	{
		int aux = culoare_tabla;
		culoare_tabla = culoare_tabla4;
		culoare_tabla4 = aux;
	}

	if (culoare == culoare_tabla5)
	{
		int aux = culoare_tabla;
		culoare_tabla = culoare_tabla5;
		culoare_tabla5 = aux;
	}

	if (culoare == culoare_tabla6)
	{
		int aux = culoare_tabla;
		culoare_tabla = culoare_tabla6;
		culoare_tabla6 = aux;
	}

	culoare_tabla = culoare;
	selectieTablaCuloare(parametruTabla);

	for (int i = 2; i <= 8; i++)
		for (int j = 2; j <= 8; j++)
		{
			if (tabla[i][j] == 1)
				deseneazaPiesa(j, i, culoare_piese);
			else if (tabla[i][j] == 2)
				deseneazaPiesa(j, i, BLACK);
		}

	if (mod == 1)
	{
		setcolor(culoare_tabla);
		outtextxy(lat *4.2, lat *9.4, "PIESE RAMASE:");
	}

	setfillstyle(SOLID_FILL, culoare_tabla);
	floodfill(lat *11.5, lat *1.5, WHITE);
	setfillstyle(SOLID_FILL, BLACK);
	bar(lat *10 + 1, lat *2, lat *11, lat *8 + 1);
}

void afiseazaScorTwoPlayers(int jucator)
{
	setcolor(culoare_piese);
	itoa(scor1, sirScor1, 10);
	itoa(scor2, sirScor2, 10);

	int i, j;
	if (jucator == 0)
    {
		for (i = 2; i <= 8; i++)
			for (j = 2; j <= 8; j++)
				if (tabla[i][j] == 2)
				{
					setfillstyle(SOLID_FILL, BLACK);
					bar(lat *2, 11 *lat, 5 *lat, 12 *lat);
					setcolor(LIGHTRED);
					settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
					scor1 += 1;
				}
        m = scor1 - 1 - scor2;
					itoa(scor1 - 1 - scor2, sirScor1, 10);
					outtextxy(lat *2.5, 11 *lat, sirScor1);
    }
	cout << m << " ";

	if (jucator == 1)
    {
		for (i = 2; i <= 8; i++)
			for (j = 2; j <= 8; j++)
				if (tabla[i][j] == 2)
				{
					setfillstyle(SOLID_FILL, BLACK);
					bar(lat *7, 11 *lat, lat *10, lat *12);
					setcolor(LIGHTRED);
					scor2 += 1;
				}
        n = scor2 - scor1;
        itoa(scor2 - scor1, sirScor2, 10);
        outtextxy(lat *8.1, 11 *lat, sirScor2);
    }

	if (jucator == 3)
	{
		setcolor(LIGHTRED);
		//m = 0, n = 0;
		itoa(m, sirScor1, 10);
		outtextxy(lat *2.5, 11 *lat, sirScor1);
		itoa(n, sirScor2, 10);
		outtextxy(lat *8.1, 11 *lat, sirScor2);
	}

	cout << n << endl;
}

void endgame(int mod)
{
	int numarPiesePierdute = verificarePozitieValidaINT();
	int numarPiese = numarDePieseINT();
	if (numarPiese == numarPiesePierdute)
	{
		delay(500);
		PlaySound("endmusic.WAV", NULL, SND_ASYNC);
		for (int i = 2; i <= 8; i++)
			for (int j = 2; j <= 8; j++)
				if (tabla[i][j] == 1)
				{
					deseneazaPiesa(j, i, 12);
					delay(300);
				}

		delay(1500);
		//cleardevice();

		if (mod == 1)
			readimagefile("gamelost.jpg", lat *3, lat *3, lat *8, lat *8);
		else
		{
			m = m * 100;
			n = n * 100;
			itoa(m, sirScor1, 10);
			itoa(n, sirScor2, 10);

			settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
			readimagefile("gameover.jpg", lat *3, lat *3, lat *8, lat *8);
			if (m > n)
			{
				outtextxy(lat *4, lat *6, "PLAYER1");
				outtextxy(lat *5, lat *6.5, "WON");
				outtextxy(lat *4.75, lat *7, "WITH");
				outtextxy(lat *4, lat *7.5, sirScor1);
				outtextxy(lat *6, lat *7.5, "PCT");
			}
			else if (m < n)
			{
				// (scor1 - 1 - scor2 < scor2 - scor1)
				outtextxy(lat *4, lat *6, "PLAYER2");
				outtextxy(lat *5, lat *6.5, "WON");
				outtextxy(lat *4.75, lat *7, "WITH");
				outtextxy(lat *4, lat *7.5, sirScor2);
				outtextxy(lat *6, lat *7.5, "PCT");
			}
			else if (m == n)	//??? nu merge, ceva nu se updateaza la timp
			{
				outtextxy(lat *4, lat *6, "DRAW");
				outtextxy(lat *5, lat *6.5, "WITH");
				outtextxy(lat *3.5, lat *7, sirScor1);
				outtextxy(lat *6, lat *7, "PCT");
			}
		}

		delay(1000);
		for (int i = 0; i <= 11; i++)
			for (int j = 0; j <= 12; j++)
			{
				setfillstyle(HATCH_FILL, (j + i) % 15);
				bar(i *lat, j *lat, (i + 1) *lat + 1, (j + 1) *lat + 1);
				delay(10);
			}

		getch();
		closegraph();
		exit(0);	//?
	}
}

void mutareMultipla(int coloanaInitiala, int linieInitiala, int jucator)
{
	int numarPiesePierdute = verificarePozitieValidaINT();
	int numarPiese = numarDePieseINT();
	if (numarPiese == numarPiesePierdute)
	{
		setcolor(3);
		outtextxy(100, 275, "NU MAI EXISTA MISCARI POSIBILE!");
		delay(1500);
		cleardevice();
		outtextxy(200, 200, "GAME OVER!");
		getch();
		closegraph();
	}	// probabil nefolositoare?

	int culoare;

	if (jucator == 0)
		culoare = 13;
	else
		culoare = 9;

	deseneazaPiesa(linieInitiala, coloanaInitiala, culoare);
	int click = false, x, y, linia2, coloana2;

	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			x = mousex();
			y = mousey();
			linia2 = (y - lat) / lat + 1;
			coloana2 = (x - lat) / lat + 1;
		} while (!click);

	if (verificareMutarePiesa(coloanaInitiala, linieInitiala, coloana2, linia2))
	{
		PlaySound("pop.WAV", NULL, SND_ASYNC);
		tabla[coloanaInitiala][linieInitiala] = 2;
		tabla[coloana2][linia2] = 1;
		deseneazaPiesa(linia2, coloana2, culoare_piese);
		deseneazaPiesa(linieInitiala, coloanaInitiala, culoarea_mea);

		if (linieInitiala == linia2)
		{
			tabla[(coloanaInitiala + coloana2) / 2][linieInitiala] = 2;
			deseneazaPiesa(linieInitiala, (coloanaInitiala + coloana2) / 2, BLACK);
		}
		else if (coloanaInitiala == coloana2)
		{
			tabla[coloanaInitiala][(linieInitiala + linia2) / 2] = 2;
			deseneazaPiesa((linieInitiala + linia2) / 2, coloanaInitiala, BLACK);
		}

		if ((tabla[coloana2 - 1][linia2] == 1 && tabla[coloana2 - 2][linia2] % 2 == 0 && tabla[coloana2 - 2][linia2] != 6) ||
			(tabla[coloana2 + 1][linia2] == 1 && tabla[coloana2 + 2][linia2] % 2 == 0 && tabla[coloana2 + 2][linia2] != 6) ||
			(tabla[coloana2][linia2 - 1] == 1 && tabla[coloana2][linia2 - 2] % 2 == 0 && tabla[coloana2][linia2 - 2] != 6) ||
			(tabla[coloana2][linia2 + 1] == 1 && tabla[coloana2][linia2 + 2] % 2 == 0 && tabla[coloana2][linia2 + 2] != 6))
			mutareMultipla(coloana2, linia2, jucator);
	}
	else
	{
		if (tabla[coloanaInitiala][linieInitiala] == 1)
			deseneazaPiesa(linieInitiala, coloanaInitiala, culoare_piese);
		else if (tabla[coloanaInitiala][linieInitiala] == 2)
			deseneazaPiesa(linieInitiala, coloanaInitiala, BLACK);
		PlaySound("error.WAV", NULL, SND_ASYNC);
		readimagefile("invalid1.jpg", lat *4, lat *10, lat *7, lat *11);
		delay(700);
		setfillstyle(SOLID_FILL, BLACK);
		bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
		mutareMultipla(coloanaInitiala, linieInitiala, jucator);
	}
}

void mutarePiesaAutoPlay(int coloana1, int linia1, int coloana2, int linia2)
{
	bool k = false;
	int x, y, a, b;
	int x1, y1, x2, y2;
	int xmijloc, ymijloc;

	if (tabla[coloana1][linia1] == 1)
		deseneazaPiesa(linia1, coloana1, 13);	// inversate

	srand(time(0));
	int time0;
	for (int i = 1; i <= 5; i++)
		time0 = 300 + (rand() % 501);
	delay(time0);
	// delay(500);
	afiseazaScorAutoplay();
	a = coloana2, b = linia2;
	if (verificareMutarePiesa(coloana1, linia1, coloana2, linia2))
	{
		PlaySound("pop.WAV", NULL, SND_ASYNC);

		tabla[coloana1][linia1] = 2;
		tabla[coloana2][linia2] = 1;
		deseneazaPiesa(linia2, coloana2, WHITE);
		deseneazaPiesa(linia1, coloana1, culoarea_mea);

		if (linia1 == linia2)
		{
			tabla[(coloana1 + coloana2) / 2][linia1] = 2;
			deseneazaPiesa(linia1, (coloana1 + coloana2) / 2, BLACK);
		}
		else if (coloana1 == coloana2)
		{
			tabla[coloana1][(linia1 + linia2) / 2] = 2;
			deseneazaPiesa((linia1 + linia2) / 2, coloana1, BLACK);
		}
	}



	if (!este_meci_neterminat_autoplay())
	{
		PlaySound("ohyeah.WAV", NULL, SND_ASYNC);
        readimagefile("macho.jpg", lat *3, lat *3, lat *8, lat *8);

	}

	srand(time(0));
	int time;
	for (int i = 1; i <= 5; i++)
		time = 500 + (rand() % 1001);
	delay(time);


}

void autoplay()
{

	outtextxy(lat * 4, lat * 9.4, "PIESE RAMASE:");
	//afiseazaScorAutoplay();
	srand(time(0));
	int time = 1 + (rand() % 3);
	if (time == 1)
	{
		mutarePiesaAutoPlay(5, 3, 5, 5);

		mutarePiesaAutoPlay(7, 4, 5, 4);
		mutarePiesaAutoPlay(6, 2, 6, 4);
		mutarePiesaAutoPlay(6, 5, 6, 3);



		mutarePiesaAutoPlay(4, 2, 6, 2);
		mutarePiesaAutoPlay(6, 7, 6, 5);
		mutarePiesaAutoPlay(6, 2, 6, 4);
		mutarePiesaAutoPlay(8, 6, 6, 6);
		mutarePiesaAutoPlay(5, 6, 7, 6);
		mutarePiesaAutoPlay(8, 4, 8, 6);
		mutarePiesaAutoPlay(3, 6, 5, 6);
		mutarePiesaAutoPlay(8, 6, 6, 6);
		mutarePiesaAutoPlay(4, 8, 4, 6);
		mutarePiesaAutoPlay(4, 5, 4, 7);
		mutarePiesaAutoPlay(6, 8, 4, 8);
		mutarePiesaAutoPlay(4, 3, 4, 5);
		mutarePiesaAutoPlay(4, 8, 4, 6);
		mutarePiesaAutoPlay(2, 4, 4, 4);
		mutarePiesaAutoPlay(5, 4, 3, 4);
		mutarePiesaAutoPlay(2, 6, 2, 4);
		mutarePiesaAutoPlay(5, 6, 5, 4);
		mutarePiesaAutoPlay(2, 4, 4, 4);
		mutarePiesaAutoPlay(5, 4, 3, 4);
		mutarePiesaAutoPlay(7, 5, 5, 5);
		mutarePiesaAutoPlay(3, 4, 3, 6);
		mutarePiesaAutoPlay(4, 5, 6, 5);
		mutarePiesaAutoPlay(3, 6, 5, 6);
		mutarePiesaAutoPlay(5, 6, 7, 6);
		mutarePiesaAutoPlay(6, 4, 6, 6);
		mutarePiesaAutoPlay(7, 6, 5, 6);
		mutarePiesaAutoPlay(5, 7, 5, 5);
	}

	if (time == 2)
	{
		mutarePiesaAutoPlay(5, 3, 5, 5);
		mutarePiesaAutoPlay(5, 6, 5, 4);
		mutarePiesaAutoPlay(7, 5, 5, 5);
		mutarePiesaAutoPlay(5, 5, 5, 3);
		mutarePiesaAutoPlay(6, 3, 6, 5);
		mutarePiesaAutoPlay(8, 4, 6, 4);
		mutarePiesaAutoPlay(3, 4, 5, 4);
		mutarePiesaAutoPlay(5, 4, 7, 4);
		mutarePiesaAutoPlay(4, 2, 4, 4);
		mutarePiesaAutoPlay(4, 5, 4, 3);
		mutarePiesaAutoPlay(4, 7, 4, 5);
		mutarePiesaAutoPlay(2, 6, 4, 6);
		mutarePiesaAutoPlay(7, 6, 5, 6);
		mutarePiesaAutoPlay(5, 6, 3, 6);
		mutarePiesaAutoPlay(6, 8, 6, 6);
		mutarePiesaAutoPlay(6, 5, 6, 7);
		mutarePiesaAutoPlay(6, 2, 4, 2);
		mutarePiesaAutoPlay(4, 2, 4, 4);
		mutarePiesaAutoPlay(2, 4, 2, 6);
		mutarePiesaAutoPlay(2, 6, 4, 6);
		// ?? 32 -> 33
		mutarePiesaAutoPlay(4, 8, 6, 8);
		mutarePiesaAutoPlay(6, 8, 6, 6);
		mutarePiesaAutoPlay(8, 6, 8, 4);
		mutarePiesaAutoPlay(8, 4, 6, 4);
		mutarePiesaAutoPlay(4, 5, 4, 3);
		mutarePiesaAutoPlay(4, 3, 6, 3);
		mutarePiesaAutoPlay(6, 3, 6, 5);
		mutarePiesaAutoPlay(6, 5, 6, 7);
		mutarePiesaAutoPlay(6, 7, 4, 7);
		// ?????
		mutarePiesaAutoPlay(4, 7, 4, 5);
		mutarePiesaAutoPlay(3, 5, 5, 5);
	}

	if (time == 3)
	{
		mutarePiesaAutoPlay(5, 3, 5, 5);
		mutarePiesaAutoPlay(7, 4, 5, 4);
		mutarePiesaAutoPlay(6, 2, 6, 4);
		mutarePiesaAutoPlay(6, 5, 6, 3);
		mutarePiesaAutoPlay(6, 7, 6, 5);
		mutarePiesaAutoPlay(8, 6, 6, 6);
		mutarePiesaAutoPlay(5, 6, 7, 6);
		mutarePiesaAutoPlay(8, 4, 8, 6);
		mutarePiesaAutoPlay(8, 6, 6, 6);
		mutarePiesaAutoPlay(4, 4, 6, 4);
		mutarePiesaAutoPlay(2, 4, 4, 4);
		mutarePiesaAutoPlay(3, 6, 5, 6);
		mutarePiesaAutoPlay(5, 6, 7, 6);
		mutarePiesaAutoPlay(7, 6, 7, 4);
		mutarePiesaAutoPlay(7, 4, 5, 4);
		mutarePiesaAutoPlay(5, 4, 3, 4);
		mutarePiesaAutoPlay(4, 8, 4, 6);
		mutarePiesaAutoPlay(4, 5, 4, 7);
		mutarePiesaAutoPlay(6, 8, 4, 8);
		mutarePiesaAutoPlay(4, 8, 4, 6);
		mutarePiesaAutoPlay(2, 6, 2, 4);
		mutarePiesaAutoPlay(2, 4, 4, 4);
		mutarePiesaAutoPlay(4, 2, 6, 2);
		mutarePiesaAutoPlay(6, 2, 6, 4);
		mutarePiesaAutoPlay(6, 4, 6, 6);
		mutarePiesaAutoPlay(4, 3, 4, 5);
		mutarePiesaAutoPlay(4, 5, 4, 7);
		mutarePiesaAutoPlay(4, 7, 6, 7);
		mutarePiesaAutoPlay(6, 7, 6, 5);
		mutarePiesaAutoPlay(6, 5, 4, 5);
		mutarePiesaAutoPlay(3, 5, 5, 5);
	}


}

void deseneazaMarimeaConteazaSiRimeaza()
{
	setfillstyle(SOLID_FILL, culoare_tabla);
	bar(lat *0.48, lat *2, lat *0.52, lat *6);
	for (int i = 2; i <= 6; i++)
		bar(lat *0.35, i *lat, lat *0.65, (i *lat) + 3);
	if (aaa == 1)
		deseneazaPiesaMeniu(2, 0, culoare_piese);
	else if (aaa == 2)
		deseneazaPiesaMeniu(3, 0, culoare_piese);
	else if (aaa == 3)
		deseneazaPiesaMeniu(4, 0, culoare_piese);
	else if (aaa == 4)
		deseneazaPiesaMeniu(5, 0, culoare_piese);
}

void mutarePiesaSingleplayer(int culoare)
{
	bool k = false;
	int linia1, coloana1, linia2, coloana2, x, y;
	int x1, y1, x2, y2;
	int xmijloc, ymijloc;
	int click = false;

	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			x = mousex();
			y = mousey();
			linia1 = (y - lat) / lat + 1;
			coloana1 = (x - lat) / lat + 1;
		}

	while (!click);	// primul click

	if (x > 0 && x < lat && y > 0 && y < lat)
	{
		culoare_piese = 15,
			culoare_piesa1 = 8,
			culoare_piesa2 = 9,
			culoare_piesa3 = 10,
			culoare_piesa4 = 11,
			culoare_piesa5 = 12,
			culoare_piesa6 = 14;
		culoare_tabla = 3,
			culoare_tabla1 = 1,
			culoare_tabla2 = 2,
			culoare_tabla3 = 4,
			culoare_tabla4 = 5,
			culoare_tabla5 = 6,
			culoare_tabla6 = 7;
		cleardevice();
		initializareMatriceTabla();
		DesTabla(culoare_tabla, 1);
		setcolor(culoare_tabla);
		outtextxy(lat *4.2, lat *9.4, "PIESE RAMASE:");
		afiseazaScorSingleplayer();
	}
	else if (x > 0 && x < lat && y > lat && y < lat *2)
	{
		int linia1, coloana1;
		deseneazaMarimeaConteazaSiRimeaza();
		int click = false;

		do
			if (ismouseclick(WM_LBUTTONDOWN) && !click)
			{
				click = true;
				clearmouseclick(WM_LBUTTONDOWN);
				x = mousex();
				y = mousey();
			}

		while (!click);
		if (x > 0 && x < lat && y > lat *2 && y < lat *3)
		{
			closegraph();
			lat = 35;
			openGraph();
			DesTabla(culoare_tabla, 1);
			aaa = 1;
		}
		else if (x > 0 && x < lat && y > lat *3 && y < lat *4)
		{
			closegraph();
			lat = 50;
			openGraph();
			DesTabla(culoare_tabla, 1);
			aaa = 2;
		}
		else if (x > 0 && x < lat && y > lat *4 && y < lat *5)
		{
			closegraph();
			lat = 65;
			openGraph();
			DesTabla(culoare_tabla, 1);
			aaa = 3;
		}
		else if (x > 0 && x < lat && y > lat *5 && y < lat *6)
		{
			closegraph();
			lat = 75;
			openGraph();
			DesTabla(culoare_tabla, 1);
			aaa = 4;
		}

		afiseazaScorSingleplayer();
		setcolor(culoare_tabla);
		outtextxy(lat *4.2, lat *9.4, "PIESE RAMASE:");
		setfillstyle(SOLID_FILL, BLACK);
		bar(0, lat *2, lat, lat *6 + 6);

		mutarePiesaSingleplayer(culoare_piese);
	}
	else
	{
		if (y > 0 && y < lat && x > lat *9 && x < lat *10)
		{
			deseneazaMeniuCuloarePiesa();
			schimbaCuloarePiese(1);
			int click = false;
		}
		else if (x > lat *10 && x < lat *11 && y > lat && y < lat *2)
		{
			deseneazaMeniuCuloareTabla();
			schimbaCuloareTabla(1);
			int click = false;
			/*do
				if (ismouseclick(WM_LBUTTONDOWN) && !click)
				{
					click = true;
					clearmouseclick(WM_LBUTTONDOWN);
					x = mousex();
					y = mousey();
					linia1 = (y - lat) / lat + 1;
					coloana1 = (x - lat) / lat + 1;
				} while (!click); */
		}
		else if (tabla[coloana1][linia1] == 6 || tabla[coloana1][linia1] == 7)
		{
			PlaySound("error.WAV", NULL, SND_ASYNC);
			readimagefile("joacapetabla.jpg", lat *4, lat *10, lat *7, lat *11);
			delay(700);
			setfillstyle(SOLID_FILL, BLACK);
			bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
			mutarePiesaSingleplayer(culoare_piese);
		}
		else
		{
			if (tabla[coloana1][linia1] == 1)
				deseneazaPiesa(linia1, coloana1, 13);
			click = false;

			do
				if (ismouseclick(WM_LBUTTONDOWN) && !click)
				{
					click = true;
					clearmouseclick(WM_LBUTTONDOWN);
					x = mousex();
					y = mousey();
					linia2 = (y - lat) / lat + 1;
					coloana2 = (x - lat) / lat + 1;
				} while (!click);
			if (tabla[coloana2][linia2] == 6 && tabla[coloana1][linia1] == 1)
			{
				PlaySound("error.WAV", NULL, SND_ASYNC);
				setcolor(WHITE);
				readimagefile("joacapetabla.jpg", lat *4, lat *10, lat *7, lat *11);
				delay(700);
				setfillstyle(SOLID_FILL, BLACK);
				bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
				deseneazaPiesa(linia1, coloana1, culoare_piese);
				mutarePiesaSingleplayer(culoare_piese);
			}
			else if (verificareMutarePiesa(coloana1, linia1, coloana2, linia2))
			{
				PlaySound("pop.WAV", NULL, SND_ASYNC);
				tabla[coloana1][linia1] = 2;
				tabla[coloana2][linia2] = 1;
				deseneazaPiesa(linia2, coloana2, culoare_piese);
				deseneazaPiesa(linia1, coloana1, culoarea_mea);

				if (linia1 == linia2)
				{
					tabla[(coloana1 + coloana2) / 2][linia1] = 2;
					deseneazaPiesa(linia1, (coloana1 + coloana2) / 2, BLACK);
				}
				else if (coloana1 == coloana2)
				{
					tabla[coloana1][(linia1 + linia2) / 2] = 2;
					deseneazaPiesa((linia1 + linia2) / 2, coloana1, BLACK);
				}
			}
			else
			{
				if (tabla[coloana1][linia1] == 1)
					deseneazaPiesa(linia1, coloana1, culoare_piese);
				else if (tabla[coloana1][linia1] == 2)
					deseneazaPiesa(linia1, coloana1, BLACK);
				PlaySound("error.WAV", NULL, SND_ASYNC);
				readimagefile("invalid1.jpg", lat *4, lat *10, lat *7, lat *11);
				// outtextxy(160, 500, "MISCARE INVALIDA!");
				delay(700);
				setfillstyle(SOLID_FILL, BLACK);
				bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
			}
		}
	}
}

void mutarePiesaTwoplayers(int jucator)
{
	int diferenta1, diferenta2;

	int linia1, coloana1, linia2, coloana2, x, y;
	int x1, y1, x2, y2;
	int xmijloc, ymijloc;
	int click = false;

	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			x = mousex();
			y = mousey();
			linia1 = (y - lat) / lat + 1;
			coloana1 = (x - lat) / lat + 1;
		}

	while (!click);
	if (x > lat && x < 2 *lat && y > 0 && y < lat)
	{
		deseneazaMeniuTable();
		int click = false;
		do
			if (ismouseclick(WM_LBUTTONDOWN) && !click)
			{
				click = true;
				clearmouseclick(WM_LBUTTONDOWN);
				x = mousex();
				y = mousey();
			}

		while (!click);

		if (x > lat *2 && x < lat *3 && y > 0 && y < lat)
		{
			initializareMatriceTabla();
			tabla[3][3] = 1;
			tabla[3][7] = 1;
			tabla[7][3] = 1;
			tabla[7][7] = 1;
            initializarePieseTabla(culoare_piese);
			schimbaTabla1(culoare_tabla);
			parametruTabla = 2;
		}
		else if (x > lat *3 && x < lat *4 && y > 0 && y < lat)
		{
			for (int i = 0; i <= 10; i++)
				for (int j = 0; j <= 10; j++)
					tabla[i][j] = 6;
			for (int i = 2; i <= 8; i++)
				for (int j = 2; j <= 8; j++)
					tabla[i][j] = 1;

			tabla[2][2] = 6;
			tabla[8][2] = 6;
			tabla[2][8] = 6;
			tabla[8][8] = 6;

			tabla[4][4] = 6;
			tabla[5][4] = 6;
			tabla[6][4] = 6;
			tabla[4][6] = 6;
			tabla[5][6] = 6;
			tabla[6][6] = 6;
			tabla[5][5] = 2;

			initializarePieseTabla(culoare_piese);

			schimbaTabla3(culoare_tabla);
			parametruTabla = 3;
		}
		else if (x > lat *4 && x < lat *5 && y > 0 && y < lat)
		{
			for (int i = 0; i <= 10; i++)
				for (int j = 0; j <= 10; j++)
					tabla[i][j] = 6;
			for (int i = 2; i <= 8; i++)
				for (int j = 2; j <= 8; j++)
					tabla[i][j] = 1;

			tabla[5][5] = 2;
			initializarePieseTabla(culoare_piese);
			schimbaTabla2(culoare_tabla);
			parametruTabla = 4;
		}
		else if (x > lat *5 && x < lat *6 && y > 0 && y < lat)
		{
			for (int i = 0; i <= 10; i++)
				for (int j = 0; j <= 10; j++)
					tabla[i][j] = 6;
			for (int i = 2; i <= 8; i++)
				for (int j = 2; j <= 8; j++)
					tabla[i][j] = 1;
			for (int i = 2; i <= 8; i++)
				for (int j = 2; j <= 8; j += 6)
				{
					tabla[i][j] = 6;
				}

			tabla[5][2] = 1;
			tabla[5][8] = 1;

			tabla[2][3] = 6;
			tabla[3][3] = 6;
			tabla[2][4] = 6;

			tabla[2][6] = 6;
			tabla[3][7] = 6;
			tabla[2][7] = 6;

			tabla[7][3] = 6;
			tabla[8][3] = 6;
			tabla[8][4] = 6;

			tabla[8][6] = 6;
			tabla[7][7] = 6;
			tabla[8][7] = 6;

			tabla[5][5] = 2;
			initializarePieseTabla(culoare_piese);
			schimbaTabla4(culoare_tabla);
			parametruTabla = 5;
		}

        readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
        readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);
		setfillstyle(SOLID_FILL, BLACK);
		bar(lat *2, 0, lat *6 + 1, lat);
		m = 0, n = 0;
		//afiseazaScorTwoPlayers(0);
		//afiseazaScorTwoPlayers(1);
		bar (lat * 1, lat * 11, lat * 10, lat * 12);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	setcolor(LIGHTRED);
	char sir1[10], sir2[10];
		itoa(m, sir1, 10);
		itoa(n, sir2, 10);
		outtextxy(lat *2.5, 11 *lat, sir1);
		outtextxy(lat *8.1, 11 *lat, sir2);
		mutarePiesaTwoplayers(jucator);
	}
	else if (x > 0 && x < lat && y > 0 && y < lat)
	{
		culoare_piese = 15,
			culoare_piesa1 = 8,
			culoare_piesa2 = 9,
			culoare_piesa3 = 10,
			culoare_piesa4 = 11,
			culoare_piesa5 = 12,
			culoare_piesa6 = 14;
		culoare_tabla = 3,
			culoare_tabla1 = 1,
			culoare_tabla2 = 2,
			culoare_tabla3 = 4,
			culoare_tabla4 = 5,
			culoare_tabla5 = 6,
			culoare_tabla6 = 7;
		cleardevice();
		parametruTabla = 1;
		initializareMatriceTabla();
		m = 0, n = 0;
		DesTabla(culoare_tabla, 2);
		readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
        readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);
        mutarePiesaTwoplayers(jucator);
	}
	else if (x > 0 && x < lat && y > lat && y < lat *2)
	{
		int linia1, coloana1;
		deseneazaMarimeaConteazaSiRimeaza();
		int click = false;

		do
			if (ismouseclick(WM_LBUTTONDOWN) && !click)
			{
				click = true;
				clearmouseclick(WM_LBUTTONDOWN);
				x = mousex();
				y = mousey();
			}

		while (!click);
		if (x > 0 && x < lat && y > lat *2 && y < lat *3)
		{
			closegraph();
			lat = 35;
			openGraph();
			selectieTablaCuloare(parametruTabla);
			aaa = 1;
		}
		else if (x > 0 && x < lat && y > lat *3 && y < lat *4)
		{
			closegraph();
			lat = 50;
			openGraph();
			selectieTablaCuloare(parametruTabla);
			aaa = 2;
		}
		else if (x > 0 && x < lat && y > lat *4 && y < lat *5)
		{
			closegraph();
			lat = 65;
			openGraph();
			selectieTablaCuloare(parametruTabla);
			aaa = 3;
		}
		else if (x > 0 && x < lat && y > lat *5 && y < lat *6)
		{
			closegraph();
			lat = 75;
			openGraph();
			selectieTablaCuloare(parametruTabla);
			aaa = 4;
		}

		readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
        readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);
		setcolor(LIGHTRED);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
		char sir1[10], sir2[10];
		itoa(m, sir1, 10);
		itoa(n, sir2, 10);
		outtextxy(lat *2.5, 11 *lat, sir1);
		outtextxy(lat *8.1, 11 *lat, sir2);
		//afiseazaScorTwoPlayers(0);
		//afiseazaScorTwoPlayers(1);
		setfillstyle(SOLID_FILL, BLACK);
		bar(0, lat *2, lat, lat *6 + 6);
		//bar (lat * 1, lat * 11, lat * 10, lat * 12);
		mutarePiesaTwoplayers(jucator);
	}
	else
	{
		if (y > 0 && y < lat && x > lat *9 && x < lat *10)
		{

			deseneazaMeniuCuloarePiesa();
			schimbaCuloarePiese(2);
			setcolor(LIGHTRED);
			char sir1[10], sir2[10];
		itoa(m, sir1, 10);
		itoa(n, sir2, 10);
		outtextxy(lat *2.5, 11 *lat, sir1);
		outtextxy(lat *8.1, 11 *lat, sir2);
            //bar (lat * 1, lat * 11, lat * 10, lat * 12);
			mutarePiesaTwoplayers(jucator);

		}
		else if (x > lat *10 && x < lat *11 && y > lat && y < lat *2)
		{

			deseneazaMeniuCuloareTabla();
			schimbaCuloareTabla(2);
			setcolor(LIGHTRED);
			char sir1[10], sir2[10];
            itoa(m, sir1, 10);
            itoa(n, sir2, 10);
            outtextxy(lat *2.5, 11 *lat, sir1);
            outtextxy(lat *8.1, 11 *lat, sir2);
			//bar (lat * 1, lat * 11, lat * 10, lat * 12);
			mutarePiesaTwoplayers(jucator);

			readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
            readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);
		}
		else if (tabla[coloana1][linia1] == 6 || tabla[coloana1][linia1] == 7)
		{
			PlaySound("error.WAV", NULL, SND_ASYNC);
			readimagefile("joacapetabla.jpg", lat *4, lat *10, lat *7, lat *11);
			delay(700);
			setfillstyle(SOLID_FILL, BLACK);
			bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
			mutarePiesaTwoplayers(jucator);
		}
		else
		{
			if (jucator == 0)
				if (tabla[coloana1][linia1] == 1)
					deseneazaPiesa(linia1, coloana1, 13);
			if (jucator == 1)
				if (tabla[coloana1][linia1] == 1)
					deseneazaPiesa(linia1, coloana1, 9);

			click = false;

			do
				if (ismouseclick(WM_LBUTTONDOWN) && !click)
				{
					click = true;
					clearmouseclick(WM_LBUTTONDOWN);
					x = mousex();
					y = mousey();
					linia2 = (y - lat) / lat + 1;
					coloana2 = (x - lat) / lat + 1;
				} while (!click);

			if (jucator == 0)
			{
				if (tabla[coloana2][linia2] == 6 && tabla[coloana1][linia1] == 1)
				{
					PlaySound("error.WAV", NULL, SND_ASYNC);
					setcolor(WHITE);
					readimagefile("joacapetabla.jpg", lat *4, lat *10, lat *7, lat *11);
					delay(700);
					setfillstyle(SOLID_FILL, BLACK);
					bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
					deseneazaPiesa(linia1, coloana1, culoare_piese);
					mutarePiesaTwoplayers(0);
				}
				else if (verificareMutarePiesa(coloana1, linia1, coloana2, linia2))
				{
					PlaySound("pop.WAV", NULL, SND_ASYNC);
					tabla[coloana1][linia1] = 2;
					tabla[coloana2][linia2] = 1;
					deseneazaPiesa(linia2, coloana2, culoare_piese);
					deseneazaPiesa(linia1, coloana1, culoarea_mea);

					if (linia1 == linia2)
					{
						tabla[(coloana1 + coloana2) / 2][linia1] = 2;
						deseneazaPiesa(linia1, (coloana1 + coloana2) / 2, BLACK);
					}
					else if (coloana1 == coloana2)
					{
						tabla[coloana1][(linia1 + linia2) / 2] = 2;
						deseneazaPiesa((linia1 + linia2) / 2, coloana1, BLACK);
					}

					if ((tabla[coloana2 - 1][linia2] == 1 && tabla[coloana2 - 2][linia2] % 2 == 0 && tabla[coloana2 - 2][linia2] != 6) ||
						(tabla[coloana2 + 1][linia2] == 1 && tabla[coloana2 + 2][linia2] % 2 == 0 && tabla[coloana2 + 2][linia2] != 6) ||
						(tabla[coloana2][linia2 - 1] == 1 && tabla[coloana2][linia2 - 2] % 2 == 0 && tabla[coloana2][linia2 - 2] != 6) ||
						(tabla[coloana2][linia2 + 1] == 1 && tabla[coloana2][linia2 + 2] % 2 == 0 && tabla[coloana2][linia2 + 2] != 6))
					{
						mutareMultipla(coloana2, linia2, 0);
					}
					afiseazaScorTwoPlayers(0);
				}
				else
				{
					if (tabla[coloana1][linia1] == 1)
						deseneazaPiesa(linia1, coloana1, culoare_piese);
					else if (tabla[coloana1][linia1] == 2)
						deseneazaPiesa(linia1, coloana1, BLACK);

					PlaySound("error.WAV", NULL, SND_ASYNC);
					readimagefile("invalid1.jpg", lat *4, lat *10, lat *7, lat *11);
					delay(700);
					setfillstyle(SOLID_FILL, BLACK);
					bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
					mutarePiesaTwoplayers(jucator);
				}
			}
			else if (jucator == 1)
			{
				if (tabla[coloana2][linia2] == 6 && tabla[coloana1][linia1] == 1)
				{
					PlaySound("error.WAV", NULL, SND_ASYNC);
					setcolor(WHITE);
					readimagefile("joacapetabla.jpg", lat *4, lat *10, lat *7, lat *11);
					delay(700);
					setfillstyle(SOLID_FILL, BLACK);
					bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
					deseneazaPiesa(linia1, coloana1, culoare_piese);
					mutarePiesaTwoplayers(1);
				}
				else if (verificareMutarePiesa(coloana1, linia1, coloana2, linia2))
				{
					PlaySound("pop.WAV", NULL, SND_ASYNC);
					tabla[coloana1][linia1] = 2;
					tabla[coloana2][linia2] = 1;
					deseneazaPiesa(linia2, coloana2, culoare_piese);
					deseneazaPiesa(linia1, coloana1, culoarea_mea);

					if (linia1 == linia2)
					{
						tabla[(coloana1 + coloana2) / 2][linia1] = 2;
						deseneazaPiesa(linia1, (coloana1 + coloana2) / 2, BLACK);
					}
					else if (coloana1 == coloana2)
					{
						tabla[coloana1][(linia1 + linia2) / 2] = 2;
						deseneazaPiesa((linia1 + linia2) / 2, coloana1, BLACK);
					}

					if ((tabla[coloana2 - 1][linia2] == 1 && tabla[coloana2 - 2][linia2] % 2 == 0 && tabla[coloana2 - 2][linia2] != 6) ||
						(tabla[coloana2 + 1][linia2] == 1 && tabla[coloana2 + 2][linia2] % 2 == 0 && tabla[coloana2 + 2][linia2] != 6) ||
						(tabla[coloana2][linia2 - 1] == 1 && tabla[coloana2][linia2 - 2] % 2 == 0 && tabla[coloana2][linia2 - 2] != 6) ||
						(tabla[coloana2][linia2 + 1] == 1 && tabla[coloana2][linia2 + 2] % 2 == 0 && tabla[coloana2][linia2 + 2] != 6))
					{
						mutareMultipla(coloana2, linia2, 1);
					}
					afiseazaScorTwoPlayers(1);
				}
				else
				{
					if (tabla[coloana1][linia1] == 1)
						deseneazaPiesa(linia1, coloana1, culoare_piese);
					else if (tabla[coloana1][linia1] == 2)
						deseneazaPiesa(linia1, coloana1, BLACK);

					PlaySound("error.WAV", NULL, SND_ASYNC);
					readimagefile("invalid1.jpg", lat *4, lat *10, lat *7, lat *11);
					delay(700);
					setfillstyle(SOLID_FILL, BLACK);
					bar(lat *4, lat *10, lat *7 + 1, lat *11 + 1);
					mutarePiesaTwoplayers(jucator);
				}
			}
		}
	}
}

void singleplayer()
{
	int ok = 0;
	setcolor(culoare_tabla);
	outtextxy(lat *4.2, lat *9.4, "PIESE RAMASE:");

	do {
		//matriceVizualaActualizata();
		afiseazaScorSingleplayer();
		int numarPiesePierdute = verificarePozitieValidaINT();
		int numarPiese = numarDePieseINT();
		cout << numarPiese << " " << numarPiesePierdute << endl;

		endgame(1);
		este_meci_neterminat();
		// numarDePiese();

		mutarePiesaSingleplayer(culoare_piese);
		// verificarePozitieValida();

		// numarDePiese();
	} while (este_meci_neterminat());
}

void twoplayers()
{
	readimagefile("setari1.jpg", lat *1.25, lat *0.25, lat *1.75, lat *0.75);
	readimagefile("jucator1.jpg", lat *1.75, lat *10, lat *3.75, lat *11);
	readimagefile("jucator2.jpg", lat *7.25, lat *10, lat *9.25, lat *11);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	setcolor(LIGHTRED);
	char sir1[10], sir2[10];
		itoa(m, sir1, 10);
		itoa(n, sir2, 10);
		outtextxy(lat *2.5, 11 *lat, sir1);
		outtextxy(lat *8.1, 11 *lat, sir2);
	do {
		//afiseazaScorTwoPlayers(0);
		//afiseazaScorTwoPlayers(1);


		endgame(2);

		mutarePiesaTwoplayers(0);
		endgame(2);

		mutarePiesaTwoplayers(1);
		endgame(2);
	} while (este_meci_neterminat());

}

void selectieModJoc()
{

	deseneazaModJoc();

	int mx, my, click = false;

	click = false;
	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			mx = mousex();
			my = mousey();
			if (mx > 0 && mx < lat && my > 0 && my < lat)
			{
				PlaySound("bruh.WAV", NULL, SND_ASYNC);
				delay(200);
				cleardevice();
				deseneazaMeniul();
				readimagefile("setari1.jpg", lat *0.25, lat *0.25, lat *0.75, lat *0.75);

				readimagefile("solitar.jpg", 0, 0, lat * 11, lat * 2);
			}
			else if (mx > 150 && mx < 400 && my > 150 && my < 200)
			{
				PlaySound("bruh.WAV", NULL, SND_ASYNC);
				delay(200);

				cleardevice();

				DesTabla(culoare_tabla, 1);
				initializareMatriceTabla();

				initializarePieseTabla(culoare_piese);
				setcolor(LIGHTCYAN);

				singleplayer();
			}
			else if (mx > 150 && mx < 400 && my > 250 && my < 300)
			{
				PlaySound("bruh.WAV", NULL, SND_ASYNC);
				delay(200);

				cleardevice();
				DesTabla(culoare_tabla, 1);
				initializareMatriceTabla();

				initializarePieseTabla(culoare_piese);
				setcolor(LIGHTCYAN);

				twoplayers();
			}
			else if (mx > 150 && mx < 400 && my > 350 && my < 400)
			{
				PlaySound("bruh.WAV", NULL, SND_ASYNC);
				delay(200);
				cleardevice();

				DesTabla(culoare_tabla, 1);
				initializareMatriceTabla();

				initializarePieseTabla(culoare_piese);
				setcolor(LIGHTCYAN);

				autoplay();
			}

			//else if ((mx > 0 && mx < 50) && (my > 0 && my < 50))
			// play();
			else selectieModJoc();
		}

	while (!click);

}

void play()
{
	POINT mouse;

	int x, y, click = false;
	readimagefile("solitar.jpg", 0, 0, lat * 11, lat * 2);
	do
		if (ismouseclick(WM_LBUTTONDOWN) && !click)
		{
			click = true;
			clearmouseclick(WM_LBUTTONDOWN);
			x = mousex();
			y = mousey();

			if (x > lat *3 && x < lat *8 && y > lat *3 && y < lat *4)
			{
				PlaySound("bruh.WAV", NULL, SND_ASYNC);
				delay(200);
				cleardevice();
				readimagefile("solitar.jpg", 0, 0, lat * 11, lat * 2);
				readimagefile("setari.jpg", lat *0.25, lat *0.25, lat *0.75, lat *0.75);

				deseneazaModJoc();
				int mx, my, click = false;

				click = false;
				do
					if (ismouseclick(WM_LBUTTONDOWN) && !click)
					{
						click = true;
						clearmouseclick(WM_LBUTTONDOWN);
						mx = mousex();
						my = mousey();
						if (mx > 0 && mx < lat && my > 0 && my < lat)
						{
							PlaySound("bruh.WAV", NULL, SND_ASYNC);
							readimagefile("solitar.jpg", 0, 0, lat * 11, lat);
							cleardevice();
							deseneazaMeniul();
							play();
						}
						else if (mx > lat *3 && mx < lat *8 && my > lat *3 && my < lat *4)
						{
							PlaySound("bruh.WAV", NULL, SND_ASYNC);
							delay(200);

							cleardevice();

							DesTabla(culoare_tabla, 1);
							initializareMatriceTabla();

							initializarePieseTabla(culoare_piese);
							setcolor(LIGHTCYAN);

							//////////////////////
							//////////////////////
							singleplayer();
							//////////////////////
							//////////////////////
						}
						else if (mx > lat *3 && mx < lat *8 && my > lat *5 && my < lat *6)
						{
							PlaySound("bruh.WAV", NULL, SND_ASYNC);
							delay(200);

							cleardevice();
							DesTabla(culoare_tabla, 1);
							initializareMatriceTabla();

							initializarePieseTabla(culoare_piese);
							setcolor(LIGHTCYAN);

							//////////////////////
							//////////////////////
							twoplayers();
							//////////////////////
							//////////////////////
						}
						else if (mx > lat *3 && mx < lat *8 && my > lat *7 && my < lat *8)
						{
							PlaySound("bruh.WAV", NULL, SND_ASYNC);
							delay(200);
							cleardevice();

							DesTabla(culoare_tabla, 1);
							initializareMatriceTabla();

							initializarePieseTabla(culoare_piese);
							setcolor(LIGHTCYAN);

							//////////////////////
							//////////////////////
							autoplay();
							//////////////////////
							//////////////////////
						}

						//else if ((mx > 0 && mx < 50) && (my > 0 && my < 50))
						// play();
						else selectieModJoc();
					}

				while (!click);
			}
			else if (x > lat *3 && x < lat *8 && y > lat *5 && y < lat *6)
            {
                cleardevice();
                readimagefile("clasic.jpg", 0, 0, lat * 11, lat * 12);
                delay(1000);
                closegraph();
                exit(0);
            }
			else if (x > lat *3 && x < lat *8 && y > lat *7 && y < lat *8)
            {
                closegraph();
                exit(0);
            }
			else
				play();
		}

	while (!click);
}

int main()
{
	openGraph();

	//readimagefile("start2.jpg", lat, lat, lat * 10, lat * 11);
	//delay(1000);
	cleardevice();
	readimagefile("solitar.jpg", 0, 0, lat * 11, lat * 2);
	deseneazaMeniul();
	play();

	getch();
	closegraph();

	return 0;
}
