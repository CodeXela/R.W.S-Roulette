#pragma once


class Player
{
public:

	Player();

	//Fülle die Klasse mit anfangsdaten
	void initPlayer(double konto, unsigned int lvl, unsigned int exp, unsigned int lvlcap);


	//----------Auzskunft über Daten--------------->
	double holeKonto() { return _Konto; };
	unsigned int holeLVL() { return _LVL; };
	double holeEXP() { return _EXP; };
	unsigned int holeLVLCap() { return _LVLCap; };
	//----------Auzskunft über Daten--------------->

	//-------Konto--------------->
	void setzeKonto(double& konto);
	void entferneKonto(double& konto);
	//-------Konto--------------->

	void setzeLVL(unsigned int& lvl);
	void setzeEXP(double& exp);

	//------------->
	bool setzeAufRot(int &kugelgefallen);
	bool setzeAufSchwarz(int& kugelgefallen);
	bool setzeAufUngerade(int& kugelgefallen);
	bool setzeAufGerade(int& kugelgefallen);
	bool setzeAufHigh(int& kugelgefallen);
	bool setzeAufLow(int& kugelgefallen);
	bool setzeAufDutzen1_12(int& kugelgefallen);
	bool setzeAufDutzen2_12(int& kugelgefallen);
	bool setzeAufDutzen3_12(int& kugelgefallen);
	bool setzeAufSpalte_1(int& kugelgefallen);
	bool setzeAufSpalte_2(int& kugelgefallen);
	bool setzeAufSpalte_3(int& kugelgefallen);

	bool setzeAufQuadrat_1(int& kugelgefallen);
	bool setzeAufQuadrat_2(int& kugelgefallen);
	bool setzeAufQuadrat_3(int& kugelgefallen);
	bool setzeAufQuadrat_4(int& kugelgefallen);
	bool setzeAufQuadrat_5(int& kugelgefallen);
	bool setzeAufQuadrat_6(int& kugelgefallen);
	bool setzeAufQuadrat_7(int& kugelgefallen);
	bool setzeAufQuadrat_8(int& kugelgefallen);
	bool setzeAufQuadrat_9(int& kugelgefallen);
	bool setzeAufQuadrat_10(int& kugelgefallen);
	bool setzeAufQuadrat_11(int& kugelgefallen);
	bool setzeAufQuadrat_12(int& kugelgefallen);
	bool setzeAufQuadrat_13(int& kugelgefallen);
	bool setzeAufQuadrat_14(int& kugelgefallen);
	bool setzeAufQuadrat_15(int& kugelgefallen);
	bool setzeAufQuadrat_16(int& kugelgefallen);
	bool setzeAufQuadrat_17(int& kugelgefallen);
	bool setzeAufQuadrat_18(int& kugelgefallen);
	bool setzeAufQuadrat_19(int& kugelgefallen);
	bool setzeAufQuadrat_20(int& kugelgefallen);
	bool setzeAufQuadrat_21(int& kugelgefallen);
	bool setzeAufQuadrat_22(int& kugelgefallen);

	~Player();

protected:

	void pruefeLVLCap();


protected:

	double _Konto{};
	unsigned int _LVL{};
	double _EXP{};
	unsigned int _LVLCap{};

	int* _rot = new int[18]{ 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
	int* _schwarz = new int[18]{ 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
	int* _ungerade = new int[18]{ 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35 };
	int* _gerade = new int[18]{ 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36 };
	int* _high = new int[18]{ 19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
	int* _low = new int[18]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
	int* _dutzen1_12 = new int[12]{ 1,2,3,4,5,6,7,8,9,10,11,12 };
	int* _dutzen2_12 = new int[12]{ 13,14,15,16,17,18,19,20,21,22,23,24 };
	int* _dutzen3_12 = new int[12]{ 25,26,27,28,29,30,31,32,33,34,35,36 };
	int* _spalte_1 = new int[12]{ 1,4,7,10,13,16,19,22,25,28,31,34 };
	int* _spalte_2 = new int[12]{ 2,5,8,11,14,17,20,23,26,29,32,35 };
	int* _spalte_3 = new int[12]{ 3,6,9,12,15,18,21,24,27,30,33,36 };
	int* _quadrat_1 = new int[4]{ 1,2,4,5 };
	int* _quadrat_2 = new int[4]{ 2,3,4,6 };
	int* _quadrat_3 = new int[4]{ 4,5,7,8 };
	int* _quadrat_4 = new int[4]{ 5,6,8,9 };
	int* _quadrat_5 = new int[4]{ 7,8,10,11 };
	int* _quadrat_6 = new int[4]{ 8,9,11,12 };
	int* _quadrat_7 = new int[4]{ 10,11,13,14 };
	int* _quadrat_8 = new int[4]{ 11,12,14,15 };
	int* _quadrat_9 = new int[4]{ 13,14,16,17 };
	int* _quadrat_10 = new int[4]{ 14,15,17,18 };
	int* _quadrat_11 = new int[4]{ 16,17,19,20 };
	int* _quadrat_12 = new int[4]{ 17,18,20,21 };
	int* _quadrat_13 = new int[4]{ 19,20,22,23 };
	int* _quadrat_14 = new int[4]{ 20,21,23,24 };
	int* _quadrat_15 = new int[4]{ 22,23,25,26 };
	int* _quadrat_16 = new int[4]{ 23,24,26,27 };
	int* _quadrat_17 = new int[4]{ 25,26,28,29 };
	int* _quadrat_18 = new int[4]{ 26,27,29,30 };
	int* _quadrat_19 = new int[4]{ 28,29,31,32 };
	int* _quadrat_20 = new int[4]{ 29,30,32,33 };
	int* _quadrat_21 = new int[4]{ 31,32,34,35 };
	int* _quadrat_22 = new int[4]{ 32,33,35,36 };


private:

};

