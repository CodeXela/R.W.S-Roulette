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

	InitTisch(false,false,false,false,0.0,0.0,0.0,0.0,0.0,0,0.0,0.0,0.0,0u);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_casinoBank.initCB(100000.0f);// Casinobank wird aufgefüllt(MERKE*ersetzen mit eingabe)
	
	_aiPlayer.initPlayer(0,0,0,0);
	_spieler.initPlayer(1000,0,0,0);

}
void Tisch::spieleSpiel() //wird in der mainfunktion gerufen und startet das spiel
{

	Print();//Gibt das Menue usw. aus
}

Tisch::~Tisch()//Dekonstruktor
{
	

}
void Tisch::InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, double gewonnenAufRot, double gewonnenAufSchwarz, double verlorenAufRot, double verlorenAufSchwarz, double verlorenAufZahl, int gespielteSpiele, double setzeAufRot, double setzeAufSchwarz, double setzeAufZahl, unsigned int lvlCap)
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
		
			MenueAbfragePrint();
			break;

		case SINGLE_PLAYER:
			
			singelPlayerPrint();
			
			switch (setzen)
			{
			case SETZE_ROT:

				setzeAufRotPrint();
				break;

			case SETZE_SCHWARZ:

				setzeAufSchwarzPrint();
				break;

			case SETZE_ZAHL:

				setzeAufZahlPrint();
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
			optionen = MAIN_MENU;
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

	//Bereinige Zeiger für Einsatzarten


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
		FILE << std::fixed << std::setprecision(1) << _spieler.holeKonto() << endl;
		FILE << std::fixed << std::setprecision(1) << _spieler.holeEXP() << endl;
		FILE << std::fixed << std::setprecision(1) << _casinoBank.holeBank() << endl;*/

		FILE << "\nRunde , StartKonto , EndKonto , Einsatz , Farbe , CasinoKonto, Gewonnen , Kugel , Gewinn/Verlust , LVL , EXP , expAnzahl, Multi , expBonus" << endl;

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
void Tisch::legeDatenAb(string runde,string skonto,string konto, string eisatz, string farbe, string casinobank, string gewonnen,string kugel,string gewonnenauf, string lvl, string exp, string expAnzahl, string multi, string expBonus)
{
	
	_vectorDaten.push_back( runde + "," + skonto + "," + konto + "," + eisatz + "," + farbe + "," + casinobank + "," + gewonnen + "," + kugel + "," + gewonnenauf + "," + lvl + "," + exp + "," + expAnzahl+ "," + multi+ "," + expBonus+"\n");
	
}
void Tisch::berechnungXpbeute()
{
	if (_RundeGewonnen == false) {

		Multiplikator = ((halteEinsatz* 10) /halteKonto);

		xpanzahl = Multiplikator*halteEinsatz;

		//printXpBerechnungVerlust();

		legeDatenAb(to_string(_gespielteSpiele), to_string(int (halteKonto)), to_string(int(_aiPlayer.holeKonto())),to_string(int(_Mindesteinsatz)),_auswahlWahl,to_string(int(_casinoBank.holeBank())), to_string( _RundeGewonnen), to_string(_kugelgefallen), to_string(int(_auswahlWahl == "ROT" ? _verlorenAufRot : _verlorenAufSchwarz)),to_string(_aiPlayer.holeLVL()),to_string(_aiPlayer.holeEXP()), to_string(xpanzahl),to_string(Multiplikator),to_string(xpBonus));
	}
	else if(_RundeGewonnen == true) {

		Multiplikator = ((halteEinsatz * 10) /halteKonto);

		xpBonus = Multiplikator*0.2f;

		xpanzahl = (Multiplikator + xpBonus) * halteEinsatz;

		//printXpBerechnungGewinn();
		
		legeDatenAb(to_string(_gespielteSpiele), to_string(int (halteKonto)), to_string(int(_aiPlayer.holeKonto())), to_string(int(_Mindesteinsatz)), _auswahlWahl, to_string(int(_casinoBank.holeBank())), to_string(_RundeGewonnen),to_string(_kugelgefallen),to_string(int(_auswahlWahl == "ROT" ? _gewonnenAufRot : _gewonnenAufSchwarz)),to_string(_aiPlayer.holeLVL()), to_string(_aiPlayer.holeEXP()), to_string(xpanzahl), to_string(Multiplikator), to_string(xpBonus));
	}
}

void Tisch::MenueAbfragePrint()
{
	string tName;//Puffer für name
	while (_Richtig != true)// TO DO 05.11<---------------------------------------<<<<
	{
		printf("\n\n\n\n\n\t\t\tBitte Spieler Name eingeben:");

		cin >> tName;

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

	_spieler.setzeSpielerName(tName);
	system("CLS");
	//----------------------------------------------------------------------------------Menue
	printf("%s\n", string(95, '#').c_str());
	printf("\t\t\t\t\tRWS v%.3f\n\n\n\n\n",_version);
	printf("\t\t\t\t\t(1)Single Player\n\t\t\t\t\t(2)AI Player\n\t\t\t\t\t(3)Option\n\t\t\t\t\t(4)Exit\n");
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
void Tisch::singelPlayerPrint()
{
	if (_spieler.holeKonto() >= _Mindesteinsatz)
	{

		//----------------------------------------------------------------------------------Menue
		printf("%s\n", string(95, '#').c_str());
		printf("\tSpieler Name:%s\t\t\t\tCasino Bank:%.1f\n\tSpieler Konto:%.1f\t\t\t\tMindesteinsatz: %.1f\n\tLVL:%i\tEXP:%.2f\tCap:%i\t\t\t\tCasino Hausvorteil: 2,70%%\n",_spieler.holeSpielerName().c_str(), _casinoBank.holeBank(), _spieler.holeKonto(), _Mindesteinsatz, _spieler.holeLVL(), _spieler.holeEXP(), _spieler.holeLVLCap());
		printf("%s\n", string(95, '#').c_str());
		printf("%sAuszahlung: 2 zu 1%s%sAuszahlung: 8 zu 1%s%sAuszahlung: 2 zu 1%s\n", string(3, '-').c_str(), string(3, '-').c_str(), string(9, '-').c_str(), string(10, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str());
		printf("(D1)D-1,2,3,4,5,6,7,8\t|(1)Q-1,2,4,5     |(2)Q-2,3,4,6     |(S1)S-1,4,7,10,13,16,19,22\n(D1)D-9,10,11,12\t%s(S1)S-25,28,31,34\n(D2)D-13,14,15,16,17,18\t|(3)Q-4,5,7,8     |(4)Q-5,6,8,9     |(S2)S-2,5,8,11,14,17,20\n(D2)D-19,20,21,22,23,24\t%s(S2)S-23,26,29,32,35\n(D3)D-25,26,27,28,29,30\t|(5)Q-7,8,10,11   |(6)Q-8,9,11,12   |(S3)S-3,6,9,12,15,18,21,24\n(D3)D-31,32,33,34,35,36\t%s(S3)S-27,30,33,36\n%sAuszahlung: 1 zu 1%s|(7)Q-10,11,13,14 |(8)Q-11,12,14,15 |%sAuszahlung: 1 zu 1%s\n(Lo)L-1,2,3,4,5,6,7,8,9\t%s(Ro)R-1,3,5,7,9,12,14,16,18,19\n(Lo)L-10,11,12,13,14,15\t|(9)Q-13,14,16,17 |(10)Q-14,15,17,18|(Ro)R-21,23,25,27,30,32,34,36\n(Lo)L-16,17,18\t\t%s(Sc)S-2,4,6,8,10,11,13,15,17,20\n(Hi)H-19,20,21,22,23,24\t|(11)Q-16,17,19,20|(12)Q-17,18,20,21|(Sc)S-22,24,26,28,29,31,33,35\n(Hi)H-25,26,27,28,29,30\t%s%sAuszahlung: 37 zu 1%s\n(Hi)H-31,32,33,34,35,36\t|(13)Q-19,20,22,23|(14)Q-20,21,23,24|(Z)Setze auf eine Zahl\n%sAuszahlung: 1 zu 1%s%s\n(Un)U-1,3,5,7,9,11,13\t|(15)Q-22,23,25,26|(16)Q-23,24,26,27|\n(Un)U-15,17,19,21,23,25\t%s\n(Un)U-27,29,31,33,35\t|(17)Q-25,26,28,29|(18)Q-26,27,29,30|\n\t\t\t%s\n(Ge)G-2,4,6,8,10,12,14\t|(19)Q-28,29,31,32|(20)Q-29,30,32,33|\n(Ge)G-16,18,20,22,24,26\t%s\n(Ge)G-28,30,32,34,36\t|(21)Q-31,32,34,35|(22)Q-32,33,35,36|\n\t\t\t%s\n",string(37,'-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str());
		printf("%s\n", string(95, '#').c_str());
		printf("\t\t(E)Einzelauswahl\t(M)Mehrfachauswahl\t(Q)Zurueck\n");
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
void Tisch::AIMenuePrint()
{
	double puffer = 0.0;

	system("CLS");

	//cleanupAIPlayer();

	printAiMainMenu();

	_setzeAufRot = _Mindesteinsatz;
	_setzeAufSchwarz = _Mindesteinsatz;

	_gewinnAIP += _einsatzAIP;

	cin.clear();
	cin.ignore(INT_MAX, '\n');//fix für doppelte ausgabe bug
	//cin.ignore(CHAR_MAX, '\n');

	switch (_farbe)

			case 'r':
			case 'R':

				while (_aiPlayer.holeKonto() >= _Mindesteinsatz && _aiPlayer.holeKonto() <= _gewinnAIP)
				{

					if (_Runde == 'A')//doppeltgemoppelt
					{
						//printf("\n%s|Setze auf Rot \n\n", string(24, '*').c_str());

						halteKonto = _aiPlayer.holeKonto();

						halteEinsatz = _Mindesteinsatz;

						_gespielteSpiele++;

						_auswahlWahl = "ROT";

						_aiPlayer.entferneKonto(_Mindesteinsatz);

						_kugelgefallen = _dealer.RolltKugel();

						if (_kugelgefallen == 0)
						{
							_zahlZero++;

							//printGewinnVerlust(ZERO);

							_casinoBank.setzeBankKonto(_Mindesteinsatz);

							_verlorenAufRot += _Mindesteinsatz;

							_RundeGewonnen = false;

							berechnungXpbeute();


							_aiPlayer.setzeEXP(xpanzahl);//XP und LVL Test

							//prüfeLVLCap(_aiPlayer.holeEXP());

							if ((_Mindesteinsatz * 2) > _MultiCap)
							{
								_Mindesteinsatz = _setzeAufRot;
							}
							else {

								_Mindesteinsatz += _Mindesteinsatz;
							}
							_Runde = 'B';
						}
						else if (_aiPlayer.setzeAufRot(_kugelgefallen))
						{
							_zahlRot++;

							//printGewinnVerlust(WINRED);

							_casinoBank.entferneBankKonto(_Mindesteinsatz);

							_gewonnenAufRot += _Mindesteinsatz;

							puffer = _Mindesteinsatz * 2;

							_aiPlayer.setzeKonto(puffer);

							_RundeGewonnen = true;

							berechnungXpbeute();

							_aiPlayer.setzeEXP(xpanzahl);//XP und LVL Test

							//prüfeLVLCap(_aiPlayer.holeEXP());

							_Mindesteinsatz = _setzeAufRot;

							puffer = 0.0f;
						}
						else if (_aiPlayer.setzeAufSchwarz(_kugelgefallen))
						{
							_zahlSchwarz++;

							//printGewinnVerlust(LOSEBLACK);

							_casinoBank.setzeBankKonto(_Mindesteinsatz);

							_verlorenAufRot += _Mindesteinsatz;

							_RundeGewonnen = false;

							berechnungXpbeute();

							_aiPlayer.setzeEXP(xpanzahl);

							//prüfeLVLCap(_aiPlayer.holeEXP());

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
					else if (_Runde == 'B')
					{

						//printf("\n%s|Setze auf Schwarz \n\n", string(24, '*').c_str());

						halteKonto = _aiPlayer.holeKonto();

						halteEinsatz = _Mindesteinsatz;

						_gespielteSpiele++;

						_auswahlWahl = "SCHWARZ";

						_aiPlayer.entferneKonto(_Mindesteinsatz);

						_kugelgefallen = _dealer.RolltKugel();

						if (_kugelgefallen == 0)
						{
							_zahlZero++;

							//printGewinnVerlust(ZERO);

							_casinoBank.setzeBankKonto(_Mindesteinsatz);

							_verlorenAufSchwarz += _Mindesteinsatz;

							_RundeGewonnen = false;

							berechnungXpbeute();

							_aiPlayer.setzeEXP(xpanzahl);//XP und LVL Test

							//prüfeLVLCap(_aiPlayer.holeEXP());

							if ((_Mindesteinsatz * 2) > _MultiCap)
							{
								_Mindesteinsatz = _setzeAufSchwarz;
							}
							else {

								_Mindesteinsatz += _Mindesteinsatz;
							}
							_Runde = 'A';
						}
						else if (_aiPlayer.setzeAufRot(_kugelgefallen))
						{
							_zahlRot++;

							//printGewinnVerlust(LOSERED);

							_casinoBank.setzeBankKonto(_Mindesteinsatz);

							_verlorenAufSchwarz += _Mindesteinsatz;

							_RundeGewonnen = false;

							berechnungXpbeute();

							_aiPlayer.setzeEXP(xpanzahl);//XP und LVL Test

							//prüfeLVLCap(_aiPlayer.holeEXP());

							if ((_Mindesteinsatz * 2) > _MultiCap)
							{
								_Mindesteinsatz = _setzeAufSchwarz;
							}
							else {

								_Mindesteinsatz += _Mindesteinsatz;
							}

							_Runde = 'A';
						}
						else if (_aiPlayer.setzeAufSchwarz(_kugelgefallen))
						{

							_zahlSchwarz++;

							//printGewinnVerlust(WINBLACK);

							_casinoBank.entferneBankKonto(_Mindesteinsatz);

							_gewonnenAufSchwarz += _Mindesteinsatz;


							puffer = _Mindesteinsatz * 2;


							_aiPlayer.setzeKonto(puffer);

							_RundeGewonnen = true;

							berechnungXpbeute();

							_aiPlayer.setzeEXP(xpanzahl);

							//prüfeLVLCap(_aiPlayer.holeEXP());

							_Mindesteinsatz = _setzeAufSchwarz;

							puffer = 0.0f;

						}


					}

				}
				//system("CLS");


				for (string n : _vectorDaten)
				{
					cout << n;
				}
				Speichern();
				getchar();
}

void Tisch::setzeAufRotPrint()
{
	if (_spieler.holeKonto() >= _Mindesteinsatz)
	{
		system("CLS");
		//----------------------------------------------------------------------------------Menue
		printf("%s\n", string(95, '#').c_str());
		printf("\tSpieler Name:%s\t\t\t\tCasino Bank:%.1f\n\tSpieler Konto:%.1f\t\t\t\tMindesteinsatz: %.1f\n\tLVL:%i\tEXP:%.2f\tCap:%i\t\t\t\tCasino Hausvorteil: 2,70%%\n", _spieler.holeSpielerName().c_str(), _casinoBank.holeBank(), _spieler.holeKonto(), _Mindesteinsatz, _spieler.holeLVL(), _spieler.holeEXP(), _spieler.holeLVLCap());
		printf("%s\n", string(95, '#').c_str());
		printf("%sAuszahlung: 2 zu 1%s%sAuszahlung: 8 zu 1%s%sAuszahlung: 2 zu 1%s\n", string(3, '-').c_str(), string(3, '-').c_str(), string(9, '-').c_str(), string(10, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str());
		printf("(D1)D-1,2,3,4,5,6,7,8\t|(1)Q-1,2,4,5     |(2)Q-2,3,4,6     |(S1)S-1,4,7,10,13,16,19,22\n(D1)D-9,10,11,12\t%s(S1)S-25,28,31,34\n(D2)D-13,14,15,16,17,18\t|(3)Q-4,5,7,8     |(4)Q-5,6,8,9     |(S2)S-2,5,8,11,14,17,20\n(D2)D-19,20,21,22,23,24\t%s(S2)S-23,26,29,32,35\n(D3)D-25,26,27,28,29,30\t|(5)Q-7,8,10,11   |(6)Q-8,9,11,12   |(S3)S-3,6,9,12,15,18,21,24\n(D3)D-31,32,33,34,35,36\t%s(S3)S-27,30,33,36\n%sAuszahlung: 1 zu 1%s|(7)Q-10,11,13,14 |(8)Q-11,12,14,15 |%sAuszahlung: 1 zu 1%s\n(Lo)L-1,2,3,4,5,6,7,8,9\t%s(Ro)R-1,3,5,7,9,12,14,16,18,19\n(Lo)L-10,11,12,13,14,15\t|(9)Q-13,14,16,17 |(10)Q-14,15,17,18|(Ro)R-21,23,25,27,30,32,34,36\n(Lo)L-16,17,18\t\t%s(Sc)S-2,4,6,8,10,11,13,15,17,20\n(Hi)H-19,20,21,22,23,24\t|(11)Q-16,17,19,20|(12)Q-17,18,20,21|(Sc)S-22,24,26,28,29,31,33,35\n(Hi)H-25,26,27,28,29,30\t%s%sAuszahlung: 37 zu 1%s\n(Hi)H-31,32,33,34,35,36\t|(13)Q-19,20,22,23|(14)Q-20,21,23,24|(Z)Setze auf eine Zahl\n%sAuszahlung: 1 zu 1%s%s\n(Un)U-1,3,5,7,9,11,13\t|(15)Q-22,23,25,26|(16)Q-23,24,26,27|\n(Un)U-15,17,19,21,23,25\t%s\n(Un)U-27,29,31,33,35\t|(17)Q-25,26,28,29|(18)Q-26,27,29,30|\n\t\t\t%s\n(Ge)G-2,4,6,8,10,12,14\t|(19)Q-28,29,31,32|(20)Q-29,30,32,33|\n(Ge)G-16,18,20,22,24,26\t%s\n(Ge)G-28,30,32,34,36\t|(21)Q-31,32,34,35|(22)Q-32,33,35,36|\n\t\t\t%s\n", string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str());
		printf("%s\n", string(95, '#').c_str());
		printf("\t\t\t\tWie viel moechtest Du auf \"Rot\" setzen ? \n");
		//----------------------------------------------------------------------------------Menue
		
		

		halteKonto = _spieler.holeKonto();

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
		if (_setzeAufRot <= _spieler.holeKonto())
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

			_spieler.entferneKonto(_setzeAufRot);//TO DO 24.10.2015->

			system("CLS");

			_kugelgefallen = _dealer.RolltKugel();
			
			if (_kugelgefallen == 0)
			{

				_zahlZero++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt auf`s Zero feld\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

				_casinoBank.setzeBankKonto(_setzeAufRot);

				_RundeGewonnen = false;

				berechnungXpbeute();

				_spieler.setzeEXP(xpanzahl);//XP und LVL Test

				//prüfeLVLCap(_spieler.holeEXP());

				_setzeAufRot = NULL;


			}else if(_spieler.setzeAufRot(_kugelgefallen)){
					
					_zahlRot++;

					//----------------------------------------------------------------------------------Menue
					printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
					//----------------------------------------------------------------------------------Menue

					_casinoBank.entferneBankKonto(_setzeAufRot);

					_setzeAufRot = (_setzeAufRot * 2);

					_spieler.setzeKonto(_setzeAufRot);

					_RundeGewonnen = true;

					berechnungXpbeute();

					_spieler.setzeEXP(xpanzahl);//XP und LVL Test

					//prüfeLVLCap(_spieler.holeEXP());

					_setzeAufRot = NULL;


			}else if (_spieler.setzeAufSchwarz(_kugelgefallen)){
					
					_zahlSchwarz++;

					//----------------------------------------------------------------------------------Menue
					printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
					//----------------------------------------------------------------------------------Menue

					_casinoBank.setzeBankKonto(_setzeAufRot);

					_RundeGewonnen = false;

					berechnungXpbeute();

					_spieler.setzeEXP(xpanzahl);

					//prüfeLVLCap(_spieler.holeEXP());

					_setzeAufRot = NULL;

			}
			getchar();
		}
			
	}else{
		printf("Du hast zu wenig Geld");

		getchar();

		optionen = MAIN_MENU;
		return;
	}
	
}
void Tisch::setzeAufSchwarzPrint()
{
	if (_spieler.holeKonto() >= _Mindesteinsatz)
	{
	system("CLS");

	//----------------------------------------------------------------------------------Menue
	printf("%s\n", string(95, '#').c_str());
	printf("\tSpieler Name:%s\t\t\t\tCasino Bank:%.1f\n\tSpieler Konto:%.1f\t\t\t\tMindesteinsatz: %.1f\n\tLVL:%i\tEXP:%.2f\tCap:%i\t\t\t\tCasino Hausvorteil: 2,70%%\n", _spieler.holeSpielerName().c_str(), _casinoBank.holeBank(), _spieler.holeKonto(), _Mindesteinsatz, _spieler.holeLVL(), _spieler.holeEXP(), _spieler.holeLVLCap());
	printf("%s\n", string(95, '#').c_str());
	printf("%sAuszahlung: 2 zu 1%s%sAuszahlung: 8 zu 1%s%sAuszahlung: 2 zu 1%s\n", string(3, '-').c_str(), string(3, '-').c_str(), string(9, '-').c_str(), string(10, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str());
	printf("(D1)D-1,2,3,4,5,6,7,8\t|(1)Q-1,2,4,5     |(2)Q-2,3,4,6     |(S1)S-1,4,7,10,13,16,19,22\n(D1)D-9,10,11,12\t%s(S1)S-25,28,31,34\n(D2)D-13,14,15,16,17,18\t|(3)Q-4,5,7,8     |(4)Q-5,6,8,9     |(S2)S-2,5,8,11,14,17,20\n(D2)D-19,20,21,22,23,24\t%s(S2)S-23,26,29,32,35\n(D3)D-25,26,27,28,29,30\t|(5)Q-7,8,10,11   |(6)Q-8,9,11,12   |(S3)S-3,6,9,12,15,18,21,24\n(D3)D-31,32,33,34,35,36\t%s(S3)S-27,30,33,36\n%sAuszahlung: 1 zu 1%s|(7)Q-10,11,13,14 |(8)Q-11,12,14,15 |%sAuszahlung: 1 zu 1%s\n(Lo)L-1,2,3,4,5,6,7,8,9\t%s(Ro)R-1,3,5,7,9,12,14,16,18,19\n(Lo)L-10,11,12,13,14,15\t|(9)Q-13,14,16,17 |(10)Q-14,15,17,18|(Ro)R-21,23,25,27,30,32,34,36\n(Lo)L-16,17,18\t\t%s(Sc)S-2,4,6,8,10,11,13,15,17,20\n(Hi)H-19,20,21,22,23,24\t|(11)Q-16,17,19,20|(12)Q-17,18,20,21|(Sc)S-22,24,26,28,29,31,33,35\n(Hi)H-25,26,27,28,29,30\t%s%sAuszahlung: 37 zu 1%s\n(Hi)H-31,32,33,34,35,36\t|(13)Q-19,20,22,23|(14)Q-20,21,23,24|(Z)Setze auf eine Zahl\n%sAuszahlung: 1 zu 1%s%s\n(Un)U-1,3,5,7,9,11,13\t|(15)Q-22,23,25,26|(16)Q-23,24,26,27|\n(Un)U-15,17,19,21,23,25\t%s\n(Un)U-27,29,31,33,35\t|(17)Q-25,26,28,29|(18)Q-26,27,29,30|\n\t\t\t%s\n(Ge)G-2,4,6,8,10,12,14\t|(19)Q-28,29,31,32|(20)Q-29,30,32,33|\n(Ge)G-16,18,20,22,24,26\t%s\n(Ge)G-28,30,32,34,36\t|(21)Q-31,32,34,35|(22)Q-32,33,35,36|\n\t\t\t%s\n", string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str());
	printf("%s\n", string(95, '#').c_str());
	printf("\t\t\t\tWie viel moechtest Du auf \"Schwarz\" setzen ? \n");
	//----------------------------------------------------------------------------------Menue


	halteKonto = _spieler.holeKonto();

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

		if (_setzeAufSchwarz <= _spieler.holeKonto())
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

			_spieler.entferneKonto(_setzeAufSchwarz);

			_kugelgefallen = _dealer.RolltKugel();//Werfe die Kugel

			if (_kugelgefallen == 0)
			{

				_zahlZero++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt auf`s Zero feld\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

				_casinoBank.setzeBankKonto(_setzeAufSchwarz);

				_RundeGewonnen = false;

				berechnungXpbeute();

				_spieler.setzeEXP(xpanzahl);//XP und LVL Test

				//prüfeLVLCap(_spieler.holeEXP());

				_setzeAufSchwarz = NULL;

			}
			else if (_spieler.setzeAufSchwarz(_kugelgefallen)) {

				_zahlSchwarz++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

				_casinoBank.entferneBankKonto(_setzeAufSchwarz);

				_setzeAufSchwarz = _setzeAufSchwarz * 2;

				_spieler.setzeKonto(_setzeAufSchwarz);

				_RundeGewonnen = true;

				berechnungXpbeute();

				_spieler.setzeEXP(xpanzahl);//XP und LVL Test

				//prüfeLVLCap(_spieler.holeEXP());

				_setzeAufSchwarz = NULL;


			}
			else if (_spieler.setzeAufRot(_kugelgefallen)) {

				_zahlRot++;

				//----------------------------------------------------------------------------------Menue
				printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				//----------------------------------------------------------------------------------Menue

				_casinoBank.setzeBankKonto(_setzeAufSchwarz);

				_RundeGewonnen = false;

				berechnungXpbeute();

				_spieler.setzeEXP(xpanzahl);

				//prüfeLVLCap(_spieler.holeEXP());

				_setzeAufSchwarz = NULL;


			}
			getchar();

		}

	}else {

		printf("Du hast zu wenig Geld");

		getchar();

		optionen = SINGLE_PLAYER;
		return;
	}	
}
void Tisch::setzeAufZahlPrint()
{
	if (_spieler.holeKonto() >= _Mindesteinsatz)
	{
		system("CLS");
		//----------------------------------------------------------------------------------Menue
		printf("%s\n", string(95, '#').c_str());
		printf("\tSpieler Name:%s\t\t\t\tCasino Bank:%.1f\n\tSpieler Konto:%.1f\t\t\t\tMindesteinsatz: %.1f\n\tLVL:%i\tEXP:%.2f\tCap:%i\t\t\t\tCasino Hausvorteil: 2,70%%\n", _spieler.holeSpielerName().c_str(), _casinoBank.holeBank(), _spieler.holeKonto(), _Mindesteinsatz, _spieler.holeLVL(), _spieler.holeEXP(), _spieler.holeLVLCap());
		printf("%s\n", string(95, '#').c_str());
		printf("%sAuszahlung: 2 zu 1%s%sAuszahlung: 8 zu 1%s%sAuszahlung: 2 zu 1%s\n", string(3, '-').c_str(), string(3, '-').c_str(), string(9, '-').c_str(), string(10, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str());
		printf("(D1)D-1,2,3,4,5,6,7,8\t|(1)Q-1,2,4,5     |(2)Q-2,3,4,6     |(S1)S-1,4,7,10,13,16,19,22\n(D1)D-9,10,11,12\t%s(S1)S-25,28,31,34\n(D2)D-13,14,15,16,17,18\t|(3)Q-4,5,7,8     |(4)Q-5,6,8,9     |(S2)S-2,5,8,11,14,17,20\n(D2)D-19,20,21,22,23,24\t%s(S2)S-23,26,29,32,35\n(D3)D-25,26,27,28,29,30\t|(5)Q-7,8,10,11   |(6)Q-8,9,11,12   |(S3)S-3,6,9,12,15,18,21,24\n(D3)D-31,32,33,34,35,36\t%s(S3)S-27,30,33,36\n%sAuszahlung: 1 zu 1%s|(7)Q-10,11,13,14 |(8)Q-11,12,14,15 |%sAuszahlung: 1 zu 1%s\n(Lo)L-1,2,3,4,5,6,7,8,9\t%s(Ro)R-1,3,5,7,9,12,14,16,18,19\n(Lo)L-10,11,12,13,14,15\t|(9)Q-13,14,16,17 |(10)Q-14,15,17,18|(Ro)R-21,23,25,27,30,32,34,36\n(Lo)L-16,17,18\t\t%s(Sc)S-2,4,6,8,10,11,13,15,17,20\n(Hi)H-19,20,21,22,23,24\t|(11)Q-16,17,19,20|(12)Q-17,18,20,21|(Sc)S-22,24,26,28,29,31,33,35\n(Hi)H-25,26,27,28,29,30\t%s%sAuszahlung: 37 zu 1%s\n(Hi)H-31,32,33,34,35,36\t|(13)Q-19,20,22,23|(14)Q-20,21,23,24|(Z)Setze auf eine Zahl\n%sAuszahlung: 1 zu 1%s%s\n(Un)U-1,3,5,7,9,11,13\t|(15)Q-22,23,25,26|(16)Q-23,24,26,27|\n(Un)U-15,17,19,21,23,25\t%s\n(Un)U-27,29,31,33,35\t|(17)Q-25,26,28,29|(18)Q-26,27,29,30|\n\t\t\t%s\n(Ge)G-2,4,6,8,10,12,14\t|(19)Q-28,29,31,32|(20)Q-29,30,32,33|\n(Ge)G-16,18,20,22,24,26\t%s\n(Ge)G-28,30,32,34,36\t|(21)Q-31,32,34,35|(22)Q-32,33,35,36|\n\t\t\t%s\n", string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(6, '-').c_str(), string(10, '-').c_str(), string(3, '-').c_str(), string(3, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str(), string(37, '-').c_str());
		printf("%s\n", string(95, '#').c_str());
		printf("\t\t\t\tWie viel moechtest Du auf \"Zahl\" setzen ? \n");
		//----------------------------------------------------------------------------------Menue

		halteKonto = _spieler.holeKonto();

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
		printf("\t\t\t\tDeine Zahl auf die Du wetten moechtest?\n");
		//----------------------------------------------------------------------------------Menue

		cin >> _ZahlAuswahl;

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (_setzeAufZahl <= _spieler.holeKonto())
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

			_spieler.entferneKonto(_setzeAufZahl);//TO DO 24.10.2015->

			system("CLS");

			_kugelgefallen = _dealer.RolltKugel();


			//----------------------------------------------------------------------------------------------------------------------------------------



			if (_kugelgefallen == _ZahlAuswahl)
			{


				printf("%s\n%s|Die Kugel rollt aufs Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				
				_casinoBank.entferneBankKonto(_setzeAufZahl);
				
				_setzeAufZahl = (_setzeAufZahl * 36);
				
				_spieler.setzeKonto(_setzeAufZahl);
				
				_RundeGewonnen = true;
				
				berechnungXpbeute();
				
				_spieler.setzeEXP(xpanzahl);//XP und LVL Test
				
				//prüfeLVLCap(_spieler.holeEXP());
				
				_setzeAufZahl = NULL;


			}
			else {


				printf("%s\n%s|Die Kugel rollt aufs Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
				
				_casinoBank.setzeBankKonto(_setzeAufZahl);
				
				_RundeGewonnen = false;
				
				berechnungXpbeute();
				
				_spieler.setzeEXP(xpanzahl);
				
				//prüfeLVLCap(_spieler.holeEXP());

				_setzeAufZahl = NULL;

			}

		}
		
		getchar();
	}
	else {

		printf("Du hast zu wenig Geld!!!");

		getchar();

		optionen = SINGLE_PLAYER;
		return;
	}
}

void Tisch::setzeAufUngeradePrint()
{

}


void Tisch::printAiMainMenu()
{
	//----------------------------------------------------------------------------------Menue

	printf("%s\n", string(95, '#').c_str());
	printf("\n\nMit wie viel Geld starten wir? : "); cin >> _einsatzAIP; _aiPlayer.setzeKonto(_einsatzAIP);
	printf("\nDer starteinsatz wir beim verlust multipliziert nach dem Martingalprinzip.");
	printf("\nWie gross sollen der Starteinsatz sein? :"); cin >> _Mindesteinsatz;
	printf("\nWie hoch ist das Multiplikations Cap? :"); cin >> _MultiCap;
	printf("\nWie hoch soll der Gewinn sein? :"); cin >> _gewinnAIP;
	printf("\nMit welcher Farbe starten wir?: (R)ot oder (S)chwarz"); cin >> _farbe;

	//----------------------------------------------------------------------------------Menue
}
void Tisch::cleanupAIPlayer()
{
	double zero = 0.0;
	unsigned int zeroint = 0;
	unsigned long zerolong = 0;
	_aiPlayer.setzeKonto(zero);
	_aiPlayer.setzeLVL(zeroint);
	_aiPlayer.setzeEXP(zero);

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
	_vectorDaten.clear();

}
void Tisch::printXpBerechnungGewinn()
{
	//----------------------------------------------------------------------------------Menue
	printf("%s|\n\n%s|XPErhalten: %0.1f \n\n%s|XPMulti: %0.f%% \n\n%s|BonusMulti: %0.1f%% \n\n", string(24, '*').c_str(), string(24, '*').c_str(), xpanzahl, string(24, '*').c_str(), Multiplikator, string(24, '*').c_str(), xpBonus);
	printf("%s|Gespielte runden: %c \n\n", string(24, '*').c_str(), _gespielteSpiele);
	printf("%s|RED: %d Black: %d Zero: %d \n\n", string(24, '*').c_str(), _zahlRot, _zahlSchwarz, _zahlZero);
	printf("%s|Ai Konto: %0.1f \n\n", string(24, '*').c_str(), _aiPlayer.holeKonto());
	printf("%s|Ai Einsatz: %0.1f \n\n", string(24, '*').c_str(), _Mindesteinsatz);
	printf("%s|Ai LVL: %u \n\n", string(24, '*').c_str(), _aiPlayer.holeLVL());
	printf("%s|Ai XP: %0.0f \n\n", string(24, '*').c_str(), _aiPlayer.holeEXP());
	//----------------------------------------------------------------------------------Menue
}
void Tisch::printXpBerechnungVerlust()
{
	//----------------------------------------------------------------------------------Menue
	printf("%s|\n\n%s|XPErhalten: %0.1f \n\n%s|XPMulti: %0.1f%% \n\n%s|BonusMulti: %0.1f%% \n\n", string(24, '*').c_str(), string(24, '*').c_str(), xpanzahl, string(24, '*').c_str(), Multiplikator, string(24, '*').c_str(), xpBonus);
	printf("%s|Gespielte runden: %d \n\n", string(24, '*').c_str(), _gespielteSpiele);
	printf("%s|RED: %d Black: %d Zero: %d\n\n", string(24, '*').c_str(), _zahlRot, _zahlSchwarz, _zahlZero);
	printf("%s|Ai Konto: %0.1f \n\n", string(24, '*').c_str(), _aiPlayer.holeKonto());
	printf("%s|Ai Einsatz: %0.1f \n\n", string(24, '*').c_str(), _Mindesteinsatz);
	printf("%s|Ai LVL: %u \n\n", string(24, '*').c_str(), _aiPlayer.holeLVL());
	printf("%s|Ai XP: %0.0f \n\n", string(24, '*').c_str(), _aiPlayer.holeEXP());
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
		printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case LOSERED:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs rote Feld mit der NR: %d|\n%s|      Du hast diese Runde Verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case WINBLACK:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der Nr: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	case LOSEBLACK:
		//----------------------------------------------------------------------------------Menue
		printf("%s\n%s|Die Kugel rollt aufs schwarze Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), _kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
		//----------------------------------------------------------------------------------Menue
		break;
	default:
		break;


	}


}


