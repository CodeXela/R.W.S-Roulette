#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <iomanip>


#include "Tisch.h"

using namespace std;

enum Colors { blue = 1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };// vergebe feste Nummern für Farben

enum Navigation{MAIN_MENU=0, SINGLE_PLAYER, AI_PLAYER, OPTION, EXIT};

enum Steuerung{MENUE_SETZEN=0,SETZE_ROT,SETZE_SCHWARZ, ZURUECK};

Tisch::Tisch()
{
	
	SetWindow(85,40);//setze Consolengröße fest

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);//setze Consolenhintergrund fest (TO DO)

	InitTisch(false,false,false,0.0f,0.0f,0,0.0f);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_spieler.initSpieler("Temak",100.0f,0.0f,0);// Spieler startwerte (MERKE*ersetzen mit eingabe)

	_casinoBank.initCB(1000000.0f);// Casinobank wird aufgefüllt(MERKE*ersetzen mit eingabe)

	
}

Tisch::~Tisch()
{

}
void Tisch::InitTisch(bool rundeGewonnen, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele, float setzeAufRot)
{

	_RundeGewonnen = rundeGewonnen;
	_bleibtRot = bleibtRot;
	_bleibtSchwarz = bleibtSchwarz;
	_verlorenAufRot = verlorenAufRot;
	_verlorenAufSchwarz = verlorenAufSchwarz;
	_gespielteSpiele = gespielteSpiele;
	_setzeAufRot = setzeAufRot;

}

void Tisch::Print()
{
	float xpanzahl = 1000000.0f;//XP und LVL Test
	unsigned short int kugelgefallen = 0;



	Navigation Navigon = MAIN_MENU;
	unsigned short int optionen = Navigon;

	Steuerung Setzen=MENUE_SETZEN;
	unsigned short int setzen = Setzen;

	

	while (Navigon != EXIT)
	{



		switch (optionen)
		{

		case MAIN_MENU:
			
			cout << "                              "; coutc(grey, "Roulette Simulator v0.101\n\n\n\n\n");
			printf("                                 (1)Single Player\n                                 (2)AI Player\n                                 (3)Option\n                                 (4)Exit\n");
			cin >> optionen;
			if (cin.fail())
			{
				printf("Deine eingabe ist Falsch");
				cin.clear();
				cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
				optionen = EXIT;
			}		
			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
			break;


		case SINGLE_PLAYER:
			//_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test

			//printf("%d",_dealer.RolltKugel());//Dealer Sound und Zahlausgabe (Test)
			system("CLS");
			printf("-------------------------------------------------------------------------------------------\n");
			cout <<"  Spieler Name:       " << _spieler.holeSpielerName()<<"  LVL: "<<_spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
			printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
			printf("  Spieler XP:           %0.1f Punkte.                                                                                   \n", _spieler.holeSpielerXP());
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                (1)Rot oder (2)Schwarz oder (3)Zurueck \n");
			printf("-------------------------------------------------------------------------------------------\n");
			
			
			cin >> setzen;

			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

			switch (setzen)
			{

			case SETZE_ROT:
				system("CLS");
				printf("-------------------------------------------------------------------------------------------\n");
				cout <<"  Spieler Name:       " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
				printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
				printf("  Spieler XP:           %0.1f Punkte.                                                                                   \n", _spieler.holeSpielerXP());
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                Wie viel moechtest Du setzen?\n");
				printf("-------------------------------------------------------------------------------------------\n");
				cin >> _setzeAufRot;
				cin.clear();
				cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
				if (_setzeAufRot<=_spieler.holeSpielerKonto())
				{
					if (_setzeAufRot < _Mindesteinsatz)
					{
						system("CLS");
						cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufRot << " versucht zu setzen " << endl;
						printf("Weiter mit belibigen taste . . .");
						getchar();
						break;

					}

					_spieler.entferneSpielerKonto(_setzeAufRot);//TO DO 20.10.2015->

					system("CLS");
					kugelgefallen = _dealer.RolltKugel();
					cout << kugelgefallen << endl;
					getchar();//->
					break;
				}
				printf("Du hast zu wenig Geld");
				getchar();
				break;
										 

			case SETZE_SCHWARZ:

				break;
			case ZURUECK:

				Speichern();
				optionen = MAIN_MENU;

				break;
				
			}
		
			
			system("CLS");
			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
			break;

		case AI_PLAYER:

			break;
		case OPTION:

			break;
		case EXIT:

			
			system("CLS");
			Speichern();
			getchar();
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
	printf("erfolgreich gespeichert. . . .\n"); printf("auf wiedersehen");
	getchar();
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


