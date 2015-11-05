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

enum Steuerung{MENUE_SETZEN=0,SETZE_ROT,SETZE_SCHWARZ,SETZE_ZAHL, ZURUECK};

Navigation Navigon = MAIN_MENU;

unsigned short int optionen = Navigon;

Steuerung Setzen = MENUE_SETZEN;

unsigned short int setzen = Setzen;

Tisch::Tisch()
{
	
	SetWindow(95,40);//setze Consolengröße fest

	InitTisch(false,false,false,false,0.0f,0.0f,0,0.0f,0.0f,0.0f,0.0f,0.0f);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_spieler.initSpieler("NONAME",100.0f,0.0f,0,0.0f);// Spieler startwerte (MERKE*ersetzen mit eingabe)

	_casinoBank.initCB(1000000.0f);// Casinobank wird aufgefüllt(MERKE*ersetzen mit eingabe)
	
	
}
void Tisch::spieleSpiel()
{

	Print();
}

Tisch::~Tisch()
{
	

}
void Tisch::InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, float verlorenAufZahl, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz,float setzeAufZahl, float lvlCap)
{

	_RundeGewonnen = rundeGewonnen;
	_Richtig = richtig;

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

	
	system("COLOR F0");
	while (Navigon != EXIT)
	{
		
		switch (optionen)
		{

		case MAIN_MENU:
		
			MenueAbfrageprint();

			break;


		case SINGLE_PLAYER:
			
			singelPlayerprint();
			
			switch (setzen)
			{

			case SETZE_ROT:

				setzeAufRotprint();
				
				break;

			case SETZE_SCHWARZ:

				setzeAufSchwarzprint();

				break;

			case SETZE_ZAHL:

				setzeAufZahlprint();

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
	delete []name;

	printf("erfolgreich geloescht");

	getchar();
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
		else if (_spieler.holeSpielerLVL() >= 6 && _spieler.holeSpielerLVL() <= 10)
		{
			_lvlCap = (halteFest / 2000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 11 && _spieler.holeSpielerLVL() <= 15)
		{
			_lvlCap = (halteFest / 3000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 16 && _spieler.holeSpielerLVL() <= 20)
		{
			_lvlCap = (halteFest / 4000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 21 && _spieler.holeSpielerLVL() <= 25)
		{
			_lvlCap = (halteFest / 5000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 26 && _spieler.holeSpielerLVL() <= 30)
		{
			_lvlCap = (halteFest / 6000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 31 && _spieler.holeSpielerLVL() <= 35)
		{
			_lvlCap = (halteFest / 7000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 36 && _spieler.holeSpielerLVL() <= 40)
		{
			_lvlCap = (halteFest / 8000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 41 && _spieler.holeSpielerLVL() <= 45)
		{
			_lvlCap = (halteFest / 9000) * 100;
		}
		else if (_spieler.holeSpielerLVL() >= 46 && _spieler.holeSpielerLVL() <= 50)
		{
			_lvlCap = (halteFest / 10000) * 100;
		}
		
	}

}
void Tisch::berechnungXpbeute()
{
	if (_RundeGewonnen == false) {

		Multiplikator = ((halteEinsatz* 10) /halteKonto);

		xpanzahl = Multiplikator*halteEinsatz;

		//----------------------------------------------------------------------------------Menue
		printf("%s|\n\n%s|XPErhalten: %0.1f \n\n%s|XPMulti: %0.2f%% \n\n%s|BonusMulti: %0.1f%% \n\n", string(24, '*').c_str(), string(24, '*').c_str(), xpanzahl, string(24, '*').c_str(), Multiplikator, string(24, '*').c_str(), xpBonus);
		printf("%s|Gespielte runden: %d \n\n", string(24, '*').c_str(), _gespielteSpiele);
		printf("%s|RED: %d Black: %d Zero: %d\n\n", string(24, '*').c_str(), _zahlRot, _zahlSchwarz, _zahlZero);
		//----------------------------------------------------------------------------------Menue

		getchar();
	}
	else if(_RundeGewonnen == true) {

		Multiplikator = ((halteEinsatz * 10) /halteKonto);

		xpBonus = Multiplikator*0.2f;

		xpanzahl = (Multiplikator + xpBonus) * halteEinsatz;

		//----------------------------------------------------------------------------------Menue
		printf("%s|\n\n%s|XPErhalten: %0.1f \n\n%s|XPMulti: %0.2f%% \n\n%s|BonusMulti: %0.1f%% \n\n", string(24, '*').c_str(),string(24, '*').c_str(),xpanzahl, string(24, '*').c_str(), Multiplikator, string(24, '*').c_str(),xpBonus);
		printf("%s|Gespielte runden: %d \n\n", string(24, '*').c_str(),_gespielteSpiele);
		printf("%s|RED: %d Black: %d Zero: %d \n\n", string(24, '*').c_str(),_zahlRot,_zahlSchwarz,_zahlZero);
		//----------------------------------------------------------------------------------Menue

		getchar();
	}
}

void Tisch::MenueAbfrageprint()
{
	while (_Richtig != true)// TO DO 05.11<---------------------------------------<<<<
	{
		printf("\n\n\n\n\n             Bitte Spieler Name eingeben:");
		cin >> name;

		if (cin.fail())
		{
			printf("Deine eingabe ist zu lang");

			cin.clear();
			cin.ignore(CHAR_MAX, '\n');//fix für doppelte ausgabe bug

			getchar();

			_Richtig = false;

			system("CLS");

		}

		_Richtig = true;

	}// TO DO 05.11<---------------------------------------<<<<

	_spieler.setzeSpielerName(name);

	//----------------------------------------------------------------------------------Menue
	printf("%s\n", string(95, '#').c_str());
	cout << "                                 "; printf("RWS v0.103\n\n\n\n\n");
	printf("                                 (1)Single Player\n                                 (2)AI Player\n                                 (3)Option\n                                 (4)Exit\n");
	//----------------------------------------------------------------------------------Menue

	cin >> optionen;
	if (cin.fail() || optionen>4 || optionen<0)
	{
		printf("Deine eingabe ist Falsch");

		cin.clear();
		cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

		getchar();

		system("CLS");

		optionen = SINGLE_PLAYER;
		return;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

	system("CLS");

}
void Tisch::singelPlayerprint()
{
	if (_spieler.holeSpielerKonto() >= _Mindesteinsatz)
	{

		
		//----------------------------------------------------------------------------------Menue
		printf("%s\n", string(95, '#').c_str());
		cout << "  Spieler Name:  " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
		printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
		printf("  XP Fortschrit:   %0.1f    %0.2f%%                                                                      \n", _spieler.holeSpielerXP(), _lvlCap);
		printf("%s\n", string(95, '#').c_str());
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                (1)Rot oder (2)Schwarz (3)Zahl (4)Zurueck \n");
		printf("%s\n", string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue

		cin >> setzen;

		if (cin.fail() || optionen > 4 || optionen < 0)
		{
			printf("Deine eingabe ist Falsch");

			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

			getchar();

			system("CLS");

			optionen = SINGLE_PLAYER;
			return;
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
	}
	else {

		printf("Du hast zu wenig Geld");

		getchar();

		optionen = MAIN_MENU;
		return;
	}
}
void Tisch::setzeAufRotprint()
{
	if (_spieler.holeSpielerKonto() >= _Mindesteinsatz)
	{
		system("CLS");
		//----------------------------------------------------------------------------------Menue
		printf("%s\n", string(95, '#').c_str());
		cout << "  Spieler Name:       " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
		printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
		printf("  XP Fortschrit:   %0.1f   %0.2f%%                                                                 \n", _spieler.holeSpielerXP(), _lvlCap);
		printf("%s\n", string(95, '#').c_str());
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                Wie viel moechtest Du setzen?\n");
		printf("%s\n", string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue

		halteKonto = _spieler.holeSpielerKonto();

		cin >> _setzeAufRot;

		if (cin.fail() || _setzeAufRot<=0)
		{
			printf("Deine eingabe ist Falsch");

			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

			getchar();

			system("CLS");

			optionen = SINGLE_PLAYER;
			return;
		}

		halteEinsatz = _setzeAufRot;

		_gespielteSpiele++;

		_auswahlWahl = "ROT";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		//----------------------------------------------------------------------------------
		if (_setzeAufRot <= _spieler.holeSpielerKonto())
		{
			if (_setzeAufRot < _Mindesteinsatz)
			{
				system("CLS");

				//----------------------------------------------------------------------------------Menue
				cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufRot << " versucht zu setzen " << endl;
				printf("Weiter mit belibigen taste . . .");
				//----------------------------------------------------------------------------------Menue

				getchar();
				

			}

			_spieler.entferneSpielerKonto(_setzeAufRot);//TO DO 24.10.2015->

			system("CLS");

			kugelgefallen = _dealer.RolltKugel();

			if (kugelgefallen == 0)
			{

				_zahlZero++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt auf`s Zero feld\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

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

					_zahlRot++;

					//----------------------------------------------------------------------------------Menue
					printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
					//----------------------------------------------------------------------------------Menue

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

					_zahlSchwarz++;

					//----------------------------------------------------------------------------------Menue
					printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
					//----------------------------------------------------------------------------------Menue

					_casinoBank.setzeBankKonto(_setzeAufRot);

					_RundeGewonnen = false;

					berechnungXpbeute();

					_spieler.setzeSpielerXP(xpanzahl);

					prüfeLVLCap(_spieler.holeSpielerXP());

					_setzeAufRot = NULL;

				}

			}



		}
		else {
			printf("Du hast zu wenig Geld");

			getchar();

			optionen = MAIN_MENU;
			return;
		}
	}
}
void Tisch::setzeAufSchwarzprint()
{
	if (_spieler.holeSpielerKonto() >= _Mindesteinsatz)
	{
	system("CLS");

	//----------------------------------------------------------------------------------Menue
	printf("%s\n", string(95, '#').c_str());
	cout << "  Spieler Name:       " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
	printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
	printf("  XP Fortschrit:  %0.1f    %0.2f%%                                                                        \n", _spieler.holeSpielerXP(), _lvlCap);
	printf("%s\n", string(95, '#').c_str());
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("                           Wie viel moechtest Du setzen?\n");
	printf("%s\n", string(95, '#').c_str());
	//----------------------------------------------------------------------------------Menue

	halteKonto = _spieler.holeSpielerKonto();

	cin >> _setzeAufSchwarz;

	if (cin.fail() || _setzeAufSchwarz <= 0)
	{
		printf("Deine eingabe ist Falsch");

		cin.clear();
		cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

		getchar();

		system("CLS");

		optionen = SINGLE_PLAYER;
		return;
	}

	halteEinsatz = _setzeAufSchwarz;

	_auswahlWahl = "SCHWARZ";

	_gespielteSpiele++;

	cin.clear();
	cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

	if (_setzeAufSchwarz <= _spieler.holeSpielerKonto())
	{
		if (_setzeAufSchwarz < _Mindesteinsatz)
		{
			system("CLS");
			//----------------------------------------------------------------------------------Menue
			cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufRot << " versucht zu setzen " << endl;
			printf("Weiter mit belibigen taste . . .");
			//----------------------------------------------------------------------------------Menue

			getchar();

			Setzen = SETZE_SCHWARZ;
			return;

		}

		system("CLS"); //Screen bereinigen

		_spieler.entferneSpielerKonto(_setzeAufSchwarz);

		kugelgefallen = _dealer.RolltKugel();//Werfe die Kugel

		if (kugelgefallen == 0)
		{

			_zahlZero++;

			//----------------------------------------------------------------------------------Menue
			printf("%s\n%s|Die Kugel rollt auf`s Zero feld\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), string(24, ' ').c_str(), string(95, '#').c_str());
			//----------------------------------------------------------------------------------Menue

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

				_zahlSchwarz++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

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

				_zahlRot++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

				_casinoBank.setzeBankKonto(_setzeAufSchwarz);

				_RundeGewonnen = false;

				berechnungXpbeute();

				_spieler.setzeSpielerXP(xpanzahl);

				prüfeLVLCap(_spieler.holeSpielerXP());

				_setzeAufSchwarz = NULL;

			}

		}

	}else {

		printf("Du hast zu wenig Geld");

		getchar();

		optionen = SINGLE_PLAYER;
		return;
		}
	}
}
void Tisch::setzeAufZahlprint()
{
	if (_spieler.holeSpielerKonto() >= _Mindesteinsatz)
	{
		system("CLS");
		//----------------------------------------------------------------------------------Menue
		printf("%s\n", string(95, '#').c_str());
		cout << "  Spieler Name:       " << _spieler.holeSpielerName() << "  LVL: " << _spieler.holeSpielerLVL(); printf("                   Casino Bank:  %0.1f  Euro   \n", _casinoBank.holeBank());
		printf("  Spieler Konto:      %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
		printf("  XP Fortschrit:   %0.1f   %0.2f%%                                                                 \n", _spieler.holeSpielerXP(), _lvlCap);
		printf("%s\n", string(95, '#').c_str());
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                Wie viel moechtest Du setzen?\n");
		printf("%s\n", string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue

		halteKonto = _spieler.holeSpielerKonto();

		cin >> _setzeAufZahl;

		if (cin.fail() || _setzeAufZahl <= 0)
		{
			printf("Deine eingabe ist Falsch");

			cin.clear();
			cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug

			getchar();

			system("CLS");

			optionen = SINGLE_PLAYER;
			return;
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		halteEinsatz = _setzeAufZahl;

		_gespielteSpiele++;

		_auswahlWahl = "ZAHL";

		//----------------------------------------------------------------------------------Menue
		printf("                           Deine Zahl auf die Du Wetten moechtest?\n");
		//----------------------------------------------------------------------------------Menue

		cin >> _ZahlAuswahl;

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (_setzeAufZahl <= _spieler.holeSpielerKonto())
		{
			if (_setzeAufZahl < _Mindesteinsatz)
			{
				system("CLS");

				//----------------------------------------------------------------------------------Menue
				cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufZahl << " versucht zu setzen " << endl;
				printf("Weiter mit belibigen taste . . .");
				//----------------------------------------------------------------------------------Menue

				getchar();


			}

			_spieler.entferneSpielerKonto(_setzeAufZahl);//TO DO 24.10.2015->

			system("CLS");

			kugelgefallen = _dealer.RolltKugel();


			//----------------------------------------------------------------------------------------------------------------------------------------



			if (kugelgefallen == _ZahlAuswahl)
			{


				printf("%s\n%s|Die Kugel rollt aufs Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				
				_casinoBank.entferneBankKonto(_setzeAufZahl);
				
				_setzeAufZahl = _setzeAufZahl * 36;
				
				_spieler.setzeSpielerKonto(_setzeAufZahl);
				
				_RundeGewonnen = true;
				
				berechnungXpbeute();
				
				_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test
				
				prüfeLVLCap(_spieler.holeSpielerXP());
				
				_setzeAufZahl = NULL;


			}
			else {


				printf("%s\n%s|Die Kugel rollt aufs Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				
				_casinoBank.setzeBankKonto(_setzeAufZahl);
				
				_RundeGewonnen = false;
				
				berechnungXpbeute();
				
				_spieler.setzeSpielerXP(xpanzahl);
				
				prüfeLVLCap(_spieler.holeSpielerXP());

				_setzeAufZahl = NULL;

			}

		}
		
	}
	else {

		printf("Du hast zu wenig Geld");

		getchar();

		optionen = SINGLE_PLAYER;
		return;
	}
}
void Tisch::pruefeCinEingabe()
{


}

