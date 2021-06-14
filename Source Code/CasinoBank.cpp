#include "CasinoBank.h"



CasinoBank::CasinoBank()
{
	
}

void CasinoBank::initCB(double bank)
{
	_Bank = bank;
}
CasinoBank::~CasinoBank()
{
}

void CasinoBank::setzeBankKonto(double bank)
{
	_Bank += bank;

}
void CasinoBank::entferneBankKonto(double nbank)
{
	_Bank -= nbank;

}
