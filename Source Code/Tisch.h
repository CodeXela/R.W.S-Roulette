#pragma once


#include "CasinoBank.h"
#include "Dealer.h"
#include "Spieler.h"


class Tisch
{
public:

	Tisch();

	void spieleSpiel();
	

	~Tisch();

private:

	void InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz,float verlorenAufZahl, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz,float setzeAufZahl, float lvlCap);
	
	void berechnungXpbeute();

	void prüfeLVLCap(float lvlCapP);

	void Speichern();

	/*void Laden(Spieler Sp,CasinoBank CB);*/


	void Print();

	void SetWindow(int width, int high);


	//print Menue
	void singelPlayerprint();

	void MenueAbfrageprint();

	void setzeAufRotprint();

	void setzeAufSchwarzprint();

	void setzeAufZahlprint();

	void pruefeCinEingabe();
	
private:


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

	//Einsätze
	float _setzeAufRot;

	float _setzeAufSchwarz;

	float _setzeAufZahl;

	//Verluste
	float _verlorenAufRot;

	float _verlorenAufSchwarz;

	float _verlorenAufZahl;

	//Match Statistic
	unsigned long int _gespielteSpiele=0;

	unsigned long int _zahlRot=0;

	unsigned long int _zahlSchwarz=0;

	unsigned long int _zahlZero=0;

	unsigned short int _ZahlAuswahl=0;

	float _lvlCap;

	Spieler _spieler;
	Dealer _dealer;
	CasinoBank _casinoBank;


	/*int _Width =0;
	int _Height =0;*/

	

	unsigned short int kugelgefallen = 0;
	const int anzahl = 8;
	int *rot = new int[18]{ 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	int *schwarz = new int[18]{ 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };

	char *name = new char[anzahl];
};

