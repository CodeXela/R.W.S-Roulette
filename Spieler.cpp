#include "Spieler.h"



Spieler::Spieler()
{



}

Spieler::~Spieler()
{


}

void Spieler::initSpieler(string spielerName,float konto, float verlorenAufRot, float verlorenAufSchwarz, unsigned short int gespielteSpiele)
{
	_spielerName = spielerName;
	_Konto = konto;
	_verlorenAufRot = verlorenAufRot;
	_verlorenAufSchwarz = verlorenAufSchwarz;
	_gespielteSpiele = gespielteSpiele;

}

