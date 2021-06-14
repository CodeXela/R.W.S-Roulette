#include <iostream>
//#include <string>
//#include <cstdio>
//#include <cstdlib>
//#include <stdio.h>
//#include <Windows.h>

#include "Tisch.h"

using namespace std;


int main()
{
	
	Tisch *T1 = new Tisch(); // Erzeuge instanz von Tisch als zeiger und lege es im Ram ab

	T1->spieleSpiel(); //starte das spiel

	delete T1; //Lösche den besetzten speicher im Ram

	return 0; // beende das programm
}

