#pragma once

//---------------------
#include "CasinoBank.h"
#include "Dealer.h"		//Binde alles ein was ich benutzen möchte
#include "Spieler.h"	//Die Klasse Tisch übernimmt die hautverwaltung
#include "AIPlayer.h"
//---------------------

class Tisch
{
public:

	Tisch();

	void spieleSpiel();
	

	~Tisch();

private:

	void InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, float gewonnenAufRot, float gewonnenAufSchwarz, float verlorenAufRot, float verlorenAufSchwarz,float verlorenAufZahl, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz,float setzeAufZahl, float lvlCap);
	
	void berechnungXpbeute();

	void prüfeLVLCap(float lvlCapP);

	void Speichern();

	/*void Laden(Spieler Sp,CasinoBank CB);*/


	void Print();//Gebe auf bildschirm alles aus

	void SetWindow(int width, int high); //stellt die groeße der console ein


	//print Menue
	void singelPlayerprint();

	void MenueAbfrageprint();

	void setzeAufRotprint();

	void setzeAufSchwarzprint();

	void setzeAufZahlprint();

	void AIMenuePrint();

	void pruefeCinEingabe();
	
private:

	//Var für diverse berechnungen
	const float _Prozent=100.0f;

	float _Mindesteinsatz=0.2f;

	float xpanzahl = 0.0f;

	float xpBonus = 0.0f;

	float halteFest = 0.0f;

	float halteEinsatz = 0.0f;

	float halteKonto = 0.0f;

	float Multiplikator = 0.0f;
	
	//Folgeentscheidung und Sieg
	bool _bleibtSchwarz;

	bool _bleibtRot;

	bool _RundeGewonnen;

	bool _Richtig;

	//Rot & Schwarz entscheidung
	string _auswahlWahl="KEINE";

	char _farbe = 0;

	char _Runde = 'A';

	//Einsätze
	float _setzeAufRot;

	float _setzeAufSchwarz;

	float _setzeAufZahl;

	float _einsatzAIP=0.0f;

	//gewinne

	float _gewonnenAufRot;

	float _gewonnenAufSchwarz;

	//Verluste
	float _verlorenAufRot;

	float _verlorenAufSchwarz;

	float _verlorenAufZahl;

	//Match Statistic
	unsigned long int _gespielteSpiele;

	unsigned long int _zahlRot=0;

	unsigned long int _zahlSchwarz=0;

	unsigned long int _zahlZero=0;

	unsigned short int _ZahlAuswahl=0;



	float _lvlCap;

	Spieler _spieler;

	AIPlayer _aiPlayer;
	
	Dealer _dealer;

	CasinoBank _casinoBank;


	/*int _Width =0;
	int _Height =0;*/

	unsigned short int kugelgefallen = 0;
	const int anzahl = 8;
	//Zahlen für Farben (zum testen über Heap)
	int *rot = new int[18]{ 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	int *schwarz = new int[18]{ 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };

	char *name = new char[anzahl];
};

