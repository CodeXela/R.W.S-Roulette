#pragma once


#include "CasinoBank.h"
#include "Dealer.h"
#include "Spieler.h"


class Tisch
{
public:

	Tisch();

	

	void InitTisch(bool rundeGewonnen, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele);

	void SetWindow(int width,int high);
	void coutc(int color, char* output);

	void Print();

	~Tisch();


private:


	float _Prozent=100.0f;

	double _Mindesteinsatz=0.2f;

	bool _bleibtSchwarz;
	bool _bleibtRot;
	bool _RundeGewonnen;

	unsigned long int _RotAuswahl;
	unsigned long int _SchwarzAuswahl;

	unsigned long int _setzeAufRot;
	unsigned long int _setzeAufSchwarz;

	float _verlorenAufRot;
	float _verlorenAufSchwarz;

	unsigned short int _gespielteSpiele;

	Spieler _spieler;
	Dealer _dealer;
	CasinoBank _casinoBank;

	int _Width;
	int _Height;



};

