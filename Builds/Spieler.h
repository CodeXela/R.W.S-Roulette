#pragma once

#include <string>

using namespace std;

class Spieler
{
public:
	Spieler();
	
	

	void initSpieler(string spielerName, float konto,int XP);
	//Hole daten zur ausgabe
	string holeSpielerName() { return _spielerName; };
	float holeSpielerKonto() { return _Konto; };
	int holeSpielerXP() { return _XP; };

	~Spieler();
private:

	string _spielerName;

	float _Konto;
	
	int  _XP;

};

