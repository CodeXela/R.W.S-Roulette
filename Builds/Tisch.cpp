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

enum Navigation{MAIN_MENU=0, SINGLE_PLAYER, AI_PLAYER, OPTION, EXIT};

enum Steuerung{MENUE_SETZEN=0,SETZE_ROT,SETZE_SCHWARZ, ZURUECK};



Tisch::Tisch()
{
	
	SetWindow(95,40);//setze Consolengröße fest

	InitTisch(false,false,false,false,0.0f,0.0f,0,0.0f,0.0f,0.0f);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_spieler.initSpieler("Temak",100.0f,0.0f,0);// Spieler startwerte (MERKE*ersetzen mit eingabe)

	_casinoBank.initCB(1000000.0f);// Casinobank wird aufgefüllt(MERKE*ersetzen mit eingabe)
	
	
}
void Tisch::spieleSpiel()
{

	Print();
}

Tisch::~Tisch()
{
	

}
void Tisch::InitTisch(bool rundeGewonnen, bool rundeVerloren, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz, float lvlCap)
{

	_RundeGewonnen = rundeGewonnen;
	_RundeVerloren = rundeVerloren;

	_bleibtRot = bleibtRot;
	_bleibtSchwarz = bleibtSchwarz;

	_verlorenAufRot = verlorenAufRot;
	_verlorenAufSchwarz = verlorenAufSchwarz;

	
	_setzeAufRot = setzeAufRot;
	_setzeAufSchwarz = setzeAufSchwarz;

	_gespielteSpiele = gespielteSpiele;

	_lvlCap = lvlCap;

}

void Tisch::Print()
{
	
	unsigned short int kugelgefallen = 0;

	int *rot = new int[18] { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	int *schwarz = new int[18] { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };

	Navigation Navigon = MAIN_MENU;
	unsigned short int optionen = Navigon;

	Steuerung Setzen=MENUE_SETZEN;
	unsigned short int setzen = Setzen;

	
	system("COLOR F0");
	while (Navigon != EXIT)
	{
		
		switch (optionen)
		{

		case MAIN_MENU:
			printf("%s\n",string(95,'#').c_str());
			cout << "                                 "; printf("RWS v0.102\n\n\n\n\n");
			printf("                                 (1)Single Player\n                                 (2)AI Player\n                                 (3)Option\n                                 (4)Exit\n");
			cin >> optionen;
			if (cin.fail()||optionen>4||optionen<0)
			{
				printf("Deine eingabe ist Falsch");
				cin.clear();
				cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
				getchar();
				system("CLS");
				optionen = MAIN_MENU;
			}		
			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
			system("CLS");
			break;


		case SINGLE_PLAYER: //TO DO Darstellung auf funktion reduzieren

			

			//printf("%d",_dealer.RolltKugel());//Dealer Sound und Zahlausgabe (Test)
			
			printf("%s\n", string(95, '#').c_str());
			cout <<"  Spieler Name:       " << _spieler.holeSpielerName()<<"  LVL: "<<_spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
			printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
			printf("  XP Fortschrit:   %0.1f    %0.2f Prozent                                                                      \n",_spieler.holeSpielerXP() , _lvlCap);
			printf("%s\n", string(95, '#').c_str());
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("                                (1)Rot oder (2)Schwarz oder (3)Zurueck \n");
			printf("%s\n", string(95, '#').c_str());
			
			
			cin >> setzen;
			if (cin.fail() || optionen>3 || optionen<0)
			{
				printf("Deine eingabe ist Falsch");
				cin.clear();
				cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
				getchar();
				system("CLS");
				optionen = SINGLE_PLAYER;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

			switch (setzen)
			{

			case SETZE_ROT: //TO DO Darstellung auf funktion reduzieren
				system("CLS");
				printf("%s\n", string(95, '#').c_str());
				cout << "  Spieler Name:       " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
				printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
				printf("  XP Fortschrit:   %0.1f   %0.2f Prozent                                                                 \n", _spieler.holeSpielerXP(), _lvlCap);
				printf("%s\n", string(95, '#').c_str());
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				printf("                                Wie viel moechtest Du setzen?\n");
				printf("%s\n", string(95, '#').c_str());
				halteKonto = _spieler.holeSpielerKonto();
				cin >> _setzeAufRot;
				halteEinsatz = _setzeAufRot;
				cin.clear();
				cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

				if (_setzeAufRot <= _spieler.holeSpielerKonto())
				{
					if (_setzeAufRot < _Mindesteinsatz)
					{
						system("CLS");
						cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufRot << " versucht zu setzen " << endl;
						printf("Weiter mit belibigen taste . . .");
						getchar();
						break;

					}

					_spieler.entferneSpielerKonto(_setzeAufRot);//TO DO 24.10.2015->

					system("CLS");
					kugelgefallen = _dealer.RolltKugel();
					if (kugelgefallen == 0)
					{
						printf("###############################################################################################\n[------------------------|Die Kugel rollt auf`s Zero feld \n[-----------------------|Du hast diese Runde verloren !\n###############################################################################################", kugelgefallen);
						_casinoBank.setzeBankKonto(_setzeAufRot);
						_RundeGewonnen = false;
						berechnungXpbeute();
						_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test
						prüfeLVLCap(_spieler.holeSpielerXP());
						_setzeAufRot = NULL;
					}
					for (int i = 0; i < 18; i++)
					{
						if (kugelgefallen == rot[i])
						{
							printf("###############################################################################################\n[-----------------------|Die Kugel rollt aufs rote Feld mit der NR: %d\n[-----------------------|Du hast diese Runde Gewonnen !\n###############################################################################################", kugelgefallen);
							_casinoBank.entferneBankKonto(_setzeAufRot);
							_setzeAufRot = _setzeAufRot * 2;
							_spieler.setzeSpielerKonto(_setzeAufRot);
							_RundeGewonnen = true;
							berechnungXpbeute();
							_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test
							prüfeLVLCap(_spieler.holeSpielerXP());
							_setzeAufRot = NULL;

						}
						else if (kugelgefallen == schwarz[i])
						{
							printf("###############################################################################################\n[-----------------------|Die Kugel rollt aufs schwarze Feld mit der Nr: %d\n[-----------------------|Du hast diese Runde verloren !\n###############################################################################################", kugelgefallen);
							_casinoBank.setzeBankKonto(_setzeAufRot);
							_RundeGewonnen = false;
							berechnungXpbeute();
							_spieler.setzeSpielerXP(xpanzahl);
							prüfeLVLCap(_spieler.holeSpielerXP());

							_setzeAufRot = NULL;
						}

					}

					
					break;
				}
				printf("Du hast zu wenig Geld");
				_gespielteSpiele++;
				getchar();
				break;


			case SETZE_SCHWARZ: //TO DO Darstellung auf funktion reduzieren
				system("CLS");
				printf("%s\n", string(95, '#').c_str());
				cout << "  Spieler Name:       " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
				printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
				printf("  XP Fortschrit:  %0.1f    %0.2f Prozent                                                                        \n", _spieler.holeSpielerXP(), _lvlCap);
				printf("%s\n", string(95, '#').c_str());
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				printf("                           Wie viel moechtest Du setzen?\n");
				printf("%s\n", string(95, '#').c_str());
				halteKonto = _spieler.holeSpielerKonto();
				cin >> _setzeAufSchwarz;
				halteEinsatz = _setzeAufSchwarz;
				cin.clear();
				cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
				if (_setzeAufSchwarz <= _spieler.holeSpielerKonto())
				{
					if (_setzeAufSchwarz < _Mindesteinsatz)
					{
						system("CLS");
						cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufRot << " versucht zu setzen " << endl;
						printf("Weiter mit belibigen taste . . .");
						getchar();
						break;

					}
					system("CLS"); //Screen bereinigen
					_spieler.entferneSpielerKonto(_setzeAufSchwarz);//TO DO 24.10.2015->
					kugelgefallen = _dealer.RolltKugel();

					if (kugelgefallen == 0)
					{
						printf("Die Kugel rollt auf`s Zero feld: %d Du hast diese Runde verloren \n", kugelgefallen);
						_casinoBank.setzeBankKonto(_setzeAufSchwarz);
						_RundeGewonnen = false;
						berechnungXpbeute();
						_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test
						prüfeLVLCap(_spieler.holeSpielerXP());
						_setzeAufSchwarz = NULL;
					}
					for (int i = 0; i < 18; i++)
					{
						if (kugelgefallen == schwarz[i])
						{
							printf("Die Kugel rollt aufs Schwarze Feld mit der NR: %d \n Gewonnen !", kugelgefallen);
							_casinoBank.entferneBankKonto(_setzeAufSchwarz);
							_setzeAufSchwarz = _setzeAufSchwarz * 2;
							_spieler.setzeSpielerKonto(_setzeAufSchwarz);
							_RundeGewonnen = true;
							berechnungXpbeute();
							_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test
							prüfeLVLCap(_spieler.holeSpielerXP());
							_setzeAufSchwarz = NULL;

						}
						else if (kugelgefallen == rot[i])
						{
							printf("Die Kugel rollt aufs Rote Feld mit der Nr: %d \n Du hast diese Runde verloren", kugelgefallen);
							_casinoBank.setzeBankKonto(_setzeAufSchwarz);
							_RundeGewonnen = false;
							berechnungXpbeute();
							_spieler.setzeSpielerXP(xpanzahl);
							prüfeLVLCap(_spieler.holeSpielerXP());
							_setzeAufSchwarz = NULL;
						}

					}

					_gespielteSpiele++;

					break;
				}

				printf("Du hast zu wenig Geld");
				getchar();
				break;


			case ZURUECK:

				Speichern();
				optionen = MAIN_MENU;

				break;
			}
			
			system("CLS");
			cin.clear();
			//cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
			break;

		case AI_PLAYER:

			break;
		case OPTION:

			break;
		case EXIT:

			
			system("CLS");
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
	delete []rot;
	delete []schwarz;
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
void Tisch::prüfeLVLCap(float lvlCapP)
{
	

	halteFest = lvlCapP;

	if (lvlCapP > 0)
	{
		if (_spieler.holeSpielerLVL() >= 0 && _spieler.holeSpielerLVL() <= 5)
		{
			
			_lvlCap = (halteFest/1000)*100;
	
		}
		
	}

}
void Tisch::berechnungXpbeute()
{
	if (_RundeGewonnen == false) {
		Multiplikator = ((halteEinsatz* 10) /halteKonto);
		xpanzahl = Multiplikator*halteEinsatz;
		printf("\n[-----------------------|---|---|---|---|---|---|---\n[-----------------------|XP Multi: %0.2f \n[-----------------------|XP erhalten: %0.1f \n",Multiplikator, xpanzahl);
		getchar();
	}
	else if(_RundeGewonnen == true) {
		Multiplikator = ((halteEinsatz * 10) /halteKonto);
		xpBonus = Multiplikator*0.2f;
		xpanzahl = (Multiplikator + xpBonus) * halteEinsatz;
		printf("\n[-----------------------|---|---|---|---|---|---|---\n[-----------------------|XPMulti: %0.2f \n[-----------------------|XP erhalten: %0.1f \n[-----------------------|BonusMulti: %0.1f \n",Multiplikator,xpanzahl,xpBonus);
		getchar();
	}
}

