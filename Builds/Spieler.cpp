#include "Spieler.h"



Spieler::Spieler()
{



}

Spieler::~Spieler()
{


}

void Spieler::initSpieler(string spielerName,float konto,float XP, unsigned short int Lvl)
{
	_spielerName = spielerName;
	_Konto = konto;
	_XP = XP;
	_LVL = Lvl;
}
void Spieler::setzeSpielerXP(float &xp)
{
	_XP += xp;

		if (_XP > 1000.0f && _LVL < 5)
		{
			_XP -= 1000.0f;
			_LVL++;

			printf("Neuling Stufe %d erreicht", _LVL);
			getchar();
		}
		if (_XP > 2000.0f && _LVL < 10) {
			_XP -= 2000.0f;
			_LVL++;
			printf("Anfänger Stufe %d erreicht", _LVL);
			getchar();
		}
		if (_XP > 3000.0f && _LVL <= 15) {
			_XP -= 3000.0f;
			_LVL++;
			printf("Mitspieler Stufe %d erreicht", _LVL);
			getchar();
		}
		if (_XP > 4000.0f && _LVL <= 20) {
			_XP -= 4000.0f;
			_LVL++;

		}
		if (_XP > 5000.0f && _LVL <= 25) {
			_XP -= 5000.0f;
			_LVL++;

		}
		if (_XP > 6000.0f && _LVL <= 30) {
			_XP -= 6000.0f;
			_LVL++;

		}
		if (_XP > 7000.0f && _LVL <= 35) {
			_XP -= 7000.0f;
			_LVL++;

		}
		if (_XP > 8000.0f && _LVL <= 40) {
			_XP -= 8000.0f;
			_LVL++;

		}
		if (_XP > 9000.0f && _LVL <= 45) {
			_XP -= 9000.0f;
			_LVL++;

		}
		if (_XP > 10000.0f && _LVL <= 50) {
			_XP -= 10000.0f;
			_LVL++;

		}
		if (_XP > 11000.0f && _LVL <= 55) {
			_XP -= 11000.0f;
			_LVL++;

		}
		if (_XP > 12000.0f && _LVL <= 60) {
			_XP -= 12000.0f;
			_LVL++;
		}
		if (_XP > 13000.0f && _LVL <= 65) {
			_XP -= 13000.0f;
			_LVL++;
		}
		if (_XP > 14000.0f && _LVL <= 70) {
			_XP -= 14000.0f;
			_LVL++;
		}
		if (_XP > 15000.0f && _LVL <= 75) {
			_XP -= 15000.0f;
			_LVL++;
		}
	
}
void Spieler::setzeSpielerName(string SN)
{

	_spielerName = SN;

}
void Spieler::setzeSpielerKonto(float &k)
{

	_Konto += k;

}

void Spieler::entferneSpielerKonto(float &ek)
{

	_Konto -= ek;
}
void Spieler::setzeSpielerLVL(unsigned short int &lvl)
{

	_LVL += lvl;

}



