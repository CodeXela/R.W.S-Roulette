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
	~Tisch();

private:

	void InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz, float lvlCap);
	void berechnungXpbeute();
	
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
	
	

	//Folgeentscheidung und Sieg
	bool _bleibtSchwarz;
	bool _bleibtRot;
	bool _RundeGewonnen;
	bool _Richtig;
	//Rot & Schwarz entscheidung
	string _auswahlWahl="KEINE";

	string _SchwarzAuswahl ="SCHWARZ";
	//Einsätze
	float _setzeAufRot;
	float _setzeAufSchwarz;
	//Verluste
	float _verlorenAufRot;
	float _verlorenAufSchwarz;
	//Match Statistic
	unsigned long int _gespielteSpiele=0;
	unsigned long int _zahlRot=0;
	unsigned long int _zahlSchwarz=0;
	unsigned long int _zahlZero=0;
	float _lvlCap;

	Spieler _spieler;
	Dealer _dealer;
	CasinoBank _casinoBank;


	//int _Width;
	//int _Height;


};

