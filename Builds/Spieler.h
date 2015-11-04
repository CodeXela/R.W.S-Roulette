#pragma once

#include <string>

using namespace std;

class Spieler
{
public:

	Spieler();
	
	//Init für Spieler
	void initSpieler(string spielerName, float konto,float XP, unsigned short int Lvl, float lvlCapp);

	//Spieler Name lesen und schreiben
	string holeSpielerName() { return _spielerName; };
	void setzeSpielerName(string SN);

	//Spieler Konto lesen und schreiben
	float holeSpielerKonto() { return _Konto; };
	void setzeSpielerKonto(float &k);
	void entferneSpielerKonto(float &ek);

	//Spieler XP lesen und schreiben
	float holeSpielerXP() { return _XP; };
	void setzeSpielerXP(float &xp);

	//Spieler LVL lesen und schreiben
	float holeSpielerLVL() { return _LVL; };
	void setzeSpielerLVL(unsigned short int &lvl);

	~Spieler();
private:

	void pruefeLVLCAp();

	string _spielerName;

	float _Konto;
	
	float  _XP;

	unsigned short int _LVL;

	float _lvlCapP;

	

};

