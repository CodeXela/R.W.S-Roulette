#include "Spieler.h"



Spieler::Spieler()
{



}

Spieler::~Spieler()
{


}

void Spieler::initSpieler(string spielerName,float konto,float XP, unsigned short int Lvl, float lvlCapp)
{
	_spielerName = spielerName;
	_Konto = konto;
	_XP = XP;
	_LVL = Lvl;
	_lvlCapP = lvlCapp;
}
void Spieler::setzeSpielerXP(float &xp)
{

	_XP += xp;

	while (_XP >= _lvlCapP ) {


		pruefeLVLCAp();
		
		if (_LVL >=0  && _LVL <= 5  && _XP >= 1000.0f)
		{
			_XP -= 1000.0f;
			_LVL++;
			system("CLS");
			printf("\nNeuling Stufe %d erreicht", _LVL);
			
			
		}
		if (_LVL >=6  && _LVL <= 10 && _XP >= 2000.0f) {
			_XP -= 2000.0f;
			_LVL++;
			system("CLS");
			printf("\nAnfänger Stufe %d erreicht", _LVL);
			
			
		}
		if (_LVL >=11 && _LVL <= 15 && _XP >= 3000.0f) {
			_XP -= 3000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			
		}
		if (_LVL >=16 && _LVL <= 20 && _XP >= 4000.0f) {
			_XP -= 4000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			

		}
		if (_LVL >=21 && _LVL <= 25 && _XP >= 5000.0f) {
			_XP -= 5000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
		
			

		}
		if (_LVL >=26 && _LVL <= 30 && _XP >= 6000.0f) {
			_XP -= 6000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			

		}
		if (_LVL >=31 && _LVL <= 35 && _XP >= 7000.0f) {
			_XP -= 7000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
		

		}
		if (_LVL >=36 && _LVL <= 40 && _XP >= 8000.0f) {
			_XP -= 8000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			

		}
		if (_LVL >=41 && _LVL <= 45 && _XP >= 9000.0f) {
			_XP -= 9000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			

		}
		if (_LVL >=46 && _LVL <= 50 && _XP >= 10000.0f) {
			_XP -= 10000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			

		}
		if (_LVL >=51 && _LVL <= 55 && _XP >= 11000.0f) {
			_XP -= 11000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			

		}
		if (_LVL >=56 && _LVL <= 60 && _XP >= 12000.0f) {
			_XP -= 12000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			
		}
		if (_LVL >=61 && _LVL <= 65 && _XP >= 13000.0f) {
			_XP -= 13000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			
		}
		if (_LVL >=66 && _LVL <= 70 && _XP >= 14000.0f) {
			_XP -= 14000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			
			
		}
		if (_LVL >=71 && _LVL <= 75 && _XP >= 15000.0f) {
			_XP -= 15000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			 
			
		}
		if (_LVL >=76 && _LVL <= 80 && _XP >= 16000.0f) {
			_XP -= 16000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);
			

		}
		if (_LVL >= 81 && _LVL <= 85 && _XP >= 17000.0f) {
			_XP -= 17000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);


		}
		if (_LVL >= 86 && _LVL <= 90 && _XP >= 18000.0f) {
			_XP -= 17000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);


		}
		if (_LVL >= 91 && _LVL <= 95 && _XP >= 19000.0f) {
			_XP -= 16000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);


		}
		if (_LVL >= 96 && _LVL <= 100 && _XP >= 20000.0f) {
			_XP -= 20000.0f;
			_LVL++;
			system("CLS");
			printf("\nMitspieler Stufe %d erreicht", _LVL);


		}
		
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
void Spieler::pruefeLVLCAp()
{

	

	
		if		(holeSpielerLVL() >= 0  && holeSpielerLVL() <= 5)
		{

			_lvlCapP = 1000;

		}
		else if (holeSpielerLVL() >= 6  && holeSpielerLVL() <= 10)
		{
			_lvlCapP = 2000;
		}
		else if (holeSpielerLVL() >= 11 && holeSpielerLVL() <= 15)
		{
			_lvlCapP = 3000;
		}
		else if (holeSpielerLVL() >= 16 && holeSpielerLVL() <= 20)
		{
			_lvlCapP = 4000;
		}
		else if (holeSpielerLVL() >= 21 && holeSpielerLVL() <= 25)
		{
			_lvlCapP = 5000;
		}
		else if (holeSpielerLVL() >= 26 && holeSpielerLVL() <= 30)
		{
			_lvlCapP = 6000;
		}
		else if (holeSpielerLVL() >= 31 && holeSpielerLVL() <= 35)
		{
			_lvlCapP = 7000;
		}
		else if (holeSpielerLVL() >= 36 && holeSpielerLVL() <= 40)
		{
			_lvlCapP = 8000;
		}
		else if (holeSpielerLVL() >= 41 && holeSpielerLVL() <= 45)
		{
			_lvlCapP = 9000;
		}
		else if (holeSpielerLVL() >= 46 && holeSpielerLVL() <= 50)
		{
			_lvlCapP = 10000;
		}
		else if (holeSpielerLVL() >= 51 && holeSpielerLVL() <= 55)
		{
			_lvlCapP = 11000;
		}
		else if (holeSpielerLVL() >= 56 && holeSpielerLVL() <= 60)
		{
			_lvlCapP = 12000;
		}
		else if (holeSpielerLVL() >= 61 && holeSpielerLVL() <= 65)
		{
			_lvlCapP = 13000;
		}
		else if (holeSpielerLVL() >= 66 && holeSpielerLVL() <= 70)
		{
			_lvlCapP = 14000;
		}
		else if (holeSpielerLVL() >= 71 && holeSpielerLVL() <= 75)
		{
			_lvlCapP = 15000;
		}
		else if (holeSpielerLVL() >= 76 && holeSpielerLVL() <= 80)
		{
			_lvlCapP = 16000;
		}

	

}
