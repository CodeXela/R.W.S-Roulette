#include "Dealer.h"

#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

Dealer::Dealer()
{
	
}


Dealer::~Dealer()
{
}


int Dealer::RolltKugel()//TO-DO: zufälligkeit verbessern
{
	static default_random_engine zufallGenerator(time(NULL));

	uniform_int_distribution<int> zufallWurf(0, 36);

	/*PlaySound(TEXT("roulette_wheel.wav"), NULL, SND_SYNC);*///Spiele Sound bevor ausgabe

	return zufallWurf(zufallGenerator);//übergeb die gewürfelte zahl
}