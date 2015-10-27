#pragma once


#include "CasinoBank.h"
#include "Dealer.h"
#include "Spieler.h"


class Tisch
{
public:

	Tisch();

	

	void InitTisch(bool rundeGewonnen, bool bleibtRot, bool bleibtSchwarz, float verlorenAufRot, float verlorenAufSchwarz, int gespielteSpiele, float setzeAufRot, float setzeAufSchwarz);

	void SetWindow(int width,int high);



	void Print();

	void Speichern();

	/*void Laden(Spieler Sp,CasinoBank CB);*/

	~Tisch();


private:


	float _Prozent=100.0f;

	double _Mindesteinsatz=0.2f;

	int _dealerKugel=0;

	bool _bleibtSchwarz;
	bool _bleibtRot;
	bool _RundeGewonnen;

	unsigned long int _RotAuswahl;
	unsigned long int _SchwarzAuswahl;

	float _setzeAufRot;
	float _setzeAufSchwarz;

	float _verlorenAufRot;
	float _verlorenAufSchwarz;

	unsigned short int _gespielteSpiele;

	Spieler _spieler;
	Dealer _dealer;
	CasinoBank _casinoBank;


	//int _Width;
	//int _Height;


};

