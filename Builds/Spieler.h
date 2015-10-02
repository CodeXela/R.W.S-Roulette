#pragma once

#include <string>

using namespace std;

class Spieler
{
public:
	Spieler();
	
	
	//Init für Spieler
	void initSpieler(string spielerName, float konto,float XP);

	//Spieler Name lesen und schreiben
	string holeSpielerName() { return _spielerName; };
	void setzeSpielerName(string SN);

	//Spieler Konto lesen und schreiben
	float holeSpielerKonto() { return _Konto; };
	void setzeSpielerKonto(float k);

	//Spieler XP lesen und schreiben
	float holeSpielerXP() { return _XP; };
	void setzeSpielerXP(float xp);

	~Spieler();
private:

	string _spielerName;

	float _Konto;
	
	float  _XP;

};

