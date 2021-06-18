#pragma once

//---------------------
#include "CasinoBank.h"
#include "Dealer.h"		//Binde alles ein was ich benutzen möchte
#include "Spieler.h"	//Die Klasse Tisch übernimmt die hautverwaltung
#include "AIPlayer.h"

#include <vector>
//---------------------

class Tisch
{
public:

	Tisch();

	void spieleSpiel();
	

	~Tisch();

private:

	void InitTisch(bool rundeGewonnen, bool richtig, bool bleibtRot, bool bleibtSchwarz, double gewonnenAufRot, double gewonnenAufSchwarz, double verlorenAufRot, double verlorenAufSchwarz, double verlorenAufZahl, int gespielteSpiele, double setzeAufRot, double setzeAufSchwarz, double setzeAufZahl, unsigned int lvlCap);
	
	void berechnungXpbeute();

	//void prüfeLVLCap(float lvlCapP);

	void legeDatenAb(string runde, string skonto,string konto, string eisatz, string farbe, string casinobank, string gewonnen,string kugel,string gewonnenauf,string lvl, string exp, string expAnzahl, string multi, string expBonus);

	void Speichern();

	/*void Laden(Spieler Sp,CasinoBank CB);*/


	void Print();//Gebe auf bildschirm alles aus

	void SetWindow(int width, int high); //stellt die groeße der console ein


	//print Menue
	void MenueAbfragePrint();
	void singelPlayerPrint();
	void printAiMainMenu();
	void AIMenuePrint();

	//print Einsatzarten
	void setzeAufRotPrint();
	void setzeAufSchwarzPrint();
	void setzeAufZahlPrint();
	
	void setzeAufUngeradePrint();
	void setzeAufGeradePrint();
	void setzeAufHighPrint();
	void setzeAufLowPrint();
	void setzeAufDutzen1_12Print();
	void setzeAufDutzen2_12Print();
	void setzeAufDutzen3_12Print();
	void setzeAufSpalte_1Print();
	void setzeAufSpalte_2Print();
	void setzeAufSpalte_3Print();

	void setzeAufQuadrat_1Print();
	void setzeAufQuadrat_2Print();
	void setzeAufQuadrat_3Print();
	void setzeAufQuadrat_4Print();
	void setzeAufQuadrat_5Print();
	void setzeAufQuadrat_6Print();
	void setzeAufQuadrat_7Print();
	void setzeAufQuadrat_8Print();
	void setzeAufQuadrat_9Print();
	void setzeAufQuadrat_10Print();
	void setzeAufQuadrat_11Print();
	void setzeAufQuadrat_12Print();
	void setzeAufQuadrat_13Print();
	void setzeAufQuadrat_14Print();
	void setzeAufQuadrat_15Print();
	void setzeAufQuadrat_16Print();
	void setzeAufQuadrat_17Print();
	void setzeAufQuadrat_18Print();
	void setzeAufQuadrat_19Print();
	void setzeAufQuadrat_20Print();
	void setzeAufQuadrat_21Print();
	void setzeAufQuadrat_22Print();

	

	void cleanupAIPlayer();

	void printXpBerechnungGewinn();

	void printXpBerechnungVerlust();

	void printGewinnVerlust(unsigned short int c);

	
private:

	//Var für diverse berechnungen
	const float _Prozent=100.0f;

	double _Mindesteinsatz=1.0;

	double _MultiCap = 0.0;

	double xpanzahl = 0;

	double xpBonus = 0;

	double halteFest = 0.0;

	double halteEinsatz = 0.0;

	double halteKonto = 0.0;

	double Multiplikator = 0.0;
	
	//Folgeentscheidung und Sieg
	bool _bleibtSchwarz;

	bool _bleibtRot;

	bool _RundeGewonnen;

	bool _Richtig = false;

	//Rot & Schwarz entscheidung
	string _auswahlWahl="KEINE";

	char _farbe = 0;

	char _Runde = 'A';

	//Einsätze
	double _setzeAufRot;

	double _setzeAufSchwarz;

	double _setzeAufZahl;

	double _einsatzAIP=0.0;

	double _gewinnAIP = 0.0;

	//gewinne

	double _gewonnenAufRot;

	double _gewonnenAufSchwarz;

	//Verluste
	double _verlorenAufRot;

	double _verlorenAufSchwarz;

	double _verlorenAufZahl;

	//Match Statistic
	unsigned long int _gespielteSpiele;

	unsigned long int _zahlRot=0;

	unsigned long int _zahlSchwarz=0;

	unsigned long int _zahlZero=0;

	unsigned short int _ZahlAuswahl=0;


	unsigned int _lvlCap;

	Spieler _spieler;

	AIPlayer _aiPlayer;
	
	Dealer _dealer;

	CasinoBank _casinoBank;

	std::vector<string> _vectorDaten;

	/*int _Width =0;
	int _Height =0;*/

	int _kugelgefallen = 0;
	float _version=0.105f;
	
};

