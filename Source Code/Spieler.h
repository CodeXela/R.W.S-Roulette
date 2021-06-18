#pragma once //ersatf für ifdefine
#include "Player.h"
#include <string>

using namespace std;

class Spieler:public Player // klasse spieler wird beschrieben
{
public:

	Spieler(); //konstruktor
	
	string holeSpielerName() { return _spielerName; };

	void setzeSpielerName(string SN);
	
	~Spieler();// Dekonstruktor

private:
		
	string _spielerName{}; //Lege var fest für Name
	
};

