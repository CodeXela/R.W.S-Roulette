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


int Dealer::RolltKugel()
{
	default_random_engine zufallGenerator(time(NULL));
	uniform_int_distribution<int> zufallWurf(0, 37);

	/*PlaySound(TEXT("roulette_wheel.wav"), NULL, SND_SYNC);*///Spiele Sound bevor ausgabe
	return zufallWurf(zufallGenerator);//�bergeb die gew�rfelte zahl
}