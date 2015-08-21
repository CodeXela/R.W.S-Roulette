#pragma once
#include "CasinoBank.h"
#include "Dealer.h"
#include "Spieler.h"

class Tisch
{
public:

	Tisch();

	~Tisch();

	void InitTisch(bool rundeGewonnen, bool bleibtRot, bool bleibtSchwarz);

	


private:


	float _Prozent=100.0f;

	double _Mindesteinsatz=0.2;

	bool _bleibtSchwarz;
	bool _bleibtRot;
	bool _RundeGewonnen;

	unsigned long int _RotAuswahl;
	unsigned long int _SchwarzAuswahl;

	unsigned long int _setzeAufRot;
	unsigned long int _setzeAufSchwarz;

	Spieler _spieler;
	CasinoBank _casinoBank;

};

