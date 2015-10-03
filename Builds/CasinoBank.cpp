#include "CasinoBank.h"



CasinoBank::CasinoBank()
{
	
}

void CasinoBank::initCB(float bank)
{

	_Bank = bank;

}
CasinoBank::~CasinoBank()
{
}

void CasinoBank::setzeBankKonto(float bank)
{
	_Bank += bank;

}
void CasinoBank::entferneBankKonto(float nbank)
{
	_Bank -= nbank;

}
