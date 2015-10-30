#pragma once


#include "CasinoBank.h"
#include "Dealer.h"
#include "Spieler.h"


class Tisch
{
public:

	Tisch();

	void spieleSpiel();
	
	void prüfeLVLCap(float lvlCapP);
	void berechnungXpbeute();
	void InitTisch(bool rundeGewonnen, bool rundeVerloren , bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz, float lvlCap);
	
	

	~Tisch();

private:

	void Speichern();
	/*void Laden(Spieler Sp,CasinoBank CB);*/
	void Print();
	void SetWindow(int width, int high);
	
private:


	const float _Prozent=100.0f;
	float _Mindesteinsatz=0.2f;
	float xpanzahl = 0.0f;//XP und LVL Test
	float xpBonus = 0.0f;
	float halteFest = 0.0f;
	float halteEinsatz = 0.0f;
	float halteKonto = 0.0f;
	float Multiplikator = 0.0f;
	int _dealerKugel=0;
	

	//Folgeentscheidung und Sieg
	bool _bleibtSchwarz;
	bool _bleibtRot;
	bool _RundeGewonnen;
	bool _RundeVerloren;
	//Rot & Schwarz entscheidung
	unsigned long int _RotAuswahl;
	unsigned long int _SchwarzAuswahl;
	//Einsätze
	float _setzeAufRot;
	float _setzeAufSchwarz;
	//Verluste
	float _verlorenAufRot;
	float _verlorenAufSchwarz;
	//Match counter
	unsigned short int _gespielteSpiele;

	float _lvlCap;

	Spieler _spieler;
	Dealer _dealer;
	CasinoBank _casinoBank;


	int _Width;
	int _Height;


};

