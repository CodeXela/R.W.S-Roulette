#pragma once
class AIPlayer
{
public:

	AIPlayer();

	void initAIPlayer( float konto, float XP, unsigned short int Lvl, float lvlCapp);


	float holeAIPlayerXP() { return _XP; };
	void setzeAIPlayerXP(float &xp);
	

	int holeAIPlayerLVL() { return _LVL; };
	void setzeAIPlayerLVL(unsigned short int &aipLVL);


	float holeAIPlayerKonto() { return _Konto; };
	void setzeAIPlayerKonto(float &aipKonto);
	void entferneAIPlayerKonto(float &aipKontoE);
	
	

	~AIPlayer();

private:

	void pruefeAIPlayerLVLCap();

private:

	float _Konto;

	float  _XP;

	unsigned short int _LVL;

	float _lvlCapP;
};

