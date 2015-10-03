#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <iomanip>


#include "Tisch.h"

using namespace std;

enum Colors { blue = 1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };// vergebe feste Nummern für Farben

enum Navigation{MAIN_MENU=1, SINGLE_PLAYER, AI_PLAYER, OPTION, EXIT};

enum Steuerung{MENUE_SETZEN=1,SETZE_ROT,SETZE_SCHWARZ};

Tisch::Tisch()
{
	
	SetWindow(85,40);//setze Consolengröße fest

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);//setze Consolenhintergrund fest (TO DO)

	InitTisch(false,false,false,0.0f,0.0f,0);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_spieler.initSpieler("Temak",100.0f,0.0f,0);// Spieler startwerte (MERKE*ersetzen mit eingabe)

	_casinoBank.initCB(1000000.0f);// Casinobank wird aufgefüllt(MERKE*ersetzen mit eingabe)

	
}

Tisch::~Tisch()
{

}
void Tisch::InitTisch(bool rundeGewonnen, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele)
{

	_RundeGewonnen = rundeGewonnen;
	_bleibtRot = bleibtRot;
	_bleibtSchwarz = bleibtSchwarz;
	_verlorenAufRot = verlorenAufRot;
	_verlorenAufSchwarz = verlorenAufSchwarz;
	_gespielteSpiele = gespielteSpiele;

}

void Tisch::Print()
{
	float xpanzahl = 1000;//XP und LVL Test
	Navigation Navigon = MAIN_MENU;
	unsigned short int optionen = Navigon;

	Steuerung Setzen = MENUE_SETZEN;


	while (Navigon != EXIT)
	{



		switch (optionen)
		{

		case MAIN_MENU:
			

			cout << "                              "; coutc(grey, "Roulette Simulator v0.101\n\n\n\n\n");


			printf("                                 (2)Single Player\n                                 (3)AI Player\n                                 (4)Option\n                                 (5)Exit\n");
			cin >> optionen;


			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

			_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test

			system("CLS");
			
			break;


		case SINGLE_PLAYER:

			system("CLS");
			printf("-------------------------------------------------------------------------------------------\n");
			cout << "  Spieler Name:       " << _spieler.holeSpielerName()<<"  LVL: "<<_spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
			printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
			printf("  Spieler XP:           %0.1f Punkte.                                                                                   \n", _spieler.holeSpielerXP());

			//printf("%d",_dealer.RolltKugel());//Dealer Sound und Zahlausgabe (Test)

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("-------------------------------------------------------------------------------------------\n");
			printf("(S)etzen oder (V)verlassen");
			
			cin >> optionen;

			
			system("CLS");
			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
			break;

		case AI_PLAYER:

			break;
		case OPTION:

			break;
		case EXIT:

			
			
			printf("Auf wiedersehen");
			Speichern();
			Navigon=EXIT;
			break;
		default:
			//cout << "                              "; coutc(grey, "Roulette Simulator v0.1\n\n\n\n\n");

			//printf("Bitte Waehle zwischen: \n");
			//printf("(1)Single Player  (2)AI Player  (3)Option  (4)Exit\n");
			//cin >> optionen;
			break;

		}
	} 
}

void Tisch::SetWindow(int Width, int Height) // Aufbau der Consolengröße
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Setze Buffer Größe
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Setze Fenster Größe
	
	
}
void Tisch::coutc(int color, char* output)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
	cout << output;
	SetConsoleTextAttribute(handle, color);
}
void Tisch::Speichern()
{
	ofstream FILE;

	FILE.open("saveSpieler.txt");
	if (FILE.fail())
	{
		perror("saveSpieler.txt");

		
	}
	if (FILE.is_open())
	{

		FILE << std::fixed  << _spieler.holeSpielerName() << endl;
		FILE << std::fixed << std::setprecision(1) << _spieler.holeSpielerKonto() << endl;
		FILE << std::fixed << std::setprecision(1) << _spieler.holeSpielerXP() << endl;
		FILE << std::fixed << std::setprecision(1) << _casinoBank.holeBank() << endl;

	}FILE.close();


}
//void Laden(Spieler Sp, CasinoBank CB) //Zu Erledigen
//{
//	ifstream LadeFile;
//	string Namespieler;
//	double SpielerGeld;
//	int SpielerSpiele;
//
//
//	LadeFile.open("saveSpieler.txt");
//	if (LadeFile.fail)
//	{
//		perror("saveSpieler.txt");
//
//	}
//
//	if (LadeFile.is_open())
//	{
//
//		while (LadeFile>>Namespieler>>SpielerGeld>>SpielerSpiele)
//		{
//
//
//
//		}
//
//	}LadeFile.close();
//
//
//
//}


