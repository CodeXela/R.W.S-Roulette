#include "Dealer.h"
#include <iostream>
#include <random>
#include <ctime>

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

	return zufallWurf(zufallGenerator);
}