#pragma once //ersatf für ifdefine

#include <string>

using namespace std;

class Spieler // klasse spieler wird beschrieben
{
public:

	Spieler(); //konstruktor
	
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
	int holeSpielerLVL() { return _LVL; };

	void setzeSpielerLVL(unsigned short int &lvl);
	
	~Spieler();// Dekonstruktor

private:

	void pruefeLVLCAp(); //Überpfrüfe ob lvl cap erreicht ist

	string _spielerName; //Lege var fest für Name

	float _Konto; //Lege var fest für GeldKonto
	
	float  _XP; //Lege var fest für Erfahrungspunkte

	unsigned short int _LVL; //Lege var fest für LVL

	float _lvlCapP; //Lege var fest für Lvl größe

	

};

