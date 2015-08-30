#pragma once

#include <string>

using namespace std;

class Spieler
{
public:
	Spieler();
	
	

	void initSpieler(string spielerName, float konto);

	string holeSpielerName() { return _spielerName; };
	float holeSpielerKonto() { return _Konto; };
	~Spieler();
private:

	string _spielerName;

	float _Konto;
	

};

