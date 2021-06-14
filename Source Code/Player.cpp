#include "Player.h"

Player::Player()
{
}

void Player::initPlayer(double konto, unsigned int lvl, unsigned int exp, unsigned int lvlcap)
{
	_Konto = konto;
	_LVL = lvl;
	_EXP = exp;
	_LVLCap = lvlcap;
}

Player::~Player()
{
}

void Player::setzeKonto(double& konto)
{
	_Konto += konto;
}

void Player::entferneKonto(double& konto)
{
	_Konto -= konto;
}

void Player::setzeLVL(unsigned int& lvl)
{
	_LVL += lvl;
}

void Player::setzeEXP(double& exp)
{
	_EXP += exp;

	while (_EXP >= _LVLCap) { //schleife solange wie xp größer gleich lvlCap
	
		pruefeLVLCap(); //prüfe ob Lvl cap erreicht ist
		
		if (_LVL >=0  && _LVL <= 5  && _EXP >= 1000) //wenn lvl größer oder gleich 0 und lvl kleiner oder gleich 5 und xp gößer oder gleich 1000 dann:
		{
			_EXP -= 1000; //ziehe vom spieler die 1000 xp ab
			_LVL++; // füge ein lvl hinzu		
		}
		if (_LVL >=6  && _LVL <= 10 && _EXP >= 2000) {

			_EXP -= 2000;
			_LVL++;	
		}
		if (_LVL >=11 && _LVL <= 15 && _EXP >= 3000) {

			_EXP -= 3000;
			_LVL++;
		}
		if (_LVL >=16 && _LVL <= 20 && _EXP >= 4000) {

			_EXP -= 4000;
			_LVL++;
		}
		if (_LVL >=21 && _LVL <= 25 && _EXP >= 5000) {

			_EXP -= 5000;
			_LVL++;
		}
		if (_LVL >=26 && _LVL <= 30 && _EXP >= 6000) {

			_EXP -= 6000;
			_LVL++;
		}
		if (_LVL >=31 && _LVL <= 35 && _EXP >= 7000) {

			_EXP -= 7000;
			_LVL++;

		}
		if (_LVL >=36 && _LVL <= 40 && _EXP >= 8000) {

			_EXP -= 8000;
			_LVL++;
		}
		if (_LVL >=41 && _LVL <= 45 && _EXP >= 9000) {

			_EXP -= 9000;
			_LVL++;
		}
		if (_LVL >=46 && _LVL <= 50 && _EXP >= 10000) {

			_EXP -= 10000;
			_LVL++;
		}
		if (_LVL >=51 && _LVL <= 55 && _EXP >= 11000) {

			_EXP -= 11000;
			_LVL++;
		}
		if (_LVL >=56 && _LVL <= 60 && _EXP >= 12000) {

			_EXP -= 12000;
			_LVL++;
		}
		if (_LVL >=61 && _LVL <= 65 && _EXP >= 13000) {

			_EXP -= 13000;
			_LVL++;
		}
		if (_LVL >=66 && _LVL <= 70 && _EXP >= 14000) {

			_EXP -= 14000;
			_LVL++;
		}
		if (_LVL >=71 && _LVL <= 75 && _EXP >= 15000) {

			_EXP -= 15000;
			_LVL++;
		}
		if (_LVL >=76 && _LVL <= 80 && _EXP >= 16000) {

			_EXP -= 16000;
			_LVL++;
		}
		if (_LVL >= 81 && _LVL <= 85 && _EXP >= 17000) {

			_EXP -= 17000;
			_LVL++;
		}
		if (_LVL >= 86 && _LVL <= 90 && _EXP >= 18000) {

			_EXP -= 17000;
			_LVL++;
		}
		if (_LVL >= 91 && _LVL <= 95 && _EXP >= 19000) {

			_EXP -= 16000;
			_LVL++;
		}
		if (_LVL >= 96 && _LVL <= 100 && _EXP >= 20000) {

			_EXP -= 20000;
			_LVL++;
		}
	}
}

void Player::pruefeLVLCap()
{
	if (holeLVL() >= 0 && holeLVL() <= 5) //wenn  spieler lvl größer oder gleich 0 ist und spieler lvl kleiner oder gleich 5 ist:
	{
		_LVLCap = 1000; // LVL cap für lvl 1 ist 1000 exp punkte
	}
	else if (holeLVL() >= 6 && holeLVL() <= 10)
	{
		_LVLCap = 2000;
	}
	else if (holeLVL() >= 11 && holeLVL() <= 15)
	{
		_LVLCap = 3000;
	}
	else if (holeLVL() >= 16 && holeLVL() <= 20)
	{
		_LVLCap = 4000;
	}
	else if (holeLVL() >= 21 && holeLVL() <= 25)
	{
		_LVLCap = 5000;
	}
	else if (holeLVL() >= 26 && holeLVL() <= 30)
	{
		_LVLCap = 6000;
	}
	else if (holeLVL() >= 31 && holeLVL() <= 35)
	{
		_LVLCap = 7000;
	}
	else if (holeLVL() >= 36 && holeLVL() <= 40)
	{
		_LVLCap = 8000;
	}
	else if (holeLVL() >= 41 && holeLVL() <= 45)
	{
		_LVLCap = 9000;
	}
	else if (holeLVL() >= 46 && holeLVL() <= 50)
	{
		_LVLCap = 10000;
	}
	else if (holeLVL() >= 51 && holeLVL() <= 55)
	{
		_LVLCap = 11000;
	}
	else if (holeLVL() >= 56 && holeLVL() <= 60)
	{
		_LVLCap = 12000;
	}
	else if (holeLVL() >= 61 && holeLVL() <= 65)
	{
		_LVLCap = 13000;
	}
	else if (holeLVL() >= 66 && holeLVL() <= 70)
	{
		_LVLCap = 14000;
	}
	else if (holeLVL() >= 71 && holeLVL() <= 75)
	{
		_LVLCap = 15000;
	}
	else if (holeLVL() >= 76 && holeLVL() <= 80)
	{
		_LVLCap = 16000;
	}
	
}

