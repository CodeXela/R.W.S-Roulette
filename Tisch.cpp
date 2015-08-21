#include "Tisch.h"




Tisch::Tisch()
{
	InitTisch(false,false,false);
	_spieler.initSpieler("Alex",100.0f,0.0f,0.0f,0);
	_casinoBank.initCB(1000000.0f);
}

Tisch::~Tisch()
{

}
void Tisch::InitTisch(bool rundeGewonnen, bool bleibtRot, bool bleibtSchwarz)
{

	_RundeGewonnen = rundeGewonnen;
	_bleibtRot = bleibtRot;
	_bleibtSchwarz = bleibtSchwarz;

}


