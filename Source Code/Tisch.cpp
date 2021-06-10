#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <conio.h>


#include "Tisch.h"

using namespace std;

enum  Navigation{MAIN_MENU=0, SINGLE_PLAYER, AI_PLAYER, OPTION, EXIT}; // erstelle menue 1

enum  Steuerung{MENUE_SETZEN=0,SETZE_ROT,SETZE_SCHWARZ,SETZE_ZAHL, ZURUECK}; // erstelle menue 2

enum WinLose { ZERO = 0, WINRED, LOSERED, WINBLACK, LOSEBLACK }; //Win Lose Menu für Print

Navigation Navigon = MAIN_MENU; //Mache Objekt Navigation und setze menue auf case 0

unsigned short int optionen = Navigon; //erstelle eingabe var und setze das objekt navigon damit gleich

Steuerung Setzen = MENUE_SETZEN;//Mache Objekt Setzen und setze menue auf 0

unsigned short int setzen = Setzen; //erstelle eingabe var und setze das objekt Setzen damit gleich

Tisch::Tisch()//Konstruktor der alle beim start mit daten befüllt
{
	
	SetWindow(95,40);//setze Consolengröße fest

	InitTisch(false,false,false,false,0.0f,0.0f,0.0f,0.0f,0.0f,0,0.0f,0.0f,0.0f,0.0f);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_spieler.initSpieler("NONAME",1000.0f,0.0f,0,0.0f);// Spieler startwerte (MERKE*ersetzen mit eingabe)

	_casinoBank.initCB(1000.0f);// Casinobank wird aufgefüllt(MERKE*ersetzen mit eingabe)
	
	_aiPlayer.initAIPlayer(0.0f, 0.0f, 0, 0.0f);// Aispieler wird aufgefüllt(MERKE*ersetzen mit eingabe)

	
}
void Tisch::spieleSpiel() //wird in der mainfunktion gerufen und startet das spiel
{

	Print();//Gibt das Menue usw. aus
}

Tisch::~Tisch()//Dekonstruktor
{
	

}
void Tisch::InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, float gewonnenAufRot, float gewonnenAufSchwarz, float verlorenAufRot, float verlorenAufSchwarz, float verlorenAufZahl, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz,float setzeAufZahl, float lvlCap)
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

			AIMenuePrint();

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

	printf("Speicher erfolgreich bereinigt");

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

	FILE.open("saveSpieler.csv");

	if (FILE.fail())
	{
		perror("saveSpieler.csv");

		
	}
	if (FILE.is_open())
	{

		/*FILE << std::fixed  << _spieler.holeSpielerName() << endl;
		FILE << std::fixed << std::setprecision(1) << _spieler.holeSpielerKonto() << endl;
		FILE << std::fixed << std::setprecision(1) << _spieler.holeSpielerXP() << endl;
		FILE << std::fixed << std::setprecision(1) << _casinoBank.holeBank() << endl;*/

		FILE << "\nRunde , StartKonto , EndKonto , Einsatz , Farbe , CasinoKonto, Gewonnen , Kugel , Gewinn/Verlust" << endl;

		for (string n : _vectorDaten)
		{
			FILE << n;
		}

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
void Tisch::legeDatenAb(string runde,string skonto,string konto, string eisatz, string farbe, string casinobank, string gewonnen,string kugel,string gewonnenauf)
{
	
	_vectorDaten.push_back( runde + "," + skonto + "," + konto + "," + eisatz + "," + farbe + "," + casinobank + "," + gewonnen + "," + kugel + "," + gewonnenauf+"\n");
	
}
void Tisch::berechnungXpbeute()
{
	if (_RundeGewonnen == false) {

		Multiplikator = ((halteEinsatz* 10) /halteKonto);

		xpanzahl = Multiplikator*halteEinsatz;

		//printXpBerechnungVerlust();

		legeDatenAb(to_string(_gespielteSpiele), to_string(int (halteKonto)), to_string(int(_aiPlayer.holeAIPlayerKonto())),to_string(int(_Mindesteinsatz)),_auswahlWahl,to_string(int(_casinoBank.holeBank())), to_string( _RundeGewonnen), to_string(kugelgefallen), to_string(int(_auswahlWahl == "ROT" ? _verlorenAufRot : _verlorenAufSchwarz)));
	}
	else if(_RundeGewonnen == true) {

		Multiplikator = ((halteEinsatz * 10) /halteKonto);

		xpBonus = Multiplikator*0.2f;

		xpanzahl = (Multiplikator + xpBonus) * halteEinsatz;

		//printXpBerechnungGewinn();
		
		legeDatenAb(to_string(_gespielteSpiele), to_string(int (halteKonto)), to_string(int(_aiPlayer.holeAIPlayerKonto())), to_string(int(_Mindesteinsatz)), _auswahlWahl, to_string(int(_casinoBank.holeBank())), to_string(_RundeGewonnen),to_string(kugelgefallen),to_string(int(_auswahlWahl == "ROT" ? _gewonnenAufRot : _gewonnenAufSchwarz)));
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
	system("CLS");
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
		printf("  Spieler Konto:     %0.1f Euro.", _spieler.holeSpielerKonto()); printf("                  Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
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

					_setzeAufRot = (_setzeAufRot * 2);

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

			getchar();

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

		getchar();

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
				
				_setzeAufZahl = (_setzeAufZahl * 36);
				
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
		
		getchar();
	}
	else {

		printf("Du hast zu wenig Geld");

		getchar();

		optionen = SINGLE_PLAYER;
		return;
	}
}
void Tisch::AIMenuePrint()
{
	float puffer = 0.0f;

	system("CLS");

	cleanupAIPlayer();

	printAiMainMenu();

	_setzeAufRot = _Mindesteinsatz;
	_setzeAufSchwarz = _Mindesteinsatz;

	cin.clear();
	cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
	//cin.ignore(CHAR_MAX, '\n');

	switch (_farbe)

			case 'r':
			case 'R':

				while (_aiPlayer.holeAIPlayerKonto() >= _Mindesteinsatz)
				{

					if (_Runde == 'A')//doppeltgemoppelt
					{				
						printf("\n%s|Setze auf Rot \n\n", string(24, '*').c_str());

						halteKonto = _aiPlayer.holeAIPlayerKonto();

						halteEinsatz = _Mindesteinsatz;

						_gespielteSpiele++;

						_auswahlWahl = "ROT";

						_aiPlayer.entferneAIPlayerKonto(_Mindesteinsatz);

						kugelgefallen = _dealer.RolltKugel();

						if (kugelgefallen == 0)
						{
							_zahlZero++;

							//printGewinnVerlust(ZERO);

							_casinoBank.setzeBankKonto(_Mindesteinsatz);

							_verlorenAufRot += _Mindesteinsatz;

							_RundeGewonnen = false;

							berechnungXpbeute();

							_aiPlayer.setzeAIPlayerXP(xpanzahl);//XP und LVL Test

							prüfeLVLCap(_aiPlayer.holeAIPlayerXP());

							if ((_Mindesteinsatz*2)>_MultiCap)
							{
								_Mindesteinsatz = _setzeAufRot;
							}
							else {

								_Mindesteinsatz += _Mindesteinsatz;
							}
							_Runde = 'B';
						}
						for (int i = 0; i < 18; i++)
						{
							if (kugelgefallen == rot[i])
							{
								_zahlRot++;

								//printGewinnVerlust(WINRED);

								_casinoBank.entferneBankKonto(_Mindesteinsatz);

								_gewonnenAufRot += _Mindesteinsatz;

								puffer = _Mindesteinsatz * 2;

								_aiPlayer.setzeAIPlayerKonto(puffer);

								_RundeGewonnen = true;

								berechnungXpbeute();

								_aiPlayer.setzeAIPlayerXP(xpanzahl);//XP und LVL Test

								prüfeLVLCap(_aiPlayer.holeAIPlayerXP());

								_Mindesteinsatz = _setzeAufRot;

								puffer = 0.0f;
							}
							else if (kugelgefallen == schwarz[i])
							{
								_zahlSchwarz++;

								//printGewinnVerlust(LOSEBLACK);

								_casinoBank.setzeBankKonto(_Mindesteinsatz);

								_verlorenAufRot += _Mindesteinsatz;

								_RundeGewonnen = false;

								berechnungXpbeute();

								_aiPlayer.setzeAIPlayerXP(xpanzahl);

								prüfeLVLCap(_aiPlayer.holeAIPlayerXP());
								
								if ((_Mindesteinsatz * 2) > _MultiCap)
								{
									_Mindesteinsatz = _setzeAufRot;
								}
								else {

									_Mindesteinsatz += _Mindesteinsatz;
								}

								_Runde = 'B';
							}
						}
					}
					else if (_Runde == 'B')
					{
						
						printf("\n%s|Setze auf Schwarz \n\n", string(24, '*').c_str());

						halteKonto = _aiPlayer.holeAIPlayerKonto();

						halteEinsatz = _Mindesteinsatz;

						_gespielteSpiele++;

						_auswahlWahl = "SCHWARZ";

						_aiPlayer.entferneAIPlayerKonto(_Mindesteinsatz);

						kugelgefallen = _dealer.RolltKugel();

						if (kugelgefallen == 0)
						{
							_zahlZero++;

							//printGewinnVerlust(ZERO);

							_casinoBank.setzeBankKonto(_Mindesteinsatz);

							_verlorenAufSchwarz += _Mindesteinsatz;

							_RundeGewonnen = false;

							berechnungXpbeute();

							_aiPlayer.setzeAIPlayerXP(xpanzahl);//XP und LVL Test

							prüfeLVLCap(_aiPlayer.holeAIPlayerXP());

							if ((_Mindesteinsatz * 2) > _MultiCap)
							{
								_Mindesteinsatz = _setzeAufSchwarz;
							}
							else {

								_Mindesteinsatz += _Mindesteinsatz;
							}
							_Runde = 'A';
						}
						for (int i = 0; i < 18; i++)
						{
							if (kugelgefallen == rot[i])
							{
								_zahlRot++;

								//printGewinnVerlust(LOSERED);

								_casinoBank.setzeBankKonto(_Mindesteinsatz);

								_verlorenAufSchwarz += _Mindesteinsatz;

								_RundeGewonnen = false;

								berechnungXpbeute();

								_aiPlayer.setzeAIPlayerXP(xpanzahl);//XP und LVL Test

								prüfeLVLCap(_aiPlayer.holeAIPlayerXP());

								if ((_Mindesteinsatz * 2) > _MultiCap)
								{
									_Mindesteinsatz = _setzeAufSchwarz;
								}
								else {

									_Mindesteinsatz += _Mindesteinsatz;
								}
								
								_Runde = 'A';
							}
							else if (kugelgefallen == schwarz[i])
							{

								_zahlSchwarz++;

								//printGewinnVerlust(WINBLACK);

								_casinoBank.entferneBankKonto(_Mindesteinsatz);

								_gewonnenAufSchwarz += _Mindesteinsatz;

						
								puffer = _Mindesteinsatz * 2;


								_aiPlayer.setzeAIPlayerKonto(puffer);

								_RundeGewonnen = true;

								berechnungXpbeute();

								_aiPlayer.setzeAIPlayerXP(xpanzahl);

								prüfeLVLCap(_aiPlayer.holeAIPlayerXP());

								_Mindesteinsatz = _setzeAufSchwarz;

								puffer = 0.0f;

							}
						}

					}
					
				}
				system("CLS");

				
				for (string n : _vectorDaten)
				{
					cout << n;
				}
				Speichern();
				getchar();
}

void Tisch::printAiMainMenu()
{
	//----------------------------------------------------------------------------------Menue

	printf("%s\n", string(95, '#').c_str());
	printf("\n\nMit wie viel Geld starten wir? : "); cin >> _einsatzAIP; _aiPlayer.setzeAIPlayerKonto(_einsatzAIP);
	printf("\nDer starteinsatz wir beim verlust multipliziert nach dem Martingalprinzip.");
	printf("\nWie gross sollen der Starteinsatz sein? :"); cin >> _Mindesteinsatz;
	printf("\nWie hoch ist das Multiplikations Cap? :"); cin >> _MultiCap;
	printf("\nMit welcher Farbe starten wir?: (R)ot oder (S)chwarz"); cin >> _farbe;

	//----------------------------------------------------------------------------------Menue
}
void Tisch::cleanupAIPlayer()
{
	float zero = NULL;
	unsigned short zeroint = 0;
	unsigned long zerolong = 0;
	_aiPlayer.setzeAIPlayerKonto(zero);
	_aiPlayer.setzeAIPlayerLVL(zeroint);
	_aiPlayer.setzeAIPlayerXP(zero);

	_setzeAufRot = zero;
	_setzeAufSchwarz = zero;
	_Mindesteinsatz = zero;
	_zahlRot = zerolong;
	_zahlSchwarz = zerolong;
	_zahlZero = zerolong;

	halteEinsatz = zero;
	halteKonto = zero;
	_gespielteSpiele = zerolong;
	_gewonnenAufRot = zero;
	_gewonnenAufSchwarz = zero;
	_verlorenAufRot = zero;
	_verlorenAufSchwarz = zero;
	

}
void Tisch::printXpBerechnungGewinn()
{
	//----------------------------------------------------------------------------------Menue
	printf("%s|\n\n%s|XPErhalten: %0.1f \n\n%s|XPMulti: %0.2f%% \n\n%s|BonusMulti: %0.1f%% \n\n", string(24, '*').c_str(), string(24, '*').c_str(), xpanzahl, string(24, '*').c_str(), Multiplikator, string(24, '*').c_str(), xpBonus);
	printf("%s|Gespielte runden: %c \n\n", string(24, '*').c_str(), _gespielteSpiele);
	printf("%s|RED: %d Black: %d Zero: %d \n\n", string(24, '*').c_str(), _zahlRot, _zahlSchwarz, _zahlZero);
	printf("%s|Ai Konto: %0.1f \n\n", string(24, '*').c_str(), _aiPlayer.holeAIPlayerKonto());
	printf("%s|Ai Einsatz: %0.1f \n\n", string(24, '*').c_str(), _Mindesteinsatz);
	printf("%s|Ai LVL: %u \n\n", string(24, '*').c_str(), _aiPlayer.holeAIPlayerLVL());
	printf("%s|Ai XP: %0.1f \n\n", string(24, '*').c_str(), _aiPlayer.holeAIPlayerXP());
	//----------------------------------------------------------------------------------Menue
}
void Tisch::printXpBerechnungVerlust()
{
	//----------------------------------------------------------------------------------Menue
	printf("%s|\n\n%s|XPErhalten: %0.1f \n\n%s|XPMulti: %0.2f%% \n\n%s|BonusMulti: %0.1f%% \n\n", string(24, '*').c_str(), string(24, '*').c_str(), xpanzahl, string(24, '*').c_str(), Multiplikator, string(24, '*').c_str(), xpBonus);
	printf("%s|Gespielte runden: %d \n\n", string(24, '*').c_str(), _gespielteSpiele);
	printf("%s|RED: %d Black: %d Zero: %d\n\n", string(24, '*').c_str(), _zahlRot, _zahlSchwarz, _zahlZero);
	printf("%s|Ai Konto: %0.1f \n\n", string(24, '*').c_str(), _aiPlayer.holeAIPlayerKonto());
	printf("%s|Ai Einsatz: %0.1f \n\n", string(24, '*').c_str(), _Mindesteinsatz);
	printf("%s|Ai LVL: %u \n\n", string(24, '*').c_str(), _aiPlayer.holeAIPlayerLVL());
	printf("%s|Ai XP: %0.1f \n\n", string(24, '*').c_str(), _aiPlayer.holeAIPlayerXP());
	//----------------------------------------------------------------------------------Menue
}
void Tisch::printGewinnVerlust(unsigned short int c)
{
	switch (c) {

	case ZERO:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt auf`s Zero feld\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case WINRED:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case LOSERED:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der NR: %d|\n%s|      Du hast diese Runde Verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case WINBLACK:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der Nr: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case LOSEBLACK:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	default:
		break;


	}


}


