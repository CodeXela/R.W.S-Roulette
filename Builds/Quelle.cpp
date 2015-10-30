#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>

#include "Tisch.h"

using namespace std;


int main()
{
	

	Tisch *T1 = new Tisch();

	T1->spieleSpiel();

	delete T1;

	return 0;
}

