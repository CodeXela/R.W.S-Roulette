#pragma once

#include <string>

using namespace std;

class Spieler
{
public:
	Spieler();
	
	~Spieler();

	void initSpieler(string spielerName, float konto, float verlorenAufRot, float _verlorenAufSchwarz, unsigned short int gespielteSpiele);

private:

	string _spielerName;

	float _Konto;
	float _verlorenAufRot;
	float _verlorenAufSchwarz;

	unsigned short int _gespielteSpiele;

};

