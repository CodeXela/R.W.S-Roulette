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


Tisch::Tisch()
{
	
	SetWindow(85,40);//setze Consolengröße fest

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);//setze Consolenhintergrund fest 

	InitTisch(false,false,false,0.0f,0.0f,0);//Statistik startwerte (MERKE*ersetzen mit eingabe)
	
	_spieler.initSpieler("Temako",100.0f,0);// Spieler startwerte (MERKE*ersetzen mit eingabe)

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
	
	
	printf("                                                                        \n");
	
	cout << "                              "; coutc(grey, "Roulette Simulator v0.1\n");
	cout << endl; 
	cout <<"   Spieler Name:         "<<_spieler.holeSpielerName(); printf("                      Casino Bank:  %0.2f Euro   \n", _casinoBank.BankPrint());

	printf("   Spieler Konto:        %0.2f Euro", _spieler.holeSpielerKonto()); printf("              Mindesteinsatz:        %0.2f Cent   \n", _Mindesteinsatz);
	printf("   Spieler Erfahrung:      %d Punkte.                                                                            ", _spieler.holeSpielerXP());
	
	//printf("%d",_dealer.RolltKugel());//Dealer Sound und Zahlausgabe (Test)


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
		FILE << std::fixed << std::setprecision(2) << _spieler.holeSpielerKonto() << endl;
		FILE << std::fixed << std::setprecision(2) << _casinoBank.BankPrint() << endl;

	}FILE.close();


}


