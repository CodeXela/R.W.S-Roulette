#include "Spieler.h"



Spieler::Spieler()
{



}

Spieler::~Spieler()
{


}

void Spieler::initSpieler(string spielerName,float konto,float XP)
{
	_spielerName = spielerName;
	_Konto = konto;
	_XP = XP;

}
void Spieler::setzeSpielerXP(float xp)
{
	_XP=xp;

}
void Spieler::setzeSpielerName(string SN)
{

	_spielerName = SN;

}
void Spieler::setzeSpielerKonto(float k)
{

	_Konto = k;

}

