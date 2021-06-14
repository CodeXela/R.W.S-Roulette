#include "AIPlayer.h"


AIPlayer::AIPlayer():Player()
{
}

//void AIPlayer::setzeAIPlayerXP(float &xp)
//{
//
//	_XP += xp;
//
//	while (_XP >= _lvlCapP) {
//
//
//		pruefeAIPlayerLVLCap();
//
//		if (_LVL >= 0 && _LVL <= 5 && _XP >= 1000.0f)
//		{
//			_XP -= 1000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 6 && _LVL <= 10 && _XP >= 2000.0f) {
//
//			_XP -= 2000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 11 && _LVL <= 15 && _XP >= 3000.0f) {
//
//			_XP -= 3000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 16 && _LVL <= 20 && _XP >= 4000.0f) {
//
//			_XP -= 4000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 21 && _LVL <= 25 && _XP >= 5000.0f) {
//
//			_XP -= 5000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 26 && _LVL <= 30 && _XP >= 6000.0f) {
//
//			_XP -= 6000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 31 && _LVL <= 35 && _XP >= 7000.0f) {
//
//			_XP -= 7000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 36 && _LVL <= 40 && _XP >= 8000.0f) {
//
//			_XP -= 8000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 41 && _LVL <= 45 && _XP >= 9000.0f) {
//
//			_XP -= 9000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 46 && _LVL <= 50 && _XP >= 10000.0f) {
//
//			_XP -= 10000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 51 && _LVL <= 55 && _XP >= 11000.0f) {
//
//			_XP -= 11000.0f;
//			_LVL++;
//
//
//
//
//		}
//		if (_LVL >= 56 && _LVL <= 60 && _XP >= 12000.0f) {
//
//			_XP -= 12000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 61 && _LVL <= 65 && _XP >= 13000.0f) {
//
//			_XP -= 13000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 66 && _LVL <= 70 && _XP >= 14000.0f) {
//
//			_XP -= 14000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 71 && _LVL <= 75 && _XP >= 15000.0f) {
//
//			_XP -= 15000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 76 && _LVL <= 80 && _XP >= 16000.0f) {
//
//			_XP -= 16000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 81 && _LVL <= 85 && _XP >= 17000.0f) {
//
//			_XP -= 17000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 86 && _LVL <= 90 && _XP >= 18000.0f) {
//
//			_XP -= 17000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 91 && _LVL <= 95 && _XP >= 19000.0f) {
//
//			_XP -= 16000.0f;
//			_LVL++;
//
//
//
//		}
//		if (_LVL >= 96 && _LVL <= 100 && _XP >= 20000.0f) {
//
//			_XP -= 20000.0f;
//			_LVL++;
//
//
//
//		}
//
//	}
//}
//void AIPlayer::pruefeAIPlayerLVLCap()
//{
//
//
//	if (holeAIPlayerLVL() >= 0 && holeAIPlayerLVL() <= 5)
//	{
//
//		_lvlCapP = 1000;
//
//	}
//	else if (holeAIPlayerLVL() >= 6 && holeAIPlayerLVL() <= 10)
//	{
//		_lvlCapP = 2000;
//	}
//	else if (holeAIPlayerLVL() >= 11 && holeAIPlayerLVL() <= 15)
//	{
//		_lvlCapP = 3000;
//	}
//	else if (holeAIPlayerLVL() >= 16 && holeAIPlayerLVL() <= 20)
//	{
//		_lvlCapP = 4000;
//	}
//	else if (holeAIPlayerLVL() >= 21 && holeAIPlayerLVL() <= 25)
//	{
//		_lvlCapP = 5000;
//	}
//	else if (holeAIPlayerLVL() >= 26 && holeAIPlayerLVL() <= 30)
//	{
//		_lvlCapP = 6000;
//	}
//	else if (holeAIPlayerLVL() >= 31 && holeAIPlayerLVL() <= 35)
//	{
//		_lvlCapP = 7000;
//	}
//	else if (holeAIPlayerLVL() >= 36 && holeAIPlayerLVL() <= 40)
//	{
//		_lvlCapP = 8000;
//	}
//	else if (holeAIPlayerLVL() >= 41 && holeAIPlayerLVL() <= 45)
//	{
//		_lvlCapP = 9000;
//	}
//	else if (holeAIPlayerLVL() >= 46 && holeAIPlayerLVL() <= 50)
//	{
//		_lvlCapP = 10000;
//	}
//	else if (holeAIPlayerLVL() >= 51 && holeAIPlayerLVL() <= 55)
//	{
//		_lvlCapP = 11000;
//	}
//	else if (holeAIPlayerLVL() >= 56 && holeAIPlayerLVL() <= 60)
//	{
//		_lvlCapP = 12000;
//	}
//	else if (holeAIPlayerLVL() >= 61 && holeAIPlayerLVL() <= 65)
//	{
//		_lvlCapP = 13000;
//	}
//	else if (holeAIPlayerLVL() >= 66 && holeAIPlayerLVL() <= 70)
//	{
//		_lvlCapP = 14000;
//	}
//	else if (holeAIPlayerLVL() >= 71 && holeAIPlayerLVL() <= 75)
//	{
//		_lvlCapP = 15000;
//	}
//	else if (holeAIPlayerLVL() >= 76 && holeAIPlayerLVL() <= 80)
//	{
//		_lvlCapP = 16000;
//	}
//
//
//
//}
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
