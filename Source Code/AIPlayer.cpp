#include "AIPlayer.h"


AIPlayer::AIPlayer():Player()
{
}


////bool AIPlayer::setzeAIPAufZahl(unsigned short int kugelGefallen,float mindestEinsatz,float setzeAufZahl, unsigned short int zahlAuswahl)
////{
////	if (_Konto >= mindestEinsatz)
////	{
////		
////		halteKonto = _Konto;
////
////		halteEinsatz = setzeAufZahl;
////
////		_gespielteSpiele++;
////
////		_auswahlWahl = "ZAHL";
////
////		//----------------------------------------------------------------------------------Menue
////		printf("                           Deine Zahl auf die Du Wetten moechtest?\n");
////		//----------------------------------------------------------------------------------Menue
////
////		cin >> zahlAuswahl;
////
////		cin.clear();
////		cin.ignore(INT_MAX, '\n');
////
////		if (setzeAufZahl <= _Konto)
////		{
////			if (setzeAufZahl < mindestEinsatz)
////			{
////				system("CLS");
////
////				//----------------------------------------------------------------------------------Menue
////				cout << "Der mindesteinsatz ist " << _Mindesteinsatz << endl << "Du hast aber " << _setzeAufZahl << " versucht zu setzen " << endl;
////				printf("Weiter mit belibigen taste . . .");
////				//----------------------------------------------------------------------------------Menue
////
////				getchar();
////
////
////			}
////
////			
////			entferneAIPlayerKonto(setzeAufZahl);
////
////			if (kugelGefallen == zahlAuswahl)
////			{
////
////
////				printf("%s\n%s|Die Kugel rollt aufs Feld mit der NR: %d|\n%s|      Du hast diese Runde Gewonnen !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
////
////				_casinoBank.entferneBankKonto(setzeAufZahl);
////
////				setzeAufZahl = (setzeAufZahl * 36);
////
////				setzeAIPlayerKonto(setzeAufZahl);
////
////				_RundeGewonnen = true;
////
////				berechnungXpbeute();
////
////				_spieler.setzeSpielerXP(xpanzahl);//XP und LVL Test
////
////				prüfeLVLCap(_spieler.holeSpielerXP());
////
////				setzeAufZahl = NULL;
////
////				return true;
////			}
////			else {
////
////
////				printf("%s\n%s|Die Kugel rollt aufs Feld mit der Nr: %d|\n%s|      Du hast diese Runde verloren !\n%s\n", string(95, '#').c_str(), string(24, ' ').c_str(), kugelgefallen, string(24, ' ').c_str(), string(95, '#').c_str());
////
////				_casinoBank.setzeBankKonto(setzeAufZahl);
////
////				_RundeGewonnen = false;
////
////				berechnungXpbeute();
////
////				_spieler.setzeSpielerXP(xpanzahl);
////
////				prüfeLVLCap(_spieler.holeSpielerXP());
////
////				setzeAufZahl = NULL;
////
////				return false;
////			}
////
////		}
////
////		getchar();
////	}
////	else {
////
////		printf("Du hast zu wenig Geld");
////
////		getchar();
////
////		optionen = SINGLE_PLAYER;
////		return;
////	}
////
////}


AIPlayer::~AIPlayer()
{
}
